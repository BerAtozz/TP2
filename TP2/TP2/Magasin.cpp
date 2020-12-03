#include "Magasin.h"
#include "Product.h"
#include <iomanip>
Magasin::Magasin(std::string nom)
{
	m_nom = nom;
}

void Magasin::AddToMagasin(std::string nom, std::string description, float prix, int quantity)
{
	Product* p = new Product(nom, description, prix, quantity);
	m_products.push_back(p);
}

std::vector<Product*> Magasin::getProductList()
{
	return m_products;
}

void Magasin::DisplayFrame()
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Products                                                           |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Name             Description            Quantity             Price |" << std::endl;
}

void Magasin::DisplayAllProducts()
{
	DisplayFrame();
	std::string str;
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {	
		std::cout << "|";
		std::cout << std::left << std::setw(17) << (*it)->getTitle() << " ";
		std::cout << std::left << std::setw(26) << (*it)->getDescription() << " ";
		std::cout << std::left << std::setw(16) << (*it)->getQuantity() << " ";
		std::cout << std::setw(5) << (*it)->getPrice();
		std::cout << "|" << std::endl;		
	}
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

void Magasin::DisplayProduct(std::string name)
{
	DisplayFrame();
	std::string str;
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getTitle() == name) {
			std::cout << "|";
			std::cout << std::left << std::setw(17) << (*it)->getTitle() << " ";
			std::cout << std::left << std::setw(26) << (*it)->getDescription() << " ";
			std::cout << std::left << std::setw(16) << (*it)->getQuantity() << " ";
			std::cout << std::setw(5) << (*it)->getPrice();
			std::cout << "|" << std::endl;
			std::cout << "----------------------------------------------------------------------" << std::endl;
		}
	}
}

void Magasin::UpdateQuantity(std::string name, int quantity)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getTitle() == name) {
			(*it)->ChangeQuantity(quantity);
		}
	}
}

void Magasin::AddProductPanier(std::string nomProduit, std::string nomClient, std::string prenomClient)
{
	Client* client;
	client = new Client ();

	bool clientTrouve = false;
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it)
	{
		if ((*it)->getFirstName() == prenomClient && (*it)->getName() == nomClient) {
			client = *it;
			clientTrouve = true;
		}
	}
	if (clientTrouve) {
		for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it)
		{
			if (nomProduit == (*it)->getTitle())
			{
				client->AddProductPanier(*it);
			}
		}
	}
}

void Magasin::AddClient(std::string nom, std::string prenom, int id) //Vérifier les doublons !!!! + client pas vide
{
	Client* c = new Client(nom, prenom, id);
	m_clients.push_back(c);
}

void Magasin::DisplayAllClients()
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Client                                                             |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| UID              Identity                                          |" << std::endl;
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it)
	{		
		std::cout << "|";
		std::cout << std::left << std::setw(15) << (*it)->getId() << " ";
		std::cout << std::left << std::setw(0) << (*it)->getName() << " ";
		std::cout << std::left << std::setw(42) << (*it)->getFirstName() << " ";
		std::cout << "|" << std::endl;
	}
	std::cout << "----------------------------------------------------------------------" << std::endl;
}
