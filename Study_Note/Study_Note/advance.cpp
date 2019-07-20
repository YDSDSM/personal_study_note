#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*Note:
模板的错误大多只在实例化的时候报告，查错依靠三个阶段：1.IDE检查语法错误；2.编译器检查（报告类型是否匹配）；3.模板实例化，会充分报错。
*/


shared_ptr<int> p1 = make_shared<int>(42);

struct SAMPLE  // 定义结构体，与class类似但又不同：1.结构体声明的变量都是public的，2.在大括号末尾要声明变量
{
	int x;
	int y;
	int add() { return x + y; }
}s1;

class MilkTea
{
public:
	MilkTea();
	~MilkTea();

	int Price;
	string Brand;

	void setPrice(int pr)
	{
		Price = pr;
	}

	void setBrand(string br)
	{
		Brand = br;
	}
	
	bool operator <(const MilkTea& MT)
	{
		return (this -> Price < MT.Price) ? true : false;
	}

private:

};

MilkTea::MilkTea()
{
}

MilkTea::~MilkTea()
{
	cout << "MilkTea is residual waste" << endl;
}
template <typename T> void swap1(T& t1, T& t2) /* declare a function template, "typename T" means
											  we could decide a specific type when we call template function.
											  T相当于模板类型参数，必须要在<>中声明*/
{
	T temT;
	temT = t1;
	t1 = t2;
	t2 = temT;
}

template <typename T> int compare_f(T& v1, T& v2)
{
	if ( v1 < v2) return -1;
	if ( v2 < v1) return 1;
	return 0;
}

/*we could declare class templates*/
template <typename T> class compare // T 会在被实例化的时候替换为具体的类，如 int,float。
//  在<>括号中 typename 和class没有什么不同，typename可能会更好看一点。
{
public:

	bool equal(T t1, T t2)
	{
		return t1 == t2;
	}

private:

};

/*C++ Primer类模板示例*/
template <typename T> class Blob
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type; // 看不懂，为啥写typename而不是T？ 
	Blob();
	Blob(std::initializer_list<T> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr < std::vector<T>> data; // data 是一个shared_ptr（一个可以shared的smart pointer)，指向以Blob的模板参数（T）为实参的vector，vector是模板。
	void check(size_type i, const std::string &msg) const;
};

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const
// 模板类的成员函数定义，以template开始，具体形式与普通的类差不多
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::back() //这是啥？ 回答: 这就是自定义的成员函数,功能就是返回数组最后一个数值.
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) { } //分类一个空的vector,将指向vector的指针保存在data中。

template <typename T>Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }


template <typename T> T& Blob<T>::operator[](size_type i) //这是啥？ 回答: 重载 []运算符 ,如 Blob[xxx] ,在实例化的时候xxx就是这里的输入参数,然后[]的意义就如目前所定义的一样
{
	check(i, "subsctipt out of range");
	return (*data)[i]; // 返回一个引用，指向用来实例化Blob的类型
}

template <typename T> inline T Min(const T& t1, const T& t2) // inline的函数模板； 
{
	return (t1 < t2) ? t1 : t2; // 编译器处理此模板时不能验证 符号“<”是否合法，因为 < 可以重载；
}

// specific template.dedicated to handling char type.
template<>class compare<char *>
{
public:
	bool equal(char* t1, char* t2)
	{
		return strcmp(t1, t2) == 0;
	}
};


/* instantiate template */
int ins_tem()
{
	int i = 39;
	int j = 20;
	cout << "i = " << i << " j = " << j << endl;
	swap1<int>(i, j); // define templete's T as int.
	cout << "i = " << i << " j = " << j << endl;
	float f1 = 19.5;
	float f2 = 21.1;
	cout << "f1 = " << f1 << " f2 = " << f2 << endl;
	swap1<float>(f1, f2);
	cout << "f1 = " << f1 << " f2 = " << f2 << endl;
	return 0;
}

int ins_class_tem()
{
	char str1[] = "Hello";
	char str2[] = "Hello";
	compare<int> c1; //call class template, c1 is a instance of class compare with type int.
	compare<char *> c2; // call class template, c2 is a specific template for handling char type.

	cout << c1.equal(1, 1) << endl;
	cout << c2.equal(str1, str2) << endl;

	return 0;
}

int ins_min()
{
	cout << "The smaller number is " << Min(2.1, 5.2) << endl;
	return 0;
}

int overload_template()
{
	
	MilkTea Coco;
	MilkTea TeaWay;
	Coco.setPrice(12);
	TeaWay.setPrice(15);

	cout << compare_f(Coco, TeaWay) << endl; // 为类MilkTea重载了 "<"运算符，并运用比较函数模板，成功。
	return 0;
	

}

int use_struct() // 结构体简单应用
{
	cout << "s1 = " << s1.add() << endl;
	s1.y = 2;
	s1.x = 5;
	cout << "s1 = " << s1.add() << endl;
	return 0;
}

int Blob_instance() // C++Primer 类模板实例 确实是成功run起来了，but why？
{
	Blob<int> squares = { 0,1,2,3,4,5,6,7,8,9 };
	for (size_t i = 0; i != squares.size(); ++i)
	{
		squares[i] = i * i;
		cout << squares[i] << endl;
	}
	return 0;
}

int main()
{
	int temp = Blob_instance();
	return 0;
}
