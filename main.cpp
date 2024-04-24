#include <iostream>
#include <iomanip>
#include "ShoppingCart.h"
using namespace std;

void PrintMenu() {
    
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;

}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    
    string itemName, itemDescription;
    int itemPrice, itemQuantity;

    cout << endl;

    if (option == 'a'){

        cout << "ADD ITEM TO CART" << endl;

        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, itemName);

        cout << "Enter the item description:" << endl;
        getline(cin, itemDescription);

        cout << "Enter the item price:" << endl;
        cin >> itemPrice;

        cout << "Enter the item quantity:" << endl;
        cin >> itemQuantity;

        ItemToPurchase addItem(itemName, itemDescription, itemPrice, itemQuantity);
        theCart.AddItem(addItem);

    }
    else if (option == 'd'){

        cout << "REMOVE ITEM FROM CART" << endl;

        cout << "Enter name of item to remove:" << endl;
        cin.ignore();
        getline(cin, itemName);

        theCart.RemoveItem(itemName);

    }
    else if (option == 'c'){

        cout << "CHANGE ITEM QUANTITY" << endl;

        cout << "Enter the item name:" << endl;
        cin.ignore();
        getline(cin, itemName);

        cout << "Enter the new quantity:" << endl;
        cin >> itemQuantity;

        ItemToPurchase changeItem;
        changeItem.SetName(itemName);
        changeItem.SetQuantity(itemQuantity);

        theCart.ModifyItem(changeItem);

    }
    else if (option == 'i'){

        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        theCart.PrintDescriptions();

    }
    else if (option == 'o'){

        cout << "OUTPUT SHOPPING CART" << endl;
        theCart.PrintTotal();

    }
   
}

int main() {
    
    string customerName;
    string currentDate;
    char option = ' ';

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);

    ShoppingCart cart(customerName, currentDate);

    while (option != 'q'){

        cout << endl;
        cout << "MENU" << endl;
        PrintMenu();

        while (true){
            
            cout << "Choose an option: ";
            cin >> option;

            if ((option == 'a') || (option == 'd') || (option == 'c') || (option == 'i') || (option == 'o') || (option == 'q'))
                break;
            else   
                continue;    

        }

        ExecuteMenu(option, cart);

    }

    return 0;

}
