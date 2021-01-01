#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include "Magasin.h"
#include <iostream>

class Display
{
public :
	Display(std::string name);
	void Main();
	void MainMenu();
	void AjouterProduitMagasin();
	void AfficherProduitsMagasin();
	void AfficherUnProduitMagasin();
	void ChangerQuantiteProduit();
	void AjouterClientMagasin();
	void AfficherTousLesClients();
	void AfficherUnClient();
	void AjouterProduitPanier();
	void SupprimerProduitPanier();
	void ChangerQuantiteProduitPanier();
	void ValiderPanierClient();
	void ChangerStatutCommande();
	void AfficherToutesCommandesMagasin();
private :
	std::string nom;
	Magasin mShop;
};

#endif // !DISPLAY_H