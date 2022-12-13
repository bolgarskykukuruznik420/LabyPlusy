#pragma once
#include<iostream>
#include"cover.h"
#include"binding.h"
#include"Page.h"
#include"Print.h"
using namespace std;
namespace Book_zavod
{
	class Book
	{
	protected:
		Page page;
		binding bind;
		cover cov;
		Print print;
		std::string nameofdabook;
	public:
		Book() = default;
		Book(int page_, std::string bind_, std::string cov_, std::string nameofdabook_,int print_);
		~Book() = default;
		void printBook();
	};
}

