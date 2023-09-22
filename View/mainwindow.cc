#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  graphWindow = new graph_window();
  connect(graphWindow, &graph_window::firstWindow, this, &MainWindow::show);

  connect(ui->pushButton_1, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_4, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_5, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_6, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_7, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_8, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_9, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_0, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_Dot, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);

  connect(ui->pushButton_Plus, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_Minus, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_Mult, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_Divide, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_Pow, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_Mod, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_X, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_LeftBracket, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);
  connect(ui->pushButton_RightBracket, &QPushButton::clicked, this,
          &MainWindow::on_symbol_button_clicked);

  creditWindow = new credit_window();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_Calc_clicked() {
  QString textData = ui->textEdit->toPlainText();
  ui->textEdit->setText(controller.GetCalcResult(textData));
}

void MainWindow::on_symbol_button_clicked() {
  QPushButton *button = (QPushButton *)sender();
  ui->textEdit->setText(ui->textEdit->toPlainText() + button->text());
}

void MainWindow::on_pushButton_Positive_clicked() { addTextToField("(+"); }

void MainWindow::on_pushButton_Negative_clicked() { addTextToField("(-"); }

void MainWindow::on_pushButton_Sin_clicked() { addTextToField("sin("); }

void MainWindow::on_pushButton_Cos_clicked() { addTextToField("cos("); }

void MainWindow::on_pushButton_Tan_clicked() { addTextToField("tan("); }

void MainWindow::on_pushButton_Acos_clicked() { addTextToField("acos("); }

void MainWindow::on_pushButton_Asin_clicked() { addTextToField("asin("); }

void MainWindow::on_pushButton_Atan_clicked() { addTextToField("atan("); }

void MainWindow::on_pushButton_Sqrt_clicked() { addTextToField("sqrt("); }

void MainWindow::on_pushButton_Ln_clicked() { addTextToField("ln("); }

void MainWindow::on_pushButton_Log_clicked() { addTextToField("log("); }

void MainWindow::addTextToField(QString additionalText) {
  QString currentText = ui->textEdit->toPlainText();
  ui->textEdit->setText(currentText + additionalText);
}

void MainWindow::on_pushButton_Clear_clicked() { ui->textEdit->setText(""); }

void MainWindow::on_pushButton_Delete_clicked() {
  QString text = ui->textEdit->toPlainText();
  text.chop(1);
  ui->textEdit->setText(text);
}

void MainWindow::on_pushButton_Graph_clicked() {
  graphWindow->setText(ui->textEdit->toPlainText());
  graphWindow->show();
}

void MainWindow::on_pushButton_Credit_clicked() { creditWindow->show(); }

void MainWindow::on_pushButton_Deposit_clicked() {}
