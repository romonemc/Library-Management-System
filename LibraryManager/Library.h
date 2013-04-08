#include "Book.h"
#include <string>
#include <iostream>

#ifndef LIBRARY_H
#define	LIBRARY_H

class Library {
public:
	Library();
	~Library(void);

	bool Empty();
	std::string front();
	int InsertAt(int, const Book*);
	void removeAt(int, const Book);
	int SearchLibrary(int = 0, std::string n = "Blah");
	int DeleteBook(int);
	int DeleteBook(std::string);
	void EditBook(std::string);
	void AllBooks(void);
	void DisplayBookInfo(std::string);
	int Count(void);
private:
	Book* head;
	int size;
};

#endif