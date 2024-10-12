#include <iostream>

int main()
{
    unsigned int x;
    int i;
    std::cin>>x>>i;
    if (x>0 && x<1000000000 && i<32)
    {
      std::cout<< (x & ~(1<<i));

    }
    else
    {
      std::cout<<"neprav"<<std::endl;
    } 
    return 0;

}
