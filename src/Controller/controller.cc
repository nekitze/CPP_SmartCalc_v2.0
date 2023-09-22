#include "controller.h"

#include <QMessageBox>

namespace s21 {

QString Controller::GetCalcResult(QString textData) {
  try {
    calc.InputData(textData.toStdString());
    return QString::number(calc.Calculate());
  } catch (const std::exception& e) {
    return e.what();
  }
}

QString Controller::GetFinanceCalcResult(QString amountText, QString rateText,
                                         QString termText, bool isAnnuity) {
  try {
    return QString::fromStdString(fincalc.CalculatePayments(
        amountText.toStdString(), rateText.toStdString(),
        termText.toStdString(), isAnnuity));
  } catch (const std::exception& e) {
    QMessageBox::critical(nullptr, "Error", e.what());
    return nullptr;
  }
}

void Controller::PlotGraph(QString functionText, QString dFromText,
                           QString dToText) {
  try {
    plotter.MakeGraphData(functionText, dFromText, dToText);
  } catch (const std::exception& e) {
    QMessageBox::critical(nullptr, "Error", e.what());
  }
}

QVector<double> Controller::GetGraphDataX() { return plotter.GetXData(); }

QVector<double> Controller::GetGraphDataY() { return plotter.GetYData(); }

}  // namespace s21
