#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>

void bubble_sort(std::vector<int> & vec); // 声明函数,这个函数是写在basic.cpp中的;

using namespace std;

template <typename T> inline T* begin(vector<T> &vec) // 取vector第一个元素地址.如果vector是空的,返回0;
{
	return vec.empty() ? 0 : &vec[0];
}

int* find(std::vector<int> &vec, int value) // 查找向量中是否有和value一样的值,有的话返回指向它的指针. const std::vec... 这种写法是不通过的.
{
	for( int ix = 0; ix < vec.size(); ++ix )
		if (vec[ix] == value)
			return &vec[ ix ];
	return 0;
}

// 查找函数版本2,编写模板以应对array和vector两种情况,并且通过传递地址的方式存取元素(因为cpp不支持传递整个数组.)
template <typename T> T *find_addr(T *array1, int size, T &value) // 参数:array首地址,array大小,需要查找的元素
{
	if (!array1 || size < 1)
		return 0; // 传进来的东西啥也没有,返回0表示没找到

	for (int ix = 0; ix < size; ++ix)
		if (array1[ix] == value) // 仍然可以通过下标运算来访问数组的地址,编译器会自动处理成 *(array = ix)
			return &array1[ix]; // 找到了,返回地址
	return 0; //数组有内容,但是仍找不到;
}

template <typename IteratorType, typename elemType >
IteratorType
find_iter(IteratorType first, IteratorType last,
	const elemType &value)
{
	for (; first != last; ++first) // 从first开始 一直到last结尾;last的位置是数组最后一个值的后一位(哨兵),这样的好处是只要用"<"就能让程序终止在恰当的位置;
		if (value == *first)
			return first;
	return last;
}

int ConstPointer()
{
	/*常量指针指向一个固定内存区不会改变,但是修改此内存的值是运行的.而常量的话自己占据一块内存区,并且其值是不可更改的.*/
	std::vector<int> vec1{ 1,2,3,4,5,6,7 };
	int *p;
	p = find(vec1, 3);
	std::cout << *p << "\t" << p << " basic find\n"; 
	const int j = 5;
	// 运用模板+传址的方式传递array;
	int ia[8] = { 1,2,3,4,5,9,8,7 };
	int *pia;
	pia = &ia[0];
	int *pia_result;
	int pia_value = 3;
	pia_result = find_addr<int>(pia, 8, pia_value);
	std::cout << "template find by addr: "<<*pia_result << "\t" << pia_result << "\n";

	int *vp;
	vp = &vec1[0];
	int *vp_result;
	vp_result = find_addr<int>(begin(vec1), 7, pia_value); // 传地址只能传单个值的;
	std::cout << "template find in vector: " << *vp_result << "\t" << vp_result << "\n";

	std::list<int> ilist(ia, ia + 8); // 初始化list;
	std::list<int>::iterator iter; //iterator 具有指针的效果, 通过*tier就可以访问其指向的内容; 与指针的不同之处在于, 其(提领 * dereference)操作是通过内相关的inline函数提供.
	iter = find_iter(ilist.begin(), ilist.end(), 2);  // 
	std::cout << *iter << " iterator find \t\n";

	int i = 2;
	const int *p2 = &i; // 这是一个底层const
	//std::cout << *p2 << "\t";
	i = 3;
	//std::cout << *p2;


	//int *const p3 = &j //这样写是不行的 此时p3是顶层const 不允许指向常量


	return 0;
}

template <typename InputIterator, typename OutputIterator,
	typename ElemType, typename Comp> 
	OutputIterator
	filter(InputIterator first, InputIterator last,
		OutputIterator at, const ElemType &val, Comp pred)
{// 学习如何使用内置算法与 function object (adapter);
	while ((first =
		find_if(first, last, //find_if是内置函数
			bind2nd(pred, val))) != last) // bind2nd也是,可以输入需要的操作(less or greanter), 然后与用户需要的元素比较
	{
		// just to see what is going on ... 
		cout << "found value: " << *first << endl;
		// assign value, then advance both iterators 
		*at++ = *first++;
	}
	return at;
}


int count_occurs(const std::vector<int> &vec, int val)
{
	std::vector<int>::const_iterator iter = vec.begin();
	int occurs_count = 0;
	while ((iter = find_iter(iter, vec.end(), val)) != vec.end())
	{
		++occurs_count;
		++iter; // 找到元素之后,则从此位置再向后寻找相同元素.
	}
	return occurs_count;
}

bool less_than(int v1, int v2)
{
	return v1 < v2 ? true : false;
}

bool greater_than(int v1, int v2)
{
	return v1 > v2 ? true : false;
}

int algorithm_practice()
{
	std::vector<int> vec_random{465,155,64,165,974,651,654,498,132,164,987,651,87,165,987,324,98,135,467,135,968,465,351,361,654,684,651,354,698,71,311,513,198,405 };
	bubble_sort(vec_random);
	const int elem_size = 8;
	int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	vector<int> ivec(ia, ia + elem_size);
	// containers to hold the results of our filter() 
	int ia2[elem_size];
	vector<int> ivec2(elem_size);
	std::vector<int> vec_rout(vec_random.size());
	filter(vec_random.begin(), vec_random.end(), vec_rout.begin(), 132, less<int>());
	cout << "filtering integer array for values less than 8\n";
	filter(ia, ia + elem_size, ia2, elem_size, less<int>());
	cout << "filtering integer vector for values greater than 8\n";
	filter(ivec.begin(), ivec.end(), ivec2.begin(),
		elem_size, greater<int>());

 	return 0;
}

int map1()
{
	std::map<string, int> word_count = { {"class", 1},{"function", 5},{"template", 9} }; // 定义并用{}花括号初始化map.


	return 0;
}

int sub_main2()
{
	int temp = algorithm_practice();
	return 0;
}
