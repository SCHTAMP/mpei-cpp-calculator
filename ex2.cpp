/*
 Написать программу для решения системы линейных алгебраческих уравнений (СЛАУ)
 методом Гаусса
*/
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <limits>

using namespace std;

int main() {
    const int n = 3; //Размерность системы
    float a[n][n + 1], a0[n][n + 1];
    //A - расширенная матрица системы, A0 - ее копия для проверки решения
    int i, j, k;
    float buf, x[n], b[n];
    int input;
    cout << "Матрица и вектор правой части";
    for (i = 0; i < n; i++) {
        cout << endl;
        for (j = 0; j < n + 1; j++) {
            cout << "array[" << i << "," << j << "]=";
            cin >> input;
            while (!std::cin.good())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Неверный ввод! array[" << i << "," << j << "]=";
                cin >> input;
            }
            a[i][j] = a0[i][j];
            //Нулевых элементов нет, деления на ноль не будет
        }
    }
    
    cout << endl << "Матрица:";
    for (i = 0; i < n; i++) {
        cout << endl;
        for (j = 0; j < n + 1; j++) {
            cout << a0[i][j] << " ";
        }
    }
    

    //Прямой ход метода Гаусса
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            buf = a[i][i] / a[j][i];
            for (k = 0; k <= n; k++) a[j][k] = a[j][k] * buf - a[i][k];
        }
    //Обратный ход метода Гаусса
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        buf = 0;
        for (j = i + 1; j < n; j++) buf += a[i][j] * x[j];
        x[i] = (a[i][n] - buf) / a[i][i];
    }

    cout << endl << "Решение" << endl;
    for (i = 0; i < n; i++) cout << x[i] << " ";

    cout << endl << "Проверка" << endl;
    for (i = 0; i < n; i++) {
        b[i] = 0;
        for (j = 0; j < n; j++) b[i] += a0[i][j] * x[j];
        cout << b[i] << " ";
    }
    return 0;
}
