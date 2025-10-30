#include<iostream>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 20;
    int b = 30;
    Swap(&a,&b);
    swap(a, b);
    std::cout <<"a: "<<a <<" b: "<<b << std::endl;
    return 0;
}