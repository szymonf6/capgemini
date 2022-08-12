#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;

//declaration struct with elements
struct bookCollection
{
	string title;
	string name;
	string surname;
	string genre;
	string publisher;
	int numOfPages;
	int year;
};

bookCollection book[200];
int numOfBooks;
int z = 0;

//adding books to book collection
void addBooks()
{
	ifstream r("data.txt");
	r >> z;
	//taking the datas about book
	cout << "Warning! Please introduce titles of books as in the example: BraciaKaramazow." << endl;
	cout << "Title of a book: " << endl;
	cin >> book[numOfBooks].title;
	cout << "Author of book: ";
	cin >> book[numOfBooks].name >> book[numOfBooks].surname;
	cout << "Genre of a book:  ";
	cin >> book[numOfBooks].genre;
	cout << "Number of pages:  ";
	cin >> book[numOfBooks].numOfPages;
	cout << "Book year publication:";
	cin >> book[numOfBooks].year;
	cout << "Publisher of book: ";
	cin >> book[numOfBooks].publisher;

	//saving in a txt file
	ofstream save("data.txt", ios_base::app);
	save << book[numOfBooks].title << " ";
	save << book[numOfBooks].name << " ";
	save << book[numOfBooks].surname << " ";
	save << book[numOfBooks].genre << " ";
	save << book[numOfBooks].numOfPages << " ";
	save << book[numOfBooks].year << " ";
	save << book[numOfBooks].publisher << " " << endl;
	cout << "Success! You add a book to a book collection." << endl;
	numOfBooks++;
	ofstream number("number.txt");
	z = z + numOfBooks;
	number << z;
	numOfBooks = 0;
}

//funkcja ktora wyszukuje ksiazki w bazie
void showBookByAuthor()
{
	ifstream r("number.txt");
	r >> z;
	string d;
	string f;
	int k = 0;
	fstream data;
	data.open("data.txt", ios::in);
	for (int i = 0; i < z; i++)
	{
		data >> book[i].title;
		data >> book[i].name;
		data >> book[i].surname;
		data >> book[i].genre;
		data >> book[i].numOfPages;
		data >> book[i].year;
		data >> book[i].publisher;
	}

	cout << "Please, type name of author: " << endl;
	cin >> d;
	cout << "Please, type surname of author: " << endl;
	cin >> f;

	for (int i = 0; i < z; i++)
	{
		if (d == book[i].name && f == book[i].surname)
		{
			cout << book[i].title << "  ";
			cout << book[i].name << "  ";
			cout << book[i].surname << "  ";
			cout << book[i].genre << " ";
			cout << book[i].numOfPages << "  ";
			cout << book[i].year << "  ";
			cout << book[i].publisher << endl;
		}
		else
		{
			k++;
		}
	}
	if (k == z)
	{
		cout << "Books of that author not found! " << endl;
	}
}

void showBookByGenrePublisher()
{
	ifstream r("number.txt");
	r >> z;
	string d;
	string f;
	int k = 0;
	fstream data;
	data.open("data.txt", ios::in);
	for (int i = 0; i < z; i++)
	{
		data >> book[i].title;
		data >> book[i].name;
		data >> book[i].surname;
		data >> book[i].genre;
		data >> book[i].numOfPages;
		data >> book[i].year;
		data >> book[i].publisher;
	}

	cout << "Please, type genre of books: " << endl;
	cin >> d;
	cout << "Please, type publisher of books: " << endl;
	cin >> f;

	for (int i = 0; i < z; i++)
	{
		if (d == book[i].genre && f == book[i].publisher)
		{
			cout << book[i].title << "   ";
			cout << book[i].name << "   ";
			cout << book[i].surname << "   ";
			cout << book[i].genre << "    ";
			cout << book[i].numOfPages << "   ";
			cout << book[i].year << "   ";
			cout << book[i].publisher << endl;
		}
		else
		{
			k++;
		}
	}
	if (k == z)
	{
		cout << "Books of that genre and publisher not found! " << endl;
	}

}

void deleteBook()
{
	ifstream r("number.txt");
	r >> z;
	fstream data;
	data.open("data.txt", ios::in);
	for (int i = 0; i < z; i++)
	{
		data >> book[i].title;
		data >> book[i].name;
		data >> book[i].surname;
		data >> book[i].genre;
		data >> book[i].numOfPages;
		data >> book[i].year;
		data >> book[i].publisher;
	}
	string e;
	int k = 0;
	int a = 0;
	int b = 0;
	char t;
	cout << "Please type a book's title and a year of publication : ";
	cin >> e;
	cin >> b;

	ofstream another("data.txt", ios_base::out);
	for (int i = 0; i <= z; i++)
	{
		if (e == book[i].title && b == book[i].year)
		{
				z--;
				ofstream nNumber("number.txt");
				nNumber << z;
				cout << "Book has been deleted." << endl;
		}
	}
	if (k == z + 1)
	{
		cout << "There is no book like that in book collection." << endl;
		cout << "Would you like to add this book? (T/N)" << endl;
		cin >> t;
		if (t == 'T' || t == 't')
		{
			addBooks();
		}
		else if (t != 'T' || t != 't')
		{

		}
	}
}

int main()
{
	int a = 0;
	do
	{
		cout << "1.Add book to the collection." << endl;
		cout << "2.Delete book from the collection." << endl;
		cout << "3.Show book list of the same author" << endl;
		cout << "4.Show book list by the same genre and publisher" << endl;
		cout << "5. Finish the program " << endl;
		cout << "Funkcja: ";
		cin >> a;
		//funkcja wykonuje sie dopoki nie nacisniemy 6
		switch (a)
		{
		case 1:
			addBooks();
			break;

		case 2:
			deleteBook();
			break;

		case 3:
			showBookByAuthor();
			break;

		case 4:
			showBookByGenrePublisher();
			break;

		case 5:
			return 0;
		}
	} while (a = '7');
}