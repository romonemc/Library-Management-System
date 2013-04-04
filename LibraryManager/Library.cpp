#include "Library.h"
#include <string>
#include <iostream>

Library::Library() :head(NULL), size(0)
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

	//for (int i = 0; i <= b->authors.size(); i++)
	//{
	//	newBook->authors.at(i) = b->authors.at(i);
	//}

	if(index == 0) {
		newBook->nextBook = head;
		head = newBook;
	} else {
		newBook->nextBook = currNode->nextBook;
		currNode->nextBook = newBook;
	}
	std::cout << "Book Inserted Successfully!" << std::endl;
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

bool Library::empty()
{
	return head == NULL;	
}

void Library::AllBooks()
{
	int count = 0;
	Book* currBook = head;

	std::cout << "ISBN \t\tName \t\t\t\t\t\t\tPublisher \t\tCategory \tQuantity" << "\n" << std::endl;
	while(currBook != NULL) {
		std::cout << currBook->isbn 
				  << " \t\t" << currBook->name 
				  << " \t\t\t\t" << currBook->publisher 
				  << " \t\t" << currBook->category
				  << " \t\t" << currBook->quantity
				  << " " << std::endl;
		currBook = currBook->getNextBook();
		count++;
	}
	std::cout << "\n" << "Their are " << count << " book(s) in this library." << "\n" << std::endl;
}