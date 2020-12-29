#pragma once
#ifndef COMMANDE_H
#define COMMANDE_H

#include "Client.h"
class Commande
{
public :
	Commande(Client client, std::vector <Product*> panier);

private :
	Client client;
	std::vector <Product*> m_BuyedProducts;
	bool statut; //Si false, commande en attente, si true, commande validée

};


#endif COMMANDE_H
