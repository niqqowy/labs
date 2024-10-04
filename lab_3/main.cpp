#include <iostream>

int main()
{
    unsigned int x;
    short i;
    std::cin>>x>>i;
    std::cout<< (x & ~(1<<i)); //побитовая операция and 'x' и 'маской' (которая имеет 0 на позиции i и 1 на всех остальных позициях.)
    return 0;

}


// 0110 1001
// 0000 1000 = ~ 1111 0111
//