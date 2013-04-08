#include "Library.h"
#include <string>
#include <iostream>

void Questions(Book*);

Library::Library() :head(NULL)
{

}

Library::~Library()
{
	Book* currBook = head;
	Book* nextBook = NULL;

	while(currBook != NULL) {
		nextBook = currBook->nextBook;
		delete currBook;
		currBook = nextBook;
	}
}

int Library::InsertAt(int index, const Book* b)
{

	if(index < 0) return NULL;

	int current = 1;
	Book* currNode = head;

	while(currNode && index > current)
	{
		currNode = currNode->nextBook;
		current++;
	}

	if(index > 0 && currNode == NULL) return NULL;

	Book* newBook = new Book(b->isbn, b->quantity, b->edition, b->name, b->category, b->publisher, b->authors);

	if(index == 0) {
		try {
			newBook->nextBook = head;
			head = newBook;
			std::cout << "Book Inserted Successfully! :)" << std::endl;
		} 
		catch(...)
		{
			std::cout << "Oops :( seems something went wrong. No harm, no foul just try again." << std::endl;
		}
	} 
	else 
	{
		try {
			newBook->nextBook = currNode->nextBook;
			currNode->nextBook = newBook;
			std::cout << "Book Inserted Successfully! :)" << std::endl;
		}
		catch(...)
		{
			std::cout << "Oops :(, seems something went wrong. No harm, no foul just try again." << std::endl;
		}
	}
	return 0;
}

int Library::SearchLibrary(int is, std::string n)
{
	Book* currNode = head;
	int currIndex = 1;
	if(is != 0) {
		while(currNode && currNode->isbn != is) {
			currNode = currNode->nextBook;
			currIndex++;
		}
		if(currNode) { std::cout << is << " found at position " << currIndex << " titled " << currNode->getName() << std::endl; }
		else {
			std::cout << "Sorry :(, a book with the isbn '"<< is << "' was not found in this library." << std::endl;
		}
		return 0;
	} else {
		while(currNode && currNode->name != n) {
			currNode = currNode->nextBook;
			currIndex++;
		}
		if(currNode) { std::cout << n << " found at position " << currIndex << " with the isbn " << currNode->getISBN() << std::endl; }
		else {
			std::cout << "Sorry :(, '"<< n << "' was not found in this library." << std::endl;
		}
		return 0;
	}

}

int Library::DeleteBook(int is)
{
	Book* prevBook = NULL;
	Book* currBook = head;

	int currIndex = 1;
	if(is != 0) {
		while(currBook && currBook->isbn != is) {
			prevBook = currBook;
			currBook = currBook->nextBook;
			currIndex++;
		}
	} 

	if(currBook) {
		if(prevBook) {
			prevBook->nextBook = currBook->nextBook;
			std::cout << currBook->isbn << " - " << currBook->name << " was deleted successfully." << std::endl;
			delete currBook;
		} else {
			head = currBook->nextBook;
			std::cout << currBook->isbn << " - " << currBook->name << " was deleted successfully." << std::endl;
			delete currBook;
		}
		return currIndex;
	}
	return 0;
}

void Library::EditBook(std::string n)
{
	Book* currNode = head;
	int currIndex = 1;

	while(currNode && currNode->name != n) {
			currNode = currNode->nextBook;
			currIndex++;
	} 
	if(currNode) { 

			Questions(currNode);
			std::cout << currNode->getName() << " updated successfully :)" << std::endl;
	}
	else {
			std::cout << "Sorry :( '"<< n << "' was not found in this library." << std::endl;
	}
}

int Library::DeleteBook(std::string n)
{
	Book* prevBook = NULL;
	Book* currBook = head;

	int currIndex = 1;

	while(currBook && currBook->name != n) {
			prevBook = currBook;
			currBook = currBook->nextBook;
			currIndex++;
	}

	if(currBook) {
		if(prevBook) {
			prevBook->nextBook = currBook->nextBook;
			std::cout << currBook->name << " - " << currBook->isbn << " was deleted successfully." << std::endl;
			delete currBook;
		} else {
			head = currBook->nextBook;
			std::cout << currBook->name << " - " << currBook->isbn << " was deleted successfully." << std::endl;
			delete currBook;
		}
		return currIndex;
	}
	return 0;
}

bool Library::Empty()
{
	return head == NULL;	
}

int Library::Count() {
	int count = 0;
	Book* currBook = head;

	while (currBook != NULL)
	{
		currBook = currBook->getNextBook();
		count++;
	}
	return count;
}

void Questions(Book* b)
{
	system("cls");

	int isbn;
	int edition;
	int quantity;
	int no_authors;
	std::string name;
	std::string publisher;
	std::string category;
	std::string author_name;
	std::vector<std::string> auth;

	std::cout << "ISBN: " << std::endl;
	std::cin >> isbn;
	std::cin.ignore();

	std::cout << "Name: " << std::endl;
	std::getline(std::cin, name);

	std::cout << "Edition: " << std::endl;
	std::cin >> edition;

	std::cout << "Quantity: " << std::endl;
	std::cin >> quantity;
	std::cin.ignore();

	std::cout << "Publisher: " << std::endl;
	std::getline(std::cin, publisher);

	std::cout << "Category (Fiction or Non-Fiction): " << std::endl;
	std::cin >> category;

	std::cout << "How many authors does " << name << " have?" << std::endl;
	std::cin >> no_authors;
	std::cin.ignore();

	b->clearAuthors();

	for (int i = 0; i < no_authors; i++)
	{
		std::cout << "Enter the name of author " << i + 1 << std::endl;
		getline(std::cin, author_name);
		auth.push_back(author_name);
	}

	b->setISBN(isbn)->setName(name)->setEdition(edition)->setPublisher(publisher)->setAuthors(auth)->setQuantity(quantity);
}

void Library::DisplayBookInfo(std::string n)
{
	Book* currNode = head;

	while(currNode && currNode->name != n) {
		currNode = currNode->nextBook;
	}

	if(currNode) {
		std::cout << std::endl;
		std::cout << "ISBN: " << currNode->getISBN() << std::endl;
		std::cout << "Name: " << currNode->getName() << std::endl;
		std::cout << "Edition: " << currNode->getEdition() << std::endl;
		std::cout << "Publisher: " << currNode->getPublisher() << std::endl;
		std::cout << "Quantity: " << currNode->getQuantity() << std::endl;
		std::cout << "Category: " << currNode->getCategory() << std::endl;
		currNode->getAuthors();

	} else {
		std::cout << "Sorry :( '"<< n << "' was not found in this library." << std::endl;
	}

}

void Library::AllBooks()
{
	int count = 0;
	Book* currBook = head;
	while(currBook != NULL) {
			std::cout << currBook->isbn 
					  << "\n - Name: " << currBook->name 
					  << "\n - Publisher: " << currBook->publisher 
					  << "\n - Category: " << currBook->category
					  << "\n - Quantity: " << currBook->quantity
					  << "\n - Edition: " << currBook->edition
					  << "\n - Author: " << currBook->FirstAuthor()
					  << " " << std::endl;
			currBook = currBook->getNextBook();
			count++;

	}
	std::cout << "\n" << "Their are " << count << " book(s) in this library." << "\n" << std::endl;
}