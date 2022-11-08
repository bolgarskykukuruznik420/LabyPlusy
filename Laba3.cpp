#include<iostream>

class Home
{
protected:
	std::string street;
public:
	Home(std::string street_ = "") :street(street_)
	{

	}
	~Home() = default;
	void GetHome() {
		std::cout << street;
	}
};
class Dacha : virtual public Home
{
protected:
	int size;
public:
	Dacha(int size_, std::string street_) :size(size_), Home(street_)
	{

	}
	~Dacha() = default;

	void GetDacha() {
		std::cout << size;
	}
};
class Saray : public Dacha
{
protected:
	int Drova;
public:
	Saray(int drova_, int size_, std::string street_) :Drova(drova_), Dacha(size_, street_), Home(street_)
	{

	}
	~Saray() = default;

	void GetDrova() {
		std::cout << "V sarae drov : " << Drova;
	}
};
class Banya : virtual public Home
{
protected:
	int sizev;
public:
	Banya(int sizev_, std::string streetv_) :sizev(sizev_), Home(streetv_)
	{

	}
	~Banya() = default;
	void GetDacha() {
		std::cout << sizev;
	}
};
class Parilka : public Banya
{
protected:
	int drova;
public:
	Parilka(int drova_, int sizev_, std::string streetv_) :drova(drova_), Banya(sizev_, streetv_), Home(streetv_)
	{

	}
	~Parilka() = default;

	void GetDrova() {
		std::cout << "V parilke drov : " << drova;
	}


};
class Zdaniye : public  Parilka, public  Saray {

public:
	Zdaniye(std::string street, int size, int Drova, std::string streetv, int sizev, int drova) :
		Home(street), Parilka(drova, sizev, streetv), Saray(Drova, size, street)
	{

	}
	~Zdaniye() = default;

	void GetZdaniye() {
		std::cout << "Street : " << street << "\ndacha size : " << size << "\ncount of wood in da Saray: "
			<< Drova << "\nsize of banya: " << sizev << "\ncount of wood in da banya: " << drova;
	}
};
int main()
{
	Zdaniye zd("Broke street 69", 500, 20, "Broke street 69", 150, 5);
	zd.GetZdaniye();
	return 0;
}
