#include <iostream>
extern int count2; // ���Դ��ⲿ��count2��ֵ
void write_extern(void)
{
	std::cout << "Count is " << count2 << std::endl;
}

#include <io.h>      
#include <string>    
#include <vector>    
#include <iostream>    
using namespace std;
//��ȡ�ض���ʽ���ļ���    
void getAllFiles(string path, vector<string>& files, string format)
{
	intptr_t  hFile = 0;//�ļ����  64λ��long ��Ϊ intptr_t
	struct _finddata_t fileinfo;//�ļ���Ϣ 
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1) //�ļ�����
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))//�ж��Ƿ�Ϊ�ļ���
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)//�ļ������в���"."��".."
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name)); //�����ļ�����
					getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files, format); //�ݹ�����ļ���
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));//��������ļ��У������ļ���
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
	string format = "";				 //�����ļ��ĸ�ʽ
	getAllFiles(filePath, files, format);
	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i] << endl;
	}
	system("pause");
	return 0;
}