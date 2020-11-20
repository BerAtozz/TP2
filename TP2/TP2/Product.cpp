#include "Product.h"
#include <string>

Product::Product(std::string title, std::string descrption, int quantity, double price)
{
  m_title = title;
  m_descrption = descrption;
  m_quantity = quantity;
  m_price = price;
}

std::string Product::getTitle()
{
  return m_title;
}

std::string Product::getDescription()
{
  return m_descrption;
}

int Product::getQuantity()
{
  return m_quantity;
}

double Product::getPrice()
{
  return m_price;
}

void Product::ChangeQuantity(int quantity)
{
  m_quantity = quantity;
}
