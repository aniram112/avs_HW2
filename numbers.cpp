//
// Created by Marina Roshchupkina on 15.10.2021.
//

#include "numbers.h"
#include "cstring"
//------------------------------------------------------------------------------
// Ввод параметров зашифрованной строки из файла
void Numbers::In(ifstream &ifst) {
    ifst >> length;
    for (int i = 0; i < length; ++i) {
        ifst >> cyphered[i];
    }
    for (int i = 0; i < length; ++i) {
        char temp;
        ifst >> temp >> cypher[1][i];
        cypher[0][i]=(int)temp;
    }
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if(cyphered[i]==cypher[1][j])
                decyphered[i]=cypher[0][j];
        }
    }
}

// Случайный ввод параметров строки
void Numbers::InRnd() {
    Random r;
    length = r.RandomSmall();
    for (int i = 0; i < length; ++i) {
        cyphered[i] = r.RandomSmall()*r.RandomSmall();
        decyphered[i] = (char)(r.Rand());
        cypher[0][i] = cyphered[i];
        cypher[1][i] = decyphered[i];
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в форматируемый поток
void Numbers::Out(ofstream &ofst) {
    ofst << "numbers cypher: cyphered text = ";
    for (int i = 0; i < length; ++i) {
        ofst  << cyphered[i];
    }
    ofst << ", decyphered text = " << decyphered
         << ". function result = " << Func() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление общей функции
double Numbers::Func() {
    int sum = 0;
    for (int i = 0; i < strlen(decyphered); ++i) {
        sum += (int) decyphered[i];
    }
    return (double) sum / strlen(decyphered);
}
