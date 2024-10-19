#include <iostream>


int main() 
{
    int i=0;
    int n=0;
    unsigned long long multi=1;
    int maxim=INT_MIN;
    int place=0;
    
    std::cout<<"start from: "<<std::endl;
    std::cin>>i;
    
    std::cout<<"end on: "<<std::endl;
    std::cin>>n;
    
    
    if(n>0)
    {
        for (i;i<=n;i++)
        {
            if (i%5!=0)
            {
                multi*=i;
                if (maxim<i)
                {
                    maxim=i;
                    place=i;
                }
            }
            

        }

        std::cout<<"multiplication of numbers indivisible by 5: "<<multi<<std::endl;
        std::cout<<"maximum: "<<maxim<<std::endl;
        std::cout<<"the number in the sequence: "<<place<<std::endl;
    }
    
    
    else
    {
        std::cout<<"error"<<std::endl;
    }

    return 0;
}


/*
int main()
{
    int N=0;
    int multi=1;
    int digit=0;


    std::cout<<"enter a number: "<<std::endl;
    std::cin>>N;
    

    if (0<N && N<1000000000)
    {
        while(N>0)
        {
            digit=N%10;
            if (digit%2!=0)
            {
                multi*=digit;  
            }
            N=N/10;
        }

        std::cout<<"the product of odd digits: "<<multi<<std::endl;

    }

    else
    {
        std::cout<<"error"<<std::endl;
    }
        

    return 0;
}

*/










