/*
5. Define a class BOOK with the following specifications :
Private members of the class BOOK are: BOOK NO (integer type),
BOOKTITLE (20 characters), PRICE (float), TOTAL_COST() (A function to
calculate the total cost for N number of copies where N is passed to the
function as argument).
Public members of the class BOOK are: INPUT() – function to read
BOOK_NO., BOOKTITLE, PRICE and PURCHASE() – function to ask the
user to input the number of copies to be purchased. It invokes
TOTAL_COST() and prints the total cost to be paid by the user.
Note: You are also required to give detailed function definitions.
*/

#include <iostream>
using namespace std;
class BOOK
{
private:
    int BOOK_NO;
    char BOOKTITLE[20];
    float PRICE;
    int TOTAL_COST(int N)
    {
        return PRICE * N;
    }

public:
    void INPUT()
    {
        cout << "Enter Book.No, Book title and Price: " << endl;
        cin >> BOOK_NO >> BOOKTITLE >> PRICE;
    }
    void PURCHASE()
    {
        int n;
        float total;
        cout << "Enter the number of copies to be purchased: ";
        cin >> n;
        total = TOTAL_COST(n);
        cout << "Total price to be paid: " << total;
    }
};
int main()
{
    BOOK b1;
    b1.INPUT();
    b1.PURCHASE();
    return 0;
}