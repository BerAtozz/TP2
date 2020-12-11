#include <iostream>
#include "Magasin.h"

int main (int argc , char const *argv[])
{
   
    Magasin magasin1("m1");
    magasin1.AddToMagasin("PS4", "Sony Play Station 4", 399.99, 10);
    magasin1.AddToMagasin("Switch", "Nintendo Switch", 299.99, 5);
    magasin1.AddToMagasin("RTX3080", "Carte graphique", 800.00, 15);
    magasin1.AddToMagasin("PS5", "Sony Play Station 5", 400.00, 12);
    magasin1.AddToMagasin("gamecube", "vintage console jeu", 20.00, 5);
    magasin1.AddToMagasin("JBL", "Enceinte", 99.99, 20);

    magasin1.DisplayAllProducts();

    magasin1.UpdateQuantity("PS5", 17);

    magasin1.DisplayProduct("PS5");
    

    Client c1("Valentin", "Berthoz", 1);
    c1.AddProductPanier(magasin1.getProductList(),"PS5");
    <<c1;
    return 0;
}
