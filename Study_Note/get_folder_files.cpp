#include <iostream>
extern int count2; // 可以从外部找count2的值
void write_extern(void)
{
	std::cout << "Count is " << count2 << std::endl;
}

#include <io.h>      
#include <string>    
#include <vector>    
#include <iostream>    
using namespace std;
//获取特定格式的文件名    
void getAllFiles(string path, vector<string>& files, string format)
{
	intptr_t  hFile = 0;//文件句柄  64位下long 改为 intptr_t
	struct _finddata_t fileinfo;//文件信息 
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1) //文件存在
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))//判断是否为文件夹
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)//文件夹名中不含"."和".."
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name)); //保存文件夹名
					getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files, format); //递归遍历文件夹
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));//如果不是文件夹，储存文件名
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

int sub_main4()
{
	cout << "start" << endl;
	string filePath = "C:\\Program Files (x86)\\VTK\\bin\\";
	vector<string> files;
	string format = "";				 //查找文件的格式
	getAllFiles(filePath, files, format);
	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i] << endl;
	}
	system("pause");
	return 0;
}