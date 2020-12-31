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
	void setStatus(std::string status);
	std::string getStatus();
private:
	Client* m_client;
	std::vector <Product*> m_BuyedProducts;
	std::string statut; 

};


#endif ORDER_H
