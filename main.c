#include "temp_functions.h"
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_help();
        return 1;
    }

    const char *filename = NULL;
    int month = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            filename = argv[++i];
        } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            month = atoi(argv[++i]);
            if (month < 1 || month > 12) { // Исправлено условие
                printf("Некорректный месяц. Пожалуйста, укажите месяц от 1 до 12.\n");
                return 1;
            }
        }
    }

    if (!filename) {
        printf("Не указан файл для анализа.\n");
        return 1;
    }

    TemperatureData data[MAX_DATA];
    int count = 0;

    // Проверка на успешное чтение данных
    if (read_data(filename, data, &count) == 0) {
        printf("Всего считано строк: %d\n", count);
        print_statistics(data, count, month);
    } else {
        printf("Ошибка при чтении данных из файла.\n");
        return 1;
    }

    return 0;
}
