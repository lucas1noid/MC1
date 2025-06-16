#include <iostream>
using namespace std;
/*Implementar uma função que retorne o piso de um 
número de ponto flutuante sem usar a operação de truncamento 
ou arredondamento da linguagem*/

int funcPiso(float x){
int piso = 0;

if (x >= 0){
    while (piso + 1 <= x)
    {
        piso++;
    }
} else {
while (piso > x)
{
    piso--;
}
}

return piso;
}

int main () {
float N;
cin >> N;

cout << funcPiso(N) << endl;
return 0;
}