#include "Order.h"
Order::Order(Client* panierclient, std::vector<Product*> panier)
{
	client = *panierclient;
	m_BuyedProducts = panier;
}


