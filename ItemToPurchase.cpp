#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
  itemName = "none";
  itemPrice = 0;
  itemQuantity = 0;
  itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity) {
  this->itemName = itemName;
  this->itemDescription = itemDescription;
  this->itemPrice = itemPrice;
  this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetName(string itemName) {
  this->itemName = itemName;
}

string ItemToPurchase::GetName() const {
  return itemName;
}

void ItemToPurchase::SetPrice(int itemPrice) {
  this->itemPrice = itemPrice;
}

int ItemToPurchase::GetPrice() const {
  return itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
  this->itemQuantity = itemQuantity;
}

int ItemToPurchase::GetQuantity() const {
  return itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription) {
  this->itemDescription = itemDescription;
}

string ItemToPurchase::GetDescription() const {
  return itemDescription;
}

void PrintItemCost() {
  /*cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $"
       << itemQuantity * itemPrice << endl;*/
}

void PrintItemDescription() {
  //cout << itemName << ": " << itemDescription;
}
