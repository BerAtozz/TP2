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

//Retourne le nom du magasin
std::string Magasin::getNomMagasin()
{
	return m_nom;
}

//Créé un objet produit à partir des éléments passés en paramètre et ajoute son pointeur au vecteur de produits
void Magasin::AddToMagasin(std::string nom, std::string description, float prix, int quantity)
{
	Product* p = new Product(nom, description, prix, quantity);
	m_products.push_back(p);
}

//Retourne le vecteur de pointeurs de produits
std::vector<Product*> Magasin::getProductList()
{
	return m_products;
}

//Affiche la frame des produits
void Magasin::DisplayFrame()
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Products                                                           |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Name             Description            Quantity             Price |" << std::endl;
}

//Pacours le vecteur de pointeurs de produits et les affiches
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

//Parcours le vecteur de pointeurs de produits et affiche le produit dont le nom est passé en paramètres
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

//Parcours le vecteur de pointeurs de produits et change la quantité (passée en paramètre) de celui dont le nom est passé en paramètre 
void Magasin::ChangeQuantity(std::string name, int quantity)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getTitle() == name) {
			(*it)->ChangeQuantity(quantity);
		}
	}
}

//Parcours le vecteur de pointeurs de produits et soustrait a la quantité de produits restant la quantité de produit acheté 
//(passé en paramètre) au produit dont le nom est passé en paramètres
void Magasin::UpdateQuantity(std::string name, int quantity)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {
		if ((*it)->getTitle() == name) {
			(*it)->ChangeQuantity(((*it)->getQuantity()-quantity));			
		}
	}
}

//Créé un objet de type client à partir des paramètres et ajoute son pointeur au vecteur de pointeurs client
void Magasin::AddClient(std::string prenom, std::string nom)
{
	Client* c = new Client(nom, prenom);
	c->setID(m_clients.size() + 1);
	m_clients.push_back(c);
	
}

//Affiche la frame client
void Magasin::DisplayClientFrame()
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Clients                                                            |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Uid             Identity                                           |" << std::endl;
}

//Parcours le vecteur de pointeurs de clients et les affiches
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

//Parcours le vecteur de pointeurs de clients et affiche celui dont l'id est passé en paramètre
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
			std::cout << "----------------------------------------------------------------------" << std::endl;
			std::cout << "Panier" << std::endl;
			std::cout << "----------------------------------------------------------------------" << std::endl;
			std::cout << "| Name             Description            Quantity             Price |" << std::endl;

			std::vector<Product*>pan = (*it)->getVectorPanier();
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
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

//Parcours le vecteur de pointeurs de clients et affiche celui dont le prénom et nom sont passés en paramètre
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
			std::cout << "|" << std::endl;
			std::cout << "----------------------------------------------------------------------" << std::endl;
			std::cout << "Panier" << std::endl;
			std::cout << "----------------------------------------------------------------------" << std::endl;
			std::cout << "| Name             Description            Quantity             Price |" << std::endl;

			std::vector<Product*>pan = (*it)->getVectorPanier();
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
	std::cout << "----------------------------------------------------------------------" << std::endl;
}

//Parcours le vecteur de pointeurs de clients et ajoute à celui dont le nom et prénom sont passés en paramètre le produit dont le nom est 
//passé en paramètre et sa quantité à son panier
void Magasin::AddProductPanier(std::string prenom, std::string nom, std::string product, int quantity)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
			(*it)->AddProductPanier(m_products,product, quantity);
		}
	}
}

//Parcours le vecteur de pointeurs de clients et ajoute à celui dont l'id est passé en paramètre le produit dont le nom est passé
//en paramètre et sa quantité à son panier
void Magasin::AddProductPanier(int id, std::string product, int quantity)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getID() == id) {
			(*it)->AddProductPanier(m_products, product, quantity);
		}
	}
}

//Parcours le vecteur de pointeurs de produits et récupère celui dont le nom est passé en paramètre
//Parcours le vecteur de pointeurs de clients et récupère celui dont le nom et prénom sont passés en paramètre
//Supprime du panier du client *it le produit *pit
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

//Parcours le vecteur de pointeurs de produits et récupère celui dont le nom est passé en paramètre
//Parcours le vecteur de pointeurs de clients et récupère celui dont l'id est passé en paramètre
//Supprime du panier du client *it le produit *pit
void Magasin::DeleteProductPanier(int id, std::string product)
{
	for (std::vector<Product*>::iterator pit = m_products.begin(); pit != m_products.end(); ++pit) {
		if ((*pit)->getTitle() == product) {
			for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
				if ((*it)->getID() == id) {
					(*it)->DeleteProductPanier(*pit);
				}
			}
		}
	}
}

//Parcours le vecteur de pointeurs de produits et récupère celui dont le nom est passé en paramètre
//Parcours le vecteur de pointeurs de clients et récupère celui dont le nom et prénom sont passés en paramètre
//Change la quantité (passé en paramètre) du produit *pit présent dans le panier du client *it
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

//Parcours le vecteur de pointeurs de produits et récupère celui dont le nom est passé en paramètre
//Parcours le vecteur de pointeurs de clients et récupère celui dont l'id est passé en paramètre
//Change la quantité (passé en paramètre) du produit *pit présent dans le panier du client *it
void Magasin::ChangeQuantityPanier(int id, std::string product, int quantity)
{
	for (std::vector<Product*>::iterator pit = m_products.begin(); pit != m_products.end(); ++pit) {
		if ((*pit)->getTitle() == product) {
			for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
				if ((*it)->getID() == id) {
					(*it)->ChangeQuantityPanier(*pit, quantity);
				}
			}
		}
	}
}

//Parcours le vecteur de pointeurs de clients et récupère celui dont le nom et prénom sont passés en paramètre
//Créé un objet de typer Order en prenant en paramètre le client *it récupéré et son panier
//Stocke le panier du client dans le vecteur pan
//Parcours le vecteur de pointeurs de produits "pan" et modifie la quantité des produits restants dans le magasin en fonction
//des produits commandés
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

//Parcours le vecteur de pointeurs de clients et récupère celui dont l'id est passé en paramètre
//Créé un objet de typer Order en prenant en paramètre le client *it récupéré et son panier
//Stocke le panier du client dans le vecteur pan
//Parcours le vecteur de pointeurs de produits "pan" et modifie la quantité des produits restants dans le magasin en fonction
//des produits commandés
void Magasin::ValidateOrder(int id)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getID() == id) {
			Order* o = new Order((*it), (*it)->getVectorPanier(), m_orders.size() + 1);
			m_orders.push_back(o);
			std::vector<Product*> pan = (*it)->getVectorPanier();

			for (std::vector<Product*>::iterator pit = pan.begin(); pit != pan.end(); ++pit) {
				UpdateQuantity((*pit)->getTitle(), (*pit)->getQuantity());
			}
			(*it)->ClearPanier();
		}
	}
}

//Parcours le vecteur de pointeurs de clients et récupère celui dont le nom et prénom sont passés en paramètre
//Parcours le vecteur de pointeurs de commandes et récupère celle dont l'id est passé en paramètre
//Modifie le statut de la commande (*oit) en fonction du statut passé en paramètre
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

//Parcours le vecteur de pointeurs de commandes et récupère chacune d'elles
//Stocke la commande en cours (boucle for) dans le vecteur de pointeurs "pan"
//Parcours le vecteur de pointeurs "pan" et affiche tous les produits qu'il contient
void Magasin::DisplayAllOrders()
{
	for (std::vector<Order*>::iterator it = m_orders.begin(); it != m_orders.end(); ++it) {
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "| Numero de commande : ";
		std::cout << std::left << std::setw(42) << (*it)->getID() << " ";
		std::cout << "|" << std::endl;
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "| Client : ";
		std::cout << std::left << std::setw(2) << (*it)->getClient()->getFirstName() << " ";
		std::cout << std::left << std::setw(45) << (*it)->getClient()->getName() << " ";
		std::cout << "|" << std::endl;
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

//Parcours le vecteur de pointeurs de clients et récupère celui dont le nom et prénom sont passés en paramètre
//Parcours le vecteur de pointeurs de commandes dont le nom et prenom est passé en paramètre
//Stocke la commande en cours (boucle for) dans le vecteur de pointeurs "pan"
//Parcours le vecteur de pointeurs "pan" et affiche tous les produits qu'il contient
void Magasin::DisplayAllOrdersClient(std::string prenom, std::string nom)
{
	for (std::vector<Client*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it) {
		if ((*it)->getName() == nom && (*it)->getFirstName() == prenom) {
			for (std::vector<Order*>::iterator oit = m_orders.begin(); oit != m_orders.end(); ++oit) {
				if((*oit)->getClient()->getName()==nom && (*oit)->getClient()->getFirstName()==prenom){
					std::cout << "----------------------------------------------------------------------" << std::endl;
					std::cout << "| Numero de commande : ";
					std::cout << std::left << std::setw(42) << (*oit)->getID() << " ";
					std::cout << "|" << std::endl;
					std::cout << "----------------------------------------------------------------------" << std::endl;
					std::cout << "| Client : ";
					std::cout << std::left << std::setw(2) << (*oit)->getClient()->getFirstName() << " ";
					std::cout << std::left << std::setw(45) << (*oit)->getClient()->getName() << " ";
					std::cout << "|" << std::endl;
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
}
