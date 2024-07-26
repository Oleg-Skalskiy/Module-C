#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 100000 // Максимальное количество строк

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    float temperature;
} TemperatureData;

int read_data(const char *filename, TemperatureData data[], int *count);
void print_statistics(TemperatureData data[], int count, int month);
void print_help();

#endif // TEMP_FUNCTIONS_H
