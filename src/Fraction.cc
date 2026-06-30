#include "Fraction.h"

#include <iostream>
#include <numeric>
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator)
  : numerator(numerator), denominator(denominator) {
  if(denominator == 0)
    throw std::invalid_argument("denominator cannot be zero");

  normalize();
}

Fraction::Fraction(int numerator)
  : Fraction(numerator, 1) {
}

int Fraction::num() const {
  return numerator;
}

int Fraction::den() const {
  return denominator;
}

void Fraction::normalize(){
  if (denominator < 0) {
    denominator = -denominator;
    numerator = -numerator;
  }

  int gcd = std::gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
}

Fraction& Fraction::operator+=(const Fraction& other){
  numerator = numerator * other.den() + other.num() * denominator;
  denominator = denominator * other.den();

  normalize();
  return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
  numerator = numerator * other.den() - other.num() * denominator;
  denominator = denominator * other.den();

  normalize();
  return *this;
}

Fraction operator+(Fraction a, const Fraction& b){
  a += b;
  return a;
}

Fraction operator-(Fraction a, const Fraction& b){
  a -= b;
  return a;
}

Fraction operator*(const Fraction& a, const Fraction& b){
  return Fraction(a.num() * b.num(), a.den() * b.den());
}

Fraction operator/(const Fraction& a, const Fraction& b){
  if(b.num() == 0)
    throw std::invalid_argument("b numerator can't be zero");

  return Fraction(a.num() * b.den(), a.den() * b.num());
}

bool operator==(const Fraction& a, const Fraction& b){
  return a.num() == b.num() && a.den() == b.den();
}

bool operator!=(const Fraction& a, const Fraction& b){
  return !(a == b);
}

bool operator<(const Fraction& a, const Fraction& b){
  return a.num() * b.den() < b.num() * a.den();
}

bool operator<=(const Fraction& a, const Fraction& b){
  return a < b || a == b;
}

bool operator>(const Fraction& a, const Fraction& b){
  return !(a <= b);
}

bool operator>=(const Fraction& a, const Fraction& b){
  return !(a < b);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f){
  os << f.num() << '/' << f.den();
  return os;
}

std::istream& operator>>(std::istream& is, Fraction& f){
  int num, den;
  char slash;

  if (is >> num >> slash >> den) {
    if (slash != '/' || den == 0) {
      is.setstate(std::ios::failbit);
    } else {
      f = Fraction(num, den);
    }
  }

  return is;
}
