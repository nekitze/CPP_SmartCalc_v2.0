#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>

#include "Model/calculator.h"
#include "Model/financecalculator.h"
#include "Model/graphplotter.h"

namespace s21 {

class Controller {
 public:
  QString GetCalcResult(QString textData);
  QString GetFinanceCalcResult(QString amountText, QString rateText,
                               QString termText, bool isAnnuity);
  void PlotGraph(QString functionText, QString dFromText, QString dToText);
  QVector<double> GetGraphDataX();
  QVector<double> GetGraphDataY();

 private:
  s21::Calculator calc;
  s21::GraphPlotter plotter;
  s21::FinanceCalculator fincalc;
};
}  // namespace s21

#endif  // CONTROLLER_H
