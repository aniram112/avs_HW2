//
// Created by Marina Roshchupkina on 15.10.2021.
//

#ifndef __cypher__
#define __cypher__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающее все строки шифрования
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// класс, обобщающий все строки шифрования
class Cypher {
protected:

public:
    virtual ~Cypher() {};

    // Ввод обобщенной строки
    static Cypher *StaticIn(ifstream &ifdt);

    // Ввод обобщенной строки
    virtual void In(ifstream &ifdt) = 0;

    // Случайный ввод обобщенной строки
    static Cypher *StaticInRnd();

    // Виртуальный метод ввода случайной строки
    virtual void InRnd() = 0;

    // Вывод обобщенной строки
    virtual void Out(ofstream &ofst) = 0;

    // Вычисление функции обобщенной строки
    virtual double Func() = 0;
};


#endif
