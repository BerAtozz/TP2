#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include "Product.h"
#include <vector>
#include <string>
class Client
{
public:
	Client(std::string name, std::string firstname, std::vector <Product*> panier, int id);
  void ClearPanier();
  void AddProductPanier(Product* product);
  void ChangeQuantityPanier(Product product, int quantity);
  void DeleteProductPanier(Product product);
private:
	std::string m_name;
	std::string m_firstname;
	std::vector <Product*> m_panier;
	int m_id;
};

#endif // !CLIENT_H
