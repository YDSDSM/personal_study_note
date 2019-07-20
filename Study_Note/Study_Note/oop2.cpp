#include <iostream>

using namespace std;

// ����1
class Shape
{// ���Ա��Ϊpublic,protected,private��Ϊ�˼̳з��㡣
public:
	Shape();
	~Shape();
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}

	void setHeight(int h)
	{
		height = h;
	}
	void setWidth(int w)
	{
		width = w;
	}

	virtual int getArea() // �麯�������ѱ�������Ҫ���ӵ��˴�ת������������ͬ������
	{
		cout << "Parent class area : " << endl;
		return 0;
	}

protected:
	int height;
	int width;

private:

};

Shape::Shape()
{
	cout << "base class called." << endl;
}

Shape::~Shape()
{
	cout << "base class exit." << endl;
}
//����2
class PaintCost
{
public:
	PaintCost();
	~PaintCost();

	int getCost(int area)
	{
		return area * 70;
	}
private:

};

PaintCost::PaintCost()
{
}

PaintCost::~PaintCost()
{
}
// ������ʾ���ض���������
class printData
{
public:
	printData();
	~printData();

	void print(int i)
	{
		cout << "print integer " << i << endl;
	}

	void print(float f)
	{
		cout << "print float " << f << endl;
	}

	void print(char c[])
	{
		cout << "print character " << c << endl;
	}

private:

};

printData::printData()
{
}

printData::~printData()
{
}


// ������ ��״�̳��Ƽ�ʹ������̳и�ʽ�����������ܻ��ж�β���Ҫ�Ĵ���
/*class D{......};
class B: virtual public D{......};
class A: virtual public D{......};
class C: public B, public A{.....};*/
class Rectangle : public Shape, public PaintCost /* �̳��˻���Shape���̳з�ʽ��public��������ʹ��������ʽ�̳У�
							   ��������Ϊpublic�̳��Ѿ���Ӧ�Դ󲿷������,��˻���Ĺ��г�Ա������Ҳ����*/
{
public:
	Rectangle(int a = 0, int b = 0):Shape(a, b){ }
	int getArea()
	{
		int area1;
		area1 = width * height;
		cout << "Rec area = " << area1 << endl;
		return (area1);
	}
};

class Triangle : public Shape
{
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { } // ��ʽ�ĵ��û����вι��캯����
	~Triangle();

	int getArea()
	{
		int area1;
		area1 = width * height / 2;
		cout << "Tri area = " << area1 << endl;
		return (area1);
	}

private:

};

Triangle::~Triangle()
{
}

int successor_test()
{
	Rectangle rec1; // ����һ����Rectangle�Ķ���ʵ��������Ϊrec1��

	rec1.setHeight(5);
	rec1.setWidth(8);
	
	cout << "Total area: " << rec1.getArea() << endl;
	cout << "Total paint cost RMB " << rec1.getCost(rec1.getArea()) << endl; // ����Ƕ�׵�д��������ġ�
	return 0;
}

int overload_test()
{
	printData pd;
	pd.print(20);

	float f1 = 200.0; // �������壬ֱ�Ӵ���200.0�����غ��������ܻᱻ���Ϊdouble���͡�
	pd.print(f1);

	char c1[] = "Hello World";
	pd.print(c1);
	return 0;
}

int polymorphic()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(3, 4);
	// ��̬��ʹ�� ---û��⡣���ܾ����ڻ���д�麯������ʵ�ֵ�ʱ���õ�ַ+ָ��ķ�ʽ���Ե���ͬ��ȴ��ͬ���ܵĺ�����
	shape = &rec; // ͨ����ַ�����������塣
	shape->getArea();

	shape = &tri;
	shape->getArea();

	return 0;
}

int sub_main5()
{
	int temp = polymorphic();
	return 0;
}
