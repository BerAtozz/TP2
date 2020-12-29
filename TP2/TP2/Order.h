#pragma once
#ifndef ORDER_H
#define ORDER_H

#include "Client.h"
class Order
{
public:
	Order(Client* client, std::vector <Product*> panier);

private:
	Client client;
	std::vector <Product*> m_BuyedProducts;
	bool statut; //Si false, commande en attente, si true, commande validée

};


#endif ORDER_H
