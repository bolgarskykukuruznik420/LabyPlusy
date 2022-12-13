#pragma once
#include<iostream>
using namespace std;
namespace Book_zavod
{
	class cover
	{
	private:
		std::string Covertype;
	public:
		cover() = default;
		cover(std::string Covertype_);
		~cover() = default;
		std::string GetCovertype() { return Covertype; };
	};

}