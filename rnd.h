#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 97 до 122 (для символов) или от 1 до 10 (для чисел)
//------------------------------------------------------------------------------
class Random {
public:
    int Rand() {
        return rand() % 26 + 97;
    }
    int RandomSmall() {
        return rand() % 10+1;
    }
private:
};

#endif //__rnd__
