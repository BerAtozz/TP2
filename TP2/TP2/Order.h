#pragma once
#ifndef ORDER_H
#define ORDER_H

#include "Client.h"
class Order
{
public:
	Order(Client* client, std::vector <Product*> panier, int id);
	std::vector <Product*> getBuyedProducts();
	Client* getClient();
	void setStatus(std::string status);
	std::string getStatus();
	void setID(int id);
	int getID();
private:
	Client* m_client;
	std::vector <Product*> m_BuyedProducts;
	std::string statut; 
	int ID;
};


#endif ORDER_H
