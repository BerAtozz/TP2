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
	std::vector <Product*> getProductList();
	void DisplayFrame();
	void DisplayAllProducts();
	void DisplayProduct(std::string name);
	void UpdateQuantity(std::string name, int quantity);
	void AddClient(std::string prenom, std::string nom);
	void DisplayClientFrame();
	void DisplayAllClients();
	void DisplayClient(int id);
	void DisplayClient(std::string prenom, std::string nom);
	void AddProductPanier(std::string prenom, std::string nom, std::string product, int quantity);
	void AddProductPanier(int id, std::string product, int quantity);
	void DeleteProductPanier(std::string nom, std::string prenom, std::string product);
	void ChangeQuantityPanier(std::string prenom, std::string nom, std::string product, int quantity);
	void ValidateOrder(std::string prenom, std::string nom);
	void UpdateOrderStatus(std::string firstname, std::string name, bool status);
	/*void DisplayAllOrders();
	void DisplayAllOrdersClient(Client client);*/

private:
	std::string m_nom;
	std::vector <Product*> m_products;
	std::vector <Client*> m_clients;
	std::vector <Order*> m_orders;

};
#endif // !MAGASIN_H