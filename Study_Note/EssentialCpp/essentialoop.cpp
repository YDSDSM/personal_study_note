#include <iostream>
#include <string>
#include <vector>
class Stack// �������һ��Stack(��ջ),���й���:push,pop(����ȳ�),ѯ���Ƿ�����,���Ƿ�Ϊ��,ѯ��Ԫ����Ŀ,�۲����һ����push����ֵ.
{
public:
	Stack();
	~Stack();
	// �κβ����ɹ����᷵�� true
	bool push(const std::string&elem); //bool push(const std::string&) ����ֻд������; �ش�,���ּ�����,���ܴ����ϰ汾�Ĵ������push���洫����,����ʵ���������õ�,Ϊ�����ϰ汾�Ĵ���Ҳͨ��,��ֻд������,û������.���ֲ���Ҳ����Ԫ;
	bool pop(std::string&elem);
	bool peek(std::string&elem);

	bool empty(void);

	int size(void) { return _stack ->size(); } // ������Class�ڲ�, �Զ���Ϊinline����;

	bool full(void)
	{
		return (*_stack).size() == _stack -> max_size();
	}

private:
	std::vector<std::string> *_stack; // ����Ҫ����vector����װ�����Լ�����,��ʵ��Ԥ�ڹ���
};

Stack::Stack()
{
	_stack = new std::vector<std::string>; // �ö�̬�ڴ�ķ�ʽ����_stack
}

Stack::~Stack()
{
	delete [] _stack;  // ʵ���ϼ������ǲ��ֶ��ͷ��ڴ�,��������˳���ʱ��Ҳ���Զ��ͷ���ռ�ݵ��ڴ�.��һ��д���������.
}

inline bool Stack::empty(void) // �ں����ⲿ����Ϊinline����;�ֺ����෶Χ���������,��ʾ��Stack���(������������)
{
  	return _stack -> empty();
}

bool Stack::peek(std::string&elem)
{
	if (empty()) // �յĻ�û��Ԫ�ؿ��Է���
		return false;
	elem = _stack -> back(); // �������һ��Ԫ��
	return true;
}

bool Stack::push(const std::string&elem)
{
	if (full())
		return false;
	_stack -> push_back(elem);
	return true;
}
bool Stack::pop(std::string&elem)
{
	if (empty())
		return false;
	elem = _stack -> back(); // ûɶ��ѽ
	_stack -> pop_back();
	return true;
}

int sub_main3()
{
//	Stack *ps; // ����һ��ָ����Stack��ָ��;
	Stack stack1;
	std::string peak_out;
	std::string pop_out;
	stack1.push("I");
	stack1.push("can");
	stack1.peek(peak_out);
	stack1.pop(pop_out);
	int stack_size = stack1.size();
	std::cout << "peakout = " << peak_out << " popout =  " << pop_out << " stacksize = " << stack_size << "\n";
	stack1.empty();


	return 0;
}