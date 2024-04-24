#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {

    private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;

    public:
    ShoppingCart();
    ShoppingCart(string name, string date);

    string GetCustomerName();
    string GetDate();

    void AddItem(ItemToPurchase item);
    void RemoveItem(string name);
    void ModifyItem(ItemToPurchase item);

    int GetNumItemsInCart();
    int GetCostOfCart();

    void PrintTotal();
    void PrintDescriptions();

};