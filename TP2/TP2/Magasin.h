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
	Magasin(std::string nom);
	void AddToMagasin(std::string nom,std::string description, float prix, int quantity);
	void DisplayAllProducts();
	/*void DisplayProduct(std::string name);
	void UpdateQuantity(std::string name, int quantity);
	void AddClient(Client client);
	void DisplayAllClients();
	void DisplayOneClient(int id);
	void AddProductPanier(Client client, Product product);
	void DeleteProductPanier(Client client, Product product);
	void ChangeQuantityPanier(Client client, Product product, int quantity);
	void ValidateOrder(Client client);
	void UpdateOrderStatus(Order order, std::string status);
	void DisplayAllOrders();
	void DisplayAllOrdersClient(Client client);*/

private:
	std::string m_nom;
	std::vector <Product*> m_products;
	std::vector <Client*> m_clients;
	std::vector <Order*> m_orders;

};
#endif // !MAGASIN_H