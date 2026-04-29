// 1.include area ---------=------------------------------

#include <Arduino.h>
#include <hal_pins.h>
#include <UIManager.h>
#include <OneButton.h>
#include "PowerManager.h"


// decleeartioon for the tasks
// 2.GLOBAL VARIABLES
//-----------------------------------------
SystemState currentState = STATE_BOOT_LOGO;  // initial state of the system BOOT state

OneButton btnUp(PIN_BTN_UP, true);           // active low button, 

OneButton btnDown(PIN_BTN_DOWN, true):       // active down button, for the other fuction like BACK i wiil use the BOOT fuction lter on

OneButton btnSelect(PIN_BTN_SEL, true);      // active slection button 

PowerManager power; 

//3. task declaration

void taskUI(void *pvParameters);        //
void handleClickUp();                   //
void handleClickDown();                 //
void handleClickSelect();               //
void taskRadioGPS(void *pvParameters);  //


// 4.SETUP FUNCTION (Runs once on boot)
void setup() {
  Serial.begin(115200);
  delay(2000); 

  Serial.println("Cyrus Core Compute is ALIVE!");

  // initialize the I2C bus and IOExpander  
  power.init();

  // HArdware reset the oled screeen so it's ready to receive commands

  powerr.resetOLED();

  // wakeup the  radios! yeahhhhh

  power.enableLoRa(true);
  power.enableGPS(true);

  // Button event attachments for the physical selections
  btnUp.attachClick(handleClickUp);
  btnDown.attachClick(handleClickDown);
  btnSelect.attachClick(handleClickSelect);

  // ini

  


  // UI task and sensor Task on core 1
  xTaskCreatePinnedToCore(
    taskUI,          // Task function
    "Task_UI",       // Name of the task 
    8192,            // memory size in bytes
    NULL,
    1,               // priority
    NULL,
    1                // core 1    

    );

    xTaskCreatePinnedToCore(
    taskRadioGPS,
    "Task_RadioGPS",

    8192,
    NULL,
    2,           // Higher priority for communications
    NULL,
    0
    );
}


//- 5. standard loop -------
/// @brief Main loop, not used as we are using FreeRTOS tasks, so we delete the default loop task to save resources
void loop() {
  // free Rtos is handling the task scheduling
  vTaskDelete(NULL);
}

// --- 6. task Implementiation ---

void taskUI(void *pvParameters) {

    // everything in this 'for' loop runs forever on core 1
  for(;;) {

    btnUp.tick();     // check the state of the UP button
    btnDown.tick();   // check the state of the DOWN button
    btnSelect.tick(); // check the state of the SELECT button


    switch (currentState)
    {

    // FMS logic, and OLED drawing 
    case STATE_BOOT_LOGO:
      Serial.println("Display: showing Boot Logo..............");
      vTaskDelay(pdMS_TO_TICKS(2000));  // wqait for 2 sec
      currentState = STATE_DASHBOARD; // changfe the state !
      break;

    case STATE_DASHBOARD:
      Serial.println("Display: Rendaring Dashboard..............");
      // Drawinhg code 

      break;

    case STATE_MENU_LORA:
      Serial.println("Display: Rendaring LoRa Menu..............");
      // Menu Drawinhg code
      break;
    default:
      break;  // five "*****" star do nothing 
    }

  
    // this will delay the task for 50 ms so it doesn't hog the CPU
    vTaskDelay(pdMS_TO_TICKS(50)); // Run at ~20hz
  }
  }


void taskRadioGPS(void *pvParameters) {
    for(;;) {

        // LoRa communication handling (sending and receiving)
        // GPS serial reading and parsing
        vTaskDelay(pdMS_TO_TICKS(10)); // run at 100hz

    }


}

// ------- Button Handlers callbacks functions -----------

void handleClickUp() {
  Serial.println("Acion: UP button clicked");
  // for now , just a test 
  currentState = STATE_DASHBOARD; // when the UP button is clicked, we go to the DASHBOARD
}

void handleClickDown() {
  Serial.println("Acion: DOWN button clicked");
  // for now , just a test (dowm lol )
  currentState = STATE_MENU_LORA; // when the DOWN button is clicked, we go to the LORA MENU
}

void handleClickSelect() {
  Serial.println("Action: SELECT button clicked");
    // for now , just a test (select)
    currentState = STATE_MAP_LOGO;
}