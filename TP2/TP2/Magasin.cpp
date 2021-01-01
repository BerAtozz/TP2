#include "Magasin.h"
#include "Product.h"
#include <iomanip>
Magasin::Magasin()
{
}
Magasin::Magasin(std::string nom)
{
	m_nom = nom;
}

std::string Magasin::getNomMagasin()
{
	return m_nom;
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

void Magasin::ChangeQuantity(std::string name, int quantity)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getTitle() == name) {
			(*it)->ChangeQuantity(quantity);
		}
	}
}

void Magasin::UpdateQuantity(std::string name, int quantity)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getTitle() == name) {
			(*it)->ChangeQuantity(((*it)->getQuantity()-quantity));			
		}
	}
}

void Magasin::AddClient(std::string prenom, std::string nom)
{
	Client* c = new Client(nom, prenom);
	c->setID(m_clients.size() + 1);
	m_clients.push_back(c);
	
}

void Magasin::DisplayClientFrame()
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Clients                                                            |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Uid             Identity                                           |" << std::endl;
}


void Magasin::DisplayAllClients()
{
	std::string str;
	DisplayClientFrame();
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		std::cout << "|";
		std::cout << std::left << std::setw(16) << (*it)->getID() << " ";
		std::cout << (*it)->getFirstName() << " " << (*it)->getName()<<std::left << std::setw(34) << " ";
		std::cout << "|" << std::endl;		
	}
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

void Magasin::DisplayClient(int id)
{
	std::string str;
	DisplayClientFrame();
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getID() == id) {
			std::cout << "|";
			std::cout << std::left << std::setw(16) << (*it)->getID() << " ";
			std::cout << (*it)->getFirstName() << " " << (*it)->getName() << std::left << std::setw(34) << " ";
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

void Magasin::DisplayClient(std::string prenom, std::string nom)
{
	std::string str;
	DisplayClientFrame();
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
			std::cout << "|";
			std::cout << std::left << std::setw(16) << (*it)->getID() << " ";
			std::cout << (*it)->getFirstName() << " " << (*it)->getName() << std::left << std::setw(34) << " ";
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

void Magasin::AddProductPanier(std::string prenom, std::string nom, std::string product, int quantity)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
			(*it)->AddProductPanier(m_products,product, quantity);
		}
	}
}

void Magasin::AddProductPanier(int id, std::string product, int quantity)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getID() == id) {
			(*it)->AddProductPanier(m_products, product, quantity);
		}
	}
}

void Magasin::DeleteProductPanier(std::string nom, std::string prenom, std::string product)
{
	for (std::vector<Product*>::iterator pit = m_products.begin(); pit != m_products.end(); ++pit) {
		if ((*pit)->getTitle() == product) {
			for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
				if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
					(*it)->DeleteProductPanier(*pit);
				}
			}
		}
	}
	
}

void Magasin::ChangeQuantityPanier(std::string prenom, std::string nom, std::string product, int quantity)
{
	for (std::vector<Product*>::iterator pit = m_products.begin(); pit != m_products.end(); ++pit) {
		if ((*pit)->getTitle() == product) {
			for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
				if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
					(*it)->ChangeQuantityPanier(*pit,quantity);
				}
			}
		}
	}
}

void Magasin::ValidateOrder(std::string prenom, std::string nom)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {			
			Order* o = new Order((*it), (*it)->getVectorPanier(), m_orders.size()+1);
			m_orders.push_back(o);
			std::vector<Product*> pan = (*it)->getVectorPanier();
			
			for (std::vector<Product*>::iterator pit = pan.begin(); pit != pan.end(); ++pit) {
				UpdateQuantity((*pit)->getTitle(), (*pit)->getQuantity());				
			}
			(*it)->ClearPanier();
		}
	}
}

void Magasin::UpdateOrderStatus(std::string prenom, std::string nom, int id, std::string status)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
			for (std::vector<Order*>::iterator oit = m_orders.begin(); oit != m_orders.end(); ++oit) {
				if ((*oit)->getClient() == (*it) && (*oit)->getID() == id ){
					(*oit)->setStatus(status);
				}
			}
		}
	}
}

void Magasin::DisplayAllOrders()
{
	for (std::vector<Order*>::iterator it = m_orders.begin(); it != m_orders.end(); ++it) {
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "| Statut de la commande : ";
		std::cout << std::left << std::setw(42) << (*it)->getStatus() << " ";
		std::cout << "|" << std::endl;
		DisplayFrame();
		std::vector<Product*> pan = (*it)->getBuyedProducts();
		for (std::vector<Product*>::iterator oit = pan.begin(); oit != pan.end(); ++oit) {
			std::cout << "|";
			std::cout << std::left << std::setw(17) << (*oit)->getTitle() << " ";
			std::cout << std::left << std::setw(26) << (*oit)->getDescription() << " ";
			std::cout << std::left << std::setw(16) << (*oit)->getQuantity() << " ";
			std::cout << std::setw(5) << (*oit)->getPrice();
			std::cout << "|" << std::endl;
		}
		std::cout << "----------------------------------------------------------------------" << std::endl;
	}
}

void Magasin::DisplayAllOrdersClient(std::string prenom, std::string nom)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
			for (std::vector<Order*>::iterator oit = m_orders.begin(); oit != m_orders.end(); ++oit) {
				std::cout << "----------------------------------------------------------------------" << std::endl;
				std::cout << "| Statut de la commande : ";
				std::cout << std::left << std::setw(42) << (*oit)->getStatus() << " ";
				std::cout << "|" << std::endl;
				DisplayFrame();
				std::vector<Product*> pan = (*oit)->getBuyedProducts();
				for (std::vector<Product*>::iterator pit = pan.begin(); pit != pan.end(); ++pit) {
					std::cout << "|";
					std::cout << std::left << std::setw(17) << (*pit)->getTitle() << " ";
					std::cout << std::left << std::setw(26) << (*pit)->getDescription() << " ";
					std::cout << std::left << std::setw(16) << (*pit)->getQuantity() << " ";
					std::cout << std::setw(5) << (*pit)->getPrice();
					std::cout << "|" << std::endl;
				}
				std::cout << "----------------------------------------------------------------------" << std::endl;
			}
		}
	}
}
