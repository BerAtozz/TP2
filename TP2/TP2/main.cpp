#include <iostream>
#include "Magasin.h"
#include "Display.h"

int main (int argc , char const *argv[])
{
    Display affichage("");
    affichage.Main();
    return 0;

    //Magasin magasin1("m1");
    //magasin1.AddToMagasin("PS4", "Sony Play Station 4", 399.99, 10);
    //magasin1.AddToMagasin("Switch", "Nintendo Switch", 299.99, 5);
    //magasin1.AddToMagasin("RTX3080", "Carte graphique", 800.00, 15);
    //magasin1.AddToMagasin("PS5", "Sony Play Station 5", 400.00, 12);
    //magasin1.AddToMagasin("gamecube", "vintage console jeu", 20.00, 5);
    //magasin1.AddToMagasin("JBL", "Enceinte", 99.99, 20);

    //magasin1.DisplayAllProducts();

    //magasin1.UpdateQuantity("PS5", 17);

    //magasin1.DisplayProduct("PS5");
    

    //Client c1("Valentin", "Berthoz");
    //c1.AddProductPanier(magasin1.getProductList(), "PS4", 1);
    //std::cout << c1;
    

    //magasin1.AddClient("Valentin", "Berthoz");
    //magasin1.AddClient("Hugo", "Senechal");
    //magasin1.AddClient("Dom", "Ginhac");
    //magasin1.AddClient("Bill", "Gates");

    //magasin1.DisplayAllClients();

    //magasin1.DisplayClient(2);
    //magasin1.DisplayClient("Bill","Gates");

    //magasin1.AddProductPanier("Valentin", "Berthoz", "PS5", 1);
    //magasin1.AddProductPanier("Hugo", "Senechal", "JBL", 5);
    //magasin1.ValidateOrder("Valentin", "Berthoz");
    //magasin1.ValidateOrder("Hugo", "Senechal");
    //magasin1.DisplayClient(1);
    //magasin1.DeleteProductPanier(1, "PS5");
    //magasin1.DisplayClient(1);
    //magasin1.DisplayAllProducts();

    //magasin1.AddProductPanier("Valentin", "Berthoz", "gamecube", 1);
    //magasin1.ValidateOrder("Valentin", "Berthoz");
    //magasin1.DisplayAllOrders();

    //magasin1.ChangeQuantityPanier("Valentin", "Berthoz", "PS5", 3);

    //magasin1.UpdateOrderStatus("Valentin", "Berthoz", 1, "En preparation");
    
    //magasin1.DisplayAllOrdersClient("Hugo", "Senechal");  
}
