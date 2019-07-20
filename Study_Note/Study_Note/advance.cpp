#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*Note:
ģ��Ĵ�����ֻ��ʵ������ʱ�򱨸棬������������׶Σ�1.IDE����﷨����2.��������飨���������Ƿ�ƥ�䣩��3.ģ��ʵ���������ֱ���
*/


shared_ptr<int> p1 = make_shared<int>(42);

struct SAMPLE  // ����ṹ�壬��class���Ƶ��ֲ�ͬ��1.�ṹ�������ı�������public�ģ�2.�ڴ�����ĩβҪ��������
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
											  T�൱��ģ�����Ͳ���������Ҫ��<>������*/
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
template <typename T> class compare // T ���ڱ�ʵ������ʱ���滻Ϊ������࣬�� int,float��
//  ��<>������ typename ��classû��ʲô��ͬ��typename���ܻ���ÿ�һ�㡣
{
public:

	bool equal(T t1, T t2)
	{
		return t1 == t2;
	}

private:

};

/*C++ Primer��ģ��ʾ��*/
template <typename T> class Blob
{
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type; // ��������Ϊɶдtypename������T�� 
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
	std::shared_ptr < std::vector<T>> data; // data ��һ��shared_ptr��һ������shared��smart pointer)��ָ����Blob��ģ�������T��Ϊʵ�ε�vector��vector��ģ�塣
	void check(size_type i, const std::string &msg) const;
};

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const
// ģ����ĳ�Ա�������壬��template��ʼ��������ʽ����ͨ������
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::back() //����ɶ�� �ش�: ������Զ���ĳ�Ա����,���ܾ��Ƿ����������һ����ֵ.
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) { } //����һ���յ�vector,��ָ��vector��ָ�뱣����data�С�

template <typename T>Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { }


template <typename T> T& Blob<T>::operator[](size_type i) //����ɶ�� �ش�: ���� []����� ,�� Blob[xxx] ,��ʵ������ʱ��xxx����������������,Ȼ��[]���������Ŀǰ�������һ��
{
	check(i, "subsctipt out of range");
	return (*data)[i]; // ����һ�����ã�ָ������ʵ����Blob������
}

template <typename T> inline T Min(const T& t1, const T& t2) // inline�ĺ���ģ�壻 
{
	return (t1 < t2) ? t1 : t2; // �����������ģ��ʱ������֤ ���š�<���Ƿ�Ϸ�����Ϊ < �������أ�
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

	cout << compare_f(Coco, TeaWay) << endl; // Ϊ��MilkTea������ "<"������������ñȽϺ���ģ�壬�ɹ���
	return 0;
	

}

int use_struct() // �ṹ���Ӧ��
{
	cout << "s1 = " << s1.add() << endl;
	s1.y = 2;
	s1.x = 5;
	cout << "s1 = " << s1.add() << endl;
	return 0;
}

int Blob_instance() // C++Primer ��ģ��ʵ�� ȷʵ�ǳɹ�run�����ˣ�but why��
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
