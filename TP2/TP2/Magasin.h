#pragma once
#ifndef MAGASIN_H
#define MAGASIN_H
#include <vector>
#include <string>
#include "Client.h"
#include "Product.h"
#include "Order.h"
class Magasin
{
public:
	Magasin();
	void AddToMagasin(Product product);
	void DisplayAllProducts();
	void DisplayProduct(std::string name);
	void UpdateQuantity(std::string name, int quantity);
	void AddClient
a
private:
	std::vector <Product> m_products;
	std::vector <Client> m_clients;
	std::vector <Order> m_orders;

};
#endif // !MAGASIN_H