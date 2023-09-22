#ifndef CREDIT_WINDOW_H
#define CREDIT_WINDOW_H

#include <QWidget>

#include "Controller/controller.h"

namespace Ui {
class credit_window;
}

class credit_window : public QWidget {
  Q_OBJECT

 public:
  explicit credit_window(QWidget *parent = nullptr);
  ~credit_window();

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::credit_window *ui;
  s21::Controller controller;
};

#endif  // CREDIT_WINDOW_H
