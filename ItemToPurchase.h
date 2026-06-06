#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {

public:
  ItemToPurchase();
  ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity);
  void SetName(string itemName);
  string GetName() const;
  void SetPrice(int itemPrice);
  int GetPrice() const;
  void SetQuantity(int itemQuantity);
  int GetQuantity() const;
  void SetDescription(string itemDescription);
  string GetDescription() const;
  void PrintItemCost();
  void PrintItemDescription();

private:
  string itemName;
  int itemPrice;
  int itemQuantity;
  string itemDescription;

};

#endif
