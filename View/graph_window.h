#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QWidget>

#include "Controller/controller.h"

namespace Ui {
class graph_window;
}

class graph_window : public QWidget {
  Q_OBJECT

 public:
  explicit graph_window(QWidget *parent = nullptr);
  ~graph_window();

  void setText(const QString &text);

 signals:
  void firstWindow();

 private slots:

  void on_plotButton_clicked();

 private:
  Ui::graph_window *ui;
  s21::Controller controller;
};

#endif  // GRAPH_WINDOW_H
