#pragma once
#include <iostream>
using namespace std;
namespace Book_zavod
{
	class Print
	{
	private:
		int Printnum;
	public:
		Print() = default;
		Print(int Printnum_);
		~Print() =default;
		int GetPrintnum() { return Printnum; };
	};
}

