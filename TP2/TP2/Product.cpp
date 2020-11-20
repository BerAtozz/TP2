#include "Product.h"
#include <string>

Product(std::string title, std::string descrption, int quantity, double price);
{
  m_title = title;
  m_descrption = descrption;
  m_quantity = quantity;
  m_price = price;
}

std::string getTitle();
{
  return m_title;
}

std::string getDescription();
{
  return m_descrption;
}

int getQuantity();
{
  return m_quantity;
}

double getPrice();
{
  return m_price;
}

void ChangeQuantity(int quantity);
{
  m_quantity = quantity;
}
