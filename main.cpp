#include <iostream>
#include <vector>
#include <windows.h>

// yassine abbou , software engineering student & Code enthusiast & problem solver

using namespace std;



class Book {
public:
    string title, author;
    int publicationYear;

    // Default constructor
    Book() {
        title = "";
        author = "";
        publicationYear = 0;
    }

    Book(string title, string author, int publicationYear) {
        this->title = title;
        this->author = author;
        this->publicationYear = publicationYear;
    }

    void displayBook() {
        cout << "Title: " << title << ", Author: " << author << ", Publication Year: " << publicationYear << '\n';
    }
};

class Library {
public:
    vector<Book> bookList;

    void addBook(Book& book) {
        bookList.push_back(book);
    }

    void displayBooks() {
        cout << "\n\t\t\tDisplaying books in the library:\n" << endl;
        for (int i = 0; i < bookList.size(); i++) {
            cout << "Book " << i + 1 << ":\n";
            bookList[i].displayBook();
        }
    }

    int searchBook(string title) {
        for (int i = 0; i < bookList.size(); i++) {
            if (bookList[i].title.find(title) != string::npos) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    system("cls");
    system("color 0a");
    Library library;

    int choice;
    do {
        system("cls");
        cout << "\t\t\t*******************Library Management************************\n\n" << endl;
        cout << "\t1. Add a book to the library " << endl;
        cout << "\t2. Display all books in the library" << endl;
        cout << "\t3. Search for a book by title" << endl;
        cout << "\t0. Quit" << endl;
        cout << "\n\t\t\tChoice: ";

        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            system("color 0b");
            string title, author;
            int publicationYear;
            cout << "\n\tEnter the title of the book: ";
            fflush(stdin);
            getline(cin, title);

            cout << "\tEnter the author's name: ";
            getline(cin, author);

            cout << "\tEnter the publication year of the book: ";
            cin >> publicationYear;

            Book book(title, author, publicationYear);
            library.addBook(book);
            cout << "\tBook added! \n\n\n\n" << '\n';
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            system("color 0c");
            library.displayBooks();
            cout << "\n\n\n";
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            string searchTitle;
            cout << "\n\tEnter the title of the book to search: ";
            cin >> searchTitle;
            int result = library.searchBook(searchTitle);
            if (result != -1)
                cout << "\tThe book exists." << endl;
            else
                cout << "\tThe book does not exist!" << endl;
            cout << "\n\n\n";
            system("pause");
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
