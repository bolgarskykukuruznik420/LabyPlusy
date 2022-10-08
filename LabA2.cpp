#include <iostream>
class floatArr
{
private:
	float *arr;
	int size;
	float count;
public:
	floatArr(int size_=3,float count_ = 0) :size(size_), count(count_)
	{
		arr = new float[size];
		for (int i = 0; i < size;i++)
		{
			arr[i] = 0;
		}
	}
	friend void show(floatArr& fl_a);
	friend void input(floatArr& fl_a);
	friend floatArr operator--(floatArr& a);
    floatArr operator+( floatArr& f1);
	floatArr operator++();
	floatArr operator++(int);
	floatArr& operator=(const floatArr &f1);
	operator float();
	float& operator()(int id, float value);
	float& operator[](int id);
	bool operator==(floatArr& f1);
	friend floatArr operator+(floatArr& f1,float value);
	friend floatArr operator+(float value,floatArr& f1);
	friend bool operator==(floatArr& f1, float value);
	friend std::ostream& operator<< (std::ostream& out,floatArr& f1);

};
void out(floatArr arr)
{
	std::cout << arr << std::endl;
}
floatArr::operator float()
{
	for (int i = 0; i < size; i++)
	{
		count =count + arr[i];
	}
	std::cout << "sum of the arr elements : ";
	return count;
}
float& floatArr::operator()(int id, float value)
{
	return(arr[id] = value);
}
float& floatArr::operator[](int id)
{
	return(arr[id]);
}
floatArr &floatArr::operator=(const floatArr& f1)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = f1.arr[i];
	}
	return *this;
}
floatArr floatArr::operator++(int)
{
	for (int i = 0; i < size; i++)
	{
		arr[i]++;
	}
	return *this;
}
floatArr floatArr::operator++()
{
	for (int i = 0; i < size; i++)
	{
	    arr[i]++;
	}
	return *this;
}
bool floatArr::operator==(floatArr& f1)
{
	for (int i = 0; i < f1.size; i++)
	{
		if (arr[i] != f1.arr[i])
			return false;
	}
	return true;
}
bool operator==(floatArr& f1, float value)
{
	int tmp1 = 0;
	for (int i = 0; i < f1.size;i++)
	{
		if (f1.arr[i] == value)
		{
			tmp1 = i;
			std::cout << "Arr" << "[" << tmp1 << "] == " << value<<"\n";
		}
	}
	
	return(f1.arr[tmp1] == value);
}
std::ostream& operator<< (std::ostream& out,floatArr& f1)
{
	for(int i=0;i<f1.size;i++)
	out << "Arr["<<i<<"]: "<< f1.arr[i]<<"\n";

	return out;
}
floatArr operator+(floatArr& f1, float value)
{
	for (int i = 0; i < f1.size; i++)
	{
		f1.arr[i] = f1.arr[i] + value;
	}
	return f1;
}
floatArr operator+( float value, floatArr& f1)
{
	for (int i = 0; i < f1.size; i++)
	{
		f1.arr[i] = f1.arr[i] + value;
	}
	return f1;
}
floatArr operator--(floatArr& a)
{
	for (int i = 0; i < a.size; i++)
	{
		a.arr[i]--;
	}
	return a;
}
floatArr floatArr::operator+( floatArr& f1)
{
	floatArr A;
	for (int i = 0; i < f1.size; i++)
	{
		A.arr[i] = f1.arr[i] + arr[i];
	}
	return A;
}
void show(floatArr& fl_a)
{
	for (int i = 0; i < fl_a.size; i++)
	{
		std::cout << fl_a.arr[i] << " ";
	}
	std::cout << "\n";
}
void input(floatArr& fl_a)
{
	for (int i = 0; i < fl_a.size; i++)
	{
		std::cout << "arr[" << i << "]" << ": ";
		std::cin >> fl_a.arr[i];
	}
}
void print(float value)
{
	std::cout << value;
}


int main()
{
	floatArr arr1;
	std::cout << "Enter first array: ";
	input(arr1);
	show(arr1);
	floatArr arr2;
	std::cout << "Enter second array: ";
	input(arr2);
	show(arr2);
	floatArr arr3;
	std::cout << "\nop + overload(same type op)\n";
    arr3 = arr1 + arr2;
	show(arr3);
	std::cout << "\noverload --\n";
	--arr1;
	show(arr1);
	float val = 1;
	std::cout << "\nop + overload(dif type op)\n";
	arr2 = arr2 + val;
	show(arr2);
	std::cout << "\noverload <<\n";
	std::cout << "\n" << arr1;
	std::cout << "\noverload == (same type op)\n";
	float tmp;
	std::cout << "Enter number to search this element in first arr: ";
	std::cin >> tmp;
	if (arr1 == tmp)
	{		
	}
	else
	{
		std::cout << "\nNone of da elements of arr equals "<<tmp<<"\n";
	}
	std::cout << "\noverload == (dif type op)\n";
	if (arr1 == arr2)
	{
		std::cout << "\nArrays are equal\n";
	}
	else
	{
		std::cout << "\narr1!=arr2\n";
	}
	std::cout << "\noverload ++prefiks\n";
	++arr1;
	show(arr1);
	std::cout << "\noverload ++postfiks\n";
	arr1++;
	show(arr1);
	std::cout << "\noverload =\n";
	arr1 = arr2;
	show(arr1);
	show(arr2);
	std::cout << "\noverload []\n";
	arr1[0] = 15;
	show(arr1);
	std::cout << "\noverload ()\n";
	arr1(0, 20);
	show(arr1);
	std::cout << "\noverload in float\n";
	print(arr1);
	std::cout << "\n";
	return 0;
}