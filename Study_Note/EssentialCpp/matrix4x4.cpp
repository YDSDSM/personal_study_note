#include <iostream>
/*ʵ��4x4MatrixClass ����A.(done)����ӷ�,B.(done)����˷�,C.(done)��ӡ����print(),D.(done)��������� += һ��
֧���±������function call ��
E.float& operator() (int row. int column);
F.float operator() (int row, int column) const;
�ṩdefault constructor,G(done).��ѡ���Եؽ���16������ֵ. H(done).���ṩһ��constructor �ɽ���һ��ӵ��16��Ԫ�ص�����

��״,����function call,��Ķ�������;
*/

class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(double arr[16]); // ����16��Ԫ�ص�����Ĺ��캯��
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
	//double mat4x4[4][4]; //��ʼ��һ��4x4�Ķ�λ����,���ƾ���; ��������ָ��ķ�ʽ����������
	double mat4x4[16]; // C++������ʹ��һ������ȥ��ʼ����һ������;

	double *ptr_mat; // ����ָ��һ��Ҫ�����ָ���ָ��

};
//��������������:
Matrix4x4::Matrix4x4():ptr_mat(&mat4x4[0])
{
	//ptr_mat = &mat4x4[0]; // ���û�д�ֵ�Ļ�,ָ���Ϊ��; ��һ�ַ�����ʼ��֮�ں��������ð��
	for (int ix = 0; ix < 16; ++ix)
	{
		ptr_mat[ix] = 0; //ȫ��װ��0;
	}
}

Matrix4x4::Matrix4x4(double d00, double d01, double d02, double d03,
	double d10, double d11, double d12, double d13,
	double d20, double d21, double d22, double d23,
	double d30, double d31, double d32, double d33):ptr_mat(&mat4x4[0]) //���G
{
	// double mat4x4[16]; // C++������ʹ��һ������ȥ��ʼ����һ������; ����д��û�õ�;��ʱ��mat4x4�൱�ڴ洢�ڶ�̬�ڴ�,�����캯����ɺ�,����ڴ�����ͻᱻ�ͷŵ�;
	//ptr_mat = &mat4x4[0];// ָ��ָ��mat4x4��λԪ�ص�һ��λ��;
	ptr_mat[0] = d00;	ptr_mat[1] = d01;	ptr_mat[2] = d02;	ptr_mat[3] = d03;
	ptr_mat[4] = d10;	ptr_mat[5] = d11;	ptr_mat[6] = d12;	ptr_mat[7] = d13;
	ptr_mat[8] = d20;	ptr_mat[9] = d21;	ptr_mat[10] = d22;	ptr_mat[11] = d23;
	ptr_mat[12] = d30;	ptr_mat[13] = d31;	ptr_mat[14] = d32;	ptr_mat[15] = d33;
}

Matrix4x4::Matrix4x4(double arr[16]):ptr_mat(&mat4x4[0]) // ���H
{
	//ptr_mat = &mat4x4[0];// ָ��ָ��mat4x4��λԪ�ص�һ��λ��;
	for (int ix = 0; ix < 16 ; ++ix)
	{
		ptr_mat[ix] = arr[ix];
	}
}


Matrix4x4::~Matrix4x4()
{
}

// һ��ĳ�Ա����
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

// ���������
Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat1) // ��֤�ɹ��� 
{
	Matrix4x4 mat2;
	for (int ix = 0; ix < 16; ++ix)
	{
		mat2.ptr_mat[ix] = this->ptr_mat[ix] + mat1.ptr_mat[ix]; // �����ĸ�ֵֻ����ʱ��,�˳��������ֱ�ˢ����
	}
	return mat2;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat1)// ��֤�ɹ�;
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

Matrix4x4 Matrix4x4::operator+=(const Matrix4x4& mat1) // ��֤�ɹ�.
{
	for (int ix = 0; ix < 16; ++ix)
	{
		this->ptr_mat[ix] += mat1.ptr_mat[ix]; // �����ĸ�ֵֻ����ʱ��,�˳���ָ���Ʈ��;
	}
	return *this;
}

int sub_main4()
{
	double array1[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//double *parr;
	double array2[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	// int array3[4][4](array2); ����д�ǲ��е�;
	Matrix4x4 mat1(array2);
	Matrix4x4 mat2(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	
	mat1.print(2, 3); // ������һ���ڴ�ͱ������. Ϊʲô? ��Ϊ����汾�洢���ݵ�����ʵ�����ڹ��캯��ִ�������ͷ���,�²�������ϵͳ�����㹻��,��˸���ˢ��֮ǰ��ȡ��һ��Ҫ��ʾ������.
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

