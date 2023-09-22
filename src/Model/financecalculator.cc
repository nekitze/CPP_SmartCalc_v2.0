#include "financecalculator.h"

std::string s21::FinanceCalculator::CalculatePayments(std::string amountText,
                                                      std::string rateText,
                                                      std::string termText,
                                                      bool isAnnuity) {
  std::string output;

  if (isAnnuity) {
    std::string resultText = amountText + "*" + rateText + "/100/12" +
                             "/(1-(1+" + rateText + "/100/12)^(-" + termText +
                             "))";

    calc.InputData(resultText);
    resultText = std::to_string(calc.Calculate());

    for (int i = 0; i < std::stoi(termText); i++) {
      output = output + "Month " + std::to_string(i + 1) +
               " payment: " + resultText + "\n";
    }

  } else {
    std::string monthlyPayment;
    std::string monthlyPayMain = amountText + "/" + termText;

    calc.InputData(monthlyPayMain);
    monthlyPayMain = std::to_string(calc.Calculate());

    for (int i = 0; i < std::stoi(termText); i++) {
      monthlyPayment = monthlyPayMain + "+(" + amountText + "-" +
                       monthlyPayMain + "*" + std::to_string(i) + ")*" +
                       rateText + "/100*29.3/365";
      calc.InputData(monthlyPayment);
      output = output + "Month " + std::to_string(i + 1) +
               " payment: " + std::to_string(calc.Calculate()) + "\n";
    }
  }

  return output;
}
