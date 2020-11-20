#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product
{
public:
  Product(std::string title, std::string descrption, int quantity, double price);
  std::string getTitle();
  std::string getDescription();
  int getQuantity();
  double getPrice();
  void ChangeQuantity(int quantity);
private:
  std::string m_title;
  std::string m_descrption;
  int m_quantity;
  double m_price;
};

#endif
