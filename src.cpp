/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<cmath>

using namespace std;
#define degree(x) (x*M_PI)


void print_menu() {
    system("clear");
    printf("Выберете нужный пункт:\n");
    printf("1. Базовые арифметические вычисления.\n");
    printf("2. Тригонометрические вычисления.\n");
    printf("3. Побитовые вычисления.\n");
    printf("4. Вычисление степени числа.\n");
    printf("5. Вычисление факториала.\n");
    printf("6. Вычисление натурального логарифма числа.\n");
    printf("7. Вычисление НОД и НОК двух чисел\n");
    printf("8. Перевод числа из одной системы исчисления в другую.\n");
    printf("9. Вычисление площади натурального n-угольника.\n");
    printf("10. Нахождение корней квадратного уравнения по заданым коофицентам.\n");
    printf("0. Выход\n");
    printf(">");
}

int get_input(int count=3) {
    int variant;
    char s[100];
    scanf("%s", s);
    
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Неккоректный ввод. Попробуйте снова.\n");
        scanf("%s", s);
    };
    
    return variant;
}

void basic_ariphmetic_operations() {
    char op;
    float num1, num2;
    printf("Введите один из операторов +, -, *, /\n");
    cin >> op;
    printf("Введите два числа через пробел:\n");
    cin >> num1 >> num2;
    
    switch (op) {
        case '+':
            cout << num1 + num2 << '\n';
            break;
        case '-':
            cout << num1 - num2 << '\n';
            break;
        case '*':
            cout << num1 * num2 << '\n';
            break;
        case '/':
            cout << num1 / num2 << '\n';
            break;
        default:
            printf("Ошибка. Оператор не найден.");
    }
}

void tregonometric_operations() { // TODO
    char op[20], num[20];
    
    printf("Выберете одну из тригонометрических функций sin, cos, tg, ctg, asin, acos, atg, actg, а после через ПРОБЕЛ введите число в градусах.\n");
    cin >> op >> num;
    
    cout << "TEST \n" << op << " " << num << " ";
};

void bit_operations() {};

void number_power() {
    float number, power;
    printf("Введите 2 числа. Первое число - число для возведения в степень. Второе - степень. Вводить через пробел.\n");
    cin >> number >> power;
    cout << pow(number, power) << "\n";
}

int main()
{
    int variant;
    
    do {
        print_menu();
        
        variant = get_input(10);
        
        switch (variant) {
            case 1:
                basic_ariphmetic_operations();
                break;
            case 2:
                tregonometric_operations();
                break;
            case 3:
                printf("3 punkt\n");
                break;
            case 4:
                number_power();
                break;
        }
        
        if (variant != 0) system("read -p 'Press Enter to continue...' var");
    } while (variant != 0);

    return 0;
}
