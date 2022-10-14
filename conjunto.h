#ifndef CONJUNTO_H
#define CONJUNTO_H
#include<QString>
namespace ejm {
class Conjunto
{
    //Atributos
private:
    int tamanho;
    int indiceOcupacao;
    int *array;
public:
    Conjunto(int tamanho);
    ~Conjunto();
    int getTamanho() const;
    QString getConjunto() const;
    bool buscar(int elemento) const;
    void incluirElemento(int elemento);


    Conjunto *uniao(Conjunto const *const P);
    Conjunto *inter(Conjunto const *const P);
    Conjunto *diff(Conjunto const *const P);
};

}
#endif // CONJUNTO_H
