/*
味儿正的C++ 由chatGPT老师根据我的C翻译
*/
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class ComplexNum {
public:
    ComplexNum(double realPart = 0.0, double imaginaryPart = 0.0)
        : realPart(realPart), imaginaryPart(imaginaryPart) {}

    double getRealPart() const { return realPart; }
    double getImaginaryPart() const { return imaginaryPart; }

    void setRealPart(double realPart) { this->realPart = realPart; }
    void setImaginaryPart(double imaginaryPart) { this->imaginaryPart = imaginaryPart; }

    ComplexNum operator+(const ComplexNum& other) const {
        return ComplexNum(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    ComplexNum operator-(const ComplexNum& other) const {
        return ComplexNum(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    ComplexNum operator*(const ComplexNum& other) const {
        double real = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
        double imaginary = imaginaryPart * other.realPart + realPart * other.imaginaryPart;
        return ComplexNum(real, imaginary);
    }

    ComplexNum operator/(const ComplexNum& other) const {
        double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        double real = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denominator;
        double imaginary = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / denominator;
        return ComplexNum(real, imaginary);
    }

    ComplexNum conjugate() const {
        return ComplexNum(realPart, -imaginaryPart);
    }

private:
    double realPart;
    double imaginaryPart;
};

std::ostream& operator<<(std::ostream& os, const ComplexNum& num) {
    if (num.getRealPart() != 0 || num.getImaginaryPart() == 0) {
        os << num.getRealPart();
    }
    if (num.getImaginaryPart() > 0) {
        os << (num.getRealPart() == 0 ? "" : "+") << "i" << num.getImaginaryPart();
    } else if (num.getImaginaryPart() < 0) {
        os << "-i" << -num.getImaginaryPart();
    }
    return os;
}

int main() {
    double realPart=0;
    double imaginaryPart=0;
    char charin[100]={0};
    std::cin >> charin ; 
    double realPart1, imaginaryPart1, realPart2, imaginaryPart2;
    ComplexNum *p1=NULL;
    ComplexNum *p2=NULL;
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
        std::cout << "failed to enter" << std::endl;
        return 1;
    }

    ComplexNum sum = *p1 + *p2;
    std::cout << sum << std::endl;
    delete p1;
    delete p2;
    return 0;
}