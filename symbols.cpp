//
// Created by Marina Roshchupkina on 15.10.2021.
//


#include "symbols.h"
#include "cstring"
//------------------------------------------------------------------------------
// Ввод параметров зашифрованной строки из файла
void Symbols::In(ifstream &ifst) {
    ifst >> cyphered;
    length = strlen(cyphered);
    for (int i = 0; i < length; ++i) {
        ifst >> cypher[0][i]>> cypher[1][i];
    }
    // Расшифровка, заменой символов с шифра на символы ключа.
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; j ++) {
            if (cyphered[i] == cypher[0][j])
                decyphered[i]= cypher[1][j];
        }
    }
}

// Случайный ввод параметров зашифрованной строки
void Symbols::InRnd() {
    Random r;
    length = r.RandomSmall();
    for (int i = 0; i < length; ++i) {
        char symb = (char)(r.Rand());
        cyphered[i]=symb;
        char symb_new = (char)(r.Rand());
        decyphered[i]+=symb_new;
        cypher[0][i]=symb;
        cypher[1][i]=symb_new;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров строки в форматируемый поток
void Symbols::Out(ofstream &ofst) {
    ofst << "symbols cypher: cyphered text = " << cyphered << ", decyphered text = " << decyphered
         << ". function_result = " << Func() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление общей функции
double Symbols::Func() {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += (int) decyphered[i];
    }
    return (double) sum / length;
}


