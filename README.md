# Домашнее задание к работе 12
## Условие задачи
Разработайте программу, которая записывает в файл поля структуры ДЗ работы 11ут.
## 1. Реализация программы
```
﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int number;
    char dep_point[50];
    int dep_hour;
    int dep_min;
    char arr_point[50];
    int arr_hour;
    int arr_min;
} Train;

int writefile(char* fname, Train* trains, int size)
{
    FILE* out;
    if ((out = fopen(fname, "at")) == NULL)
    {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(out, "Номер:%d ; Отбытие: %s (%02d:%02d) ; Прибытие: %s (%02d:%02d)\n",
            trains[i].number,
            trains[i].dep_point, trains[i].dep_hour, trains[i].dep_min,
            trains[i].arr_point, trains[i].arr_hour, trains[i].arr_min);
    }
    fclose(out);
    return 1;
}

int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251 > nul");

    Train trains[10];
    int n;
    int i;
    int found;
    int target_minutes;
    int dep_total, arr_total, travel_time;

    printf("Введите количество поездов (от 5 до 10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\n===== Ввод данных для поезда №%d =====\n", i + 1);
        printf("Введите номер поезда: ");
        scanf("%d", &trains[i].number);
        printf("Введите пункт отбытия (без пробелов): ");
        scanf("%s", trains[i].dep_point);
        printf("Введите время отбытия (часы и минуты через пробел): ");
        scanf("%d %d", &trains[i].dep_hour, &trains[i].dep_min);
        printf("Введите пункт прибытия (без пробелов): ");
        scanf("%s", trains[i].arr_point);
        printf("Введите время прибытия (часы и минуты через пробел): ");
        scanf("%d %d", &trains[i].arr_hour, &trains[i].arr_min);
    }
    if (writefile("trains.txt", trains, n)) {
        printf("\nДанные успешно записаны в файл trains.txt!\n");
        system("notepad trains.txt");
    }
    printf("\n=============================================================\n");
    printf("ПОЕЗДА, ВРЕМЯ В ПУТИ КОТОРЫХ БОЛЕЕ 7 ЧАСОВ 20 МИНУТ:\n");
    printf("=============================================================\n");
    found = 0;
    target_minutes = 7 * 60 + 20;
    for (i = 0; i < n; i++) {
        dep_total = trains[i].dep_hour * 60 + trains[i].dep_min;
        arr_total = trains[i].arr_hour * 60 + trains[i].arr_min;
        if (arr_total < dep_total) {
            arr_total = arr_total + (24 * 60);
        }
        travel_time = arr_total - dep_total;
        if (travel_time > target_minutes) {
            found = 1;
            printf("Поезд №%d\n", trains[i].number);
            printf("  Маршрут: %s (%02d:%02d) -> %s (%02d:%02d)\n",
                trains[i].dep_point, trains[i].dep_hour, trains[i].dep_min,
                trains[i].arr_point, trains[i].arr_hour, trains[i].arr_min);
            printf("  Время в пути: %d часов %d минут\n", travel_time / 60, travel_time % 60);
            printf("-------------------------------------------------------------\n");
        }
    }
    if (found == 0) {
        printf("Поездов с таким временем в пути не найдено.\n");
    }
    return 0;
}
```
## 2. Результат работы программы
```
Номер:1 ; Отбытие: Липецк (15:02) ; Прибытие: Москва (00:11)
Номер:2 ; Отбытие: Краснодар (03:26) ; Прибытие: Сочи (08:59)
```
## 3. Информация о разработчике
**Холодова Елизавета Юрьевна бИЦТ-262**
