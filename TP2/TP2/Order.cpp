#include "Order.h"
Order::Order(Client* client, std::vector<Product*> panier)
{
	m_client = client;
	m_BuyedProducts = panier;
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


