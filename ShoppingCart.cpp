#include <iostream>
using namespace std;

#include "ShoppingCart.h"

/*ShoppingCart::ShoppingCart() {
  string customerName = "none";
  string currentDate = "January 1, 2016";
}*/

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
  this->customerName = customerName;
  this->currentDate = currentDate;
}

string ShoppingCart::GetCustomerName() const {
  return customerName;
}

string ShoppingCart::GetDate() const {
  return currentDate;
}

//void ShoppingCart::AddItem(vector<ItemToPurchase> cartItems) 
void ShoppingCart::AddItem(ItemToPurchase cartItem) {
  cartItems.push_back(cartItem);
  // Adds an item to cartItems vector. Has a parameter of type ItemToPurchase. Does not return anything.
  /*string itemName;
  string itemDesc;
  int itemPrice;
  int itemQty;
  cout << "Enter the item name:" << endl;
  cin >> itemName;
  cout << "Enter the item description:" << endl;
  cin >> itemDesc;
  cout << "Enter the item price:" << endl;
  cin >> itemPrice;
  cout << "Enter the item quantity:" << endl;
  cin >> itemQty;
  ItemToPurchase newItem(itemName, itemDesc, itemPrice, itemQty);
  cartItems.push_back(newItem);*/
}

void ShoppingCart::RemoveItem(string itemName) { //FIXME !!!
  //Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
  //If item name cannot be found, output this message: "Item not found in cart. Nothing removed."
  bool itemFound = false;
  for (int i = 0; i < cartItems.size(); ++i) {
    if ((cartItems.at(i)).GetName() == itemName) {
      cartItems.erase(cartItems.begin()+i);
      itemFound = true;
      //break;
      i = cartItems.size() - 1;
    }
  }
  if (itemFound == false){
    cout << "Item not found in cart. Nothing removed." << endl << endl;
  }
}

int ShoppingCart::GetNumItemsInCart() const {
  int itemTotal = 0;
  for (int i = 0; i < cartItems.size(); ++i) {
    itemTotal = itemTotal + (cartItems.at(i)).GetQuantity();
  }
  return itemTotal;
  //return cartItems.size(); //Returns quantity of all items in cart. Has no parameters.
}

int ShoppingCart::GetCostOfCart() const {
  double cartCost = 0.0;
  for (int i = 0; i < cartItems.size(); ++i) {
    cartCost = cartCost + ((cartItems.at(i)).GetPrice() * (cartItems.at(i).GetQuantity()));
  }
  return cartCost; //Determines and returns the total cost of items in cart. Has no parameters.
}

void ShoppingCart::PrintTotal() {
  //Outputs total of objects in cart.
  //If cart is empty, output this message: SHOPPING CART IS EMPTY
  int cartTotal = 0;
  int itemTotal = 0;
  for (int i = 0; i < cartItems.size(); ++i) {
    itemTotal = itemTotal + (cartItems.at(i)).GetQuantity();
  }
  cout << customerName << "\'s Shopping Cart - " << currentDate << endl;
  cout << "Number of Items: " << itemTotal << endl << endl;
  if (cartItems.size() > 0) {
    for (int i = 0; i < cartItems.size(); ++i) {
      cout << (cartItems.at(i)).GetName() << " " << (cartItems.at(i)).GetQuantity()
           << " @ $" << (cartItems.at(i)).GetPrice() << " = $" 
           << (cartItems.at(i)).GetQuantity() * (cartItems.at(i)).GetPrice() << endl;
      cartTotal = cartTotal + ((cartItems.at(i)).GetQuantity() * (cartItems.at(i)).GetPrice());
    }
  }
  else {
    cout << "SHOPPING CART IS EMPTY" << endl << endl;
  }
  cout << "Total: $" << cartTotal << endl << endl;
}

void ShoppingCart::PrintDescriptions() {
  //Outputs each item's description.
  cout << customerName << "\'s Shopping Cart - " << currentDate << endl;
  cout << endl;
  cout << "Item Descriptions" << endl;
  for (int i = 0; i < cartItems.size(); ++i) {
    cout << (cartItems.at(i)).GetName() << ": " << (cartItems.at(i)).GetDescription() << endl;
  }
  cout << endl;
}
