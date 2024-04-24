#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(){

    customerName = "none";
    currentDate = "January 1, 2016";

}

ShoppingCart::ShoppingCart(string name, string date){

    customerName = name;
    currentDate = date;

}

string ShoppingCart::GetCustomerName(){
    return customerName;
}

string ShoppingCart::GetDate(){
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item){
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name){

    for (int i = 0; i < cartItems.size(); i++)
        if (cartItems[i].GetName() == name){
            cartItems.erase(cartItems.begin() + i);
            return;
        }

    cout << "Item not found in cart. Nothing removed." << endl;    
            
}

void ShoppingCart::ModifyItem(ItemToPurchase item){

    for (int i = 0; i < cartItems.size(); i++)
        if (cartItems[i].GetName() == item.GetName()){
            cartItems[i].SetQuantity(item.GetQuantity());
            return;
        }
                
    cout << "Item not found in cart. Nothing removed." << endl;

}

int ShoppingCart::GetNumItemsInCart(){

    int numItems = 0;

    for (int i = 0; i < cartItems.size(); i++)
        numItems += cartItems[i].GetQuantity();
    
    return numItems;

}

int ShoppingCart::GetCostOfCart(){

    int totalCost = 0;
    int cost = 0;

    for (int i = 0; i < cartItems.size(); i++){
        cost = cartItems[i].GetPrice() * cartItems[i].GetQuantity();
        totalCost += cost;
    }

    return totalCost;
        
}

void ShoppingCart::PrintTotal(){

    if (cartItems.size() == 0)
        cout << "SHOPPING CART IS EMPTY" << endl;

    else {

        cout << customerName << "'s Shopping Cart - " << currentDate << endl;
        cout << "Number of Items: " << GetNumItemsInCart() << endl;
        cout << endl;

        for (int i = 0; i < cartItems.size(); i++)
            cartItems[i].PrintItemCost();
        
        cout << endl;
        cout << "Total: $" << GetCostOfCart() << endl;

    }

}

void ShoppingCart::PrintDescriptions(){

    if (cartItems.size() == 0)
        cout << "SHOPPING CART IS EMPTY" << endl;

    else {

        cout << customerName << "'s Shopping Cart - " << currentDate << endl;
        cout << endl;
        cout << "Item Descriptions" << endl;

        for (int i = 0; i < cartItems.size(); i++)
            cartItems[i].PrintItemDescription();
            
    }
}