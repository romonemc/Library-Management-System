/*
	name: Library/Book Management System
	programmer: Romone Mcfarlane
	date: April 2, 2013
	programme: MIS 2
	
*/

#include "Book.h"
#include "Library.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

Book* createBook();
void searchLibrary(Library&);
void deleteBook(Library&);
void watchPup();

void PreloadLibrary(Library &lib)
{
	/* Preloading a library */

	Book* b1 = new Book(1001, 1, 1, "Jack and the Beanstalk", "Fiction", "Carlong");
	Book* b2 = new Book(1002, 1, 1, "Hansel and Gretel", "Fiction", "Carlong");
	Book* b3 = new Book(1003, 1, 1, "Superman Returns", "Fiction", "DC Comics");
	Book* b4 = new Book(1004, 1, 1, "Jasper and the Evil Monkey", "Fiction", "Bentham Books");

	lib.InsertAt(0, b1);
	lib.InsertAt(1, b2);
	lib.InsertAt(2, b3);
	lib.InsertAt(3, b4);

	/* END Preloading */

	cout << "A library has been created and preloaded with books for you. :)" << endl;
}

int main()
{
	Library lib;

	while(true) {

		int option;
		system("cls");

		cout << "What would you like to do?" << "\n" 
			 << "1. View all books in the library \n" 
			 << "2. Enter a new book into the library \n"
			 << "3. Search for a book in the library \n"
			 << "4. Delete a book in the library \n"
			 << "5. Edit a book in the library \n"
			 << "6. View the information for a book.\n"
			 << "7. Preload Library."
			 << endl;

		cin >> option;

		if (option == 1) // List all books in library
		{
			system("cls");
			lib.AllBooks();
			watchPup();
		} 
		else if (option == 2) // Enter a new book
		{
			int pos;
			int count = lib.Count();

			Book* newBook = createBook();
			cout << endl;
			cout << "Where would you like to insert this book?" << endl;
			cout << "There are " << count << " books in the library." << endl;
			cout << "Pro Tip - Enter 1 to insert it at the beginning and " << count + 1 << " to enter it at the end." << endl;
			cin >> pos;
			lib.InsertAt(pos - 1, newBook);

			Sleep(2000);
			system("cls");
		}
		else if (option == 3) // Search for a book
		{
			searchLibrary(lib);
		}
		else if (option == 4) // Delete a book
		{
			deleteBook(lib);
		}
		else if(option == 5) // Edit a book
		{
			string book;

			cin.ignore();
			cout << "Please enter the name of the book that you would like to edit." << endl;
			getline(cin, book);

			lib.EditBook(book);
			Sleep(2000);
		}
		else if(option == 6)
		{
			string book;

			cin.ignore();
			cout << "Please enter the name of the book that you would like to view." << endl;
			getline(cin, book);

			lib.DisplayBookInfo(book);
			watchPup();
		} 
		else if (option == 7)
		{
			PreloadLibrary(lib);
		}
		else {

			system("cls");
			cout << "Please enter a valid option!" << endl;
			Sleep(1000);
		}

	}

	return 0;
}

// Creates a new book.
Book* createBook()
{
	system("cls");

	int isbn;
	int edition;
	int quantity;
	int no_authors;
	string name;
	string publisher;
	string category;
	string author_name;
	vector<string> authors;

	cout << "ISBN: " << endl;
	cin >> isbn;
	cin.ignore();

	cout << "Name: " << endl;
	getline(cin, name);

	cout << "Edition: " << endl;
	cin >> edition;

	cout << "Quantity: " << endl;
	cin >> quantity;
	cin.ignore();

	cout << "Publisher: " << endl;
	getline(cin, publisher);

	cout << "Category (Fiction or Non-Fiction): " << endl;
	cin >> category;

	cout << "How many authors does " << name << " have?" << endl;
	cin >> no_authors;
	cin.ignore();

	for (int i = 0; i < no_authors; i++)
	{
		cout << "Enter the name of author " << i + 1 << endl;
		getline(cin, author_name);

		authors.push_back(author_name);
	}

	Book* newbook = new Book(isbn, quantity, edition, name, category, publisher, authors);
	cout << name << " succesfully created!" << endl;

	Sleep(2000);
	return newbook;
}

void searchLibrary(Library& lib)
{
	string searchParam1;
	int searchParam2 = 1;
	int option;

	system("cls");

	cout << "How would you like to search? \n"
		 << "1 - By Name \n"
		 << "2 - By ISBN"
		 << endl;
	cin >> option;
	cout << endl;
	switch (option)
	{
	case 1:
		cin.ignore();
		// Search by Name
		cout << "Enter the name of the book you would like to search for." << endl;
		getline(cin, searchParam1);
		lib.SearchLibrary(0, searchParam1);
		watchPup();
		break;
	case 2:
		//Search by ISBN
		cout << "Enter the ISBN of the book you would like to search for." << endl;
		cin >> searchParam2;
		lib.SearchLibrary(searchParam2, "Blah");
		watchPup();
		break;
	default:
		cout << "Please choose a valid option!" << endl;
		break;
	}	

}

void deleteBook(Library& lib)
{
	int option;
	string deleteParam1;
	int deleteParam2;

	system("cls");

	cout << "You can either \n"
		 << "1 - Delete by ISBN \n"
		 << "2 - Delete by name of book \n"
		 << "3 - Delete most recently added book."
		 << endl;
	cin >> option;
	cout << endl;
	switch (option)
	{
	case 2:
		cin.ignore();
		// Search by Name
		cout << "Enter the name of the book you would like to delete." << endl;
		getline(cin, deleteParam1);
		lib.DeleteBook(deleteParam1);
		Sleep(3000);
		break;
	case 1:
		//Search by ISBN
		cout << "Enter the ISBN of the book you would like to delete." << endl;
		cin >> deleteParam2;
		lib.DeleteBook(deleteParam2);
		Sleep(3000);
		break;
	default:
		cout << "Please choose a valid option!" << endl;
		break;
	}

}

// Gives user option to return to menu
void watchPup()
{
	string key;

	Sleep(3000);
	cout << "\n" << "Press any key to return to menu" << endl;
	cin >> key;
	system("cls");
	cout << "Warping..." << endl;
	Sleep(500);
	system("cls");	

}