#include <stdio.h>
#include <locale.h>
#include <math.h>

void task1(void);
void task2(void);
void task3(void);
void task4(void);

int main() {
    setlocale(LC_ALL, "RUS");

    task1();
    task2();
    task3();
    task4();

    return 0;
}

// Задание 1: проверка года на високосность
void task1(void) {
    int year;

    printf("Введите год: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("год %d високосный\n", year);
    else
        printf("год %d не високосный\n", year);
}

// Задание 2: вычисление F(x) по варианту
void task2(void) {
    double x;
    double F;

    printf("Введите x:\n");
    scanf("%lf", &x);

    if (x > 2) {
        // Контрольный пример: x = 3  ->  (27+18+4)/(9+4) = 49/13 ≈ 3.769231
        F = (x * x * x + 2 * x * x + 4) / (x * x + 4);
    } else {
        // Для x <= 2 (замените формулу, если нужно)
        F = (x * x + 2 * x + 1) / (x + 2);
    }

    printf("F(%.2f) = %f\n", x, F);
}

// Задание 3: проверка, является ли четырёхзначное число перевёртышем
void task3(void) {
    int num;
    int original;
    int reversed = 0;

    printf("Введите четырёхзначное число: ");
    scanf("%d", &num);

    if (num < 1000 || num > 9999) {
        printf("Ошибка: число должно быть четырёхзначным.\n");
        return;
    }

    original = num;
    // Цикл for вместо while
    for (int n = num; n > 0; n /= 10) {
        reversed = reversed * 10 + n % 10;
    }

    if (original == reversed)
        printf("Число %d является перевёртышем.\n", num);
    else
        printf("Число %d не является перевёртышем.\n", num);
}

int isInArea(double x, double y);

//дз
void task4(void) {
    double x, y;
    int repeat;

    setlocale(LC_ALL, "RUS");

    do
    {
        printf("Введите координаты точки (x y): ");
        if (scanf("%lf %lf", &x, &y) != 2)
        {
            printf("Ошибка ввода координат.\n");
        }

        if ((x, y) == 1)
            printf("Точка (%.2f, %.2f) ПРИНАДЛЕЖИТ области\n", x, y);
        else
            printf("Точка (%.2f, %.2f) НЕ ПРИНАДЛЕЖИТ области\n", x, y);

        printf("Проверить ещё одну точку? (1 - да, 0 - нет): ");
        scanf("%d", &repeat);
        printf("\n");
    }
    while (repeat == 1);
}