#include <iostream>
/*实现4x4MatrixClass 具有A.(done)矩阵加法,B.(done)矩阵乘法,C.(done)打印函数print(),D.(done)符合运算符 += 一组
支持下表操作的function call 如
E.float& operator() (int row. int column);
F.float operator() (int row, int column) const;
提供default constructor,G(done).可选择性地接受16个数据值. H(done).再提供一个constructor 可接受一个拥有16个元素的数组

现状,除了function call,别的都做好啦;
*/

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(double arr[16]); // 接受16个元素的数组的构造函数
	Matrix4x4(double d00, double d01, double d02, double d03,
		double d10, double d11, double d12, double d13,
		double d20, double d21, double d22, double d23,
		double d30, double d31, double d32, double d33);
	~Matrix4x4();
	bool print(int i, int j);
	bool print(void);
	Matrix4x4 operator+(const Matrix4x4& mat1);
	Matrix4x4 operator*(const Matrix4x4& mat1);
	Matrix4x4 operator+=(const Matrix4x4& mat1);

private:
	//double mat4x4[4][4]; //初始化一个4x4的二位数组,形似矩阵; 本例采用指针的方式来访问数组
	double mat4x4[16]; // C++不允许使用一个数组去初始化另一个数组;

	double *ptr_mat; // 操纵指针一定要管理好指针的指向

};
//构造与析构函数:
Matrix4x4::Matrix4x4():ptr_mat(&mat4x4[0])
{
	//ptr_mat = &mat4x4[0]; // 如果没有传值的话,指针就为空; 另一种方法初始化之在函数后面加冒号
	for (int ix = 0; ix < 16; ++ix)
	{
		ptr_mat[ix] = 0; //全部装载0;
	}
}

Matrix4x4::Matrix4x4(double d00, double d01, double d02, double d03,
	double d10, double d11, double d12, double d13,
	double d20, double d21, double d22, double d23,
	double d30, double d31, double d32, double d33):ptr_mat(&mat4x4[0]) //完成G
{
	// double mat4x4[16]; // C++不允许使用一个数组去初始化另一个数组; 这样写是没用的;此时的mat4x4相当于存储在动态内存,当构造函数完成后,这块内存区域就会被释放掉;
	//ptr_mat = &mat4x4[0];// 指针指向mat4x4首位元素第一个位置;
	ptr_mat[0] = d00;	ptr_mat[1] = d01;	ptr_mat[2] = d02;	ptr_mat[3] = d03;
	ptr_mat[4] = d10;	ptr_mat[5] = d11;	ptr_mat[6] = d12;	ptr_mat[7] = d13;
	ptr_mat[8] = d20;	ptr_mat[9] = d21;	ptr_mat[10] = d22;	ptr_mat[11] = d23;
	ptr_mat[12] = d30;	ptr_mat[13] = d31;	ptr_mat[14] = d32;	ptr_mat[15] = d33;
}

Matrix4x4::Matrix4x4(double arr[16]):ptr_mat(&mat4x4[0]) // 完成H
{
	//ptr_mat = &mat4x4[0];// 指针指向mat4x4首位元素第一个位置;
	for (int ix = 0; ix < 16 ; ++ix)
	{
		ptr_mat[ix] = arr[ix];
	}
}


Matrix4x4::~Matrix4x4()
{
}

// 一般的成员函数
bool Matrix4x4::print(int i, int j)
{
	//if (*ptr_mat == NULL)
	//	return false;
	ptr_mat = &mat4x4[0];
	std::cout << ptr_mat[i * 4 + j] << "\n";
	return true;
}

bool Matrix4x4::print(void)
{
	//if (*ptr_mat == NULL)
	//{
	//	return false;
	//}
	ptr_mat = &mat4x4[0];
	int temp;
	for (int ix = 0; ix < 4; ++ix)
	{
		for (int jy = 0; jy < 4; ++jy)
		{
			temp = ix * 4 + jy;
			std::cout << ptr_mat[temp] << "\t";
		}
		std::cout << "\t\n";
	}
	return true;
}

// 重载运算符
Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat1) // 验证成功； 
{
	Matrix4x4 mat2;
	for (int ix = 0; ix < 16; ++ix)
	{
		mat2.ptr_mat[ix] = this->ptr_mat[ix] + mat1.ptr_mat[ix]; // 这样的赋值只是暂时的,退出后数据又被刷掉了
	}
	return mat2;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat1)// 验证成功;
{
	Matrix4x4 mat2; 
	for (int ix = 0; ix < 4; ++ix)
	{
		for (int jy = 0; jy < 4; ++jy)
		{
			for (int kz = 0; kz < 4; ++kz)
				mat2.ptr_mat[ix * 4 + jy] += (this->ptr_mat[ix * 4 + kz])*(mat1.ptr_mat[kz * 4 + jy]);
		}
	}
	return mat2;
}

Matrix4x4 Matrix4x4::operator+=(const Matrix4x4& mat1) // 验证成功.
{
	for (int ix = 0; ix < 16; ++ix)
	{
		this->ptr_mat[ix] += mat1.ptr_mat[ix]; // 这样的赋值只是暂时的,退出后指针就飘了;
	}
	return *this;
}

int sub_main4()
{
	double array1[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//double *parr;
	double array2[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	// int array3[4][4](array2); 这样写是不行的;
	Matrix4x4 mat1(array2);
	Matrix4x4 mat2(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	
	mat1.print(2, 3); // 访问完一次内存就被冲掉了. 为什么? 因为最初版本存储数据的区域实际上在构造函数执行完后就释放了,猜测是由于系统运行足够快,因此赶在刷新之前读取了一次要显示的内容.
	mat1.print(0, 0);
	mat1.print();
	
	Matrix4x4 mat_plus;
	mat_plus = mat1 + mat2;
	mat_plus.print();
	
	Matrix4x4 mat_multiply;
	mat_multiply = mat1 * mat2;
	mat_multiply.print();

	Matrix4x4 mat_pluseq;
	mat_pluseq += mat2;
	mat_pluseq.print();

	return 0;
}

