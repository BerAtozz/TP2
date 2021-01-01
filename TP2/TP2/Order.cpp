#include "Order.h"
Order::Order(Client* client, std::vector<Product*> panier, int id)
{
	m_client = client;
	m_BuyedProducts = panier;
	ID = id;
}

std::vector<Product*> Order::getBuyedProducts()
{
	return m_BuyedProducts;
}

Client* Order::getClient()
{
	return m_client;
}

void Order::setStatus(std::string status)
{
	statut = status;
}

std::string Order::getStatus()
{
	return statut;
}

void Order::setID(int id)
{
	ID = id;
}

int Order::getID()
{
	return ID;
}


