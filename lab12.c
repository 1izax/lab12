#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int task1()
{
    setlocale(LC_ALL, "RUS");
    char fname[20] = "number.txt";
    FILE* out;
    puts("Создание файла");
    if ((out = fopen(fname, "at")) == NULL)
    {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    fprintf(out, "%d", 5);
    fprintf(out, "%d\n", 12.56);
    fclose(out);

    return 1;
}

double calc_y(double x) {
    return 2.0 * x * x * x - x + 1.0;
}

int task2(void) {
    int n;
    int choice;
    double x, y;
    double start = -1.0;
    double end = 1.0;
    double step;
    FILE* file;
    printf("=== ТАБУЛИРОВАНИЕ ФУНКЦИИ ===\n");
    printf("Функция: y = 2x^3 - x + 1 на интервале [-1; 1]\n");
    printf("Введите количество точек табулирования: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Ошибка: количество точек должно быть больше нуля.\n");
        return 0;
    }
    printf("\nВыберите действие:\n");
    printf("1) Записать в новый файл (стереть старые данные)\n");
    printf("2) Дозаписать в существующий файл\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    if (choice == 1) {
        file = fopen("temp.txt", "w");
    }
    else if (choice == 2) {
        file = fopen("temp.txt", "a");
    }
    else {
        printf("Неверный выбор. Программа завершена.\n");
        return 0;
    }
    if (file == NULL) {
        printf("Файл не открылся!\n");
        return 0;
    }
    fprintf(file, "x\t\ty\n");
    if (n > 1) {
        step = (end - start) / (n - 1);
    }
    else {
        step = 0;
    }
    x = start;
    for (int i = 0; i < n; i++)
    {
        y = 2.0 * x * x * x - x + 1.0;
        fprintf(file, "%.2f\t\t%.4f\n", x, y);
        x = x + step;
    }

    fclose(file);
    printf("\nГотово! Результат записан в temp.txt\n\n");

    return 1;
}

int main(void)
{
    setlocale(LC_ALL, "RUS");

    task2();

    system("pause");
    return 0;
}