#include "Book.h"
#include "Library.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

Book* createBook();
void searchLibrary(Library&);

int main()
{
	Library lib;

	Book* b1 = new Book(1001, 1, 1, "Jack and the Beanstalk", "Fiction", "Carlong");
	Book* b2 = new Book(1002, 1, 1, "Hansel and Gretel", "Fiction", "Carlong");
	Book* b3 = new Book(1003, 1, 1, "Superman Returns", "Fiction", "DC Comics");

	lib.InsertAt(0, b1);
	lib.InsertAt(1, b2);
	lib.InsertAt(2, b3);

	cout << "A library has been created and preloaded with books for you. :)" << endl;

	while(true) {

		int option;

		Sleep(2000);
		system("cls");

		cout << "What would you like to do?" << "\n" 
			 << "1 - View all books in the library \n" 
			 << "2 - Enter a new book into the library \n"
			 << "3 - Search for a book in the library \n"
			 << "4 - Delete a book in the library \n"
			 << "5 - Exit \n"
			 << endl;

		cin >> option;

		if (option == 1)
		{
			system("cls");
			lib.AllBooks();
		} 
		else if (option == 2)
		{
			Book* newBook = createBook();
			lib.InsertAt(3, newBook);

			Sleep(2000);
			system("cls");
		}
		else if (option == 3)
		{
			searchLibrary(lib);
		}
		else if (option == 4)
		{

		}
		else if (option == 5)
		{
			system("cls");
			cout << "Goodbye" << endl;
			return 0;
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

	Sleep(3000);
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
		lib.FindBook(0, searchParam1);
		Sleep(5000);
		break;
	case 2:
		//Search by ISBN
		cout << "Enter the ISBN of the book you would like to search for." << endl;
		cin >> searchParam2;
		lib.FindBook(searchParam2, "Blah");
		Sleep(5000);
		break;
	default:
		cout << "Please choose a valid option!" << endl;
		break;
	}	

}