#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H

#include <iostream>
class ComplexNum {
public:
    ComplexNum(double realPart = 0.0, double imaginaryPart = 0.0);

    double getRealPart() const;
    double getImaginaryPart() const;

    void setRealPart(double realPart);
    void setImaginaryPart(double imaginaryPart);

    ComplexNum operator+(const ComplexNum& other) const;
    ComplexNum operator-(const ComplexNum& other) const;
    ComplexNum operator*(const ComplexNum& other) const;
    ComplexNum operator/(const ComplexNum& other) const;

    ComplexNum conjugate() const;

private:
    double realPart;
    double imaginaryPart;
};

std::ostream& operator<<(std::ostream& os, const ComplexNum& num);

#endif // COMPLEXNUM_H
