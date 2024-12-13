#include "func.hpp"
#include <iostream>

void task1(){
    long long num = 0;
    std::cout<<"Введите число"<<std::endl;
    std::cin>>num;

    unsigned char* bytePointer = reinterpret_cast<unsigned char*>(&num);
    
    std::cout << "Содержимое каждого байта числа " << num << ":" << std::endl;
    
    for (size_t i = 0; i < sizeof(num); ++i)
    
    std::cout << "Байт " << i << ": " << static_cast<int>(bytePointer[i]) << std::endl;

}



// &num  адресс числа в стеке
//<unsigned char*>(&num) сохранение в указатель, тк чар то значение первого байта
//reinterpret_cast<unsigned char*>(&num); рассмотрим значение байта в чаре а не инте