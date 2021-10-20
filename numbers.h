//
// Created by Marina Roshchupkina on 15.10.2021.
//
#ifndef __numbers__
#define __numbers__

//------------------------------------------------------------------------------
// number.h - содержит описание строки, зашифрованной заменой букв на числа
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "cypher.h"
// строка, шифрующаяся числами.
class Numbers: public Cypher {
public:
    virtual ~Numbers() {}
    // Ввод параметров строки из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров строки
    virtual void InRnd();
    // Вывод параметров строки в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление периметра строки
    virtual double Func();
private:
    int length;
    int cypher[2][100];
    int cyphered[100];
    char decyphered[100];

};

#endif
