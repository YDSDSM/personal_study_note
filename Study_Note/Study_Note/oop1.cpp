#include <iostream>
#include <string>  // C++�е��ַ���
using namespace std;

class Box // �Զ�����һ���� ��ΪBox
{
public: // ���г�Ա���ⲿ�ɷ��ʡ�
	// ���캯������������
	Box()
	{
		cout << "create a box" << endl;
		objectCount++;
		cout << "Now you have" << objectCount << "boxs" << endl;
	}
	Box(double rmb); // ��Ĺ��캯�����������������һ�¡��вκ��޲ι��캯��������һִ�У��������ĸ����Ǵ��������ʱ��񴫵ݲ�����
	~Box(void);
	// ��̬��Ա
	static int objectCount; // �����������ٸ���Ķ��󣬾�̬��Ա����ֻ��һ����
	// ���г�Ա
	double length;
	double width;
	double height;
	int copybox;
	// ��Ԫ����
	friend void printmaterial(Box& box0); /*
	������һ����Ԫ������������ class Box�� printmaterial���Ѻõģ����Է���private�����ݡ�
	ע��ע�⣡�� ���������󵱲������ݵ�ʱ�򣬾����������õ��õķ�ʽ�����ݣ��������˳�ʱ����
	����Ҫ������������������������������overloaded.
	���⣬���������뺯��ʵ�ֲ����������Ĳ���Ҫ����һ�£���Ȼ�޷���ȷ���ʡ�
	

	// ��Ա����									  */
	double getVolume2(void); // �����ⲿ����ĳ�Ա����,ע�⣺����void�Ǳ�Ҫ��


	double getVolume(void) // ��ĳ�Ա������������������ڲ��ĺ�������û���������������£�����void��Ϊ�����Ǳ���ġ�
	{
		return length * width * height;
	}
	
	int setmaterial(string mat1)  //����cpp�������ַ�������������ͷ�ļ�<string>
	{
		material = mat1;
		return 0;
	}

	int compare(Box& box)  // ��&�����ű����˵��ú��ִ�����һ��������Box��ʵ���������˳�ʱҲ����ִ����������
	{
		return this->getVolume() > box.getVolume(); // thisָ��
	}
	

	// ��̬��Ա���� ͨ�������ӷ�Χ����������Ϳ��Է��ʣ�û��thisָ�룬ֻ�ܷ��ʾ�̬��Ա��
	static int getCount()
	{
		cout << "You have " << objectCount << " boxes" << endl;
		return 0;
	}

	Box operator++(int) // ���غ�׺��������������ûд�ã����ǻᴥ������������������
	{
		copybox++;
	}


protected: //��������������ǿɷ��ʵ�
	double diagnol;

private: // ���ɷ��ʣ�ֻ��ͨ�����к������ʣ����Ǻ�׼ȷ��˵����
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


double Box::getVolume2(void) // ���ⲿ������ĳ�Ա������
{
	return length * width * height;
}


// ������һ������ ��ΪSmallBox
class SmallBox :public Box // SmallBox ��Box��������,��˾��и���prtected�е����ԡ��������̳з�ʽ�������Ĭ�϶��ǰ���private�̳е�
{
public:
	SmallBox(); // ����Ĺ��캯���� ���ʣ� ���ഴ���Ĺ��캯������Ǵ������ģ�����ʵ�������ᱨ����֪��Ϊʲô��

	void setSmallDiagnol(double wid);
	double getSmallDiagnol(void);

};

double SmallBox::getSmallDiagnol(void)
{
	return diagnol;
}

SmallBox::SmallBox(void)// ����ڱ���֮�����ôһ�� ��:Box(5)�� �����ø����вι��캯�������Ҳ��ٵ����޲ι��캯����
{
	cout << "You get a smallbox" << endl;
}

void SmallBox::setSmallDiagnol(double dia)
{
	diagnol = dia;
}

void printmaterial(Box& box0) // ��Ԫ������ û�����ӡ�������֮��ķ��š� ������ ��䡰 Box box0�� ��Ȼ��box3�������д��������������˳�ʱ��box0��Ȼ�ᴥ������������-_-���
{
	cout << "material of box : " << box0.material << endl;  // �˳�ʱ������������
}

inline int Max(double x, double y)  // �����������������ô�������Ч�ʸ��ߡ����⣬���ں�������������������Ȼ��û����ʽ����˵����
{
	return (x > y) ? x : y;
}
// ��ʼ����̬��Ա
int Box::objectCount = 0;

int imp_box()
{
	Box Box1(10.5);
	Box Box2(20.0); // declare box1 and box2
	Box *ptrBox; // ����ָ�����ָ�룬��һ���Ǳ���ģ�û�г�ʼ����ָ�����ָ�벻���á�
	/* �Ǻ��Ǽ��Ѱַ����������Ǻŵı��������������ַ�ģ�ǰ���type�������Ǹ��߱�����˭�ĵ�ַ
	���� int *ptr ��������������Ϊint�ı����ĵ�ַ */
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

	ptrBox = &Box1; //����Box1�ĵ�ַ������ Box1�ĵ�ַ��

	cout << "Method2: Volume of Box1 " << ptrBox->getVolume() << endl; // �ó�Ա��������������ʳ�Ա��
	// ptrBox ��Ϊ�洢��Box1�ĵ�ַ���൱��ptrBox�����������������ĺô������ü������ȷ�ķ��ʶ���
	// ��ˣ� ͨ����Ա����������ķ�ʽȥ�޸Ķ���Ļ����޸ĺ�����ݻᱻ���档

	Box::getCount();

	Box Box3(8);
	Box3.setmaterial("Plasitc");
	printmaterial(Box3);

	cout << Box::objectCount << " boxes will be destory." << endl;
	return 0;
}

int sucesser_test()
{
	SmallBox box1; // ���ഴ��ʱ����ִ�и�����޲������캯����Ȼ��ִ������Ĺ��캯����
	box1.setSmallDiagnol(5.0);
	cout << "diagnol length is " << box1.getSmallDiagnol() << endl;

	return 0;
}

int sub_main3()
{
	int temp = imp_box();
	return 0;
}