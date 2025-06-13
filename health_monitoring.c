// health_monitoring.c
#include "health_monitoring.h"
#include "FreeRTOS.h"
#include "queue.h"

void vHealthMonTask(void *pvParameters) {
    sensor_data_t data;
    for (;;) {
        if (xQueueReceive(dataQueue, &data, portMAX_DELAY)) {
            if (data.airspeed < 200 || data.airspeed > 350)
                Raise_Fault("Airspeed out of range");
            if (data.altitude < 1000 || data.altitude > 41000)
                Raise_Fault("Altitude out of range");
            if (data.temp > 80)
                Raise_Warning("Temperature high");
        }
    }
}
