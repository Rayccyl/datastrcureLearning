/*
简版C++ 近乎是C with namespace
*/
#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct complexNum
{
    double realPart;
    double imaginaryPart;
}complexNum;

complexNum creat(double realPart,double imaginaryPart)
{
    complexNum created;
    created.realPart=realPart;
    created.imaginaryPart=imaginaryPart;
    return created;
}

void show(complexNum in)
{
    if (in.realPart==0&&in.imaginaryPart!=0) goto A;
    cout << in.realPart;
A:  if (in.imaginaryPart<0){in.imaginaryPart*=-1;cout << "-i" <<in.imaginaryPart;}
    else if (in.imaginaryPart==0){printf("");}
    else{cout << "+i" <<in.imaginaryPart;}
}

double showImaginaryPart(complexNum in)
{
    return in.imaginaryPart;
}

double showRealPart(complexNum in)
{
    return in.realPart;
}

complexNum sum(complexNum a,complexNum  b)
{
    complexNum sumed;
    sumed.realPart=a.realPart+b.realPart;
    sumed.imaginaryPart=a.imaginaryPart+b.imaginaryPart;
    return sumed;
}

complexNum Minus(complexNum a,complexNum  b)
{
    complexNum minused;
    minused.realPart=a.realPart-b.realPart;
    minused.imaginaryPart=a.imaginaryPart-b.imaginaryPart;
    return minused;
}
complexNum multiply(complexNum a,complexNum b)
{
    complexNum multiplied;
    multiplied.realPart=a.realPart*b.realPart-a.imaginaryPart*b.imaginaryPart;
    multiplied.imaginaryPart=a.imaginaryPart*b.realPart+a.realPart*b.imaginaryPart;
    return multiplied;
}

complexNum divide(complexNum a,complexNum b)
{
    complexNum divided;
    divided=multiply(a,b);
    double temp=multiply(b,b).realPart;
    divided.imaginaryPart/=temp;
    divided.realPart/=temp;
    return divided;
}

complexNum conjugate(complexNum in)
{
    in.imaginaryPart*=-1;
    return in;
}

int main()
{
    double realPart=0;
    double imaginaryPart=0;
    char charin[100]={0};
    cin >> charin ; 
    
    complexNum ina,inb;
    if (sscanf(charin,"%lf;%lf;",&ina.realPart,&inb.realPart)==2)
    {
        ina.imaginaryPart=0;
        inb.imaginaryPart=0;
    }
    else if (sscanf(charin,"%lf,%lf;%lf,%lf;",&ina.realPart,&ina.imaginaryPart,&inb.realPart,&inb.imaginaryPart)==4){}
    else
    {
        printf("failed to enter");
        return 1;
    }
    complexNum out=sum(ina,inb);
    show(out);
    return 0;
}