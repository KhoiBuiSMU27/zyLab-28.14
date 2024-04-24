#include <string>
using namespace std;

class ItemToPurchase {

    private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;

    public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    void SetName(string name);
    string GetName();

    void SetDescription(string description);
    string GetDescription();

    void SetPrice(int price);
    int GetPrice();

    void SetQuantity(int quantity);
    int GetQuantity();

    void PrintItemCost();
    void PrintItemDescription();

};