#include "Book.h"
Book_zavod::Book::Book(Page page_, binding bind_, cover cov_, std::string nameofdabook_,Print print_) 
	:nameofdabook(nameofdabook_)
{
	this->page = page_;
	this->cov = cov_;
	this->bind = bind_;
	this->print = print_;
}
void Book_zavod::Book::printBook()
{
	std::cout << "Pages: " << page.GetPage() <<"\nType of bind: "<<bind.GetBindtype()<<"\nType of cover: "
		<<cov.GetCovertype()<<"\nName of da book: " << nameofdabook<< "\nCount of published books: "
		<< print.GetPrintnum() << std::endl;
}