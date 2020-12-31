#pragma once
#ifndef ORDER_H
#define ORDER_H

#include "Client.h"
class Order
{
public:
	Order(Client* client, std::vector <Product*> panier);
	std::vector <Product*> getBuyedProducts();
	Client* getClient();

private:
	Client* m_client;
	std::vector <Product*> m_BuyedProducts;
	bool statut; //Si false, commande en attente, si true, commande valid�e

};


#endif ORDER_H
