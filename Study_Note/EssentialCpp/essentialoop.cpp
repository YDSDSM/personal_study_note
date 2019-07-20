#include <iostream>
#include <string>
#include <vector>
class Stack// 动手设计一个Stack(堆栈),具有功能:push,pop(后进先出),询问是否已满,或是否为空,询问元素数目,观察最后一个被push的数值.
{
public:
	Stack();
	~Stack();
	// 任何操作成功都会返回 true
	bool push(const std::string&elem); //bool push(const std::string&) 参数只写出了类; 回答,保持兼容性,可能存在老版本的代码会往push里面传参数,但是实际上是无用的,为了让老版本的代码也通过,就只写了类型,没有名字.这种参数也叫哑元;
	bool pop(std::string&elem);
	bool peek(std::string&elem);

	bool empty(void);

	int size(void) { return _stack ->size(); } // 定义在Class内部, 自动视为inline函数;

	bool full(void)
	{
		return (*_stack).size() == _stack -> max_size();
	}

private:
	std::vector<std::string> *_stack; // 还是要借用vector来封装我们自己的类,以实现预期功能
};

Stack::Stack()
{
	_stack = new std::vector<std::string>; // 用动态内存的方式管理_stack
}

Stack::~Stack()
{
	delete [] _stack;  // 实际上即便我们不手动释放内存,类对象在退出的时候也会自动释放所占据的内存.这一段写来纯粹好玩.
}

inline bool Stack::empty(void) // 在函数外部定义为inline函数;分好是类范围决议运算符,表示是Stack类的(而不是其他类)
{
  	return _stack -> empty();
}

bool Stack::peek(std::string&elem)
{
	if (empty()) // 空的话没有元素可以返回
		return false;
	elem = _stack -> back(); // 返回最后一个元素
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
	elem = _stack -> back(); // 没啥用呀
	_stack -> pop_back();
	return true;
}

int sub_main3()
{
//	Stack *ps; // 定义一个指向类Stack的指针;
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