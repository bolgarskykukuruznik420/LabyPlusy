#pragma once
#include<iostream>
using namespace std;
namespace Book_zavod
{
	class Page
	{
	private:
		int Pagenum;
	public:
		Page() = default;
		Page(int Pagenum_);
		~Page() =default;
		int GetPage() { return Pagenum; };
	};
}

