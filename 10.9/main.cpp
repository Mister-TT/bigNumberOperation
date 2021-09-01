//(a)构造函数可以接受int类型或者string类型
//然后将最小位存在integer【29】，依次往下
//string类型要注意-48，因为它是char类型不是int类型

//对于Hugeint和Hugeint的加法，
//只需要按数位从小到大往上加，并考虑进位即可演算出正确数值

//对于string和int的加法
//先用构造函数将他们构造成Hugeint，再来进行加法


//(b)尽管是大数运算，但大数的位数不能超过30位
//否则integer数组越界，无法存储正确的数字
#include<iostream>
#include"Hugeint.h"
using namespace std;
int main()
{
	Hugeint n1(7654321);
	Hugeint n2(7891234);
	Hugeint n3("999999999999999999999999");
	Hugeint n4("754541256");
	Hugeint n5;
	
	cout << "n1 is " << n1 << "\nn2 is " << n2
		<< "\nn3 is " << n3 << "\nm4 is " << n4
		<< "\nn5 is " << n5 << "\n\n";
	


	n5 = n1 + n5;
	cout << n1 << "+" << n2 << "=" << n5 << "\n\n";

	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl<<endl;
	
	n5 = n4 * 23;
	cout << n4 << " * " << "23" << " = " << n5 << endl<<endl;

	n5 = n4 / 23;
	cout << n4 << " / " << "23" << " = " << n5 << endl<<endl;

	system("pause");
	return 0;
}