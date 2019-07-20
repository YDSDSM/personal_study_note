#include <iostream>
using namespace std;
/*
ע���ԡ�/*����ͷ���ԡ�*-/��β��С�̸���Ҫɾȥ�ģ���
*/

#define HEIGHT 180
#define NEWLINE "\n"
const int WEIGHT = 140;  //���ɱ��޸�
static int count1 = 24; /*ȫ�ֱ���*/
int g = 20;
int count2;
extern void write_extern();


void static_test(void)
{
	static int i = 5; //�ֲ���̬����
	i++;
	cout << "����iΪ" << i;
	cout << ",����countΪ" << count1 << endl;
}
int st_main()
{
	while (count1--)
	{
		static_test();
	}
	return 0;
}

int HelloWorld()
{
	cout << "Hello," 
		 << "world!" 
		 << endl;  /* ����ַ��� */
	return 0;
}


int vartest()
{
	int g = 10;
	cout << g << endl;
	cout << NEWLINE << endl;
	return 0;
}


int difference_int()
{
	short int i; // 16λ
	short unsigned int j; // �޷��ŵ�
	
	j = 50000; //1100 0011 0101 0000��ת�������������ֵΪ��0011 1100 1011 0000=15536

	i = j;
	cout << i << " " << j;
	return 0;
}

int extern_test()
{
	count2 = 5;
	write_extern();
	return 0;
}

int basic_compute()
{
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	cout << "c = " << c << endl;
	c = a - b;
	cout << "c = " << c << endl;
	c = a * b;
	cout << "c = " << c << endl;
	c = a / b;
	cout << "c = " << c << endl;
	c = a % b;
	cout << "c = " << c << endl;

	c = a++; // ��һ�ν��뾹Ȼ��û�õġ�
	c = a++;
	cout << "c = " << c << endl;
	c = b--;
	cout << "c = " << c << endl;
	return 0;
}

int relation_compute()
{
	int a1 = 24, b1 = 10, c1;

	if (a1 == b1)
	{
		cout << "a1 = b1" << endl;
	}
	else
	{
		cout << "a1 �� b1" << endl;
	}

	if (a1 > b1)
	{
		cout << "a1 > b1" << endl;
	}
	else
	{
		cout << "a1 < b1" << endl;
	}
	return 0;
}

int bin_compute()
{
	unsigned int a = 60;      // 60 = 0011 1100  
	unsigned int b = 13;      // 13 = 0000 1101
	int c = 0;

	c = a & b;             // 12 = 0000 1100
	cout << "Line 1 - c ��ֵ�� " << c << endl;

	c = a | b;             // 61 = 0011 1101
	cout << "Line 2 - c ��ֵ�� " << c << endl;

	c = a ^ b;             // 49 = 0011 0001
	cout << "Line 3 - c ��ֵ�� " << c << endl;

	c = ~a;                // -61 = 1100 0011
	cout << "Line 4 - c ��ֵ�� " << c << endl;

	c = a << 2;            // 240 = 1111 0000
	cout << "Line 5 - c ��ֵ�� " << c << endl;

	c = a >> 2;            // 15 = 0000 1111
	cout << "Line 6 - c ��ֵ�� " << c << endl;

	return 0;
}

int while_test()
{
	int a2 = 10;
	while (a2  < 20) // while(condition) {stament(s);}
	{
		if (a2 == 14)
		{
			a2 += 1; // ��д���벻��ѭ����
			continue;
		}
		cout << "a2 = " << a2 << endl;
		a2++;
		if (a2 > 17)
		{
			break;
		}
	}
	return 0;
}

int for_test()
{
	for (int a3 = 2; a3 < 20; a3++) //for(init; condition; increment) init--��ʼ������increment--����ѭ�����Ʊ���
	{
		cout << "a3 = " << a3 << endl;
	}

	return 0;
}

int cpp11_for_test()
{
	int my_array[5] = { 1, 2, 3, 4, 5 };
	// ÿ������Ԫ�س��� 2
	for (int &x : my_array)
	{
		x *= 2;
		cout << x << endl;
	}
	// auto ����Ҳ�� C++11 �±�׼�еģ������Զ���ȡ����������
	for (auto &x : my_array) 
	{
		x *= 2;
		cout << x << endl;
	}
	return 0;
}

int dw_test()
{
	int a4 = 17;
	do // ȷ���������ٱ�ִ��һ�Σ�
	{
		cout << "a4 = " << a4 << endl;
		a4++;
	}
	while (a4 < 19);
	return 0;
}

int if_test()
{
	int a5 = 1, b5 = 2;
	if (a5 == 1)
	{
		cout << "a5 = " << a5 << endl;
		if (b5 = 2)
		{
			cout << "b5 = " << b5 << endl;
		}
	}
	return 0;
}

int switch_test()
{
	// �ֲ���������
	char grade = 'A';

	switch (grade)
	{
	case 'A':
		cout << "�ܰ���" << endl;
		break;
	case 'B':
		cout << "����" << endl;
		break;
	case 'C':
		cout << "���ú�" << endl;
		break;
	case 'D':
		cout << "��ͨ����" << endl;
		break;
	case 'F':
		cout << "�������һ��" << endl;
		break;
	default:
		cout << "��Ч�ĳɼ�" << endl;
	}
	cout << "���ĳɼ��� " << grade << endl;
	return 0;
}
