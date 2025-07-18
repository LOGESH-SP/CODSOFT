#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAX_DAYS = 14;  // allowed borrowing days
const int FINE_PER_DAY = 2; // fine in currency per extra day

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable = true;
    string borrowerName = "";
    time_t borrowDate = 0;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "Enter title: ";
    getline(cin >> ws, b.title);
    cout << "Enter author: ";
    getline(cin, b.author);
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    library.push_back(b);
    cout << "Book added successfully!\n";
}

void displayBooks() {
    cout << "\nList of Books:\n";
    for (size_t i = 0; i < library.size(); ++i) {
        cout << i+1 << ". " << library[i].title
             << " | Author: " << library[i].author
             << " | ISBN: " << library[i].isbn
             << " | Status: " << (library[i].isAvailable ? "Available" : "Borrowed")
             << endl;
    }
}

void searchBooks() {
    string query;
    int choice;
    cout << "Search by: 1. Title  2. Author  3. ISBN\nChoice: ";
    cin >> choice;
    cout << "Enter search query: ";
    getline(cin >> ws, query);
    
    bool found = false;
    for (auto &book : library) {
        if ((choice == 1 && book.title.find(query) != string::npos) ||
            (choice == 2 && book.author.find(query) != string::npos) ||
            (choice == 3 && book.isbn.find(query) != string::npos)) {
            cout << "\nTitle: " << book.title << "\nAuthor: " << book.author
                 << "\nISBN: " << book.isbn << "\nStatus: "
                 << (book.isAvailable ? "Available" : "Borrowed")
                 << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching books found.\n";
}

void checkoutBook() {
    string isbn, borrower;
    cout << "Enter ISBN of the book to borrow: ";
    getline(cin >> ws, isbn);
    for (auto &book : library) {
        if (book.isbn == isbn && book.isAvailable) {
            cout << "Enter borrower's name: ";
            getline(cin, borrower);
            book.isAvailable = false;
            book.borrowerName = borrower;
            book.borrowDate = time(0);
            cout << "Book checked out to " << borrower << ".\n";
            return;
        }
    }
    cout << "Book not available or ISBN not found.\n";
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    getline(cin >> ws, isbn);
    for (auto &book : library) {
        if (book.isbn == isbn && !book.isAvailable) {
            time_t now = time(0);
            int daysBorrowed = (now - book.borrowDate) / (60 * 60 * 24);
            cout << "Book borrowed by: " << book.borrowerName << endl;
            cout << "Days borrowed: " << daysBorrowed << endl;
            
            if (daysBorrowed > MAX_DAYS) {
                int fine = (daysBorrowed - MAX_DAYS) * FINE_PER_DAY;
                cout << "Overdue! Fine to be paid: " << fine << "\n";
            } else {
                cout << "Returned within allowed time. No fine.\n";
            }

            book.isAvailable = true;
            book.borrowerName = "";
            book.borrowDate = 0;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found or already available.\n";
}

void showMenu() {
    cout << "\n===== Library Management Menu =====\n";
    cout << "1. Add Book\n";
    cout << "2. Search Books\n";
    cout << "3. Display All Books\n";
    cout << "4. Checkout Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBooks(); break;
            case 3: displayBooks(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}

