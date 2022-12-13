#include "Autor.h"
Book_zavod::Autor::Autor(std::string Name_) :Name(Name_) {}
std::string Book_zavod::Autor::getName()
{
	return this->Name;
}