#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase(){

    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;

}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){

    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
    
}

void ItemToPurchase::SetName(string name){
    itemName = name;
}

string ItemToPurchase::GetName(){
    return itemName;
}

void ItemToPurchase::SetDescription(string description){
    itemDescription = description;
}

string ItemToPurchase::GetDescription(){
    return itemDescription;
}

void ItemToPurchase::SetPrice(int price){
    itemPrice = price;
}

int ItemToPurchase::GetPrice(){
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity){
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity(){
    return itemQuantity;
}

void ItemToPurchase::PrintItemCost(){

    int cost = itemQuantity * itemPrice;
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << cost << endl;

}

void ItemToPurchase::PrintItemDescription(){
    cout << itemName << ": " << itemDescription << endl;
}
