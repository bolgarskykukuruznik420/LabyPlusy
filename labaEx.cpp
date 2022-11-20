#include<iostream>
class ArrException
{
private:
    std::string msg = "Exception";
public:
    ArrException(std::string _msg) : msg(_msg) {}
    const char* what() const noexcept { return msg.c_str(); }
};
template <class T>
class Arr
{
protected:
    T data[5];
public:
    Arr(T tmp)
    {
        for (int i = 0; i < 5; i++)
        {
            data[i] = tmp;
        }
       
    }
    ~Arr()
    {
        std::cout << "\ndestruct";
    }

    Arr operator=(Arr& a)
    {
        for (int i = 0; i < 5; i++)
        {
            data[i] = a.data[i];
        }
        return *this;
    }
    T operator[](int index)
    {
        if (index < 0 || index >= 5)
            throw ArrException("\nInvalid index\n");

        return data[index];
    }
    Arr search(T val)
    {
        int tmp = 0;
        for (int i = 0; i < 5; i++)
        {
            if (data[i] == val)
            {
                std::cout << "\nid of el u want: " << i << "\n";
                return *data;
            }
        }
        throw ArrException("\nArray doesnt have required value\n");
    }

    void getData()
    {
        std::cout << "\n";
        for (int i = 0; i < 5; i++)
        {
            std::cout << "arr[" << i << "]" << ": " << data[i] << "\n";
        }
        std::cout << "\n";
    }
};
void _terminate() {
    std::cout << "\nProgram terminated\n";
    exit(-1);
}

void _unexpected() {
    std::cout << "\nUnknow problem\n";
}
int main()
{
    std::set_terminate(_terminate);
    std::set_unexpected(_unexpected);

    try
    {
        Arr<float>fl(3.46);
        Arr<int>in1(2);
        Arr<int>in2(5);
        fl.getData();
        in1.getData();
        in2.getData();
        int tmp = in1[9];
        std::cout << "\ntmp:" << tmp << "\n";
        fl.search(5.43);
        in1 = in2;
        in1.search(1);
    }
    catch (ArrException err)
    {
        std::cout << err.what();
        terminate();
    }
}
