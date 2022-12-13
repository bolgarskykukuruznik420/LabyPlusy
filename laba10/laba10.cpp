#include<iostream>
#include<fstream>
#include<vector>
#include<string>
void SumOfPositive() 
{
	std::string in = "file1.txt";
	std::string out = "file2.txt";
	try
	{
		std::ifstream file1;
		std::ofstream file2;
		file1.open(in);
		std::cout << in << " is open" << std::endl;
		file2.open(out);
		std::cout << out << " is open" << std::endl;
		std::vector<std::string> str;
		std::string buf;
		while (!file1.eof())
		{			
			file1 >> buf;
			str.push_back(buf);
		}
		int a = 0;
		int tmp = 0;
		for (int i = 0; i < str.size(); i++)
		{
			tmp=atoi(str[i].c_str());
			if (tmp > 0)
			{
				a += tmp;
			}
		}
		std::cout << a<<"\n";
		file2 << a;
		file1.close();
		std::cout << in << " is closed" << std::endl;
		file2.close();
		std::cout << out << " is closed" << std::endl;
	}
	catch (std::exception ex) 
	{
		std::cout << "Error" << std::endl;
	}
}
int main() 
{
	SumOfPositive();
}
