#include "telaprincipal.h"
#include "ui_telaprincipal.h"

//boolenao para verificar quando os 2 conjuntos forem criados
//fazendo com que os botoes com os metodos unicao etc sejam ativos
bool verA=false,verB=false;

TelaPrincipal::TelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaPrincipal),
      CA(0),
      CB(0)
{
    ui->setupUi(this);
    ui->lineEditIncluirCA->setEnabled(false);
    ui->lineEditIncluirCB->setEnabled(false);
    ui->pushButtonIncluirCA->setEnabled(false);
    ui->pushButtonIncluirCB->setEnabled(false);
    ui->lineEditResultado->setEnabled(false);
    ui->pushButtonUniao->setEnabled(false);
    ui->pushButtonIntersecao->setEnabled(false);
    ui->pushButtonCADiferencaCB->setEnabled(false);
    ui->pushButtonCBDiferencaCA->setEnabled(false);

}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
    if(CA) delete CA;
    if(CB) delete CB;
}


void TelaPrincipal::on_pushButtonCriarCA_clicked()
{
    try {
        int tamanho = ui->lineEditTamanhoCA->text().toInt();
        CA = new ejm::Conjunto(tamanho);
        ui->lineEditIncluirCA->setEnabled(true);
        ui->pushButtonIncluirCA->setEnabled(true);
        verA=true;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    } catch(std::bad_alloc &erro){
        QMessageBox::information(this,"ERRO DO SISTEMA","Conjunto não foi criado");
    }
}
void TelaPrincipal::on_pushButtonCriarCB_clicked()
{
    try {
        int tamanho = ui->lineEditTamanhoCB->text().toInt();
        CB = new ejm::Conjunto(tamanho);
        ui->lineEditIncluirCB->setEnabled(true);
        ui->pushButtonIncluirCB->setEnabled(true);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    } catch(std::bad_alloc &erro){
        QMessageBox::information(this,"ERRO DO SISTEMA","Conjunto não foi criado");
    }
}


void TelaPrincipal::on_pushButtonUniao_clicked()
{
    try {
        ejm::Conjunto *uniao=CA->uniao(CB);
        ui->lineEditResultado->setText(uniao->getConjunto());
        ui->lineEditResultado->setEnabled(true);
        delete uniao;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }

}

void TelaPrincipal::on_pushButtonIntersecao_clicked()
{
    try {
        ejm::Conjunto *inter=CA->inter(CB);
        ui->lineEditResultado->setText(inter->getConjunto());
        ui->lineEditResultado->setEnabled(true);
        delete inter;
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO", erro);
    }
}


void TelaPrincipal::on_pushButtonCADiferencaCB_clicked()
{
    try {
        ejm::Conjunto *diff=CB->diff(CA);
        ui->lineEditResultado->setText(diff->getConjunto());
        ui->lineEditResultado->setEnabled(true);
        delete diff;
    } catch (QString &erro) {

        ui->lineEditResultado->setText(erro);
    }
}


void TelaPrincipal::on_pushButtonCBDiferencaCA_clicked()
{
    try {
        ejm::Conjunto *diff=CA->diff(CB);
        ui->lineEditResultado->setText(diff->getConjunto());
        ui->lineEditResultado->setEnabled(true);
        delete diff;
    } catch (QString &erro) {

        ui->lineEditResultado->setText(erro);
    }
}


void TelaPrincipal::on_pushButtonIncluirCA_clicked()
{
    try {
        verA=true;
        int elemento = ui->lineEditIncluirCA->text().toInt();
        CA->incluirElemento(elemento);
        ui->lineEditSaidaCA->setText(CA->getConjunto());
        ui->lineEditIncluirCA->clear();
        if(verA==true && verB==true)
        {
            ui->pushButtonUniao->setEnabled(true);
            ui->pushButtonIntersecao->setEnabled(true);
            ui->pushButtonCADiferencaCB->setEnabled(true);
            ui->pushButtonCBDiferencaCA->setEnabled(true);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    } catch(std::bad_alloc &erro){
        QMessageBox::information(this,"ERRO DO SISTEMA","Conjunto não foi criado");
    }
}

void TelaPrincipal::on_pushButtonIncluirCB_clicked()
{
    try {
        verB=true;
        int elemento = ui->lineEditIncluirCB->text().toInt();
        CB->incluirElemento(elemento);
        ui->lineEditSaidaCB->setText(CB->getConjunto());
        ui->lineEditIncluirCB->clear();
        if(verA==true && verB==true)
        {
            ui->pushButtonUniao->setEnabled(true);
            ui->pushButtonIntersecao->setEnabled(true);
            ui->pushButtonCADiferencaCB->setEnabled(true);
            ui->pushButtonCBDiferencaCA->setEnabled(true);
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    } catch(std::bad_alloc &erro){
        QMessageBox::information(this,"ERRO DO SISTEMA","Conjunto não foi criado");
    }
}


