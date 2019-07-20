#include <iostream>
#include <string>

using namespace std;

class LibMat
{
public:
	/*构造与析构函数*/
	LibMat();
	virtual ~LibMat() // virtual 虚拟函数, 加上此关键词意在用于多态;
	{
		std::cout << "LibMat::~LibMat() destructor!\n";
	}

	/*成员函数*/
	virtual void print() const // 后置const,只在成员函数中用,意思是函数捕鱼下去改变this指针的状态
	{
		std::cout << "LibMat::print() -- I am a LibMat object!\n";
	}

private:

};

// 构造与析构函数
LibMat::LibMat()
{
	std::cout << "LibMat::LibMat() default constructor!\n";// 输出消息以表示LibMat创建了一个实例;

}



/*非成员函数*/
void print(const LibMat &mat)  // LibMat及其子类都是有用的;
{
	std::cout << "in global print(): about to print mat.print()\n";
	/*下一行会依据mat实际指向的对象决议该执行哪个print()member function*/
	mat.print(); // 这个mat可能是派生类的实例;
}

// 派生类 Book 继承于 LibMat;
class Book : public LibMat {
public:
	Book(const string &title, const string &author)
		: _title(title), _author(author) 
	{
		cout << "Book::Book(" << _title
			<< ", " << _author << ") constructor\n";
	}
	virtual ~Book() {
		cout << "Book::~Book() destructor!\n";
	}
	virtual void print() const {
		cout << "Book::print() -- I am a Book object!\n"
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << endl;
	}
	const string& title() const { return _title; }
	const string& author() const { return _author; }
protected:
	string _title;
	string _author;
};

class Magazine : public LibMat
{
public:
	Magazine(const string &title,const string &date):_title(title),_date(date)
	{
		cout << "Magazine::Magazine(" << _title << "," << _date << ") constructor\n";
	}

	virtual ~Magazine()
	{
		cout << "Magazine::~Magazine() destructor!\n";
	}

	virtual void print() const {
		cout << "Magazine::print() -- I am a Magazine object!\n"
			<< "My title is: " << _title << '\n'
			<< "My date is: " << _date << endl;
	}
	const string& title() const { return _title; }
	const string& author() const { return _date; }

	string _title;
	string _date;

private:

};

// 派生类 继承于Book 三类关系 LibMat ->  Book -> AudioBook; 

class AudioBook : public Book {
public:
	AudioBook(const string &title,
		const string &author, const string &narrator)
		: Book(title, author), // 单冒号后面的内容用于初始化;1.子类可以通过显式调用父类有参构造函数,2.子类的成员可以通过括号的方式初始化成员数值;
		_narrator(narrator)
	{
		cout << "AudioBook::AudioBook(" << _title
			<< ", " << _author
			<< ", " << _narrator
			<< ") constructor\n";
	}
	~AudioBook()
	{
		cout << "AudioBook::~AudioBook() destructor!\n";
	}
	virtual void print() const {
		cout << "AudioBook::print() -- I am an AudioBook object!\n"
			// note the direct access of the inherited 
			// data members _title and _author 
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << '\n'
			<< "My narrator is: " << _narrator << endl;
	}
	const string& narrator() const { return _narrator; }
protected:
	string _narrator;
};



int main()
{

	cout << "--------------------\n" << "Creating a Book object to print()\n"; //小插曲,交换了一下子类与父类代码顺序,原本不能运行在交换后能运行了.; 真是奇了怪了,重启了VS后可以正常运行了.
	Book b( "The_Castle", "Franz Kafka"); // 疑问:此处可能没有触发构造函数
	print(b);

	cout << "*********************\n" << "Creating a LibMat object to print()\n";
	LibMat libmat; // 触发LibMat的Constructor();
	print(libmat);  // 调用Libmat.print();

	cout << "--------------------\n" << "Creating an AudioBook object to print()\n";
	AudioBook ab("Man Without Qualities",
		"Robert Musil", "Kenneth Meyer");
	print(ab);

	cout << "++++++++++++++++++++\n" << "Creating an Magazine object to print()\n";
	Magazine mag1("reader", "2019/07");
	print(mag1);

	return 0; // 退出后触发析构函数; //子类在退出后也触发父类的析构函数,触发顺序:先子类后父类;创建也同样触发构造函数,触发顺序:先父类(的无参构造函数)后子类; // 一堆实例析构顺序是后创建的先析构;
}