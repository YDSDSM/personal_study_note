#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>

void bubble_sort(std::vector<int> & vec); // ��������,���������д��basic.cpp�е�;

using namespace std;

template <typename T> inline T* begin(vector<T> &vec) // ȡvector��һ��Ԫ�ص�ַ.���vector�ǿյ�,����0;
{
	return vec.empty() ? 0 : &vec[0];
}

int* find(std::vector<int> &vec, int value) // �����������Ƿ��к�valueһ����ֵ,�еĻ�����ָ������ָ��. const std::vec... ����д���ǲ�ͨ����.
{
	for( int ix = 0; ix < vec.size(); ++ix )
		if (vec[ix] == value)
			return &vec[ ix ];
	return 0;
}

// ���Һ����汾2,��дģ����Ӧ��array��vector�������,����ͨ�����ݵ�ַ�ķ�ʽ��ȡԪ��(��Ϊcpp��֧�ִ�����������.)
template <typename T> T *find_addr(T *array1, int size, T &value) // ����:array�׵�ַ,array��С,��Ҫ���ҵ�Ԫ��
{
	if (!array1 || size < 1)
		return 0; // �������Ķ���ɶҲû��,����0��ʾû�ҵ�

	for (int ix = 0; ix < size; ++ix)
		if (array1[ix] == value) // ��Ȼ����ͨ���±���������������ĵ�ַ,���������Զ������ *(array = ix)
			return &array1[ix]; // �ҵ���,���ص�ַ
	return 0; //����������,�������Ҳ���;
}

template <typename IteratorType, typename elemType >
IteratorType
find_iter(IteratorType first, IteratorType last,
	const elemType &value)
{
	for (; first != last; ++first) // ��first��ʼ һֱ��last��β;last��λ�����������һ��ֵ�ĺ�һλ(�ڱ�),�����ĺô���ֻҪ��"<"�����ó�����ֹ��ǡ����λ��;
		if (value == *first)
			return first;
	return last;
}

int ConstPointer()
{
	/*����ָ��ָ��һ���̶��ڴ�������ı�,�����޸Ĵ��ڴ��ֵ�����е�.�������Ļ��Լ�ռ��һ���ڴ���,������ֵ�ǲ��ɸ��ĵ�.*/
	std::vector<int> vec1{ 1,2,3,4,5,6,7 };
	int *p;
	p = find(vec1, 3);
	std::cout << *p << "\t" << p << " basic find\n"; 
	const int j = 5;
	// ����ģ��+��ַ�ķ�ʽ����array;
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
	vp_result = find_addr<int>(begin(vec1), 7, pia_value); // ����ַֻ�ܴ�����ֵ��;
	std::cout << "template find in vector: " << *vp_result << "\t" << vp_result << "\n";

	std::list<int> ilist(ia, ia + 8); // ��ʼ��list;
	std::list<int>::iterator iter; //iterator ����ָ���Ч��, ͨ��*tier�Ϳ��Է�����ָ�������; ��ָ��Ĳ�֮ͬ������, ��(���� * dereference)������ͨ������ص�inline�����ṩ.
	iter = find_iter(ilist.begin(), ilist.end(), 2);  // 
	std::cout << *iter << " iterator find \t\n";

	int i = 2;
	const int *p2 = &i; // ����һ���ײ�const
	//std::cout << *p2 << "\t";
	i = 3;
	//std::cout << *p2;


	//int *const p3 = &j //����д�ǲ��е� ��ʱp3�Ƕ���const ������ָ����


	return 0;
}

template <typename InputIterator, typename OutputIterator,
	typename ElemType, typename Comp> 
	OutputIterator
	filter(InputIterator first, InputIterator last,
		OutputIterator at, const ElemType &val, Comp pred)
{// ѧϰ���ʹ�������㷨�� function object (adapter);
	while ((first =
		find_if(first, last, //find_if�����ú���
			bind2nd(pred, val))) != last) // bind2ndҲ��,����������Ҫ�Ĳ���(less or greanter), Ȼ�����û���Ҫ��Ԫ�رȽ�
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
		++iter; // �ҵ�Ԫ��֮��,��Ӵ�λ�������Ѱ����ͬԪ��.
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
	std::map<string, int> word_count = { {"class", 1},{"function", 5},{"template", 9} }; // ���岢��{}�����ų�ʼ��map.


	return 0;
}

int sub_main2()
{
	int temp = algorithm_practice();
	return 0;
}
