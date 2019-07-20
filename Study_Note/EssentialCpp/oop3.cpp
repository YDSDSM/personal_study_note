#include <iostream>
#include <string>

using namespace std;

class LibMat
{
public:
	/*��������������*/
	LibMat();
	virtual ~LibMat() // virtual ���⺯��, ���ϴ˹ؼ����������ڶ�̬;
	{
		std::cout << "LibMat::~LibMat() destructor!\n";
	}

	/*��Ա����*/
	virtual void print() const // ����const,ֻ�ڳ�Ա��������,��˼�Ǻ���������ȥ�ı�thisָ���״̬
	{
		std::cout << "LibMat::print() -- I am a LibMat object!\n";
	}

private:

};

// ��������������
LibMat::LibMat()
{
	std::cout << "LibMat::LibMat() default constructor!\n";// �����Ϣ�Ա�ʾLibMat������һ��ʵ��;

}



/*�ǳ�Ա����*/
void print(const LibMat &mat)  // LibMat�������඼�����õ�;
{
	std::cout << "in global print(): about to print mat.print()\n";
	/*��һ�л�����matʵ��ָ��Ķ�������ִ���ĸ�print()member function*/
	mat.print(); // ���mat�������������ʵ��;
}

// ������ Book �̳��� LibMat;
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

// ������ �̳���Book �����ϵ LibMat ->  Book -> AudioBook; 

class AudioBook : public Book {
public:
	AudioBook(const string &title,
		const string &author, const string &narrator)
		: Book(title, author), // ��ð�ź�����������ڳ�ʼ��;1.�������ͨ����ʽ���ø����вι��캯��,2.����ĳ�Ա����ͨ�����ŵķ�ʽ��ʼ����Ա��ֵ;
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

	cout << "--------------------\n" << "Creating a Book object to print()\n"; //С����,������һ�������븸�����˳��,ԭ�����������ڽ�������������.; �������˹���,������VS���������������.
	Book b( "The_Castle", "Franz Kafka"); // ����:�˴�����û�д������캯��
	print(b);

	cout << "*********************\n" << "Creating a LibMat object to print()\n";
	LibMat libmat; // ����LibMat��Constructor();
	print(libmat);  // ����Libmat.print();

	cout << "--------------------\n" << "Creating an AudioBook object to print()\n";
	AudioBook ab("Man Without Qualities",
		"Robert Musil", "Kenneth Meyer");
	print(ab);

	cout << "++++++++++++++++++++\n" << "Creating an Magazine object to print()\n";
	Magazine mag1("reader", "2019/07");
	print(mag1);

	return 0; // �˳��󴥷���������; //�������˳���Ҳ�����������������,����˳��:���������;����Ҳͬ���������캯��,����˳��:�ȸ���(���޲ι��캯��)������; // һ��ʵ������˳���Ǻ󴴽���������;
}