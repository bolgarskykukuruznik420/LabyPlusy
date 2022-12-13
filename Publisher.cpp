#include "Publisher.h"

void Book_zavod::Publisher::printPublisher()
{
	std::cout <<"Name of autor: " << getName() <<"\nCount of published books: "<<PublishedNum<<std::endl;
}