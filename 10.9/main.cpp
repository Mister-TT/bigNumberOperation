//(a)���캯�����Խ���int���ͻ���string����
//Ȼ����Сλ����integer��29������������
//string����Ҫע��-48����Ϊ����char���Ͳ���int����

//����Hugeint��Hugeint�ļӷ���
//ֻ��Ҫ����λ��С�������ϼӣ������ǽ�λ�����������ȷ��ֵ

//����string��int�ļӷ�
//���ù��캯�������ǹ����Hugeint���������мӷ�


//(b)�����Ǵ������㣬��������λ�����ܳ���30λ
//����integer����Խ�磬�޷��洢��ȷ������
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