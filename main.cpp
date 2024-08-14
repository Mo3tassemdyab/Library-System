#include <iostream>
#include <string>
using namespace std;




const int sizeOfLibrary = 10;
string titles[sizeOfLibrary] = { "C++", "Java", "Python" };
string Author[sizeOfLibrary] = { "Moatasen", "Mohamed", "Ahmed" };
int ids[sizeOfLibrary] = {1,2,3 };
bool status[sizeOfLibrary] = { true,false,true };


int numOfBooks = 3;


void mainMenu() {
	cout << "\n1- Display All Books" << endl;
	cout << "2- Add New Book" << endl;
	cout << "3- Borrow Book " << endl;
	cout << "4- Return Book " << endl;
	cout << "5- Update Book " << endl;
	cout << "6- Delete Book " << endl;
	cout << "7- Exit " << endl;
	cout << "\nEnter Your Choice : ";
}

void confirmMenu() {
	cout << "\nDo you wat to confirm\n";
	cout << "1- yes\n";
	cout << "2- No\n";
	cout << "\nYour Choice : ";
}

void updateMenu() {
	cout << "\nWhat do you want to update\n";
	cout << " 1- Book Titile" << endl;
	cout << " 2- Book Author" << endl;
	cout << "Enter choice : " << endl;
}

// 1- Display
void displayOneBook(string t, string a, int i, bool s) {
		string bookStatus = (s) ? "Available" : "Not Available";
		cout << "  Book Info\n\n";
		cout << "Title : " << t << endl;
		cout << "Author : " << a << endl;
		cout << "Id : " << i << endl;
		cout << "Status : " << bookStatus << endl;
		cout << "\n======================================\n";
}

void displayAllBooks() {
	for (int i = 0; i < numOfBooks; i++)
	{
		displayOneBook(titles[i], Author[i],  ids[i], status[i]);
	}
}

// 2- Add
void addNewBook() {
	if (numOfBooks == sizeOfLibrary)
	{
		cout << "\nYou Can't Add New Book\n";
	}
	else
	{
		string title, author;
		cout << "\nEnter Book Name\n";
		cin >> title;
		titles[numOfBooks] = title;
		cout << "\nEnter Book Author\n";
		cin >> author;
		Author[numOfBooks] = author;
		status[numOfBooks] = true;
		ids[numOfBooks] = numOfBooks + 1;
		numOfBooks++;
		cout << "Book Added Successfully\n";
	}



}

// Search
int search(int id) {
	for (int i = 0; i < numOfBooks; i++)
	{
		if (id == ids[i]) {
			return i;
		}
	}
	return -1;
}

// 3- Borrow
void borrowBook() {
	int id, index,choice;
	cout << "\nEnter id of the book you want to borrow\n";
	cin >> id;
	index = search(id);
	if (index == -1)
	{
		cout << "\n This book not found\n";
	}
	else {
		if (status[index])
		{
			displayOneBook(titles[index], Author[index], ids[index], status[index]);
			confirmMenu();
			cin >> choice;
			if (choice == 1)
			{
				cout << "\nBook is borrowed successfully\n";
				status[index] = false;
			}
		}
		else {
			cout << "\nThis book is Already borrowed\n";
		}
	}
}

// 4- Return
void returnBook() {
	int id, index, choice;
	cout << "\nEnter id of the book you want to return\n";
	cin >> id;
	index = search(id);
	if (index == -1)
	{
		cout << "\n This book not found\n";
	}
	else {
		if (status[index] == false)
		{
			displayOneBook(titles[index], Author[index], ids[index], status[index]);
			confirmMenu();
			cin >> choice;
			if (choice == 1)
			{
				cout << "\nBook is returned successfully\n";
				status[index] = true;
			}
			else {
				cout << "\nThis book is Already returned\n";
			}


		}
	}
}

// 5- Update

void updateBook() {
	int id, index, choice1,choice2;
	string str;
	cout << "\nEnter id of the book you want to update\n";
	cin >> id;
	index = search(id);
	if (index == -1)
	{
		cout << "\n This book not found\n";
	}
	else {


		displayOneBook(titles[index], Author[index], ids[index], status[index]);
		confirmMenu();
		cin >> choice1;
		if (choice1 == 1)
		{
			updateMenu();
			cin >> choice2;
			if (choice2 == 1) {
				cout << "\nEnter new title for book\n";
				cin >> str;
				titles[index] = str;
			}
			else if(choice2 == 2)
			{
				cout << "\nEnter new Author for book\n";
				cin >> str;
				Author[index] = str;
			}
			cout << "\nBook Updated Successfully\n";
		}



	}
}


// 6- Delete
void deleteBook() {
	int id, index, choice;
	cout << "\nEnter id of the book you want to delete\n";
	cin >> id;
	index = search(id);
	if (index == -1)
	{
		cout << "\n This book not found\n";
	}
	else {


			displayOneBook(titles[index], Author[index], ids[index], status[index]);
			confirmMenu();
			cin >> choice;
			if (choice == 1)
			{
				if (numOfBooks == id)
				{
					numOfBooks--;
				}
				else {
					for (int i = index; i < numOfBooks; i++)
					{
						titles[i] = titles[i + 1];
						Author[i] = Author[i + 1];
						ids[i] = ids[i + 1];
						status[i] = status[i + 1];
					}
					numOfBooks--;
				}

			}



		}

}


int main()
{
	int choice;
	bool flag = true;
	while (flag)
	{
		mainMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			displayAllBooks();
			break;
		case 2:
			addNewBook();
			break;
		case 3:
			borrowBook();
			break;
		case 4:
			returnBook();
			break;
		case 5:
			updateBook();
			break;
		case 6:
			deleteBook();
			break;
		case 7:
			flag = false;
			break;
		default:
			cout << "\nNot Valid" << endl;
		}

		system("pause");
		system("cls");
	}


}

