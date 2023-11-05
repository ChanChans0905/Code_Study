#include <iostream>

void print_hello()
{
    std::cout<<"Hello"<<std::endl;
}

int main()
{
    // int scores[] = {100,85,22,56,64,96};

    for(int i = 0; i < 10; i++)
    {
        print_hello();
    }

    return 0;
}

