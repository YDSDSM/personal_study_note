#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

/*int i = 128;
int j = i;// j��iΨһ����֮ͬ�������ǵ�ֵ��ͬ
int &k = i k��i�� */


int guess_fib() 
{
	// ������С��Ϸ.
	bool user_try(true);
	bool user_trymore(true);
	std::string continue_quit;
	int array1[10] = { 1,1,2,3,5,8,13,21,34 };
	int user_guess = 0;
	int tries = 0;
	int ranki = 4;
	int correct_guess = 0;

	std::cout << "sequence start 1,1,2,3 ..." << "\n";

	std::cout << "what is the next number?";
	while (user_trymore && user_guess != array1[ranki])
	{
		std::cout << "Enter number:";
		std::cin >> user_guess;
		std::cout << "\n";
		if (user_guess == array1[ranki])
		{
			std::cout << "you got it!" << "\n";
			correct_guess += 1;
			ranki += 1;
			user_trymore = true;
			if (ranki == 9)
			{
				std::cout << "you complete the game" << "\n";
				user_try = false;
				user_trymore = false;
				break;
			}
		}
		else
		{
			++tries;
			std::cout << "sorry, you are wrong " << tries << " times\n";

			while (user_try)
			{
				std::cout << "Continue/Quit Enter (Y/N)";
				std::cin >> continue_quit;
				std::cout << "\n";
				if (continue_quit == "N" || continue_quit == "n")
				{
					user_trymore = false;
					user_try = false;
					break;
				}
				else
				{
					if ((continue_quit == "Y" || continue_quit == "y"))
					{
						break;
					}
					else
					{
						std::cout << "Wrong input, please enter again" << "\n";
						continue;
					}
				}
			}
		}
	}

	return 0;
}

void fib_initiate(std::vector<int>& fib1, int count)
{
	fib1.push_back(1);
	fib1.push_back(1);
	for (int ix = 2; ix <= count; ++ix)
	{
		fib1.push_back(fib1[ix - 2] + fib1[ix - 1]);
	}
}

template<typename T> void swap_reference(T &val1, T &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

void bubble_sort(std::vector<int> & vec)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		for (int jx = ix + 1; jx < vec.size(); ++jx)
			if (vec[ix] > vec[jx])
				swap_reference(vec[ix], vec[jx]);
}

int seq_generate()
{
	const int seq_size = 18;
	std::vector<int> *pv = 0;//��ʼ��һ����ָ��ʵ��Ϊ���ε�vector��ָ��;

	std::vector<int> pell_seq(18, 0);//����vectorʵ�����洢18������Ϊint��Ԫ�أ�ÿ��Ԫ�صĳ�ֵ��0��

	pell_seq[0] = 1; // assign 1 to first element 
	pell_seq[1] = 2; // assign 2 to second element 

	for (int ix = 2; ix < seq_size; ++ix)
		pell_seq[ix] = pell_seq[ix - 2] + 2 * pell_seq[ix - 1]; // ����Pell����

	std::vector<int> Fibonacci2;
	fib_initiate(Fibonacci2, 20); // �ú����ķ�������fibonacci����

	int elem_vals[seq_size] = { // ��ʼ��array
	 1, 2, 3, // Fibonacci 
	 3, 4, 7, // Lucas 
	 2, 5, 12, // Pell 
	 3, 6, 10, //Triangular 
	 4, 9, 16, // Square 
	 5, 12, 22 // Pentagonal 
	};
	std::vector<int> elem_seq(elem_vals, elem_vals + seq_size); // ��array����ʼ��vector;���������ǳ�ʼ����
	
	const int max_seq = 6;
	std::string seq_name[max_seq] = {"Fibonacci","Lucas", "Pell", "Triangular", "Square", "Pentagonal"}; // �洢���е�����,չʾ�������д��,vector��������д;����û��
	std::vector<int> Fibonacci, Lucas, Pell, Triangular, Square, Pentagonal; // ��ʼ��һ��vector;

	//װ��Fibonacci����
	int count = 18; // ����Fibonacci��������;
	Fibonacci.push_back(1);
	Fibonacci.push_back(1);
	for (int ix = 2; ix <= count; ++ix){Fibonacci.push_back(Fibonacci[ix - 2] + Fibonacci[ix - 1]);}


 	std::vector<int> *seq_pv[max_seq] = { &Fibonacci, &Lucas, &Pell, &Triangular, &Square, &Pentagonal }; // ������һ������,����������ǵĵ�ַ |��������ָ������а��Ҵ�����vector��ˢ��������.
	srand(max_seq);
	int seq_index = rand() % max_seq; // ����0~5�������;
	// ���ɲ���ʼ��һ������32���������vector
	srand(128); // ����ȥ�������������Ļ�,����Զ����ͬһ�������,���������趨��.


	std::vector<int> v_random;
	for (int i = 0; i < 32; ++i)
	{ 
		v_random.push_back(rand()%128);
		std::cout << v_random[i] << "\n"; //����Ƿ���������Ҫ��v_random;
	}
	
	bubble_sort(v_random);
	std::cout << "sort complete" << "\n";
	for (int i = 0; i <v_random.size(); ++i)
	{
		std::cout << v_random[i] << "\n";
	}

	std::vector<int> current_vec = *seq_pv[seq_index]; // �����ȡ��һ��vector; ��ʱ��û���������о�������(Fibonacci������); 
	std::cout << "EXIT" << "\n"; //DEBUG��ʱ��������������,����ִ�е�ʱ�����������.
	return 0;
}

int file_IO()
{
	std::ofstream outfile{ "seq_data.txt" }; //����һ���ļ�seq_data.txt���������,����ļ����������½�һ��,���������ᱻ�ƻ�Ȼ���½�һ��.
	//std::ostream outfile{ "seq_data2.txt", std::ios_base::app }; //��׷��ģʽ���ļ�,����ԭ���ļ����ڵ�����²��Ḳ��ԭ�ļ�,���������,д��Ͳ��ܳ�ʼ����.


	if (!outfile) 
	{ std::cerr << "�ļ���ʧ��" << "\n"; } // �ж��ļ��Ƿ�ɹ���.
	outfile << "Fibonacci\t" << "Lucas\t" << "Pell\t" << "Triangular\t" << "Square\t" << "Pentagonal\n";

	return 0;
}


int sub_main0()
{
	int temp = seq_generate();
	return 0;
}

