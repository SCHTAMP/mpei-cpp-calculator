#include "lib.cpp"

using namespace std;

int main() {
  string infixExpression;
  cout << "Введите арифметическое выражение в инфиксной форме: ";
  getline(cin, infixExpression);


  Calculator calculator(infixExpression);
  double result = calculator.solve();

  cout << "Результат: " << result << endl;

  return 0;
}
