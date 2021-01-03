#include "Client.h"
#include "Product.h"
#include "Magasin.h"
#include <ostream>
#include <vector>
#include <string>

Client::Client()
{
}

Client::Client(std::string name, std::string firstname)
{
  m_name = name;
  m_firstname = firstname;
  m_panier;
  m_id;
}

//Parcours le vecteur de pointeurs de produits et récupère celui dont le nom est passé en paramètre
//Créé un pointeur de produit à partir de celui récupéré précédemment
//Ajouter ce pointeur au vecteur panier
void Client::AddProductPanier(std::vector<Product*> m_products, std::string nameProduct, int quantity)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it)
    {
        if (nameProduct == (*it)->getTitle())
        { 
            Product* p = new Product((*it)->getTitle(), (*it)->getDescription(), (*it)->getPrice(), quantity);             
            m_panier.push_back(p);
        }
	} 
}

void Client::ClearPanier()
{
  m_panier.clear(); //clear suprimme les elements du panier
}

void Client::ChangeQuantityPanier(Product* product, int quantity)
{
    for (std::vector<Product*>::iterator it = m_panier.begin(); it != m_panier.end(); ++it)
    {
        if (product->getTitle() == (*it)->getTitle()) {
            (*it)->ChangeQuantity(quantity);
        }
    }  
}

void Client::DeleteProductPanier(Product* product)
{  
    for (int i = 0; i < m_panier.size(); i++) {
        if (m_panier[i]->getTitle() == product->getTitle()) {
            m_panier.erase(m_panier.begin() + i);
        }
    }
}

void Client::setID(int id)
{
    m_id = id;
}

int Client::getID()
{
    return m_id;
}

std::string Client::getName()
{
    return m_name;
}

std::string Client::getFirstName()
{
    return m_firstname;
}

std::string Client::getPanier()
{
    std::string str;
    for (std::vector<Product*>::iterator it = m_panier.begin(); it != m_panier.end(); ++it)
    {
        str += "Article : " + (*it)->getTitle() + " Quantitee : " + std::to_string((*it)->getQuantity());
    }
    return str;       
}

std::vector<Product*> Client::getVectorPanier()
{
    return m_panier;
}

std::ostream& operator<<(std::ostream& os, const Client& ct)
{
    os << ct.m_name << ' ' << ct.m_firstname ;
    return os;
}
