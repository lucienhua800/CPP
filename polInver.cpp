#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
    //Commençons par créer une pile, sur laquelle on accumule tous les nombres
    std::vector<int> pile ;
    bool chiffres = true;
    //Soit i l'indice sur lequel on se trouve 
    int i = 1;
    while (chiffres) 
    {
        //Si on trouve un opérateur, on arrête de poser sur la liste
        std::string argu = argv[i];
        if ((argu == "+") or (argu == "-") or (argu == "x") or (argu == "/")) 
        {
            chiffres = false;
        }
        //Sinon, on continue à accumuler
        else 
        {
          pile.push_back(std::stoi(argv[i]));
          i+=1;
        
        }
    }
    int result = pile.back();
    pile.pop_back();
    while (i < argc) 
    {
        std::string argu = argv[i];
        int nombre = pile.back();
            pile.pop_back();
        if (argu == "+")
            {                
              result += nombre;
            }
        else if (argu == "-")
            {
              result -= nombre;
            }
        else if (argu == "x")
            {
              result *= nombre;
            }
        else 
            {
              result /= nombre;
            }
        i++;
    }
    std::cout << result;
    return 1;
}
