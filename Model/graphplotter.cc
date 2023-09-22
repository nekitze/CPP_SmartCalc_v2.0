#include "graphplotter.h"

void s21::GraphPlotter::MakeGraphData(QString functionText, QString dFromText,
                                      QString dToText) {
  double xBegin, xEnd, h, X;
  QString functionTextTemp = functionText;

  x.clear();
  y.clear();

  xBegin = dFromText.toDouble();
  xEnd = dToText.toDouble();
  h = 0.01;
  X = xBegin;

  while (X <= xEnd) {
    QString x_convert = "(x)";
    x_convert.replace("x", QString::number(X, 'd'));
    functionTextTemp.replace("x", x_convert);

    calc.InputData(functionTextTemp.toStdString());
    double calculatedValue = calc.Calculate();

    if (!y.empty() && std::abs(calculatedValue - y.back()) > 1e3) {
      y.push_back(NAN);
    } else {
      y.push_back(calculatedValue);
    }

    x.push_back(X);

    functionTextTemp = functionText;
    X += h;
  }
}
