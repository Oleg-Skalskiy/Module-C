#include "temp_functions.h"

int read_data(const char *filename, TemperatureData data[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return -1;
    }

    char line[1000000];
    *count = 0;
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        if (*count >= MAX_DATA) {
          printf("Достигнуто максимальное количество строк: %d\n", MAX_DATA);
          break;
        }

        // Используем sscanf для безопасного считывания данных
        if (sscanf(line, "%d;%d;%d;%d;%d;%f", 
                   &data[*count].year, 
                   &data[*count].month, 
                   &data[*count].day, 
                   &data[*count].hour, 
                   &data[*count].minute, 
                   &data[*count].temperature) != 6) {
            printf("Некорректная строка %d: %s", line_number, line);
            continue; // Пропускаем некорректные строки
        }

        (*count)++;
    }

    fclose(file);
    return 0;
}

void print_statistics(TemperatureData data[], int count, int month) {
    float total_temp = 0;
    int total_count = 0;

    for (int i = 0; i < count; i++) {
        if (month == 0 || data[i].month == month) {
            total_temp += data[i].temperature;
            total_count++;
        }
    }

    if (total_count > 0) {
        printf("Средняя температура: %.2f\n", total_temp / total_count);
    } else {
        printf("Нет данных для указанного месяца.\n");
    }
}

void print_help() {
    printf("Использование:\n");
    printf("  -h        Показать справку\n");
    printf("  -f FILE   Указать файл для анализа\n");
    printf("  -m MONTH  Указать месяц для анализа (1-12)\n");
}
