#include <iostream>
#include <fstream>
class Exception
{
private:
    std::string msg = "Exception";
public:
    Exception(std::string _msg) : msg(_msg) {}
    const char* what() const noexcept { return msg.c_str(); }
};
class Detail
{
private:
    int mass;
    int high;
    int length;
public:
    Detail(int mass_, int high_, int length_) : mass(mass_), high(high_), length(length_)
    {

    }
    Detail()
    {
        mass = 0;
        high = 0;
        length = 0;
    }
    friend std::ostream& operator<<(std::ostream& str, Detail& det)
    {
        str << det.mass << ' ' << det.high << ' ' << det.length << std::endl;
        return str;
    }
    friend std::istream& operator>>(std::istream& str, Detail& det)
    {
        str >> det.mass >> det.high >> det.length;
        return str;
    }
    void binWrite(std::ofstream& b)
    {
        b.write((char*)&mass, sizeof(mass));
        b.write((char*)&high, sizeof(high));
        b.write((char*)&length, sizeof(length));
    }
    void binRead(std::ifstream& b)
    {
        b.read((char*)&mass, sizeof(mass));
        b.read((char*)&high, sizeof(high));
        b.read((char*)&length, sizeof(length));
    }
    void DetSet(int a, int b, int c)
    {
        mass = a;
        high = b;
        length = c;
    }
    int GetMass()
    {
        return mass;
    }
    static void ser(int toSearch, Detail& bolt)
    {
        try
        {
            bool found = true;
            std::ifstream det("laba.bin", std::ios::binary);
            std::ofstream newdet("temp.bin", std::ios::binary);
            while (!det.eof())
            {
                det.read((char*)&bolt, sizeof(bolt));
                if (bolt.GetMass() == toSearch)
                {
                    std::cout << "found mass:" << toSearch << std::endl;
                    found = false;
                }
                else {
                    newdet.write((char*)&bolt, sizeof(bolt));
                }
            }
            if (found == true)
            {
                throw Exception("there no such el to del\n");
            }
            
        }
        catch(Exception ex)
        {
            std::cout<<ex.what();
        }       
        remove("laba.bin");
        rename("temp.bin", "laba.bin");
    }
};
int main()
{
    Detail bolt;
    {
        std::cout << "(txt)read from file: " << std::endl;
        std::ifstream text("laba.txt");
        for (int i = 0; i < 5; i++)
        {
            text >> bolt;
            std::cout << bolt;
        }
        std::cout << "(Bin)read from file: " << std::endl;
        std::ifstream bin("laba.bin", std::ios::binary);
        for (int i = 0; i < 5; i++)
        {
            bolt.binRead(bin);
            std::cout << "Read: " << bolt;
        }

    }
    std::cout << std::endl;
    {
        std::cout << "(txt)write into file: " << std::endl;
        Detail bolt;
        std::ofstream iofile("laba.txt");
        for (int i = 0; i < 5; i++)
        {
            bolt.DetSet(1 + i, 2, 2);
            iofile << bolt << std::endl;
            std::cout << bolt;
        }
        std::cout << "(bin)write into file: " << std::endl;
        std::ofstream bin("laba.bin", std::ios::binary);
        for (int i = 0; i < 5; i++)
        {
            bolt.DetSet(10 + i, 2, 2);
            bolt.binWrite(bin);
            std::cout << "Write: " << bolt;
        }
    }
    std::cout << "Enter value of mass u want to del in binary file" << std::endl;
    int searchVal;
    std::cin >> searchVal;
    Detail::ser(searchVal, bolt);
    std::ifstream bin("laba.bin", std::ios::binary);
    for (int i = 0; i < 5; i++)
    {
        bolt.binRead(bin);
        std::cout << "Read: " << bolt;
    }
}