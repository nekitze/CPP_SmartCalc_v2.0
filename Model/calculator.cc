#include "calculator.h"

#include <cmath>
#include <stack>
#include <stdexcept>

namespace s21 {

void Calculator::InputData(std::string data) {
  if (!IsCorrect(data)) throw std::invalid_argument("Invalid input");
  ParseInputDataToStack(data);
}

double Calculator::Calculate() {
  std::stack<Calc_Object> output;
  std::stack<Calc_Object> operators;

  Calc_Object left;
  Calc_Object right;
  Calc_Object single;

  while (!calc_deque.empty()) {
    if (calc_deque.front().priority == 0) {
      output.push(calc_deque.front());
      calc_deque.pop_front();
    } else if (calc_deque.front().priority > 0 &&
               calc_deque.front().priority < 4) {
      if (operators.empty() ||
          (calc_deque.front().priority > operators.top().priority) ||
          operators.top().priority == 4) {
        operators.push(calc_deque.front());
        calc_deque.pop_front();
      } else {
        right = output.top();
        output.pop();
        left = output.top();
        output.pop();
        output.push(CalcOperator(operators.top(), left, right));
        operators.pop();
      }
    } else if (calc_deque.front().priority == 4) {
      if (calc_deque.front().operation == ')') {
        while (operators.top().priority != 4) {
          right = output.top();
          output.pop();
          left = output.top();
          output.pop();
          output.push(CalcOperator(operators.top(), left, right));
          operators.pop();
        }

        single = output.top();
        output.pop();
        output.push(CalcFunction(operators.top(), single));
        operators.pop();
        calc_deque.pop_front();

      } else if (calc_deque.front().operation == '~') {
        single = calc_deque.front();
        calc_deque.pop_front();
        if (calc_deque.front().operation == '(') {
          operators.push(single);
        } else {
          single = calc_deque.front();
          single.value = -single.value;
          calc_deque.pop_front();
          calc_deque.push_front(single);
        }
      } else {
        operators.push(calc_deque.front());
        calc_deque.pop_front();
      }
    }
  }

  while (!operators.empty()) {
    if (operators.top().priority != 4 && output.size() >= 2) {
      right = output.top();
      output.pop();
      left = output.top();
      output.pop();
      output.push(CalcOperator(operators.top(), left, right));
      operators.pop();
    } else if (operators.top().priority == 4 && output.size() >= 1) {
      single = output.top();
      output.pop();
      output.push(CalcFunction(operators.top(), single));
      operators.pop();
    } else {
      throw std::invalid_argument("Invalid input");
    }
  }

  if (output.empty())
    return 0;
  else
    return output.top().value;
}

Calc_Object Calculator::CalcOperator(Calc_Object oper, Calc_Object left,
                                     Calc_Object right) {
  Calc_Object result;
  result.operation = '\0';
  result.priority = 0;

  if (oper.operation == '+') {
    result.value = left.value + right.value;
  } else if (oper.operation == '-') {
    result.value = left.value - right.value;
  } else if (oper.operation == '*') {
    result.value = left.value * right.value;
  } else if (oper.operation == '/') {
    result.value = left.value / right.value;
  } else if (oper.operation == '%') {
    result.value = fmod(left.value, right.value);
  } else if (oper.operation == '^') {
    result.value = pow(left.value, right.value);
  }

  return result;
}

Calc_Object Calculator::CalcFunction(Calc_Object oper, Calc_Object object) {
  Calc_Object result;
  result.operation = '\0';
  result.priority = 0;

  if (oper.operation == '(') {
    result.value = object.value;
  } else if (oper.operation == '~') {
    result.value = -object.value;
  } else if (oper.operation == COS) {
    result.value = cos(object.value);
  } else if (oper.operation == SIN) {
    result.value = sin(object.value);
  } else if (oper.operation == TAN) {
    result.value = tan(object.value);
  } else if (oper.operation == ACOS) {
    result.value = acos(object.value);
  } else if (oper.operation == ASIN) {
    result.value = asin(object.value);
  } else if (oper.operation == ATAN) {
    result.value = atan(object.value);
  } else if (oper.operation == SQRT) {
    result.value = sqrt(object.value);
  } else if (oper.operation == LN) {
    result.value = log(object.value);
  } else if (oper.operation == LOG) {
    result.value = log10(object.value);
  }

  return result;
}

void Calculator::ParseInputDataToStack(std::string data) {
  std::string::iterator c = data.begin();
  const std::string::iterator end = data.end();

  while (c != end) {
    if (*c != ' ') {
      if ((*c >= '0') && (*c <= '9')) {
        calc_deque.push_back(ParseOperand(c));
      } else {
        calc_deque.push_back(ParseOperation(c, data.begin()));
        c++;
      }
    } else
      c++;
  }
}

Calc_Object Calculator::ParseOperand(std::string::iterator& c) {
  Calc_Object operand;
  std::string operandStr;

  while ((*c >= '0' && *c <= '9') || *c == '.' || *c == 'e') {
    if (*c == 'e') {
      operandStr += *c;
      ++c;
      if (*c == '-' || *c == '+') {
        operandStr += *c;
        ++c;
      }
    }
    operandStr += *c;
    ++c;
  }

  operand.operation = '\0';
  operand.priority = 0;
  operand.value = std::stod(operandStr);

  return operand;
}

Calc_Object Calculator::ParseOperation(std::string::iterator& c,
                                       const std::string::iterator& begin) {
  Calc_Object operation;
  operation.operation = '\0';
  operation.priority = 0;
  operation.value = 0;

  if (*c == '+') {
    if (c > begin) {
      if (*(--c) == '(') {
        ++c;
      } else {
        ++c;
        operation.operation = '+';
        operation.priority = 1;
      }
    } else if (c == begin) {
      operation.operation = 'M';
    }
  } else if (*c == '-') {
    if (c > begin) {
      if (*(--c) == '(') {
        ++c;
        operation.operation = '~';
        operation.priority = 4;
      } else {
        ++c;
        operation.operation = '-';
        operation.priority = 1;
      }
    } else {
      operation.operation = '~';
      operation.priority = 4;
    }
  } else if (*c == '*') {
    operation.operation = '*';
    operation.priority = 2;
  } else if (*c == '/') {
    operation.operation = '/';
    operation.priority = 2;
  } else if (*c == 'm') {
    if (*(++c) == 'o' && *(++c) == 'd') {
      operation.operation = '%';
      operation.priority = 2;
    }
  } else if (*c == '^') {
    operation.operation = '^';
    operation.priority = 3;
  } else if (*c == 'c') {
    if (*(++c) == 'o' && *(++c) == 's' && *(++c) == '(') {
      operation.operation = COS;
      operation.priority = 4;
    }
  } else if (*c == 's') {
    if (*(++c) == 'i' && *(++c) == 'n' && *(++c) == '(') {
      operation.operation = SIN;
      operation.priority = 4;
    } else if (*c == 'q' && *(++c) == 'r' && *(++c) == 't' && *(++c) == '(') {
      operation.operation = SQRT;
      operation.priority = 4;
    }
  } else if (*c == 't') {
    if (*(++c) == 'a' && *(++c) == 'n' && *(++c) == '(') {
      operation.operation = TAN;
      operation.priority = 4;
    }
  } else if (*c == 'a') {
    if (*(++c) == 'c' && *(++c) == 'o' && *(++c) == 's' && *(++c) == '(') {
      operation.operation = ACOS;
      operation.priority = 4;
    } else if (*c == 's' && *(++c) == 'i' && *(++c) == 'n' && *(++c) == '(') {
      operation.operation = ASIN;
      operation.priority = 4;
    } else if (*c == 't' && *(++c) == 'a' && *(++c) == 'n' && *(++c) == '(') {
      operation.operation = ATAN;
      operation.priority = 4;
    }
  } else if (*c == 'l') {
    if (*(++c) == 'n' && *(++c) == '(') {
      operation.operation = LN;
      operation.priority = 4;
    } else if (*c == 'o' && *(++c) == 'g' && *(++c) == '(') {
      operation.operation = LOG;
      operation.priority = 4;
    }
  } else if (*c == '(') {
    operation.operation = '(';
    operation.priority = 4;
  } else if (*c == ')') {
    operation.operation = ')';
    operation.priority = 4;
  } else {
    throw std::invalid_argument("Invalid input");
  }

  return operation;
}

bool Calculator::IsCorrect(std::string data) noexcept {
  bool isLastOperator = false;
  int brackets_count = 0;

  for (const char& c : data) {
    if (isLastOperator && IsOperator(c)) return false;
    isLastOperator = IsOperator(c);
    if (c == '(') brackets_count++;
    if (c == ')') brackets_count--;
  }

  return brackets_count == 0;
}

bool Calculator::IsOperator(char c) noexcept {
  std::string str = {"+-/*.^%"};
  return str.find(c) != std::string::npos;
}

}  // namespace s21
