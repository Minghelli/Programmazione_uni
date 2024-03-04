#include <iostream>
#include <cmath>
using namespace std;

//Dichiarazione funzioni
bool isPrimo(int);
int primoMaggiore(int);

int main()
{
      int num1, num2, i;

      cout << "Inserisci 2 numeri interi non negativi:" << endl;
      do{
            cin >> num1 >> num2;

            if (num1 < 0 || num2 < 0)
                  cout << "Inserisci numeri corretti: ";

      } while (num1 < 0 || num2 < 0);

      for (i = num1; i <= num2; i++){
            //Se la funzione non ha restituito un errore allora il numero è primo e lo stampo
            if (primoMaggiore(i) != -1 && primoMaggiore(i + 2) != -1)
                  cout << i << " " << i + 2 << endl;
      }
}

bool isPrimo(int n)
{
      int maxDiv;
      //Se il numero è compreso tra 0 e 3 allora e primo
      if (n >= 0 && n <= 3)
            return true;

      //Se il numero è pari allora non può essere primo
      if (n % 2 == 0)
            return false;

      //Variabile contenente la parte intera della radice del numero
      maxDiv = static_cast<int>(sqrt(n));

      /*  Controlliamo i numeri partendo da 3 e arrivando alla radice del numero
        incrementando ogni volta di 2 (per saltare i numeri pari), se si trova 
        un divisore del numero allora esso non è prim0
    */
      for (int i = 3; i <= maxDiv; i += 2){
            if (n % i == 0)
                  return false;
      }
      //Se noin si trovano divisori allora il numero è primo
      return true;
}

int primoMaggiore(int n)
{
      //Se il numero inserito è primo lo restituisco
      if (isPrimo(n))
            return n;
      //Se nin lo è restituisco un errore
      return -1;
}