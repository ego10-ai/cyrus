#include <Arduino.h>
#include <hal_pins.h>
#include <UIManager.h>


// decleeartioon for the tasks

void taskUI(void *pvParameters);

void taskRadioGPS(void *pvParameters);

void setup() {
  Serial.begin(115200);
  

  // UI task and sensor Task on core 1
  xTaskCreatePinnedToCore(
    taskUI,          // Task function
    "Task_UI",       // Name of the task 
    8192,
    NULL,
    1,
    NULL,
    1

    );

    xTaskCreatePinnedToCore(
    taskRadioGPS,
    "Task_RadioGPS",

    8192,
    NULL,
    2,
    NULL,
    0
    );
}

void loop() {
  // free Rtos is handling the task scheduling
  vTaskDelete(NULL);
}

// --- task Implementiation ---

void taskUI(void *pvParameters) {
  for(;;) {
    // FMS logic, and OLED drawing will go here
    vTaskDelay(pdMS_TO_TICKS(50)); // Run at ~20hz
  }
  }

void taskRadioGPS(void *pvParameters) {
    for(;;) {
        // GPS serial reading and parsing
        vTaskDelay(pdMS_TO_TICKS(10)); // run at 100hz

    }
}




