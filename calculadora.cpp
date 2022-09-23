#include "calculadora.h"
#include <QString>
namespace art {
double Calculadora::getNum2() const
{
    return num2;
}

void Calculadora::setNum2(double newNum2)
{
    num2 = newNum2;
}

double Calculadora::getNum1() const
{
    return num1;
}

void Calculadora::setNum1(double newNum1)
{
    num1 = newNum1;
}
Calculadora::Calculadora(double num1, double num2):  //Construtor não padrão
    num1(num1),
    num2(num2)
{

}
Calculadora::Calculadora(): // Construtor padrão
    num1(0.0),
    num2(0.0)
{
}
    double Calculadora::calculoSoma()const{
    return num1+num2;
    }
    double Calculadora::calculoSub()const{
        return num1-num2;
    }
    double Calculadora::calculoMult()const{
        return num1*num2;
    }
    double Calculadora::calculoDiv()const{
        if (num2 == 0) throw QString("Não é possível divisão por 0");
        return num1/num2;
    }
    double Calculadora::calculoPow()const{
        return pow(num1,num2);
    }
    double Calculadora::calculoRad(double num2)const{
        if(num2 < 0) throw QString("Não pode ser negativo");
        return sqrt(num2);
    }
    double Calculadora::calculoRad(double num2, double indice)const{
        if(num2 < 0) throw QString("Não pode ser negativo");
        return pow(num2,1/indice);
    }
    double Calculadora::calculoPct()const{
        return ((num1*num2)/100.0);
    }
}
