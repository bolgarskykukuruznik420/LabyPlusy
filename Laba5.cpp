#include<iostream>
template <class T, int length>
class Arr
{
protected:
    T data[length];
public:
    Arr(T tmp)
    {
        for (int i = 0; i < length; i++)
        {
            data[i] = tmp;
        }
    }
    ~Arr()
    {
        std::cout << "\ndestruct";
    }
    T operator[](int index)
    {
        return data[index];
    }
    T operator+(T val)
    {
        for (int i = 0; i < length; i++)
        {
            data[i] = data[i] + val;
        }
        return *data;
    }
    T search(T val)
    {
        int tmp = 0;
        for (int i = 0; i < length; i++)
        {
            if (data[i] == val)
            {
                std::cout << "\nid of el u want: " << i << "\n";
                tmp++;
            }
        }
        if (tmp == 0)
        {
            std::cout << "\nno such element in data\n";
            return *data;
        }
        else
        {
            return *data;
        }
    }
    T input()
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << "arr[" << i << "]" << ": ";
            std::cin >> this->data[i];
        }
        return *data;
    }
    void getData()
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << data[i] << " ";
        }
    }
};
template <>
void Arr<char*, 5>::getData()
{
    std::cout << "\n" << data[0] << "\n";
}
template <class T, int length>
class arr :public Arr<T, length>
{
public:
    arr(T tmp_) :Arr<T, length>(tmp_)
    {

    }
    void exampleOfWork()
    {
        std::cout << "\njust method\n";
    }
};
int main()
{
    Arr<float, 5> floatArr(0);
    Arr<int, 5> intArr(4);
    intArr.input();
    intArr + 8;
    intArr.getData();
    std::cout << "\n";
    floatArr + 8.4;
    floatArr.getData();
    std::cout << "\n";
    intArr.search(8);
    floatArr.search(8.6);
    std::cout << "\n";
    arr<double, 5> dArr(9);
    dArr.input();
    dArr.getData();
    dArr.exampleOfWork();
    char string[] = "empty";
    Arr<char*, 5> chArr(string);
    chArr.getData();
}
