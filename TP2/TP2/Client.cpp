#include "Client.h"
#include "Product.h"
#include "Magasin.h"
#include <vector>

Client::Client(std::string name, std::string firstname, std::vector <Product*> panier, int id)
{
  m_name = name;
  m_firstname = firstname;
  m_panier = panier;
  m_id = id;
}

void Client::AddProductPanier(std::vector<Product*> m_products, std::string nameProduct)
{
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it)
  {
    if (nameProduct == (*it)->getTitle())
    {
      m_panier.push_back(it);
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
  product.ChangeQuantity(quantity);//affecte au produit la nouvelle quantité
}

void Client::DeleteProductPanier(Product product)
{

}
