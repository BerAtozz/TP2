#include "Client.h"
#include "Product.h"
#include "Magasin.h"
#include <vector>

Client::Client()
{
}

Client::Client(std::string name, std::string firstname, int id)
{
  m_name = name;
  m_firstname = firstname;
  m_panier;
  m_id = id;
}

void Client::AddProductPanier(Product* produit)
{
	m_panier.push_back(produit);
	(*produit).ChangeQuantity((*produit).getQuantity() - 1);
}
  //m_panier.push_back (product); //push back d'un product dans panier


void Client::ClearPanier()
{
  m_panier.clear(); //clear suprimme les elements du panier
}

void Client::ChangeQuantityPanier(Product* product, int quantity)
{
  (*product).ChangeQuantity(quantity);//affecte au produit la nouvelle quantité
}

void Client::DeleteProductPanier(Product product)
{

}

std::string Client::getName()
{
	return m_name;
}

std::string Client::getFirstName()
{
	return m_firstname;
}

int Client::getId()
{
	return m_id;
}

std::ostream& operator<<(std::ostream& out, Client& c)
{
	out << c.getName();
	out << c.getFirstName();
	return out;
}