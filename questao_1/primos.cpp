#include <iostream>
using namespace std;
/*Implementar uma função que calcula todos os primos 
dentro de um intervalo de inteiros. 
Ex: primos entre 2 e 10 são 2, 3, 5, 7.
*/

void eh_primo(int min, int max){
    for (int i = min; i < max; i++)
    {
        int div = 0;
        //testa cada numero do intervalo 
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0) {
            div++;
            }
        }
        if (div == 2)
        {
        cout << i << endl;
        }
    }
    
}

int main () {
int min, max;
cin >> min >> max;

eh_primo(min, max);
return 0;
}