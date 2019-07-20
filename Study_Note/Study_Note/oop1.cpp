#include <iostream>
#include <string>  // C++中的字符串
using namespace std;

class Box // 自定义了一个类 名为Box
{
public: // 公有成员，外部可访问。
	// 构造函数与析构函数
	Box()
	{
		cout << "create a box" << endl;
		objectCount++;
		cout << "Now you have" << objectCount << "boxs" << endl;
	}
	Box(double rmb); // 类的构造函数，名字与类的名字一致。有参和无参构造函数会择其一执行，具体是哪个看是创建对象的时候否传递参数。
	~Box(void);
	// 静态成员
	static int objectCount; // 无论声明多少个类的对象，静态成员副本只有一个。
	// 公有成员
	double length;
	double width;
	double height;
	int copybox;
	// 友元函数
	friend void printmaterial(Box& box0); /*
	声明了一个友元函数，即告诉 class Box： printmaterial是友好的，可以访问private的数据。
	注意注意！！ 当想把类对象当参数传递的时候，尽量！用引用调用的方式来传递，否则在退出时会有
	不想要的析构函数被触发，触发的理由是overloaded.
	另外，函数声明与函数实现部分所描述的参数要保持一致，不然无法正确访问。
	

	// 成员函数									  */
	double getVolume2(void); // 声明外部定义的成员函数,注意：参数void是必要的


	double getVolume(void) // 类的成员函数，即定义在类的内部的函数。在没有输入参数的情况下，可能void作为输入是必须的。
	{
		return length * width * height;
	}
	
	int setmaterial(string mat1)  //想在cpp中运用字符串，得先声明头文件<string>
	{
		material = mat1;
		return 0;
	}

	int compare(Box& box)  // “&”符号避免了调用后又创建了一个属于类Box的实例，这样退出时也不会执行析构函数
	{
		return this->getVolume() > box.getVolume(); // this指针
	}
	

	// 静态成员函数 通过类名加范围解析运算符就可以访问，没有this指针，只能访问静态成员。
	static int getCount()
	{
		cout << "You have " << objectCount << " boxes" << endl;
		return 0;
	}

	Box operator++(int) // 重载后缀递增运算符，这段没写好，总是会触发构造与析构函数。
	{
		copybox++;
	}


protected: //在派生类或子类是可访问的
	double diagnol;

private: // 不可访问，只有通过公有函数访问（不是很准确的说法）
	string material;
	int *ptr;

};

Box::Box(double rmb)
{
	cout << "You get one box" << " cost RMB " << rmb << endl;
	objectCount++;
	cout << "Now you have " << objectCount << " boxes" << endl;
	copybox = 0;
}

Box::~Box(void)
{
	cout << "You lost one box" <<endl;
	objectCount--;
}


double Box::getVolume2(void) // 在外部定义类的成员函数。
{
	return length * width * height;
}


// 定义了一个子类 名为SmallBox
class SmallBox :public Box // SmallBox 是Box的派生类,因此具有父类prtected中的属性。不声明继承方式的情况下默认都是按照private继承的
{
public:
	SmallBox(); // 子类的构造函数。 疑问： 父类创建的构造函数如果是带参数的，子类实例创建会报错，不知道为什么？

	void setSmallDiagnol(double wid);
	double getSmallDiagnol(void);

};

double SmallBox::getSmallDiagnol(void)
{
	return diagnol;
}

SmallBox::SmallBox(void)// 如果在本句之后加这么一段 “:Box(5)” 则会调用父类有参构造函数，并且不再调用无参构造函数。
{
	cout << "You get a smallbox" << endl;
}

void SmallBox::setSmallDiagnol(double dia)
{
	diagnol = dia;
}

void printmaterial(Box& box0) // 友元函数， 没有增加“：：”之类的符号。 在这里 语句“ Box box0” 虽然与box3（函数中创建），但是在退出时此box0仍然会触发析构函数。-_-无语。
{
	cout << "material of box : " << box0.material << endl;  // 退出时触发析构函数
}

inline int Max(double x, double y)  // 创建了内联函数，好处是运行效率更高。另外，类内函数都是内联函数。虽然并没有显式符号说明。
{
	return (x > y) ? x : y;
}
// 初始化静态成员
int Box::objectCount = 0;

int imp_box()
{
	Box Box1(10.5);
	Box Box2(20.0); // declare box1 and box2
	Box *ptrBox; // 声明指向类的指针，这一步是必需的，没有初始化的指向类的指针不可用。
	/* 星号是间接寻址运算符，带星号的变量就是用来存地址的，前面的type的声明是告诉变量存谁的地址
	例如 int *ptr 则是用来存类型为int的变量的地址 */
	double volume1 = 0.0; // for storing box volume
	double volume2 = 0.0;

	// box1 params
	Box1.height = 5.0;
	Box1.length = 6.0;
	Box1.width = 7.0;
	Box1.setmaterial("cardboard");

	// box2 params
	Box2.height = 12;
	Box2.length = 31;
	Box2.width = 21;
	Box2.setmaterial("cardboard");

	volume1 = Box1.getVolume();
	cout << "Box1 volume is " << volume1 << endl;

	volume2 = Box2.getVolume2();
	cout << "Box2 volume is " << volume2 << "\n";

	cout << "the bigger one volume is " << Max(volume1, volume2) << endl;

	if (Box1.compare(Box2))
	{
		cout << "Box1 is bigger one" << endl;
	}
	else
	{
		cout << "Box2 is not smaller than Box1" << endl;
	}

	ptrBox = &Box1; //返回Box1的地址；读作 Box1的地址。

	cout << "Method2: Volume of Box1 " << ptrBox->getVolume() << endl; // 用成员访问运算符来访问成员。
	// ptrBox 因为存储了Box1的地址，相当于ptrBox就是其替身。这样做的好处是能让计算机明确的访问对象。
	// 因此， 通过成员访问运算符的方式去修改对象的话，修改后的内容会被保存。

	Box::getCount();

	Box Box3(8);
	Box3.setmaterial("Plasitc");
	printmaterial(Box3);

	cout << Box::objectCount << " boxes will be destory." << endl;
	return 0;
}

int sucesser_test()
{
	SmallBox box1; // 子类创建时会先执行父类的无参数构造函数，然后执行子类的构造函数。
	box1.setSmallDiagnol(5.0);
	cout << "diagnol length is " << box1.getSmallDiagnol() << endl;

	return 0;
}

int sub_main3()
{
	int temp = imp_box();
	return 0;
}