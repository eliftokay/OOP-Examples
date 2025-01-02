#include <iostream>
#include <string>
using namespace std;

class Book;

class Librarian {
private:
    int id;
    string name;

public:
    Librarian(int id, string name) {
        this->id = id;
        this->name = name;
    }
    void updateStock(Book book, int newStock) {
        book.stock = newStock;
    }
};

class Book {

private:
    int stock;

public:
    string name;
    string author;

    Book(string name, string author) {
        this->name = name;
        this->author = author;
        this->stock = 0;
    }

    void displayStock() {
        cout << "Stock: " << stock << endl;
    }

    friend class Librarian;
};

//void Librarian::updateStock(Book& book, int newStock) {
//    book.stock = newStock; // Update Stock
//}

int main() {
    Book book("1984", "George Orwell");
    Librarian librarian(1, "Michael Scofield");

    book.displayStock();
    librarian.updateStock(book, 10);
    book.displayStock();

    return 0;
}
