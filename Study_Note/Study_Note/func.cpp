#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

#define TIMESIZE 26

using namespace std;


// �������ݴ� ��C++������ ��ʼ

/* ���庯��
return_type function_name( parameter list )
{
   body of the function
}
*/

double balance[5] = { 1000.0, 2.0, 3.4, 7.0, 50.0 };
/* �������飬�﷨�� type arrayName[ arraySize1 ][ arraySize2 ][ arraySize3 ]...;
��ά�����Python��Ndarray���ơ�
*/
int array2d[3][4] = 
{
{0, 1, 2, 3},   /*  ��ʼ��������Ϊ 0 ���� */
{4, 5, 6, 7},   /*  ��ʼ��������Ϊ 1 ���� */
{8, 9, 10, 11}   /*  ��ʼ��������Ϊ 2 ���� */
};
int array2[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 }; //array2d ��array2���ɵ������ǵȼ۵ġ����������ķ�ʽ���Է��ʶ�ά����

int max(int a1, int b1) // �Զ��庯��
{
	int result;
	if (a1 > b1)
	{
		result = a1;
	}
	else
	{
		result = b1;
	}

	return result;
}

void swap(int *x, int *y) // ����ָ�����, �����ô˺���ʱ������ʹ�� &x��ʽ���������
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	
	return;
}
/* Lambda��������ʽ
[capture](parameters)->return-type{body}
*/

int math_compute()
{
	// ���ֶ���
	short  s = 10;
	int    i = -1000;
	long   l = 100000;
	float  f = 230.47;
	double d = 200.374;

	// ��ѧ����
	cout << "sin(d) :" << sin(d) << endl;
	cout << "abs(i)  :" << abs(i) << endl;
	cout << "floor(d) :" << floor(d) << endl;
	cout << "sqrt(f) :" << sqrt(f) << endl;
	cout << "pow( d, 2) :" << pow(d, 2) << endl;

	return 0;
}

int rand_test()
{
	int i, j;
	srand((unsigned)time(NULL)); // ���������������ʲô�ã�
	for (i = 0; i < 10; i++)
	{
		j = rand();
		cout << "random out " << j << endl;
	}

	return 0;
}

int *getRandom() //ע�����Ǻ�
{
	static int r[10];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}
	return r; // ����ֵ��ָ�������ָ��
}

int userandom()
{
	int *p;

	p = getRandom(); // �õ����ɵ������ָ��
	cout << "************" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << endl; // ���������ķ���Ҫ���÷��������ָ�룬һλһλ�Ĵ��ڴ��ȡ���ݡ�
	}
	return 0;
}

int char_func1()
{
	string str1 = "Hello";
	string str2 = "World";
	string str3;
	int  len;

	// ���� str1 �� str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// ���� str1 �� str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// ���Ӻ�str3 ���ܳ���
	len = str3.size();
	cout << "str3.size :  " << len << endl;

	return 0;
}

int basic_pointer()
{
	int var1;
	char var2[10];

	cout << "var1 ������ַ�� " << &var1 << endl; 
	cout << "var2 ������ַ��" << &var2 << endl; //Ҫ��洢������ַ�ı���Ҫ���������﷨��type *var-name;
	return 0;  // ����ָ����ָ�����ֵʱҲ�á�*���������ҡ�
}

int basic_pointer2()
{
	int  var = 20;   // ʵ�ʱ���������
	int  *ip;        // ָ�����������

	ip = &var;       // ��ָ������д洢 var �ĵ�ַ

	cout << "Value of var variable: ";
	cout << var << endl;

	// �����ָ������д洢�ĵ�ַ
	cout << "Address stored in ip variable: ";
	cout << ip << endl;

	// ����ָ���е�ַ��ֵ
	cout << "Value of *ip variable: ";
	cout << *ip << endl;

	return 0;
}

int reference()
{
	// �����򵥵ı���
	int    i;
	double d;

	// �������ñ���
	int&    r = i;
	double& s = d;

	i = 5;
	cout << "Value of i : " << i << endl;
	cout << "Value of i reference : " << r << endl;

	d = 11.7;
	cout << "Value of d : " << d << endl;
	cout << "Value of d reference : " << s << endl;

	return 0;
}

int what_time_is_it()
{
	struct tm tmnow;
	char dt[100];

	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	time_t now = time(0);

	// �� now ת��Ϊ�ַ�����ʽ
	ctime_s(dt,100,&now); // ��ν�İ�ȫд��������������Ϊ��Ҫ������

	cout << "�������ں�ʱ�䣺" << dt << endl;

	// �� now ת��Ϊ tm �ṹ
	gmtime_s(&tmnow, &now);
	asctime_s(dt, &tmnow);
	cout << "UTC ���ں�ʱ�䣺" << dt << endl;
	return (0);
}

int instance_stream()
{
	char name[50];

	cout << "��������������:";
	cin >> name ;
	cout << "���������ǣ� " << name << endl;
	return 0;
}
