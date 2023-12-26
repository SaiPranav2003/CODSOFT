//Library Management System



#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    Book(const string& t, const string& a, const string& isbn) : title(t), author(a), ISBN(isbn), isAvailable(true) {}
};

class Borrower {
public:
    string name;
    vector<Book*> borrowedBooks;

    Borrower(const string& n) : name(n) {}
};

class Transaction {
public:
    Book* book;
    Borrower* borrower;
    time_t checkoutDate;
    time_t returnDate;

    Transaction(Book* b, Borrower* bor) : book(b), borrower(bor) {
        checkoutDate = time(nullptr);
        returnDate = 0; 
    }
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
    const double fine_Per_Day = 0.5;

public:
    // for book management
    void addBook(const string& title, const string& author, const string& ISBN) {
        books.push_back(Book(title, author, ISBN));
        cout << "Book added successfully." << endl;
    }

    Book* findBook(const string& searchKey) {
        for (auto& book : books) {
            if (book.title == searchKey || book.author == searchKey || book.ISBN == searchKey) {
                return &book;
            }
        }
        return nullptr;
    }

    // for borrower management
    void addBorrower(const string& name) {
        borrowers.push_back(Borrower(name));
        cout << "Borrower added successfully." << endl;
    }

    Borrower* findBorrower(const string& name) {
        auto it = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& b) {
            return b.name == name;
        });

        return (it != borrowers.end()) ? &(*it) : nullptr;
    }

    //  for transactions
    void checkoutBook(Book* book, Borrower* borrower) {
        if (book->isAvailable) {
            transactions.push_back(Transaction(book, borrower));
            book->isAvailable = false;
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book is not available for checkout." << endl;
        }
    }

    void returnBook(Book* book) {
        auto it = find_if(transactions.begin(), transactions.end(), [&](const Transaction& t) {
            return t.book == book && t.returnDate == 0; 
        });

        if (it != transactions.end()) {
            it->returnDate = time(nullptr);
            book->isAvailable = true;
            calculateFine(*it);
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book is not currently checked out." << endl;
        }
    }

    void calculateFine(const Transaction& transaction) {
        double fine = 0.0;
        time_t daysOverdue = difftime(time(nullptr), transaction.returnDate) / (24 * 3600);

        if (daysOverdue > 0) {
            fine = daysOverdue;
          cout << "Fine calculated: " << fixed << setprecision(2) << fine <<" rupees"<<" (for " << daysOverdue << " days overdue)" << endl;
        }
    }

    // to display available books
    void displayAvailableBooks() const {
    
        cout << "Available Books:" << endl;
        cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(15) << "ISBN" << endl;
        cout << string(65, '-') << endl;
        if (books.empty()) {
        cout << "No books available in the library." << endl;
    } 
else{
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isAvailable) {
                cout << setw(5) << i + 1 << setw(20) << books[i].title << setw(20) << books[i].author << setw(15) << books[i].ISBN << endl;
            }
        }
    }
}


};

// to display the main menu
char displayMainMenu() {
    cout << "           === Library Management System ===           " << endl;
    cout<<endl;
    cout << "1. Add Book\n2. Add Borrower\n3. Check out Book\n4. Return Book\n5. Display Available Books\n6. Exit" << endl;
    cout<<endl;
    cout << "Enter your choice: ";
    char choice;
    cin >> choice;
    return choice;
}

int main() {
    Library library;

    char choice;
    do {
        choice = displayMainMenu();

        switch (choice) {
            case '1': {
                string title, author, ISBN;
                cout << "Enter book title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                cin >> ISBN;
                library.addBook(title, author, ISBN);
                break;
            }
            case '2': {
                string borrowerName;
                cout << "Enter borrower name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, borrowerName);
                library.addBorrower(borrowerName);
                break;
            }
            case '3': {
                string searchKey;
                cout << "Enter book title, author, or ISBN to search: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, searchKey);
                Book* bookToCheckout = library.findBook(searchKey);

                if (bookToCheckout) {
                    string borrowerName;
                    cout << "Enter borrower name: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, borrowerName);

                    Borrower* borrower = library.findBorrower(borrowerName);

                    if (borrower) {
                        library.checkoutBook(bookToCheckout, borrower);
                    } else {
                        cout << "Borrower not found. Please add the borrower first." << endl;
                    }
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case '4': {
                string searchKey;
                cout << "Enter book title, author, or ISBN to search: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, searchKey);
                Book* bookToReturn = library.findBook(searchKey);

                if (bookToReturn) {
                    library.returnBook(bookToReturn);
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case '5':
                library.displayAvailableBooks();
                break;
            case '6':
                cout << "Exiting the Library Management System!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != '6');
}
