#pragma once
#include<iostream>
using namespace std;
namespace Book_zavod
{
	class binding
	{
	private:
		std::string Bindtype;
	public:
		binding() = default;
		binding(std::string Bindtype_);
		~binding() = default;
		std::string GetBindtype() { return Bindtype;};
	};
}

