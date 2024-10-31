#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnValidar, &QPushButton::clicked, this, &MainWindow::validarContrasena);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Definición que coincide exactamente con la declaración
void MainWindow::validarContrasena()
{
    QString pw = ui->txtPwd->toPlainText();
    QRegularExpression re("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#\\$%\\^&\\*])(?=.{8,})");
    QRegularExpressionMatch match = re.match(pw);
    bool encontrado = match.hasMatch();

    if (encontrado) {
        ui->lblSalida->setText("Valid password!");
    } else {
        ui->lblSalida->setText("Invalid password! Try again . . .\n\n");
    }
}
