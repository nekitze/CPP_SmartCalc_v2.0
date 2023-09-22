#include "credit_window.h"

#include <QTextStream>

#include "ui_credit_window.h"

credit_window::credit_window(QWidget *parent)
    : QWidget(parent), ui(new Ui::credit_window) {
  ui->setupUi(this);
}

credit_window::~credit_window() { delete ui; }

void credit_window::on_pushButton_clicked() {
  ui->outputText->setText(controller.GetFinanceCalcResult(
      ui->amountLine->text(), ui->rateLine->text(), ui->termLine->text(),
      ui->annuityRadio->isChecked()));
}
