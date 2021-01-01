#include "Display.h"
#include "Magasin.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

Display::Display(std::string name)
{	
	nom = name;
}

void Display::Main()
{
	int n = 0;
	std::string nom;

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Shop Manager V 0.1" << std::endl;
	std::cout << "1 - Creer un magasin" << std::endl;
	std::cout << "2 - Quitter" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Selectionnez une action dans le menu : ";
	std::cin >> n;
	if (n == 1) {
		system("cls");
		std::cout << "Saisissez le nom du magasin : " << std::endl;
		std::cin >> nom;
		Magasin m(nom);
		mShop = m;
		MainMenu();
	}
	else{}
}

void Display::MainMenu()
{
	int n = 0;

	system("cls");
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Nom du magasin : " << mShop.getNomMagasin() << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Ajouter un produit au magasin" << std::endl;
	std::cout << "2 - Afficher tous les produits du magasin" << std::endl;
	std::cout << "3 - Afficher un produit du magasin" << std::endl;
	std::cout << "4 - Changer la quantite en stock d'un produit" << std::endl;
	std::cout << "5 - Ajouter un client au magasin" << std::endl;
	std::cout << "6 - Afficher tous les clients du magasin" << std::endl;
	std::cout << "7 - Afficher un client du magasin et son panier" << std::endl;
	std::cout << "8 - Ajouter un produit au panier d'un client" << std::endl;
	std::cout << "9 - Supprimer un produit du panier d'un client" << std::endl;
	std::cout << "10 - Changer la quantite d'un produit dans le panier d'un client" << std::endl;
	std::cout << "11 - Valider le panier d'un client" << std::endl;
	std::cout << "12 - Changer le statut d'une commande" << std::endl;
	std::cout << "13 - Afficher toutes les commandes du magasin" << std::endl;
	std::cout << "14 - Afficher toutes les commandes d'un client" << std::endl;
	std::cout << "15 - Quitter" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Selectionnez une action dans le menu : ";
	std::cin >> n;

	switch (n) {
	case 15:
		exit(0);
	case 1:
		AjouterProduitMagasin();
	case 2:
		AfficherProduitsMagasin();
	case 3:
		AfficherUnProduitMagasin();
	case 4:
		ChangerQuantiteProduit();
	case 5:
		AjouterClientMagasin();
	case 6:
		AfficherTousLesClients();
	case 7:
		AfficherUnClient();
	case 8:
		AjouterProduitPanier();
	case 9:
		SupprimerProduitPanier();
	case 10:
		ChangerQuantiteProduitPanier();
	}
}

void Display::AjouterProduitMagasin()
{
	int n = 0;
	std::string nom;
	std::string description;
	float prix = 0;
	unsigned int quantite = 0;

	system("cls");
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Ajouter un produit au magasin" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le nom du produit : " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nom);
	std::cout << "Saisissez la description du produit : " << std::endl;
	std::getline(std::cin, description);
	std::cout << "Saisissez le prix du produit : " << std::endl;
	std::cin >> prix;
	std::cout << "Saisissez la quantite du produit : " << std::endl;
	std::cin >> quantite;

	system("cls");
	std::cout << "Voulez-vous ajouter le produit suivant au magasin ?" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "| Name             Description            Quantity             Price |" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "|";
	std::cout << std::left << std::setw(17) << nom << " ";
	std::cout << std::left << std::setw(26) << description << " ";
	std::cout << std::left << std::setw(16) << quantite << " ";
	std::cout << std::setw(5) << prix;
	std::cout << "|" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Ajouter le produit" << std::endl;
	std::cout << "Autre - Ne pas ajouter le produit" << std::endl;
	std::cin >> n;
	if (n == 1) {
		mShop.AddToMagasin(nom, description, prix, quantite);
		MainMenu();
	}
	else{
		MainMenu();
	}
}

void Display::AfficherProduitsMagasin()
{
	system("cls");
	mShop.DisplayAllProducts();
	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	MainMenu();
}

void Display::AfficherUnProduitMagasin()
{
	std::string str;

	system("cls");
	std::cout << "Saisissez le nom du produit : " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, str);
	system("cls");
	mShop.DisplayProduct(str);
	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.get();
	MainMenu();
}

void Display::ChangerQuantiteProduit()
{
	std::string str;
	int quantite = 0;

	system("cls");
	std::cout << "Saisissez le nom du produit : " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, str);
	std::cout << "Saisissez la nouvelle quantite : " << std::endl;
	std::cin >> quantite;
	mShop.ChangeQuantity(str, quantite);
	system("cls");
	std::cout << "La quantite a bien ete mise a jour" << std::endl;
	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore();
	std::cin.get();
	MainMenu();
}

void Display::AjouterClientMagasin()
{
	std::string prenom, nom;
	int n = 0;

	system("cls");
	std::cout << "Saisissez le prenom du client : " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, prenom);
	std::cout << "Saisissez le nom du client : " << std::endl;
	std::getline(std::cin, nom);
	
	system("cls");

	std::cout << "Voulez-vous ajouter le client " + prenom + " " + nom + " au magasin ?" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Oui" << std::endl;
	std::cout << "Autre - Non" << std::endl;
	std::cin >> n;
	if (n == 1) {
		mShop.AddClient(prenom, nom);
		system("cls");
		std::cout << "Le client a bien ete ajoute" << std::endl;
		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.ignore();
		std::cin.get();
		MainMenu();
	}
	else {
		MainMenu();
	}
	
}

void Display::AfficherTousLesClients()
{
	system("cls");
	mShop.DisplayAllClients();
	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore();
	std::cin.get();
	MainMenu();
}

void Display::AfficherUnClient()
{
	std::string nom, prenom;
	int n,id = 0;

	system("cls");
	std::cout << "Rechercher un client" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Par son nom et prenom" << std::endl;
	std::cout << "2 - Par son ID" << std::endl;
	std::cout << "Autre - Sortir" << std::endl;
	std::cin >> n;
	if (n == 1) {
		system("cls");
		std::cout << "Saisissez le prenom du client : " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, prenom);
		std::cout << "Saisissez le nom du client : " << std::endl;
		std::getline(std::cin, nom);

		system("cls");
		mShop.DisplayClient(prenom, nom);

		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.get();
		MainMenu();
	}
	if (n == 2) {
		system("cls");
		std::cout << "Saisissez l'ID du client : " << std::endl;
		std::cin >> id;

		system("cls");
		mShop.DisplayClient(id);

		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.ignore();
		std::cin.get();

		MainMenu();
		
	}
	else {
		MainMenu();
	}

	
}

void Display::AjouterProduitPanier()
{
	int n, m, quantite, id = 0;
	std::string prenom, nom, titre;

	system("cls");
	std::cout << "Ajouter un produit au panier d'un client en utilisant :" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Son nom et prenom" << std::endl;
	std::cout << "2 - Son ID" << std::endl;
	std::cout << "Autre - Sortir" << std::endl;
	std::cin >> n;
	if (n == 1) {
		system("cls");
		std::cout << "Saisissez le prenom du client : " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, prenom);
		std::cout << "Saisissez le nom du client : " << std::endl;
		std::getline(std::cin, nom);
		std::cout << "Saisissez le nom du produit : " << std::endl;
		std::getline(std::cin, titre);
		std::cout << "Saisissez la quantite : " << std::endl;
		std::cin >> quantite;

		system("cls");
		std::cout << "Voulez-vous ajouter au panier de " + prenom + " " + nom + " : " + std::to_string(quantite) + " " + titre << std::endl;
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "1 - Oui" << std::endl;
		std::cout << "Autre - Non" << std::endl;
		std::cin >> m;
		if (m == 1) {
			system("cls");
			mShop.AddProductPanier(prenom, nom, titre, quantite);
			std::cout << "Le produit a bien ete ajoute au panier du client" << std::endl;

			std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
			std::cin.ignore();
			std::cin.get();
			MainMenu();
		}
		else {
			MainMenu();
		}
	}
	if (n == 2) {
		system("cls");
		std::cout << "Saisissez l'ID du client :" << std::endl;
		std::cin >> id;
		std::cout << "Saisissez le nom du produit :" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, titre);
		std::cout << "Saisissez la quantite : " << std::endl;
		std::cin >> quantite;

		system("cls");
		std::cout << "Voulez-vous ajouter au panier du client numero : " + std::to_string(id) + " : " + std::to_string(quantite) + " " + titre << std::endl;
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "1 - Oui" << std::endl;
		std::cout << "Autre - Non" << std::endl;
		std::cin >> m;
		if (m == 1) {
			system("cls");
			mShop.AddProductPanier(id, titre, quantite);

			std::cout << "Le produit a bien ete ajoute au panier du client" << std::endl;

			std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
			std::cin.ignore();
			std::cin.get();
			MainMenu();
		}
		else {
			MainMenu();
		}
	}
	else {
		MainMenu();
	}
}

void Display::SupprimerProduitPanier()
{
	int n, m, id = 0;
	std::string nom, prenom, titre;

	system("cls");
	std::cout << "Supprimer un produit du panier d'un client en utilisant :" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Son nom et prenom" << std::endl;
	std::cout << "2 - Son ID" << std::endl;
	std::cout << "Autre - Sortir" << std::endl;
	std::cin >> n;
	if (n == 1) {
		system("cls");
		std::cout << "Saisissez le prenom du client : " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, prenom);
		std::cout << "Saisissez le nom du client : " << std::endl;
		std::getline(std::cin, nom);
		std::cout << "Saisissez le nom du produit : " << std::endl;
		std::getline(std::cin, titre);

		system("cls");
		std::cout << "Voulez-vous supprimer du panier de " + prenom + " " + nom +  " le produit : " + titre << std::endl;
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "1 - Oui" << std::endl;
		std::cout << "Autre - Non" << std::endl;
		std::cin >> m;
		if (m == 1) {
			mShop.DeleteProductPanier(nom, prenom, titre);
			std::cout << "Le produit a bien ete supprime du panier du client" << std::endl;

			std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
			std::cin.ignore();
			std::cin.get();
			MainMenu();
		}
		else {
			MainMenu();
		}
	}
	if (n == 2) {
		system("cls");
		std::cout << "Saisissez l'ID du client :" << std::endl;
		std::cin >> id;
		std::cout << "Saisissez le nom du produit :" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, titre);

		system("cls");
		std::cout << "Voulez-vous supprimer du panier du client numero : " + std::to_string(id) + ", le produit : " + titre << std::endl;
		std::cout << "----------------------------------------------------------------------" << std::endl;
		std::cout << "1 - Oui" << std::endl;
		std::cout << "Autre - Non" << std::endl;
		std::cin >> m;
		if (m == 1) {
			mShop.DeleteProductPanier(id, titre);
			std::cout << "Le produit a bien ete supprime du panier du client" << std::endl;

			std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
			std::cin.ignore();
			std::cin.get();
			MainMenu();
		}
		else {
			MainMenu();
		}
	}
	else {
		MainMenu();
	}
}

void Display::ChangerQuantiteProduitPanier()
{
	int n, quantite, id = 0;
	std::string prenom, nom, titre;

	system("cls");
	std::cout << "Changer la quantite d'un produit du panier d'un client en utilisant :" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Son nom et prenom" << std::endl;
	std::cout << "2 - Son ID" << std::endl;
	std::cout << "Autre - Sortir" << std::endl;
	std::cin >> n;
	if (n == 1) {
		system("cls");
		std::cout << "Saisissez le prenom du client : " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, prenom);
		std::cout << "Saisissez le nom du client : " << std::endl;
		std::getline(std::cin, nom);
		std::cout << "Saisissez le nom du produit : " << std::endl;
		std::getline(std::cin, titre);
		std::cout << "Saisissez la quantite : " << std::endl;
		std::cin >> quantite;

		system("cls");
		mShop.ChangeQuantityPanier(prenom, nom, titre, quantite);

		std::cout << "La quantite a bien ete mise a jour" << std::endl;

		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.ignore();
		std::cin.get();
		MainMenu();
	}
	if (n == 2) {
		std::cout << "Saisissez l'ID du client :" << std::endl;
		std::cin >> id;
		std::cout << "Saisissez le nom du produit :" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, titre);
		std::cout << "Saisissez la quantite : " << std::endl;
		std::cin >> quantite;

		system("cls");
		mShop.ChangeQuantityPanier(id, titre, quantite);

		std::cout << "La quantite a bien ete mise a jour" << std::endl;

		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.ignore();
		std::cin.get();
		MainMenu();
	}
	else {
		MainMenu();
	}
}
