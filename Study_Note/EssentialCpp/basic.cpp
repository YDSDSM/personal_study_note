#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

/*int i = 128;
int j = i;// j和i唯一的相同之处是他们的值相同
int &k = i k和i的 */


int guess_fib() 
{
	// 猜数列小游戏.
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
	std::vector<int> *pv = 0;//初始化一个能指向实参为整形的vector的指针;

	std::vector<int> pell_seq(18, 0);//定义vector实例，存储18个类型为int的元素，每个元素的初值是0；

	pell_seq[0] = 1; // assign 1 to first element 
	pell_seq[1] = 2; // assign 2 to second element 

	for (int ix = 2; ix < seq_size; ++ix)
		pell_seq[ix] = pell_seq[ix - 2] + 2 * pell_seq[ix - 1]; // 生成Pell序列

	std::vector<int> Fibonacci2;
	fib_initiate(Fibonacci2, 20); // 用函数的方法生成fibonacci数列

	int elem_vals[seq_size] = { // 初始化array
	 1, 2, 3, // Fibonacci 
	 3, 4, 7, // Lucas 
	 2, 5, 12, // Pell 
	 3, 6, 10, //Triangular 
	 4, 9, 16, // Square 
	 5, 12, 22 // Pentagonal 
	};
	std::vector<int> elem_seq(elem_vals, elem_vals + seq_size); // 用array来初始化vector;这组数据是初始条件
	
	const int max_seq = 6;
	std::string seq_name[max_seq] = {"Fibonacci","Lucas", "Pell", "Triangular", "Square", "Pentagonal"}; // 存储数列的名字,展示了数组的写法,vector不能这样写;本段没用
	std::vector<int> Fibonacci, Lucas, Pell, Triangular, Square, Pentagonal; // 初始化一组vector;

	//装载Fibonacci数列
	int count = 18; // 决定Fibonacci数列项数;
	Fibonacci.push_back(1);
	Fibonacci.push_back(1);
	for (int ix = 2; ix <= count; ++ix){Fibonacci.push_back(Fibonacci[ix - 2] + Fibonacci[ix - 1]);}


 	std::vector<int> *seq_pv[max_seq] = { &Fibonacci, &Lucas, &Pell, &Triangular, &Square, &Pentagonal }; // 定义了一组序列,存放了数列们的地址 |这个神奇的指针好像有把我创建的vector冲刷掉的嫌疑.
	srand(max_seq);
	int seq_index = rand() % max_seq; // 产生0~5的随机数;
	// 生成并初始化一个含义32个随机数的vector
	srand(128); // 播下去的种子如果不变的话,就永远都是同一张随机表,好垃圾的设定啊.


	std::vector<int> v_random;
	for (int i = 0; i < 32; ++i)
	{ 
		v_random.push_back(rand()%128);
		std::cout << v_random[i] << "\n"; //检查是否生成了想要的v_random;
	}
	
	bubble_sort(v_random);
	std::cout << "sort complete" << "\n";
	for (int i = 0; i <v_random.size(); ++i)
	{
		std::cout << v_random[i] << "\n";
	}

	std::vector<int> current_vec = *seq_pv[seq_index]; // 随机的取出一组vector; 暂时还没把六个序列具体生成(Fibonacci已生成); 
	std::cout << "EXIT" << "\n"; //DEBUG的时候编译器不会访问,但是执行的时候是有输出的.
	return 0;
}

int file_IO()
{
	std::ofstream outfile{ "seq_data.txt" }; //开辟一个文件seq_data.txt以用作输出,如果文件不存在则新建一个,如果存在则会被破坏然后新建一个.
	//std::ostream outfile{ "seq_data2.txt", std::ios_base::app }; //以追加模式打开文件,则在原有文件存在的情况下不会覆盖原文件,这句有问题,写完就不能初始化了.


	if (!outfile) 
	{ std::cerr << "文件打开失败" << "\n"; } // 判断文件是否成功打开.
	outfile << "Fibonacci\t" << "Lucas\t" << "Pell\t" << "Triangular\t" << "Square\t" << "Pentagonal\n";

	return 0;
}


int sub_main0()
{
	int temp = seq_generate();
	return 0;
}

