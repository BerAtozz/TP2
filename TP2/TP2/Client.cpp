#include "Client.h"
#include "Product.h"
#include "Magasin.h"
#include <vector>
#include <string>

Client::Client(std::string name, std::string firstname, int id)
{
  m_name = name;
  m_firstname = firstname;
  m_panier;
  m_id = id;
}

void Client::AddProductPanier(std::vector<Product*> m_products, std::string nameProduct)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it)
    {
        if (nameProduct == (*it)->getTitle())
        {
          m_panier.push_back(*it);
          (*it)->ChangeQuantity((*it)->getQuantity()-1);
        }

        else
        {
          std::cout<<"Le produit demandé n'est pas en stock"<<std::endl;
        }
	}
  //m_panier.push_back (product); //push back d'un product dans panier
}

void Client::ClearPanier()
{
  m_panier.clear(); //clear suprimme les elements du panier
}

void Client::ChangeQuantityPanier(Product product, int quantity)
{
    for (std::vector<Product*>::iterator it = m_panier.begin(); it != m_panier.end(); ++it)
    {
        if (product.getTitle() == (*it)->getTitle()) {
            (*it)->ChangeQuantity(quantity);
        }
    }
  
}

void Client::DeleteProductPanier(Product product)
{
    for (std::vector<Product*>::iterator it = m_panier.begin(); it != m_panier.end(); ++it)
    {
        if (product.getTitle() == (*it)->getTitle()) {
            m_panier.erase(it);
        }
    }
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

std::ostream& operator<<(std::ostream& out, Client& c)
{
    out << c.getName() << c.getFirstName() << c.getPanier();
    return out;
}
