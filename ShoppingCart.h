#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h" //
using namespace std;

class ShoppingCart {

public:
  //ShoppingCart();
  ShoppingCart(string customerName = "none", string currentDate = "January 1, 2016");
  string GetCustomerName() const;
  string GetDate() const;
  //void AddItem(vector<ItemToPurchase> cartItems);
  void AddItem(ItemToPurchase cartItems);
  void RemoveItem(string itemName); //
  int GetNumItemsInCart() const;
  int GetCostOfCart() const;
  void PrintTotal();
  void PrintDescriptions();
  

private:
  string customerName;
  string currentDate;
  vector<ItemToPurchase> cartItems;
};

#endif
