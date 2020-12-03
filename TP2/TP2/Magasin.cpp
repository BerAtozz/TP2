#include "Magasin.h"
#include "Product.h"
#include <iomanip>
Magasin::Magasin(std::string nom)
{
	m_nom = nom;
}

void Magasin::AddToMagasin(std::string nom, std::string description, float prix, int quantity)
{
	Product p(nom, description, prix, quantity);
	m_products.push_back(&p);
}

void Magasin::DisplayAllProducts()
{
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Products                                                           |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Name             Description            Quantity             Price |" << std::endl;
	std::string str;
	for (std::vector<Product*>::iterator it = m_products.begin(); it != m_products.end(); ++it) {	
		//std::cout << std::fixed << std::setprecision(2) << std::setfill(' ');
		std::cout << "|";
		std::cout << std::left << std::setw(17) << (*it)->getTitle() << " ";
		std::cout << std::left << std::setw(26) << (*it)->getDescription() << " ";
		std::cout << std::left << std::setw(16) << (*it)->getQuantity() << " ";
		std::cout << std::setw(5) << (*it)->getPrice();
		std::cout << "|" << std::endl;
	}

}
