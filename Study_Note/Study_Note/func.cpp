#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

#define TIMESIZE 26

using namespace std;


// 以下内容从 “C++函数” 开始

/* 定义函数
return_type function_name( parameter list )
{
   body of the function
}
*/

double balance[5] = { 1000.0, 2.0, 3.4, 7.0, 50.0 };
/* 声明数组，语法： type arrayName[ arraySize1 ][ arraySize2 ][ arraySize3 ]...;
多维数组跟Python的Ndarray类似。
*/
int array2d[3][4] = 
{
{0, 1, 2, 3},   /*  初始化索引号为 0 的行 */
{4, 5, 6, 7},   /*  初始化索引号为 1 的行 */
{8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};
int array2[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 }; //array2d 和array2生成的数组是等价的。利用索引的方式可以访问二维数组

int max(int a1, int b1) // 自定义函数
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

void swap(int *x, int *y) // 测试指针调用, 当调用此函数时，建议使用 &x方式输入参数。
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	
	return;
}
/* Lambda函数与表达式
[capture](parameters)->return-type{body}
*/

int math_compute()
{
	// 数字定义
	short  s = 10;
	int    i = -1000;
	long   l = 100000;
	float  f = 230.47;
	double d = 200.374;

	// 数学运算
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
	srand((unsigned)time(NULL)); // 这句对生成随机数有什么用？
	for (i = 0; i < 10; i++)
	{
		j = rand();
		cout << "random out " << j << endl;
	}

	return 0;
}

int *getRandom() //注意有星号
{
	static int r[10];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}
	return r; // 返回值是指向数组的指针
}

int userandom()
{
	int *p;

	p = getRandom(); // 得到生成的数组的指针
	cout << "************" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << endl; // 这里对数组的访问要借用返回数组的指针，一位一位的从内存读取数据。
	}
	return 0;
}

int char_func1()
{
	string str1 = "Hello";
	string str2 = "World";
	string str3;
	int  len;

	// 复制 str1 到 str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// 连接 str1 和 str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// 连接后，str3 的总长度
	len = str3.size();
	cout << "str3.size :  " << len << endl;

	return 0;
}

int basic_pointer()
{
	int var1;
	char var2[10];

	cout << "var1 变量地址： " << &var1 << endl; 
	cout << "var2 变量地址：" << &var2 << endl; //要想存储变量地址的变量要先声明，语法：type *var-name;
	return 0;  // 访问指针所指向的数值时也用“*”号来查找。
}

int basic_pointer2()
{
	int  var = 20;   // 实际变量的声明
	int  *ip;        // 指针变量的声明

	ip = &var;       // 在指针变量中存储 var 的地址

	cout << "Value of var variable: ";
	cout << var << endl;

	// 输出在指针变量中存储的地址
	cout << "Address stored in ip variable: ";
	cout << ip << endl;

	// 访问指针中地址的值
	cout << "Value of *ip variable: ";
	cout << *ip << endl;

	return 0;
}

int reference()
{
	// 声明简单的变量
	int    i;
	double d;

	// 声明引用变量
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

	// 基于当前系统的当前日期/时间
	time_t now = time(0);

	// 把 now 转换为字符串形式
	ctime_s(dt,100,&now); // 所谓的安全写法，看不懂到底为何要这样。

	cout << "本地日期和时间：" << dt << endl;

	// 把 now 转换为 tm 结构
	gmtime_s(&tmnow, &now);
	asctime_s(dt, &tmnow);
	cout << "UTC 日期和时间：" << dt << endl;
	return (0);
}

int instance_stream()
{
	char name[50];

	cout << "请输入您的名称:";
	cin >> name ;
	cout << "您的名称是： " << name << endl;
	return 0;
}
