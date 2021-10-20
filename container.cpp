//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} {len = 0;}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    len = 0;
    while(!ifst.eof()) {
        //storage[len] = Cypher::StaticIn(ifst);
        if((storage[len] = Cypher::StaticIn(ifst)) != 0) {
            len++;
        }
    }
    len--;
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((storage[len] = Cypher::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Удаление элементов значение функции у которых меньше среднего арифметического
void Container::DeleteLess(ofstream &ofst) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += storage[i]->Func();
    }
    double mean = sum / (len);
    ofst << "Mean: "<<mean<<" Sum: "<<sum<<" Len: "<<len<<endl;
    for (int i = 0; i < len; i++) {
        if (storage[i]->Func() < mean) {
            for(int j = i; j < len; j++) {
                storage[j] = storage[j+1];
            }
            storage[len-1] = NULL;
            len--;
            i--;
        }

    }

}

