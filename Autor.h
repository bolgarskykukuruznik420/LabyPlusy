#pragma once
#include <iostream>
using namespace std;
namespace Book_zavod
{
	class Autor
	{
	private:
		std::string Name;
	public:
		Autor() = default;
		Autor(std::string Name_);
		~Autor() = default;
		std::string getName();
	};
}

