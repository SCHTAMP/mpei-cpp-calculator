#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Calculator {
 public:
  Calculator(const string &infixExpression)
      : infixExpression(infixExpression) {}

  double solve() {
    string postfixExpression;
    postfixExpression = infixToPostfix(infixExpression);


    stack<double> operands;

    for (char c : postfixExpression) {
      if (!isOperator(c)) {
        double operand = c - '0';
        operands.push(operand);
      } else {
        double operand2 = operands.top();
        operands.pop();
        double operand1 = operands.top();
        operands.pop();

        switch (c) {
          case '+':
            operands.push(operand1 + operand2);
            break;
          case '-':
            operands.push(operand1 - operand2);
            break;
          case '*':
            operands.push(operand1 * operand2);
            break;
          case '/':
            operands.push(operand1 / operand2);
            break;
          case '^':
            operands.push(pow(operand1, operand2));
            break;
        }
      }
    }

    return operands.top();
  }

 private:
  string infixExpression;

  string infixToPostfix(const string &infix) {
    string postfix;
    stack<char> operators;

    for (char c : infix) {
      if (!isOperator(c) && c != '(' && c != ')') {
        postfix += c;
      }
      else if (isOperator(c)) {
        while (!operators.empty() && operators.top() != '(' &&
               getPriority(operators.top()) >= getPriority(c)) {
          postfix += operators.top();
          operators.pop();
        }
        operators.push(c);
      }
      else if (c == '(') {
        operators.push(c);
      }
      else if (c == ')') {
        while (!operators.empty() && operators.top() != '(') {
          postfix += operators.top();
          operators.pop();
        }
        operators.pop(); 
      }
    }

    while (!operators.empty()) {
      postfix += operators.top();
      operators.pop();
    }

    return postfix;
  }

  int getPriority(char op) {
    if (op == '^')
      return 3;
    else if (op == '*' || op == '/')
      return 2;
    else if (op == '+' || op == '-')
      return 1;
    else
      return 0; 
  }

  bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
  }
};
