#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include "Product.h"
#include <vector>
#include <string>
class Client
{
public:
	Client();
	Client(std::string name, std::string firstname, int id);
  void ClearPanier();
  void AddProductPanier(Product* produit);
  void ChangeQuantityPanier(Product* product, int quantity);
  void DeleteProductPanier(Product product);
  std::string getName();
  std::string getFirstName();
  int getId();
private:
	std::string m_name;
	std::string m_firstname;
	std::vector <Product*> m_panier;
	int m_id;
};

#endif // !CLIENT_H
