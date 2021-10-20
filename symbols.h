//
// Created by Marina Roshchupkina on 15.10.2021.
//

#ifndef __symbols__
#define __symbols__

//------------------------------------------------------------------------------
// symbols.h - содержит описание строки, зашифрованной посимвольной заменой
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "rnd.h"
# include "cypher.h"
class Symbols: public Cypher {
public:
    virtual ~Symbols() {}
    // Ввод параметров строки из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров строки
    virtual void InRnd();
    // Вывод параметров строик в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление функции строки
    virtual double Func();
private:
    int length;
    char cyphered[100]; // зашифрованный текст
    char decyphered[100]; // открытая строка
    char cypher[2][100]; // шифр
};



#endif
