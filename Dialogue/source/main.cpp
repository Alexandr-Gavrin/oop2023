#include <iostream>
#include <windows.h>
#include <Utils/getNumber.h>
#include <string>
#include "TernaryArray/TernaryArray.h"


using namespace Prog2;
using namespace Prog3;


int main() {
    SetConsoleOutputCP(CP_UTF8);


    size_t size;
    std::cout << "Введите размер массива:";
    size = Utils::getNum(0);

    TernaryArray tr1((int)size);
    std::string st = "1345   x 123 0 0 0 000`01010300";
    TernaryArray tr2(st);

    std::cout << std::endl;
    std::cout << tr1[3];
    
}
