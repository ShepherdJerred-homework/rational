#include "stdafx.h"
#include "Rational.h"
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::string;
using std::stringstream;
using std::ostream;

Rational::Rational(long numerator, long denominator) : numerator(numerator), denominator(denominator) {
	reduce();
	if (numerator < 0 || denominator < 0) {
		cout << "Values cannot be negative";
		throw "Values cannot be negative";
	}
}

void Rational::reduce() {
	long gcd = calcGreatestCommonDivisor(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
}

long Rational::getNumerator() const {
	return this->numerator;
}

long Rational::getDenominator() const {
	return this->denominator;
}

Rational& Rational::operator++() {
	numerator += denominator;
	reduce();
	return *this;
}

Rational& Rational::operator--() {
	numerator -= denominator;
	reduce();
	return *this;
}

Rational Rational::operator++(int x) {
	numerator += denominator;
	reduce();
	return *this;
}

Rational Rational::operator--(int x) {
	numerator -= denominator;
	reduce();
	return *this;
}

Rational Rational::operator+=(const Rational x) {
	*this = *this + x;
	reduce();
	return *this;
}

Rational Rational::operator-=(const Rational x) {
	*this = x - *this;
	reduce();
	return *this;
}

Rational Rational::operator*=(const Rational x) {
	*this = *this * x;
	reduce();
	return *this;
}

Rational Rational::operator/=(const Rational x) {
	*this = *this / x;
	reduce();
	return *this;
}

string Rational::operator()() const {
	string returnString;
	stringstream ss;
	ss << numerator << "/" << denominator;
	ss >> returnString;
	return returnString;
}

Rational::operator double() const {
	return double(numerator) / denominator;
}

Rational& Rational::operator=(const Rational x) {
	numerator = x.getNumerator();
	denominator = x.getDenominator();
	return *this;
}

bool Rational::operator>(const Rational x) const {
	return double(*this) > double(x);
}

bool Rational::operator<(const Rational x) const {
	return !(*this > x);
}

bool Rational::operator>=(const Rational x) const {
	return *this > x || *this == x;
}

bool Rational::operator<=(const Rational x) const {
	return *this < x || *this == x;
}

bool Rational::operator==(const Rational x) const {
	return numerator == x.getNumerator() && denominator == x.getDenominator();
}

bool Rational::operator!=(const Rational x) const {
	return !(*this == x);
}

Rational operator+(Rational x, Rational y) {
	long lcm = Rational::calcLeastCommonMultiple(x.getDenominator(), y.getDenominator());

	long numeratorX = (x.getNumerator() * lcm) / x.getDenominator();
	long numeratorY = (y.getNumerator() * lcm) / y.getDenominator();

	return Rational(numeratorX + numeratorY, lcm);
}

Rational operator-(Rational x, Rational y) {
	long lcm = Rational::calcLeastCommonMultiple(x.getDenominator(), y.getDenominator());

	long numeratorX = (x.getDenominator() / lcm) * x.getNumerator();
	long numeratorY = (y.getDenominator() / lcm) * y.getNumerator();

	return Rational(numeratorY - numeratorX, lcm);
}

Rational operator*(Rational x, Rational y) {
	long numerator = x.getNumerator() * y.getNumerator();
	long denominator = x.getDenominator() * y.getDenominator();
	
	return Rational(numerator, denominator);
}

Rational operator/(Rational x, Rational y) {
	Rational reciprocal = Rational(y.getDenominator(), y.getNumerator());

	return reciprocal * x;
}

// https://stackoverflow.com/questions/3154454/what-is-the-most-efficient-way-to-calculate-the-least-common-multiple-of-two-int
long Rational::calcLeastCommonDenominator(Rational x, Rational y) {
	return x.getDenominator() / y.calcGreatestCommonDivisor(x.getDenominator(), y.getDenominator()) * y.getDenominator();
}

long Rational::calcGreatestCommonDivisor(long x, long y) {
	long remainder = x % y;
	while (remainder != 0) {
		x = y;
		y = remainder;
		remainder = x % y;
	}
	return y;
}

long Rational::calcLeastCommonMultiple(long x, long y) {
	long result = x;
	while (result % y != 0) {
		result += x;
	}
	return result;
}
