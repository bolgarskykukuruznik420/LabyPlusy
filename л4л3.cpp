#include<iostream>

class Home
{
protected:
	std::string street;
	int size;
	int floor;
public:
	Home(int size_=0,int floor_=0,std::string street_ = "") :street(street_),floor(floor_),size(size_)
	{

	}
	virtual ~Home()
	{
		std::cout << "\n~Home\n";
	}
	virtual int Volume()
	{
		return floor*size;
	}
	virtual void GetObject()
	{
		std::cout <<"\n" << street << " " << floor << " " << size<<"\n";
	}

};
class Dacha : virtual public Home
{
protected:
	int door;
public:
	Dacha(int door_, std::string street_,int floor_,int size_) :door(door_), Home(size_,floor_,street_)
	{

	}
	virtual ~Dacha()
	{
		std::cout << "\n~Dacha\n";
	}
	virtual int Volume()
	{
		return floor*size;
	}
	virtual void GetObject()
	{
		std::cout <<"\n"<<size<<" "<<door<<" "<<street<<" "<<floor<<" "<<size<<"\n";
	}
};
class Saray : public Dacha
{
protected:
	int Drova;
public:
	Saray(int drova_, int size_, std::string street_,int floor_,int door_) :
		Drova(drova_), Dacha(door_,street_,floor_, size_), Home(size_,floor_,street_)
	{

	}
	virtual ~Saray()
	{
		std::cout << "\n~Saray\n";
	}
	virtual int Volume()
	{
		return floor*size;
	}
	virtual void GetObject()
	{
		std::cout <<"\n"<<Drova << " " << size << " " << floor << " " << door<<"\n";
	}
};
class Banya :  public Home
{
protected:
	int temperature;
public:
	Banya(int temperature_, std::string streetv_,int floor_,int size_) :temperature(temperature_), Home(size_,floor_,streetv_)
	{

	}
	virtual ~Banya()
	{
		std::cout << "\n~Banya\n";
	}
	virtual int Volume()
	{
		return size*floor;
	}
	virtual void GetObject()
	{
		std::cout <<"\n"<<temperature<<" "<<street<<" "<<floor<< " "<<size<<"\n";
	}
};
int main()
{
    Home** h=new Home*[4];
	h[0] = new Home(160, 2, "broke street");
	h[1] = new Dacha(3,"broke street",100,3);
	h[2] = new Saray(25,50,"broke street",1,2);
	h[3] = new Banya(45,"broke street",2,35);
	h[0]->GetObject(); 
	h[1]->GetObject();
	h[2]->GetObject();
	h[3]->GetObject();
	for (int i = 0; i < 4; i++)
	{
		delete h[i];
	}
	delete h;
	return 0;
}
