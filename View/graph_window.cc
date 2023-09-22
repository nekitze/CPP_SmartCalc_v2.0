#include "graph_window.h"

#include "ui_graph_window.h"

graph_window::graph_window(QWidget *parent)
    : QWidget(parent), ui(new Ui::graph_window) {
  ui->setupUi(this);
}

graph_window::~graph_window() { delete ui; }

void graph_window::setText(const QString &text) {
  ui->functionText->setText(text);
}

void graph_window::on_plotButton_clicked() {
  ui->widget->addGraph();
  ui->widget->graph(0)->data()->clear();

  controller.PlotGraph(ui->functionText->toPlainText(),
                       ui->dFromText->toPlainText(),
                       ui->dToText->toPlainText());

  ui->widget->graph(0)->addData(controller.GetGraphDataX(),
                                controller.GetGraphDataY());

  ui->widget->xAxis->setRange(ui->eFromText->toPlainText().toDouble(),
                              ui->eToText->toPlainText().toDouble());
  ui->widget->yAxis->setRange(ui->eFromText->toPlainText().toDouble(),
                              ui->eToText->toPlainText().toDouble());

  ui->widget->replot();
}
