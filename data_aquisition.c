// data_acquisition.c
#include "data_acquisition.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void vDataAcqTask(void *pvParameters) {
    for (;;) {
        sensor_data_t data;
        data.airspeed = Read_ADC(AIRSPEED_CHANNEL);
        data.altitude = Read_UART(ALTITUDE_SENSOR_ID);
        data.temp = Read_ADC(TEMP_SENSOR_CHANNEL);
        xQueueSend(dataQueue, &data, portMAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(20)); // 50Hz
    }
}
