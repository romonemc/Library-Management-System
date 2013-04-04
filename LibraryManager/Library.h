#include "Book.h"
#include <string>
#include <iostream>

#ifndef LIBRARY_H
#define	LIBRARY_H

class Library {
public:
	Library();
	~Library(void);

	bool empty();
	std::string front();
	int InsertAt(int, const Book*);
	void removeAt(int, const Book);
	int FindBook(int = 0, std::string n = "Blah");
	int DeleteBook(int = 0, std::string n = "Blah");
	void AllBooks(void);
	int Count(void);
private:
	Book* head;
	int size;
};

#endif