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

	void setName(std::string n) { name = n; }
	std::string getName() { return name; }

	void setCategory(std::string cat) { category = cat; }
	std::string getCategory()const { return category; }

	void setPublisher(std::string pub) { publisher = pub; }
	std::string getPublisher()const { return publisher; }

	void setQuantity(int quant) { quantity = quant; }
	int getQuantity()const { return quantity; }

	void setEdition(int ed) { edition = ed; }
	int getEdition()const { return edition; }

	void setAuthors(std::vector<std::string>);
	void getAuthors();

	int getISBN()const { return isbn; }

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