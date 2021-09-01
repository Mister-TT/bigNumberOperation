#ifndef HUGEINT_H
#define HUGEINT_H

#include<array>
#include<iostream>
#include<string>

using namespace std;

class Hugeint
{
	friend ostream &operator<<(ostream &, const Hugeint &);
public:
	static const int digits = 30;

	Hugeint(long long = 0);
	Hugeint(const string &);

	Hugeint operator+(const Hugeint &) const;
	Hugeint operator+(int) const;
	Hugeint operator+(const string &) const;
	
	Hugeint operator*(const Hugeint &) const;
	Hugeint operator*(int) const;
	Hugeint operator*(const string &) const;

	Hugeint operator/(const Hugeint &) const;
	Hugeint operator/(int) const;
	Hugeint operator/(const string &) const;
	
	bool operator< (const Hugeint &) const;
	bool operator<=(const Hugeint &) const;
	bool operator> (const Hugeint &) const;
	bool operator>=(const Hugeint &) const;
	bool operator==(const Hugeint &) const;
	bool operator!=(const Hugeint &) const;

private:
	array< short, digits>integer;
};

#endif