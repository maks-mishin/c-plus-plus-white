#pragma once
#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>
#include <string>
#include <map>

using namespace std;

/*
	Class Rational for working with algebraic rational fractions
*/
class Rational {
public:
	Rational() {
		num = 0;
		den = 1;
	}
	Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw 1;
		else if (denominator < 0) {
			if (numerator < 0) {
				denominator = abs(denominator);
				numerator = abs(numerator);
			}
			else {
				denominator = abs(denominator);
				numerator = numerator - 2 * numerator;
			}
		}
		if (numerator == 0) {
			denominator = 1;
		}
		int nod_num = nod(abs(numerator), abs(denominator));
		num = numerator / nod_num;
		den = denominator / nod_num;
	}

	int Numerator() const { return num; }
	int Denominator() const { return den; }

	friend ostream& operator << (ostream& stream, const Rational& rhs);
	friend istream& operator >> (istream& stream, const Rational& rhs);
private:
	int num;
	int den;

	int nod(int a, int b)
	{
		while (a > 0 && b > 0)
		{
			if (a > b) a %= b;
			else b %= a;
		}
		return a + b;
	}
};

bool operator == (const Rational& lhs, const Rational& rhs)
{
	return lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator();
}
Rational operator + (const Rational& lhs, const Rational& rhs)
{
	return{ lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(),
		rhs.Denominator()*lhs.Denominator() };
}
Rational operator - (const Rational& lhs, const Rational& rhs)
{
	return{ lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(),
		rhs.Denominator()*lhs.Denominator() };
}
Rational operator * (const Rational& lhs, const Rational& rhs)
{
	return{ lhs.Numerator()*rhs.Numerator(),
		rhs.Denominator()*lhs.Denominator() };
}
Rational operator / (const Rational& lhs, const Rational& rhs)
{
	if (rhs.Numerator() == 0)
		throw 2;
	return{ lhs.Numerator()*rhs.Denominator(),
		rhs.Numerator()*lhs.Denominator() };
}

istream& operator >> (istream& stream, Rational& rhs)
{
	int one, two;

	if (stream >> one && stream.ignore(1) && stream >> two)
	{
		rhs = { one, two };
	}
	return stream;
}

ostream& operator << (ostream& stream, const Rational& rhs)
{
	stream << rhs.Numerator() << '/' << rhs.Denominator();
	return stream;
}

bool operator > (Rational a, Rational b) 
{
	return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) 
{
	return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}