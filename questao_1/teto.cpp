#include <iostream>
using namespace std;
/*Implementar uma função que retorne o teto de um número 
de ponto flutuante sem usar a operação de truncamento ou 
arredondamento da linguagem.
*/
int funcTeto(float x){
int teto = 0;

if (teto <= x)
{
    while (teto < x)
    {
        teto++;
    } 
} else {
    
    while (teto - 1 >= x)
    {
        teto--;
    }  
}

return teto;
}

int main () {
float N;
cin >> N;

cout << funcTeto(N) << endl;
return 0;
}