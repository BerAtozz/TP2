#include "Client.h"


Client::Client(std::string name, std::string firstname, std::vector <Product> panier, int id)
{
  m_name = name;
  m_firstname = firstname;
  m_panier = panier;
  m_id = id;
}

void Client::AddProductPanier(Product product)
{
  m_panier.push_back (product); //push back d'un product dans panier
}

void Client::ClearPanier()
{
  m_panier::clear; //clear suprimme les elements du panier
}

void Client::ChangeQuantityPanier(Product product, int quantity)
{
  product.ChangeQuantity(quantity);//affecte au produit la nouvelle quantité
}

void Client::DeleteProductPanier(Product product)
{

}
