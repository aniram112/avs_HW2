//
// Created by Marina Roshchupkina on 15.10.2021.
//

#ifndef __cyclic__
#define __cyclic__

//------------------------------------------------------------------------------
// cyclic.h - содержит описание строки, зашифрованной измененрем кода символа.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
#include "cypher.h"

class Cyclic: public Cypher {
public:
    virtual ~Cyclic() {}
    // Ввод параметров строки из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров строки
    virtual void InRnd();
    // Вывод параметров строки в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Деление кодов символов незашифрованной строки на число символов в ней
    virtual double Func();
private:
    int cypher;
    char cyphered[100];
    char decyphered[100];
};

#endif
