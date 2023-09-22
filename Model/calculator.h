#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <deque>
#include <string>

#define COS '0'
#define SIN '1'
#define TAN '2'
#define ACOS '3'
#define ASIN '4'
#define ATAN '5'
#define SQRT '6'
#define LN '7'
#define LOG '8'

namespace s21 {

/**
 * @brief Структура объекта для польской нотации
 *
 */
typedef struct Calc_Object {
  double value;
  char operation;
  int priority;
} Calc_Object;

/**
 * @brief Объет калькулятора, выполняет
 *
 */
class Calculator {
 public:
  /**
   * @brief Метод для передачи арифметического выражения в калькулятор
   *
   * @param data Арифметическое выражение которое нужно вычислить
   */
  void InputData(std::string data);

  /**
   * @brief Метод который вычисляет входное выражение
   *
   * @return double Результат вычисления
   */
  double Calculate();

 private:
  /**
   * @brief Метод парсинга арифметического выражения
   *
   * @param data арифметическое выражение которое нужно вычислить
   */
  void ParseInputDataToStack(std::string data);

  /**
   * @brief Метод который считывает операнд
   *
   * @param c Первый символ найденного операнда
   * @return Calc_Object
   */
  Calc_Object ParseOperand(std::string::iterator &c);

  /**
   * @brief Метод который считывает операцию
   *
   * @param c Первый символ найденной операции
   * @param begin Первый элемент строки
   * @return Calc_Object
   */
  Calc_Object ParseOperation(std::string::iterator &c,
                             const std::string::iterator &begin);

  /**
   * @brief Метод для вычилсения оператора
   *
   * @param oper Оператор
   * @param left Левый операнд
   * @param right Правый операнд
   * @return Calc_Object
   */
  Calc_Object CalcOperator(Calc_Object oper, Calc_Object left,
                           Calc_Object right);

  /**
   * @brief Метод для вычисления функции
   *
   * @param oper Операция
   * @param object Операнд
   * @return Calc_Object
   */
  Calc_Object CalcFunction(Calc_Object oper, Calc_Object object);

  /**
   * @brief Метод для начальной проверки выражения
   *
   * @param data
   * @return true
   * @return false
   */
  bool IsCorrect(std::string data) noexcept;

  /**
   * @brief Метод для проверки является ли символ оператором
   *
   * @param c Символ
   * @return true
   * @return false
   */
  bool IsOperator(char c) noexcept;

  //! Очередь вычисления
  std::deque<Calc_Object> calc_deque;
};

}  // namespace s21

#endif  // CALCULATOR_H
