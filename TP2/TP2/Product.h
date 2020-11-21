#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
class Product
{
public:
  Product(std::string title, std::string descrption, float price, int quantity);
  std::string getTitle();
  std::string getDescription();
  int getQuantity();
  double getPrice();
  void ChangeQuantity(int quantity);
  friend std::ostream& operator<<(std::ostream& out, Product& p);
private:
  std::string m_title;
  std::string m_descrption;
  int m_quantity;
  float m_price;
};

#endif
