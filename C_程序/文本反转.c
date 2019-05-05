#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	string temp;
	string content("");
	string outcontent("");
	//文件读（将文件的内容读出）
	ifstream fin("D:\\test.txt");
	if(!fin)
	{
		cout<<"open error1!"<<endl;
		return 0;
	}
	//文件内容保存到outcontent中
	while (getline(fin,temp))
	{
		int i = temp.length();
		for (--i;i>=0;i--)
		{
			outcontent+=temp[i];
		}
		outcontent+='\n';
	}
	fin.close();

	//文件写（将内容写入文件）
	ofstream fout("D:\\test.txt");
	if(!fout)
	{
		cout<<"open error2!"<<endl;
		return 0;
	}
	size_t i = outcontent.length();
	for(size_t j =0;j<i;j++)
	{
		fout<<outcontent[j];
	}
	fout.close();
	return 0;
}
