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


