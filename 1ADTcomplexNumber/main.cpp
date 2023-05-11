#include <iostream>
#include <string>
#include "ComplexNum.h"

int main() {
    using namespace std;
    char charin[100]={0};
    std::cin >> charin ; 
    double realPart1, imaginaryPart1, realPart2, imaginaryPart2;
    ComplexNum *p1;
    ComplexNum *p2;
    if (sscanf(charin,"%lf;%lf;",&realPart1,&realPart2)==2)
    {
        imaginaryPart1=0;
        imaginaryPart2=0;
        p1=new ComplexNum (realPart1, imaginaryPart1);
        p2=new ComplexNum (realPart2, imaginaryPart2);
    }
    else if (sscanf(charin,"%lf,%lf;%lf,%lf;",&realPart1,&imaginaryPart1,&realPart2,&imaginaryPart2)==4)
    {
        p1=new ComplexNum (realPart1, imaginaryPart1);
        p2=new ComplexNum (realPart2, imaginaryPart2);
    }
    else
    {
        cout << "failed to enter" << endl;
        return 1;
    }

    ComplexNum sum = *p1 + *p2;
    std::cout << sum << std::endl;
    delete p1;
    delete p2;
    return 0;
}