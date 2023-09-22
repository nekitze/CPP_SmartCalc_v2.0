#ifndef GRAPHPLOTTER_H
#define GRAPHPLOTTER_H

#include <QString>
#include <QVector>

#include "Model/calculator.h"

namespace s21 {

/**
 * @brief Объект который создает необходимые данные для построения графика
 *
 */
class GraphPlotter {
 public:
  /**
   * @brief Метод для вычисления данныз для построения графика
   *
   * @param functionText Исходная функция для построения
   * @param dFromText Начало области
   * @param dToText Конец области
   */
  void MakeGraphData(QString functionText, QString dFromText, QString dToText);

  /**
   * @brief Метод для получения данных по оси X
   *
   * @return QVector<double>
   */
  QVector<double> GetXData() noexcept { return x; }

  /**
   * @brief Метод для получения данных по оси Y
   *
   * @return QVector<double>
   */
  QVector<double> GetYData() noexcept { return y; }

 private:
  /**
   * @brief Вектор точек x и y
   *
   */
  QVector<double> x, y;

  /**
   * @brief Обект для вычислений
   *
   */
  s21::Calculator calc;
};

}  // namespace s21

#endif  // GRAPHPLOTTER_H
