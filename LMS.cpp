#include <iostream>
using namespace std;

// Abstract Base Class
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    // Getters
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

// Book Class
class Book : public LibraryItem
{
public:
    Book(string t, string a, string d)
        : LibraryItem(t, a, d) {}

    void checkOut()
    {
        cout << "Book Checked Out\n";
    }

    void returnItem()
    {
        cout << "Book Returned\n";
    }

    void displayDetails()
    {
        cout << "\nBook: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate() << endl;
    }
};

// DVD Class
class DVD : public LibraryItem
{
public:
    DVD(string t, string a, string d)
        : LibraryItem(t, a, d) {}

    void checkOut()
    {
        cout << "DVD Checked Out\n";
    }

    void returnItem()
    {
        cout << "DVD Returned\n";
    }

    void displayDetails()
    {
        cout << "\nDVD: " << getTitle();
        cout << "\nAuthor: " << getAuthor();
        cout << "\nDue Date: " << getDueDate() << endl;
    }
};

int main()
{
    LibraryItem* items[2];

    items[0] = new Book("C++ Programming", "Bjarne", "01-12-2026");
    items[1] = new DVD("Learning OOP", "Teacher", "05-12-2026");

    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Display Items";
        cout << "\n2. Check Out";
        cout << "\n3. Return Item";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            items[0]->displayDetails();
            items[1]->displayDetails();
            break;

        case 2:
            items[0]->checkOut();
            items[1]->checkOut();
            break;

        case 3:
            items[0]->returnItem();
            items[1]->returnItem();
            break;

        case 4:
            cout << "\nProject Exited Successfully!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 4);

    delete items[0];
    delete items[1];

    return 0;
}