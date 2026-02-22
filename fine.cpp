#include <iostream>
#include <string>

using namespace std;

class LibraryFineCalculator {
private:
    string memberName;
    string bookTitle;
    string dueDate;
    string returnDate;
    int daysOverdue;
    double totalFine;

public:
    LibraryFineCalculator() {
        daysOverdue = 0;
        totalFine = 0.0;
    }

    void inputDetails() {
        cout << "--- Library Fine System ---" << endl;
        
        cout << "Enter member name: ";
        getline(cin, memberName);
        
        cout << "Enter due date (DD/MM/YYYY): ";
        cin >> dueDate;

        cout << "Enter return date (DD/MM/YYYY): ";
        cin >> returnDate;

        cout << "Enter Book Name: ";
        getline(cin, bookTitle);
        
        cout << "Enter number of days the book is overdue: ";
        cin >> daysOverdue;
    }

    void calculateFine() {
        if (daysOverdue <= 0) {
            totalFine = 0;
        } 
        else if (daysOverdue <= 5) {
            totalFine = daysOverdue * 5.0; 
        } 
        else if (daysOverdue <= 10) {
            totalFine = (5 * 5.0) + ((daysOverdue - 5) * 10.0);
        } 
        else {
            totalFine = (5 * 5.0) + (5 * 10.0) + ((daysOverdue - 10) * 20.0);
        }
    }

    void displayReceipt() {
        cout << "\n-----------------------------" << endl;
        cout << "       FINE RECEIPT" << endl;
        cout << "-----------------------------" << endl;
        cout << "Name of Member: " << memberName << endl;    
        cout << "Book Name: " << bookTitle << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Return Date: " << returnDate << endl;
        cout << "Days Overdue : " << daysOverdue << endl;
        cout << "Total Fine   : " << totalFine << " Rupees " << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    LibraryFineCalculator calculator;
    
    calculator.inputDetails();
    calculator.calculateFine();
    calculator.displayReceipt();

    return 0;
}