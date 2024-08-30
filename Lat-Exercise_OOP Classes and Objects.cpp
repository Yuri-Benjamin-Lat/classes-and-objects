// Program by: Yuri Benjamin Lat // C2B - OOP

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book
{
public:
	string title, author;
	int year;
	
	Book() : title(""), author(""), year(0) {}
	Book(string t, string a, int y) : title(t), author(a), year(y) {}
};


class Library
{
private:
	const int MaxBooks = 100;	
	Book Books[100];
	int BookCount = 0;
	
public:
	void AddBook(string title, string author, int year)
	{
		if(BookCount < MaxBooks)
		{
			Books[BookCount++] = Book(title, author, year);
			
			cout << "Book added successfully" << endl;
			} 
			else 
			{
				cout << "Library is full! Cannot add more books." << endl;
			}
		}	
	
	void DisplayBooks()
	{
		if(BookCount == 0)
		{
			cout << "No books available!" << endl;
			return;	
		}	
		
		cout << "Book List:" << endl;
		cout << "Title" << setw(25) << "Author" << setw(25) << "Year" << endl;
		cout << "-------------------------------------------------------------" << endl;
		
		for (int i = 0; i < BookCount; i++)
		{
			cout << Books[i].title << setw(18) << " " << Books[i].author << setw(18) << " " << Books[i].year << endl;
		}
	}
	
	void SearchBook(string title)
	{
		for(int i = 0; i < BookCount; i++)
		{
			if(Books[i].title == title)
			{
				cout << "Book found!" << endl;
				cout << "Title: " << Books[i].title << "\nAuthor: " << Books[i].author << "\nYear: " << Books[i].year << endl;
				return;
			}
		}
		cout << "Book not found!" << endl;
	}
};


int main()
{
	Library lib;
	int choice;
	string title, author;
	int year;
	
	while (true)
	{
		cout << "Menu" << endl;
		cout << "1 - Add book" << endl;
		cout << "2 - Display books" << endl;
		cout << "3 - Search books" << endl;
		cout << "4 - Exit" << endl;
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				cout << "\nEnter Title: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                lib.AddBook(title, author, year);
                
                break;
            case 2: 
            	cout << "\nDisplaying books" << endl;
            	lib.DisplayBooks();
            	
            	break;
            case 3:
            	cout << "\nEnter a book to search: ";
            	cin.ignore();
            	getline(cin, title);
            	lib.SearchBook(title);
            	
            	break;
            case 4:
				
            	return 0;
            	
            default:
            	cout << "\nInvalid choice!\n";
		}
		cout << "\n";
	}
}