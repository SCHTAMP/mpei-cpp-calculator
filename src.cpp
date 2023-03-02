/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <map>

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

int convert_to_dec(long long n) {
  int dec = 0, i = 0, rem;

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
    
    cout << "TEST " << op << " " << num << "\n";
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

void number_operations() {
    long long n;
    char type;
   
    printf("Введите один из операторов \"b\" для перевода в двоичную систему и \"d\" для перевода в десятичную\n");
    cin >> type;
    printf("Введите число для перевода:\n");
    cin >> n;
    switch (type) {
        case 'd':
            cout << "Число " << n << " в десятичном представлении " << convert_to_dec(n) << endl ;
            break;
        case 'b':
            cout << "Число " << n << " в двичном представлении " << convert_to_bin(n) << endl ;
            break;
    }
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
    if (n < 3 or side < 0) {
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
        }
        
        if (variant != 0) system("read -p 'Press Enter to continue...' var");
    } while (variant != 0);

    return 0;
}
