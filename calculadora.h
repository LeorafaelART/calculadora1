#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <cmath>
#include <QString>
namespace art{
class Calculadora
{
private:
    double num1;
    double num2;
public:
    Calculadora();//construtor padrão
    Calculadora(double num1,double num2);//construtor não padrão

    double calculoSoma()const;
    double calculoSub()const;
    double calculoMult()const;
    double calculoDiv()const;
    double calculoPow()const;
    double calculoRad(double num2)const;
    double calculoRad(double num2, double indice)const;
    double calculoPct()const;


    double getNum1() const;
    void setNum1(double newNum1);
    double getNum2() const;
    void setNum2(double newNum2);
};
}
#endif // CALCULADORA_H
