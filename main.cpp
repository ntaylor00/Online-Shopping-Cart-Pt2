#include <iostream>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
  cout << "MENU" << endl;
  cout << "a - Add item to cart" << endl
       << "d - Remove item from cart" << endl
       << "c - Change item quantity" << endl
       << "i - Output items' descriptions" << endl
       << "o - Output shopping cart" << endl
       << "q - Quit" << endl << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
  if (option == 'q') { // quit
    option = 'q'; //???
  }
  else if (option == 'a') { // add item to cart
    string itemName;
    string itemDesc;
    string tempStr;
    int itemPrice;
    int itemQty;
    cout << "ADD ITEM TO CART" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, tempStr);//cin >> itemName; //THIS IS THE PROBLEM
    getline(cin, itemName); //THIS IS THE PROBLEM
    cout << "Enter the item description:" << endl; //FIXME, skips item name
    getline(cin, itemDesc);
    cout << "Enter the item price:" << endl;
    cin >> itemPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> itemQty;
    cout << endl;
    ItemToPurchase newItem(itemName, itemDesc, itemPrice, itemQty);
    theCart.AddItem(newItem); //FIXME
  }
  else if (option == 'd') { // remove item from cart
    // FIXME
    string itemToRemove;
    string tempStr;
    cout << "REMOVE ITEM FROM CART" << endl;
    cout << "Enter name of item to remove:" << endl;
    getline(cin, tempStr);
    getline(cin, itemToRemove);
    theCart.RemoveItem(itemToRemove);
  }
  else if (option == 'c') { // change item quantity
    /*string itemToChange;
    string tempStr;
    int newQuantity;
    string tempDesc;// = //(theCart[itemToChange]).GetDescription(); //FIXME
    int tempPrice;// = //.GetPrice(); //FIXME
    ItemToPurchase newItem(itemToChange, tempDesc, tempPrice, newQuantity);
    cout << "CHANGE ITEM QUANTITY" << endl;
    getline(cin, tempStr);
    getline(cin, itemToChange);
    theCart.RemoveItem(itemToChange);
    theCart.AddItem(newItem);*/
    
    /*for (int i = 0; i < theCart.GetNumItemsInCart(); ++i) {
      if (theCart.GetName() == itemToChange) {
        //.SetQuantity() = newQuantity;
      }
    }*/
  }
  else if (option == 'i') { // output items' descriptions
    cout << "OUTPUT ITEMS\' DESCRIPTIONS" << endl;
    theCart.PrintDescriptions();
  }
  else if (option == 'o') { // output shopping cart
    cout << "OUTPUT SHOPPING CART" << endl;
    theCart.PrintTotal();
  }
}

int main() {
  
  string userName;
  string userDate;
  char userChoice;

  cout << "Enter customer's name:" << endl;
  getline(cin, userName);
  cout << "Enter today's date:" << endl;
  getline(cin, userDate);

  if (userName.length() == 0) {
    userName = "none";
  }
  if (userDate.length() == 0) {
    userDate = "January 1, 2016";
  }
  
  ShoppingCart cart1(userName, userDate); //FIXME

  cout << "Customer name: " << cart1.GetCustomerName() << endl;
  cout << "Today's date: " << cart1.GetDate() << endl << endl;

  while (userChoice != 'q') {
    PrintMenu();
    cout << "Choose an option:" << endl;
    cin >> userChoice;

    while (userChoice != 'a' && userChoice != 'd' && userChoice != 'c' && userChoice != 'i' && userChoice != 'o' && userChoice != 'q') {
      // continue to prompt cout << "Invalid choice. Choose an option:" << endl; ???
      cout << "Choose an option:" << endl;
      cin >> userChoice;
    }

    ExecuteMenu(userChoice, cart1);
    if (userChoice == 'q') {
      break;
    }
  }

  
  return 0;
}

/*int main() {

  ItemToPurchase item1;
  ItemToPurchase item2;

  string nameOfItem;
  int priceOfItem;
  int quantityOfItem;
   
  cout << "Item 1" << endl;
  cout << "Enter the item name:" << endl;

  getline(cin, nameOfItem);
  item1.SetName(nameOfItem);

  cout << "Enter the item price:" << endl;

  cin >> priceOfItem;
  item1.SetPrice(priceOfItem);

  cout << "Enter the item quantity:" << endl;

  cin >> quantityOfItem;
  item1.SetQuantity(quantityOfItem);

  cin.ignore();

  cout << endl << "Item 2" << endl;
  cout << "Enter the item name:" << endl;

  getline(cin, nameOfItem);
  item2.SetName(nameOfItem);

  cout << "Enter the item price:" << endl;

  cin >> priceOfItem;
  item2.SetPrice(priceOfItem);

  cout << "Enter the item quantity:" << endl;

  cin >> quantityOfItem;
  item2.SetQuantity(quantityOfItem);

  cout << "TOTAL COST" << endl;

  cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice()
       << " = $" << (item1.GetQuantity() * item1.GetPrice()) << endl;
  cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice()
       << " = $" << (item2.GetQuantity() * item2.GetPrice()) << endl;
  cout << endl << "Total: $" << ((item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice())) << endl;
   
   return 0;
}*/ // old main
