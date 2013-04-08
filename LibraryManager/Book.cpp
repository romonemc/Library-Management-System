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

Book::Book(int is, int quant, int ed, std::string n, std::string cat, std::string pub, std::string auth1)
	:isbn(is), quantity(quant), edition(ed), name(n), category(cat), publisher(pub)
{
	authors.push_back(auth1);
	nextBook = NULL;
}

void Book::setNextBook(Book* b)
{
	nextBook = b;
}

Book* Book::setAuthors(std::vector<std::string> A)
{
	int no_authors = A.size();

	for (int i = 0; i < no_authors; i++)
	{
		authors.push_back(A.at(i));
	}

	return this;
}

void Book::getAuthors()
{
	int no_authors = authors.size();

	std::cout << "Author(s): " << std::endl;
	for (int i = 0; i < no_authors; i++)
	{
		std::cout << authors.at(i) << std::endl;
	}
}

std::string Book::FirstAuthor()
{
	if (!authors.empty())
	{
		return authors.front();
	} else {
		return "No authors.";
	}
}

void Book::clearAuthors()
{
	authors.clear();
}