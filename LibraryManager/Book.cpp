#include "Book.h"
#include <string>
#include <iostream>
#include <vector>

Book::Book(int is, int quant, int ed, std::string n, std::string cat, std::string pub)
	:isbn(is), quantity(quant), edition(ed), name(n), category(cat), publisher(pub)
{
	nextBook = NULL;
}

Book::Book(int is, int quant, int ed, std::string n, std::string cat, std::string pub, std::vector<std::string> auth)
	:isbn(is), quantity(quant), edition(ed), name(n), category(cat), publisher(pub), authors(auth)
{
	nextBook = NULL;
}

void Book::setNextBook(Book* b)
{
	nextBook = b;
}

void Book::setAuthors(std::vector<std::string> A)
{
	int no_authors = A.size();

	for (int i = 0; i < no_authors; i++)
	{
		authors.at(i) = A.at(i);
	}
}

void Book::getAuthors()
{
	int no_authors = authors.size();

	std::cout << "The author(s) of this book is " << std::endl;
	for (int i = 0; i < no_authors; i++)
	{
		std::cout << authors.at(i) << std::endl;
	}
}