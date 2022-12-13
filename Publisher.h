#pragma once
#include"Autor.h"
using namespace std;
namespace Book_zavod
{
	class Publisher: public Autor
	{
	private:
		int PublishedNum;
	public:
		Publisher() = default;
		Publisher(std::string autor, int PublishedNum_) :Autor(autor), PublishedNum(PublishedNum_) {}
		~Publisher() = default;
		void printPublisher();
	};
}