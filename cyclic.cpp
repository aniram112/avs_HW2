//
// Created by Marina Roshchupkina on 15.10.2021.
//
//------------------------------------------------------------------------------
// cyclic.cpp - содержит функции обработки шифрования циклическим сдвигом
//------------------------------------------------------------------------------

#include "cyclic.h"
#include "cstring"

//------------------------------------------------------------------------------
// Ввод параметров строки и шифра из потока
void Cyclic::In(ifstream &ifst) {
    ifst >> cyphered >> cypher;
    for (int i = 0; i < strlen(cyphered); ++i) {
        decyphered[i]=(char)(cypher+(int)cyphered[i]);
    }
}

// Случайный ввод параметров строки и шифра
void Cyclic::InRnd() {
    Random r;
    cypher = r.RandomSmall();
    int lenght = r.RandomSmall();
    for (int i = 0; i < lenght; ++i) {
        char symb = (char)(r.Rand());
        cyphered[i]=symb;
        decyphered[i]=(char)(cypher+(int)symb);
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в поток
void Cyclic::Out(ofstream &ofst) {
    ofst << "cyclic cypher: cyphered text = " << cyphered << ", decyphered text = " << decyphered
         << ". function result = " << Func() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление функции общей для всех строк.
double Cyclic::Func() {
    int sum = 0;
    for (int i = 0; i < strlen(decyphered); ++i) {
        sum += (int) decyphered[i];
    }
    return (double) sum / strlen(decyphered);
}

