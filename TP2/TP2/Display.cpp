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

void Display::Main() //Affiche le menu principal
{
	int n = 0;
	std::string nom;

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Shop Manager V 0.3" << std::endl;
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

void Display::MainMenu()//Affiche le menu du magasin
{
	int n = 0;

	system("cls");
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Nom du magasin : " << mShop.getNomMagasin() << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Gestion magasin" << std::endl;
	std::cout << "2 - Gestion clients" << std::endl;
	std::cout << "3 - Gestion commandes" << std::endl;
	std::cout << "4 - Quitter" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Selectionnez une action dans le menu : ";
	std::cin >> n;

	switch (n) {
	case 4:
		exit(0);
	case 1:
		GestionMagasin();
	case 2:
		GestionClients();
	case 3:
		GestionCommandes();	
	}
}

void Display::GestionMagasin()//Affiche le menu de gestion du magasin
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
	std::cout << "5 - Retour" << std::endl;

	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Selectionnez une action dans le menu : ";
	std::cin >> n;

	switch (n) {
	case 5:
		MainMenu();
	case 1:
		AjouterProduitMagasin();
	case 2:
		AfficherProduitsMagasin();
	case 3:
		AfficherUnProduitMagasin();
	case 4:
		ChangerQuantiteProduit();
	}
}

void Display::GestionClients()// Affiche le menu de gestion des clients
{
	int n = 0;

	system("cls");
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Nom du magasin : " << mShop.getNomMagasin() << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Ajouter un client au magasin" << std::endl;
	std::cout << "2 - Afficher tous les clients du magasin" << std::endl;
	std::cout << "3 - Afficher un client du magasin et son panier" << std::endl;
	std::cout << "4 - Ajouter un produit au panier d'un client" << std::endl;
	std::cout << "5 - Supprimer un produit du panier d'un client" << std::endl;
	std::cout << "6 - Changer la quantite d'un produit dans le panier d'un client" << std::endl;
	std::cout << "7 - Valider le panier d'un client" << std::endl;
	std::cout << "8 - Retour" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Selectionnez une action dans le menu : ";
	std::cin >> n;
	switch (n) {
	case 1:
		AjouterClientMagasin();
	case 2:
		AfficherTousLesClients();
	case 3:
		AfficherUnClient();
	case 4:
		AjouterProduitPanier();
	case 5:
		SupprimerProduitPanier();
	case 6:
		ChangerQuantiteProduitPanier();
	case 7:
		ValiderPanierClient();
	case 8:
		MainMenu();
	}

}

void Display::GestionCommandes()//Affiche le menu de gestion des commandes
{
	int n = 0;

	system("cls");
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Nom du magasin : " << mShop.getNomMagasin() << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "1 - Changer le statut d'une commande" << std::endl;
	std::cout << "2 - Afficher toutes les commandes du magasin" << std::endl;
	std::cout << "3 - Afficher toutes les commandes d'un client" << std::endl;
	std::cout << "4 - Retour" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Selectionnez une action dans le menu : ";
	std::cin >> n;
	switch (n) {
	case 1:
		ChangerStatutCommande();
	case 2:
		AfficherToutesCommandesMagasin();
	case 3:
		AfficherToutesCommandesClient();
	case 4:
		MainMenu();
	}
}

void Display::AjouterProduitMagasin()//Affiche le menu d'ajout de produit au magasin
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

void Display::AfficherProduitsMagasin()//Affiche tous les produits du magasin
{
	system("cls");
	mShop.DisplayAllProducts();
	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	MainMenu();
}

void Display::AfficherUnProduitMagasin()//Affiche un produit spécifié
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

void Display::ChangerQuantiteProduit()//Affiche le menu de changement de quantité d'un produit
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

void Display::AjouterClientMagasin()//Affiche le menu d'ajout d'un client au magasin
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

void Display::AfficherTousLesClients()//Affiche tous les clients de magasin
{
	system("cls");
	mShop.DisplayAllClients();
	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore();
	std::cin.get();
	MainMenu();
}

void Display::AfficherUnClient()//Affiche un client spécifié
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

void Display::AjouterProduitPanier()//Affiche le menu d'ajout de produit au panier d'un client
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

void Display::SupprimerProduitPanier()//Affiche le menu de suppression d'un produit du panier d'un client
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

void Display::ChangerQuantiteProduitPanier()//Affiche le menu de changement de quantité d'un produit dans le panier d'un client
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

void Display::ValiderPanierClient()//Affiche le menu de validation du panier d'un client
{
	int n, id = 0; 
	std::string prenom, nom;

	system("cls");
	std::cout << "Valider le panier d'un client en utilisant :" << std::endl;
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

		system("cls");
		mShop.ValidateOrder(prenom, nom);

		std::cout << "La commande a bien ete validee" << std::endl;

		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.ignore();
		std::cin.get();
		MainMenu();
	}
	if (n == 2) {
		system("cls");
		std::cout << "Saisissez l'ID du client :" << std::endl;
		std::cin >> id;

		system("cls");
		mShop.ValidateOrder(id);

		std::cout << "La commande a bien ete validee" << std::endl;

		std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
		std::cin.ignore();
		std::cin.get();
		MainMenu();
	}
	else {
		MainMenu();
	}
}

void Display::ChangerStatutCommande()//Affiche le menu de changement de statu d'une commande
{
	int id = 0;
	std::string prenom, nom, statut;

	system("cls");
	std::cout << "Changer le statut d'une commande :" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le prenom du client : " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, prenom);
	std::cout << "Saisissez le nom du client : " << std::endl;
	std::getline(std::cin, nom);
	std::cout << "Saisissez le statut de la commande : " << std::endl;
	std::getline(std::cin, statut);
	std::cout << "Saisissez l'ID de la commande : " << std::endl;
	std::cin >> id;

	system("cls");
	mShop.UpdateOrderStatus(prenom, nom, id, statut);

	std::cout << "Le statut a bien ete mis a jour" << std::endl;

	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore();
	std::cin.get();
	MainMenu();
}

void Display::AfficherToutesCommandesMagasin()//Affiche toutes les commandes du magasin
{
	system("cls");
	mShop.DisplayAllOrders();

	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.ignore();
	std::cin.get();
	MainMenu();
}

void Display::AfficherToutesCommandesClient()//Affiche toutes les commandes d'un client spécifié
{
	std::string prenom, nom;

	system("cls");
	std::cout << "Afficher les commandes d'un client :" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "Saisissez le prenom du client : " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, prenom);
	std::cout << "Saisissez le nom du client : " << std::endl;
	std::getline(std::cin, nom);

	system("cls");
	mShop.DisplayAllOrdersClient(prenom, nom);

	std::cout << "Appuyez sur entree pour revenir au menu principal" << std::endl;
	std::cin.get();
	MainMenu();
}
