#include "ComplexNum.h"

ComplexNum::ComplexNum(double realPart, double imaginaryPart)
    : realPart(realPart), imaginaryPart(imaginaryPart) {}

double ComplexNum::getRealPart() const {
    return realPart;
}

double ComplexNum::getImaginaryPart() const {
    return imaginaryPart;
}

void ComplexNum::setRealPart(double realPart) {
    this->realPart = realPart;
}

void ComplexNum::setImaginaryPart(double imaginaryPart) {
    this->imaginaryPart = imaginaryPart;
}

ComplexNum ComplexNum::operator+(const ComplexNum& other) const {
    return ComplexNum(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
}

ComplexNum ComplexNum::operator-(const ComplexNum& other) const {
    return ComplexNum(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
}

ComplexNum ComplexNum::operator*(const ComplexNum& other) const {
    double real = realPart * other.realPart - imaginaryPart * other.imaginaryPart;
    double imaginary = imaginaryPart * other.realPart + realPart * other.imaginaryPart;
    return ComplexNum(real, imaginary);
}

ComplexNum ComplexNum::operator/(const ComplexNum& other) const {
    double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
    double real = (realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denominator;
    double imaginary = (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / denominator;
    return ComplexNum(real, imaginary);
}

ComplexNum ComplexNum::conjugate() const {
    return ComplexNum(realPart, -imaginaryPart);
}

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

