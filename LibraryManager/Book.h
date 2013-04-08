#include <string>
#include <iostream>
#include <vector>

#ifndef BOOK_H
#define BOOK_H

class Book {
public:
	Book() { nextBook = NULL; };
	Book(int, int, int, std::string, std::string, std::string);
	Book(int, int, int, std::string, std::string, std::string, std::vector<std::string>);

	Book* setName(std::string n) { name = n; return this; }
	std::string getName() { return name; }

	Book* setCategory(std::string cat) { category = cat; return this; }
	std::string getCategory()const { return category; }

	Book* setPublisher(std::string pub) { publisher = pub; return this; }
	std::string getPublisher()const { return publisher; }

	Book* setQuantity(int quant) { quantity = quant; return this; }
	int getQuantity()const { return quantity; }

	Book* setEdition(int ed) { edition = ed; return this; }
	int getEdition()const { return edition; }

	Book* setAuthors(std::vector<std::string>);
	void clearAuthors();
	void getAuthors();

	int getISBN()const { return isbn; }
	Book* setISBN(int is) { isbn = is; return this; }

	void setNextBook(Book* b) { nextBook = b; }
	Book* getNextBook() { return nextBook; }


private:
	int isbn;
	int quantity;
	int edition;
	std::string name;
	std::vector<std::string> authors;
	std::string category;
	std::string publisher;

	friend class Library;
	Book* nextBook;
};

#endif