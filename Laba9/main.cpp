#include <iostream>
#include"Book.h"
#include"Publisher.h"
using namespace Book_zavod;
int main()
{
	Book book(150,"Rings","Lether", "book", 2000);
	book.printBook();
	Publisher publisher("autor", 15);
	publisher.printPublisher();
}
