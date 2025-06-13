// data_acquisition.h
#ifndef DATA_ACQUISITION_H
#define DATA_ACQUISITION_H

typedef struct {
    int airspeed;
    int altitude;
    int temp;
} sensor_data_t;

extern QueueHandle_t dataQueue;

int Read_ADC(int channel);
int Read_UART(int sensor_id);

#endif
