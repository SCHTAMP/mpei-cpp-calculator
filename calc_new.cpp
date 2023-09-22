#define _USE_MATH_DEFINES

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <map>
#include <string>
#include <random>
#include <limits>

#include<windows.h>

using namespace std;
#define degree(x) (x*M_PI)

void clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}
map<string, double> memory;

double evaluateConstant(const string& constant) {
    map<string, double> constants;
    constants["pi"] = M_PI;
    constants["e"] = M_E;

    // Попытка найти константу в карте
    auto it = constants.find(constant);
    if (it != constants.end()) {
        return it->second;
    }

    return std::stod(constant);
}

void print_menu() {
    clear();
    printf("MEMORY. M1 = %f; M2 = %f; M3 = %f; M4 = %f\n", memory["M1"], memory["M2"], memory["M3"], memory["M4"]);
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
    printf("11. Генерация псевдослучайного числа в заданом диапазоне.\n");
    printf("12. Сохранение введеных значений в ячейку памяти.\n");
    printf("0. Выход\n");
    printf(">");
}
// ================= HELPER FUNCTIONS ===================
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

unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;

    if (a > b)
        return greatest_common_divisor(a%b, b);
    return greatest_common_divisor(a, b%a);
}

unsigned int least_common_multiple(unsigned int a, unsigned int b) {
    return (a*b)/greatest_common_divisor(a,b);
}

float convert_to_dec(long long n) {
    float dec = 0, i = 0, rem;

    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return dec;
}

long long convert_to_bin(int n) {
    long long bin = 0;
    int rem, i = 1;

    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

// ========== Logic Functions ============
void basic_ariphmetic_operations() {
    char op;
    string num1, num2;
    string input;
    printf("Введите один из операторов +, -, *, /\n");
    cin >> op;
    printf("Введите два числа через пробел:\n");
    cin >> num1 >> num2;

    auto parsedNum1 = evaluateConstant(num1);
    auto parsedNum2 = evaluateConstant(num2);

    switch (op) {
        case '+':
            cout << parsedNum1 + parsedNum2 << '\n';
            break;
        case '-':
            cout << parsedNum1 - parsedNum2 << '\n';
            break;
        case '*':
            cout << parsedNum1 * parsedNum2 << '\n';
            break;
        case '/':
            cout << parsedNum1 / parsedNum2 << '\n';
            break;
        default:
            printf("Ошибка. Оператор не найден.");
    }
}

void tregonometric_operations() { // TODO
    string op;
    float num;

    printf("Выберете одну из тригонометрических функций sin, cos, tg, ctg, а после через ПРОБЕЛ введите число в градусах.\n");
    cin >> op;
    cin >> num;

    std::map <std::string, int> mapping;

    mapping["sin"]  = 1;
    mapping["cos"]    = 2;
    mapping["tg"] = 3;
    mapping["ctg"]  = 4;

    switch (mapping[op]) {
        case 1:
            cout << "Синус " << num << " градусов равен " << std::sin(num) << endl;
            break;
        case 2:
            cout << "Косинус " << num << " градусов равен " << std::cos(num) << endl;
            break;
        case 3:
            cout << "Тангенс " << num << " градусов равен " << std::tan(num) << endl;
            break;
        case 4:
            cout << "Котангенс " << num << " градусов равен " << 1/std::tan(num) << endl;
            break;
        default:
            printf("Ошибка. Оператор не найден.");
            break;
    }

    cout << "DEBUG:  " << op << " " << num << "\n";
};

void bit_operations() {
    char op;
    int num1, num2;
    printf("Введите один из операторов +, -\n");
    cin >> op;
    printf("Введите два числа через пробел:\n");
    cin >> num1 >> num2;

    switch (op) {
        case '+':
            cout << (num1 & num2) << '\n';
            break;
        case '-':
            cout << (num1 | num2) << '\n';
            break;
        default:
            printf("Ошибка. Оператор не найден.");
    }
};

void factorial_operations() {
    int n;
    long factorial = 1.0;

    cout << "Введите положительное число для вычисления факториала: ";
    cin >> n;

    if (n < 0)
        cout << "Ошибка! Факториал для отрицательных чисел не работает";
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        cout << "Факториал числа " << n << " равен " << factorial << "\n";
    }
};

void nlogarithm_operations() {
    float n;
    cout << "Введите число для вычисления натурального логарифма: ";
    cin >> n;
    cout << "Натуральный логарифм " << n << " равен " << std::log(n) << "\n";
};

void nod_nok_operations() {
    int a, b;
    cout << "Введите 2 числа через пробел для вычисления НОД и НОК: ";
    cin >> a >> b;
    cout << "Для чисел " << a << " и " << b << " НОД равен " << greatest_common_divisor(a, b) << ", а НОК равен " << least_common_multiple(a, b) << "\n";
};

string convertNumber(const string& number, int fromBase, int toBase) {
    // Проверка на допустимость систем исчисления (от 2 до 36)
    if (fromBase < 2 || fromBase > 36 || toBase < 2 || toBase > 36) {
        return "Недопустимая система исчисления";
    }

    // Перевод из исходной системы в десятичную
    int decimalValue = 0;
    int power = 0;
    for (int i = number.size() - 1; i >= 0; i--) {
        int digit;
        if (isdigit(number[i])) {
            digit = number[i] - '0';
        } else {
            digit = toupper(number[i]) - 'A' + 10;
        }
        if (digit >= fromBase) {
            return "Недопустимая цифра для данной системы";
        }
        decimalValue += digit * pow(fromBase, power);
        power++;
    }

    // Перевод из десятичной системы в целевую систему
    string result;
    while (decimalValue > 0) {
        int remainder = decimalValue % toBase;
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'A' + remainder - 10;
        }
        result = digit + result;
        decimalValue /= toBase;
    }

    return result;
}

void number_operations() {
    string input;

    cout << "Введите число: ";
    cin >> input;

    cout << "Введите систему исчисления числа (от 2 до 36): ";
    int fromBase;
    cin >> fromBase;

    cout << "Введите целевую систему исчисления (от 2 до 36): ";
    int toBase;
    cin >> toBase;

    string converted = convertNumber(input, fromBase, toBase);
    cout << "Результат: " << converted << endl;
};

void number_power() {
    float number, power;
    printf("Введите 2 числа. Первое число - число для возведения в степень. Второе - степень. Вводить через пробел.\n");
    cin >> number >> power;
    cout << pow(number, power) << "\n";
}

double Snugolnika(int n, double side) {
    return (n * side * side) / (4 * tan(M_PI / n));
}


void polygon_operation() {
    int n;
    double side;

    printf("Введите 2 числа. Первое число - количество сторон. Второе - длина стороны. Вводить через пробел.\n");
    cin >> n >> side;
    if ((n < 3) || (side < 0)) {
        cout << "Ошибка! Кол-во сторон не может быть меньше 3, а длина стороны меньше 0." << endl;
        return;
    }
    cout << "Площадь правильного n-угольника с " << n << " сторон и длинной стороны " << side << " равна " << (n * side * side) / (4 * tan(M_PI / n)) << " " << Snugolnika(n, side) << endl;
}

void uravnenie_operation() {
    double a;
    double b;
    double c;
    double x;

    printf("Решение уравнения вида ax^2 + bx + c = 0, где а != 0. Введите числа а, b, c через пробел.\n");
    cin >> a >> b >> c;
    if (a == 0) {
        printf("Ошибка! Коофицент A не может быть равен 0.\n");
        return;
    };
    if((b*b - 4*a*c) >= 0) //Если дискриминант больше или равен 0
    {
        x = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << "Первый корень равен " << x << endl;
        x = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << "Второй корень равен " << x << endl;
    } else {
        cout << "Дискриминант меньше 0, корни невещественные." << endl;
        return;
    }
    return;
};

void pseudo_random() {
    int start;
    int end;

    printf("Введите 2 числа. Первое число - начало диапазона. Второе - конец диапазона. Вводить через пробел.\n");
    cin >> start >> end;

    random_device random_device;
    mt19937 generator(random_device());

    uniform_int_distribution<> distribution(start, end);

    int x = distribution(generator);
    cout << "Итоговое случайное число в диапазоне от " << start << " до " << end << " = " << x << endl;
};

bool isValidMemoryCell(string cell) {
    return (cell == "M1" || cell == "M2" || cell == "M3" || cell == "M4");
}

void memory_manage() {
    string cell;
    double input;
    printf("Введите Название ячейки памяти (M1, M2, M3, M4).\n");
    cin >> cell;
    if (!isValidMemoryCell(cell)) {
        return;
    }
    printf("Введите числовое значение, которое нужно записать в ячейку:\n");
    cin >> input;

    memory[cell] = input;

    auto data = memory[cell];
    cout << "DATA for cell " << cell << " = " << data << endl;
};

int main()
{

    SetConsoleOutputCP(CP_UTF8);
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);

    map<string, double> constants;
    constants["pi"] = M_PI;
    constants["e"] = M_E;

    int variant;

    do {
        print_menu();

        variant = get_input(12);

        switch (variant) {
            case 1:
                basic_ariphmetic_operations();
                break;
            case 2:
                tregonometric_operations();
                break;
            case 3:
                bit_operations();
                break;
            case 4:
                number_power();
                break;
            case 5:
                factorial_operations();
                break;
            case 6:
                nlogarithm_operations();
                break;
            case 7:
                nod_nok_operations();
                break;
            case 8:
                number_operations();
                break;
            case 9:
                polygon_operation();
                break;
            case 10:
                uravnenie_operation();
                break;
            case 11:
                pseudo_random();
                break;
            case 12:
                memory_manage();
                break;
        }

        if (variant != 0) {
            system("pause");
        }
        //system("read -p 'Press Enter to continue...' var");
    } while (variant != 0);

    return 0;
}
