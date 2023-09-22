#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Controller/controller.h"
#include "View/credit_window.h"
#include "View/graph_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_symbol_button_clicked();

  void on_pushButton_Calc_clicked();

  void on_pushButton_Delete_clicked();

  void on_pushButton_Clear_clicked();

  void on_pushButton_Graph_clicked();

  void on_pushButton_Credit_clicked();

  void on_pushButton_Deposit_clicked();

  void on_pushButton_Sin_clicked();

  void on_pushButton_Cos_clicked();

  void on_pushButton_Atan_clicked();

  void on_pushButton_Tan_clicked();

  void on_pushButton_Positive_clicked();

  void on_pushButton_Negative_clicked();

  void on_pushButton_Acos_clicked();

  void on_pushButton_Ln_clicked();

  void on_pushButton_Sqrt_clicked();

  void on_pushButton_Asin_clicked();

  void on_pushButton_Log_clicked();

 private:
  Ui::MainWindow *ui;
  graph_window *graphWindow;
  credit_window *creditWindow;
  s21::Controller controller;

  void addTextToField(QString additionalText);
};
#endif  // MAINWINDOW_H
