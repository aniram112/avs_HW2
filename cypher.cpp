//
// Created by Marina Roshchupkina on 15.10.2021.
//
//------------------------------------------------------------------------------
// cypher.cpp - содержит процедуры связанные с обработкой обобщенной строки
// и создания произвольной строки
//------------------------------------------------------------------------------

#include "symbols.h"
#include "cyclic.h"
#include "numbers.h"



//------------------------------------------------------------------------------
// Ввод параметров обобщенной строки из файла
Cypher* Cypher::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Cypher* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Symbols;
            sp->In(ifst);
            break;
        case 2:
            sp = new Cyclic;
            sp->In(ifst);
            break;
        case 3:
            sp = new Numbers;
            sp->In(ifst);
            break;
    }
    //sp->In(ifst);
    return sp;
}

// Случайный ввод обобщенной строки
Cypher *Cypher::StaticInRnd() {
    Cypher* sp;
    auto k = rand() % 3 + 1;
    switch(k) {
        case 1:
            sp = new Symbols;
            sp->InRnd();
            break;
        case 2:
            sp = new Cyclic;
            sp->InRnd();
            break;
        case 3:
            sp = new Numbers;
            sp->InRnd();
            break;
    }
    //sp->InRnd();
    return sp;
}