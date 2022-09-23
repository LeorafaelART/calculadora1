#include "mainwindow.h"
#include "calculadora.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//variaveis "globais"

QString saida;
int operador=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_0_clicked()
{
    saida += "0";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_1_clicked()
{
    saida += "1";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_2_clicked()
{
    saida += "2";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_3_clicked()
{
    saida += "3";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_4_clicked()
{
    saida += "4";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_5_clicked()
{
    saida += "5";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_6_clicked()
{
    saida += "6";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_7_clicked()
{
    saida += "7";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_8_clicked()
{
    saida += "8";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_9_clicked()
{
    saida += "9";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_Negativar_clicked()
{
    saida += "-";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_decimal_clicked()
{
    saida += ".";
    ui->lineEditTela->setText(saida);
}


void MainWindow::on_pushButton_soma_clicked()
{
    if(operador==0)
    {
        saida += "+";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_subtrair_clicked()
{
    if(operador==0)
    {
        saida += "-";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_div_clicked()
{
    if(operador==0)
    {
        saida += "÷";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_multiplicar_clicked()
{
    if(operador==0)
    {
        saida += "*";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_porcentagem_clicked()
{
    if(operador==0)
    {
        saida += "%";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_raiz_clicked()
{
    if(operador==0)
    {
        saida += "√";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_pow_clicked()
{
    if(operador==0)
    {
        saida += "^";
        ui->lineEditTela->setText(saida);
        operador++;
    }
    else
    {
        saida += "";
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_backspace_clicked()
{
    if(saida.isEmpty()==false)
    {
        QString rad = "√", div = "÷", pct="%";
        QString apagar=saida;
        int tam = saida.size();
        saida.clear(); //limpa a string

        if(apagar[tam-1]!='+' || apagar[tam-1] !='-' || apagar[tam-1] != '*' || apagar[tam-1] != div || apagar[tam-1] != '^' || apagar[tam-1] != rad || apagar[tam-1] !=pct)
        {
            operador=0;
        }

        for(int i=0;i<tam-1;i++)
        {
            if(apagar[tam-1]!='+' || apagar[tam-1] !='-' || apagar[tam-1] != '*' || apagar[tam-1] != div || apagar[tam-1] != '^' || apagar[tam-1] != rad || apagar[tam-1] !=pct)
            {
                operador=0;
            }
            saida+=apagar[i]; //apaga posição por posição no vetor da string
        }
        ui->lineEditTela->setText(saida);
    }
}


void MainWindow::on_pushButton_clear_clicked()
{
    saida.clear();
    ui->lineEditTela->setText(saida);
    operador=0;
}


void MainWindow::on_pushButton_menu_clicked()
{
    ui->pushButton_menu->hide();
}


void MainWindow::on_pushButton_igual_clicked()
{
    try {
        if(saida.isEmpty()==false) //evitar que feche ao digitar apenas o igual
        {
            int i;
            QString rad = "√",num1,num2, div = "÷", pct="%";

            art::Calculadora calculo;
            //repetição que percorre cada posição da string e detecta o sinal
            for(i=0;i<saida.size() && saida[i]!='+' && saida[i] !='-' && saida[i] != '*' && saida[i] != div && saida[i] != '^' && saida[i] != rad && saida[i] !=pct;i++)
            {
            }
            for(int j=0;j<i;j++)
            {
                num1+=saida[j];
            }
            for(int j=i+1;j<saida.size();j++)
            {
                num2+=saida[j];
            }
            calculo.setNum1(num1.toDouble());
            calculo.setNum2(num2.toDouble());
            if(saida[i]=='+')
            {
                saida= QString::number(calculo.calculoSoma());
            }
            else
            {
                if(saida[i]=='-')
                {

                    saida= QString::number(calculo.calculoSub());
                }
                else
                {
                    if(saida[i]=='*')
                    {
                        saida= QString::number(calculo.calculoMult());
                    }
                    else
                    {
                        if(saida[i]==div)
                        {

                                saida= QString::number(calculo.calculoDiv());

                        }
                        else
                        {
                            if(saida[i]=='^')
                            {
                                saida= QString::number(calculo.calculoPow());
                            }
                            else
                            {
                                if(saida[i]==rad)
                                {
                                    if(i == 0)
                                    {
                                         //apenas raiz quadrada
                                         saida= QString::number(calculo.calculoRad(num2.toDouble()));
                                    }
                                    else
                                    {
                                        //raiz com indice
                                        saida= QString::number(calculo.calculoRad(num2.toDouble(), num1.toDouble()));
                                    }
                                }
                                else
                                {
                                    saida= QString::number(calculo.calculoPct());
                                }
                            }
                        }
                    }
                }
                operador=0;
            }
            ui->lineEditTela->setText(saida);
        }
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }


}


void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::information(this,"Informações","Calculadora PROJECT 2022\n"
                                                "Alpha v. 0.1.0\n"
                                                "\n"
                                                "Desenvolvedores:\n"

                                                "Vitor Souza \n"
                                                "Leonardo Rafael \n "
                                                "Lucas Amorim \n");

}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this,"Como funciona","1 - Cálculo somente entre dois números;\n"
                                              "2- Negativos não funcionam;\n"
                                              "3- Resultado de raiz negativa não funcionam;\n"
                                              "4 - 2 temas disponiveis; \n "
                                              "5 - Flamengo é seleção porra \n");

}






void MainWindow::on_pushButtonClaro_clicked()
{
   ui->pushButton_0->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_1->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_2->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_3->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_4->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_5->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_6->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_7->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_8->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_9->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_Negativar->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_soma->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_subtrair->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_raiz->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_pow->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_porcentagem->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_multiplicar->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_div->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_decimal->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_clear->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButton_backspace->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->lineEditTela->setStyleSheet("background-color:#F3F3F3;color:#111");
   ui->pushButtonClaro->setStyleSheet("background-color:#FFFFFF");
   ui->pushButtonEscuro->setStyleSheet("background-color:#FFFFFF");
   ui->pushButton_menu->setStyleSheet("background-color:#FFFFFF;color:#111");
   ui->pushButton_menu->show();
}

void MainWindow::on_pushButtonEscuro_clicked()
{
    ui->pushButton_0->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_1->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_2->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_3->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_4->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_5->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_6->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_7->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_8->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_9->setStyleSheet("background-color:#2E3436;color:#4F9FF3");
    ui->pushButton_Negativar->setStyleSheet("background-color:#2E3436;color:#F57900");
    ui->pushButton_soma->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_subtrair->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_raiz->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_pow->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_porcentagem->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_multiplicar->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_div->setStyleSheet("background-color:#2E3436;color:#8AE234");
    ui->pushButton_decimal->setStyleSheet("background-color:#2E3436;color:#F57900");
    ui->pushButton_clear->setStyleSheet("background-color:#2E3436;color:#FC2020");
    ui->pushButton_backspace->setStyleSheet("background-color:#888A85;color:#111");
    ui->lineEditTela->setStyleSheet("background-color:#2E3436;color:#FFFFFF");
    ui->pushButtonClaro->setStyleSheet("background-color:#888A85");
    ui->pushButtonEscuro->setStyleSheet("background-color:#888A85");
    ui->pushButton_menu->setStyleSheet("background-color:#2E3436;color:#FFFFFF");

    ui->pushButton_menu->show();

}

