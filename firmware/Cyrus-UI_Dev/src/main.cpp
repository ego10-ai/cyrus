// 1.include area ---------=------------------------------

#include <Arduino.h>
#include <hal_pins.h>
#include <UIManager.h>
#include <OneButton.h>


// decleeartioon for the tasks
// 2.GLOBAL VARIABLES
//-----------------------------------------




//3. task declaration

void taskUI(void *pvParameters);

void taskRadioGPS(void *pvParameters);


// 4.SETUP FUNCTION (Runs once on boot)
void setup() {
  Serial.begin(115200);
  delay(2000); 
  


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

    // FMS logic, and OLED drawing 
    case STATE_BOOT_LOGO:
      Serial.println("Display: showing Boot Logo..............");
      vTaskDelay(pdMS_TO_TICKS(2000));  // wqait for 2 sec
      currentState = STATE_DASHBOARD; // changfe the state !
      break;

    vTaskDelay(pdMS_TO_TICKS(50)); // Run at ~20hz
  }
  }

void taskRadioGPS(void *pvParameters) {
    for(;;) {
        // GPS serial reading and parsing
        vTaskDelay(pdMS_TO_TICKS(10)); // run at 100hz

    }
}




