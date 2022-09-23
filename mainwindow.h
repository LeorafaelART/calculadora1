#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <calculadora.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_Negativar_clicked();

    void on_pushButton_decimal_clicked();

    void on_pushButton_soma_clicked();

    void on_pushButton_subtrair_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_multiplicar_clicked();

    void on_pushButton_porcentagem_clicked();

    void on_pushButton_raiz_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_menu_clicked();

    void on_pushButton_igual_clicked();

    void on_actionInfo_triggered();

    void on_pushButton_clicked();




    void on_pushButtonClaro_clicked();

    void on_pushButtonEscuro_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
