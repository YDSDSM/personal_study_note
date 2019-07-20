#include <iostream>

using namespace std;

// 基类1
class Shape
{// 类成员分为public,protected,private是为了继承方便。
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

	virtual int getArea() // 虚函数，提醒编译器不要链接到此处转而连接派生类同名函数
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
//基类2
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
// 用于演示重载而创建的类
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


// 派生类 环状继承推荐使用虚拟继承格式，否则基类可能会有多次不想要的触发
/*class D{......};
class B: virtual public D{......};
class A: virtual public D{......};
class C: public B, public A{.....};*/
class Rectangle : public Shape, public PaintCost /* 继承了基类Shape，继承方式是public（几乎不使用其他方式继承，
							   可能是因为public继承已经能应对大部分情况）,因此基类的公有成员派生类也具有*/
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
	Triangle(int a = 0, int b = 0) :Shape(a, b) { } // 显式的调用基类有参构造函数。
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
	Rectangle rec1; // 创建一个类Rectangle的对象（实例），名为rec1；

	rec1.setHeight(5);
	rec1.setWidth(8);
	
	cout << "Total area: " << rec1.getArea() << endl;
	cout << "Total paint cost RMB " << rec1.getCost(rec1.getArea()) << endl; // 这种嵌套的写法是允许的。
	return 0;
}

int overload_test()
{
	printData pd;
	pd.print(20);

	float f1 = 200.0; // 消除歧义，直接传递200.0给重载函数，可能会被误解为double类型。
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
	// 多态的使用 ---没理解。可能就是在基类写虚函数，在实现的时候用地址+指针的方式可以调用同名却不同功能的函数。
	shape = &rec; // 通过地址访问消除歧义。
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
