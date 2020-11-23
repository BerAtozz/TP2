#include <iostream>
#include "Magasin.h"

int main (int argc , char const *argv[])
{
    //creation de 3 magasin vide
    Magasin magasin1("m1");
    magasin1.AddToMagasin("PS4", "Sony Play Station 5", 399.99, 10);
    magasin1.AddToMagasin("Switch", "Nintendo Switch", 299.99, 5);
    magasin1.DisplayAllProducts();


    return 0;
}
