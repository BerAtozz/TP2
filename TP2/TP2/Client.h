#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include "Product.h"
#include <ostream>
#include <vector>
#include <string>
class Client
{
public:
	Client(std::string name, std::string firstname);
	void ClearPanier();
	void AddProductPanier(std::vector<Product*> m_products, std::string nameProduct);
	void ChangeQuantityPanier(Product* product, int quantity);
	void DeleteProductPanier(Product* product);
	void setID(int id);
	int getID();
	std::string getName();
	std::string getFirstName();
	std::string getPanier();
	
	friend std::ostream& operator<<(std::ostream& os, const Client& ct);

private:
	std::string m_name;
	std::string m_firstname;
	std::vector <Product*> m_panier;
	int m_id;
};

#endif // !CLIENT_H
