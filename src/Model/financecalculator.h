#ifndef FINANCECALCULATOR_H
#define FINANCECALCULATOR_H

#include <string>

#include "calculator.h"

namespace s21 {

/**
 * @brief Объект который выполняет вычисления для финансовых расчетов
 *
 */
class FinanceCalculator {
 public:
  /**
   * @brief Метод вычисляющий платежи
   *
   * @param amountText Сумма кредита
   * @param rateText Процентная ставка
   * @param termText Срок кредита в месяцах
   * @param isAnnuity Является ли кредит аннуитентным (если false, значит
   * дифференцированный)
   * @return std::string
   */
  std::string CalculatePayments(std::string amountText, std::string rateText,
                                std::string termText, bool isAnnuity);

 private:
  //! Объект калькулятора для вычислений
  Calculator calc;
};

}  // namespace s21

#endif  // FINANCECALCULATOR_H
