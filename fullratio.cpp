#ifndef CONTEST
#include "fullratio.hpp"
#endif

#include <iostream>
using namespace std;

rational::rational(int n, int d) {
	int val_gcd = gcd(n, d);

	n /= val_gcd;
	d /= val_gcd;
	if (d < 0) {
		n = -n;
		d = -d;
	}

	nom = n;
	den = d;
}

rational operator + (const rational &x, const rational &y) {
	return rational(x.nom * y.den + y.nom * x.den, x.den * y.den);
}

rational operator - (const rational &x, const rational &y) {
	return rational(x.nom * y.den - y.nom * x.den, x.den * y.den);
}

rational operator * (const rational &x, const rational &y) {
	return rational(x.nom * y.nom, x.den * y.den);
}

rational operator / (const rational &x, const rational &y) {
	return rational(x.nom * y.den, x.den * y.nom);
}

ostream & operator << (ostream &out, const rational &x) {
	out << x.nom << "/" << x.den;
	return out;
}

int rational::gcd(int p, int q)
{
	return q ? gcd(q, p%q) : p;
}
