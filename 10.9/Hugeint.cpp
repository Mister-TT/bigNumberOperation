#include "Hugeint.h"
#include<cctype>
using namespace std;

Hugeint::Hugeint(long long value)
{
	for (short &element : integer)
		element = 0;

	for (size_t j = digits - 1; value != 0 && j >= 0; j--) {
		integer[j] = value % 10;
		value /= 10;
	}
}

Hugeint::Hugeint(const string &number)
{
	for (short &element : integer)
		element = 0;

	size_t length = number.size();

	for (size_t j = digits - length, k = 0; j<digits; j++, k++) {
		if (isdigit(number[k]))//判断char类型的是不是数字
			integer[j] = number[k] - '0';
	}
}

Hugeint Hugeint::operator+(const Hugeint &op2) const
{
	Hugeint temp;
	int carry = 0;

	for (int i = digits - 1; i >= 0; i--) {
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		if (temp.integer[i] > 9) {
			temp.integer[i] %= 10;
			carry = 1;
		}
		else 
			carry = 0;
	}
	if (carry > 0) {
		cout << "ERROR\n";
		for (int i = 0; i < digits; i++)
			temp.integer[i] = 0;
	}
	return temp;
}

Hugeint Hugeint::operator+(int op2) const
{
	return *this + Hugeint(op2);
}

Hugeint Hugeint::operator+(const string &op2)const
{
	return *this + Hugeint(op2);
}
ostream & operator<<(ostream &out, const Hugeint &num)
{
	int i;

	for (i = 0; (i < Hugeint::digits) && (0 == num.integer[i]); i++);

	if (i == Hugeint::digits)
		out << 0;
	else
		for (; i < Hugeint::digits; i++)
			out << num.integer[i];
	return out;
}

bool Hugeint::operator< (const Hugeint &obj) const
{
	for (int i = 0; i < digits ; i++) {
		if (integer[i] < obj.integer[i])return true;
		if (integer[i] > obj.integer[i])return false;
	}
	return false;
}
bool Hugeint::operator<=(const Hugeint &obj) const
{
	for (int i = 0; i < digits ; i++) {
		if (integer[i] < obj.integer[i])return true;
		if (integer[i] > obj.integer[i])return false;
	}
	return true;
}
bool Hugeint::operator> (const Hugeint &obj) const
{
	for (int i = 0; i < digits; i++) {
		if (integer[i] > obj.integer[i])return true;
		if (integer[i] < obj.integer[i])return false;
	}
	return false;
}
bool Hugeint::operator>=(const Hugeint &obj) const
{
	for (int i = 0; i < digits ; i++) {
		if (integer[i] > obj.integer[i])return true;
		if (integer[i] < obj.integer[i])return false;
	}
	return true;
}
bool Hugeint::operator==(const Hugeint &obj) const
{
	for (int i = 0; i < digits ; i++) {
		if (integer[i] != obj.integer[i])return false;
	}
	return true;
}
bool Hugeint::operator!=(const Hugeint &obj) const
{
	for (int i = 0; i < digits ; i++) {
		if (integer[i] != obj.integer[i])return true;
	}
	return false;
}

Hugeint Hugeint::operator*(const Hugeint &op2) const
{
	Hugeint temp;
	for (int i = 0; i < digits; i++)
		temp.integer[i] = 0;
	
	for (int i = digits - 1; i >= 0; i--) {
		int dis = digits - 1 - i;
		
		for (int a = digits - 1; a - dis >= 0; a--)
		{
			int carry = 0;
			int tmp = a - dis;
			temp.integer[tmp] += integer[a] * op2.integer[i] + carry;

			if (temp.integer[tmp] >= 10) {
				if (tmp - 1 < 0) {
					cout << "ERROR\n";
					for (int i = 0; i < digits; i++)
						temp.integer[i] = 0;
					return temp;
				}
				else {
					temp.integer[tmp - 1] += temp.integer[tmp] / 10;
					temp.integer[tmp] = temp.integer[tmp] % 10;
				}
			}
		}
	}

	return temp;
}

Hugeint Hugeint::operator*(int op2) const
{
	return *this * Hugeint(op2);
}

Hugeint Hugeint::operator*(const string &op2)const
{
	return *this * Hugeint(op2);
}

Hugeint Hugeint::operator/(const Hugeint &op2) const
{
	Hugeint temp(*this);
	if (op2 == 0) {
		cout << "ERROR!!";
		for (int i = 0; i < digits; i++)
			temp.integer[i] = 0;
	}
	else if (*this < op2) {
		for (int i = 0; i < digits; i++)
			temp.integer[i] = 0;
	}
	else if (*this == op2) {
		temp.integer[digits - 1] = 1;
	}
	else if (op2 == 1) {
		temp = *this;
	}
	else if (op2 == 2) {
		
		int from = 0;
		for (int i = 0; i < digits; i++) {
			if (temp.integer[i] != 0) {
				from = i;
				break;
			}
		}

		int carry = 0;
		for (int i = from; i < digits; i++) {
			if (temp.integer[i] & 1) {
				if(carry==1)temp.integer[i] = ( temp.integer[i] + 10)/ 2;
				else temp.integer[i] = temp.integer[i] / 2;
				carry = 1;
			}
			else {
				if (carry == 1)temp.integer[i] = (temp.integer[i] + 10) / 2;
				else temp.integer[i] = temp.integer[i] / 2;
				carry = 0;
			}
		}
	}
	else {
		Hugeint begin(1), end ("500000000000000000000000000000");//500000000000000000000000000000
		while (begin < end) {
			Hugeint  mid = (begin + end) / 2;
			Hugeint res = mid * op2;
			
			if (res == 0 || res >= *this)end = mid;
			else begin = mid + 1;
		}
		temp = begin;
		if (temp == 1)return 0;

		int tmp = digits - 1;
		while (temp.integer[tmp] == 0) {
			temp.integer[tmp] = 9;
			tmp++;
		}
		temp.integer[tmp]--;
		return temp;
	}
	return temp;
}

Hugeint Hugeint::operator/(int op2) const
{
	return *this / Hugeint(op2);
}

Hugeint Hugeint::operator/(const string &op2)const
{
	return *this / Hugeint(op2);
}