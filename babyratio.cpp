#ifndef CONTEST
#include "babyratio.hpp"
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

rational rational::add(rational r) {
	return rational(nom * r.den + r.nom * den, den * r.den);
}

rational rational::sub(rational r) {
	return rational(nom * r.den - r.nom * den, den * r.den);
}

rational rational::mul(rational r) {
	return rational(nom * r.nom, den * r.den);
}

rational rational::div(rational r) {
	return rational(nom * r.den, den * r.nom);
}

void rational::print() {
	cout << nom << "/" << den;
}

int rational::gcd(int p, int q)
{
	return q ? gcd(q, p%q) : p;
}
