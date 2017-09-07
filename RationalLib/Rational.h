#pragma once
#include "stdafx.h"
#include <string>

class Rational {
private:
	long numerator;
	long denominator;
	void reduce();

public:
	__declspec(dllexport) Rational(long numerator = 0, long denominator = 1);
	__declspec(dllexport) long getNumerator() const;
	__declspec(dllexport) long getDenominator() const;
	__declspec(dllexport) Rational& operator ++();
	__declspec(dllexport) Rational& operator --();
	__declspec(dllexport) Rational operator ++(int);
	__declspec(dllexport) Rational operator --(int);
	__declspec(dllexport) Rational operator +=(const Rational);
	__declspec(dllexport) Rational operator -=(const Rational);
	__declspec(dllexport) Rational operator *=(const Rational);
	__declspec(dllexport) Rational operator /=(const Rational);
	__declspec(dllexport) std::string operator ()() const;
	__declspec(dllexport) operator double() const;
	__declspec(dllexport) Rational& operator =(const Rational);
	__declspec(dllexport) bool operator >(const Rational) const;
	__declspec(dllexport) bool operator <(const Rational) const;
	__declspec(dllexport) bool operator >=(const Rational) const;
	__declspec(dllexport) bool operator <=(const Rational) const;
	__declspec(dllexport) bool operator ==(const Rational) const;
	__declspec(dllexport) bool operator !=(const Rational) const;

	__declspec(dllexport) static long calcLeastCommonMultiple(long, long);
	__declspec(dllexport) static long calcGreatestCommonDivisor(long, long);
	__declspec(dllexport) static long calcLeastCommonDenominator(Rational, Rational);
};

__declspec(dllexport) Rational operator +(const Rational, const Rational);
__declspec(dllexport) Rational operator -(const Rational, const Rational);
__declspec(dllexport) Rational operator *(const Rational, const Rational);
__declspec(dllexport) Rational operator /(const Rational, const Rational);
// __declspec(dllexport) Rational& operator ^();
// __declspec(dllexport) ostream operator <<();
// __declspec(dllexport) istream operator >>();
