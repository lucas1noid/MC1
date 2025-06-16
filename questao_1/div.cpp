#include <iostream>
using namespace std;
/*Implementar uma função que retorne o div entre dois 
inteiros sem usar a operação de divisão da linguagem.
*/

int funcDiv(int dividendo, int divisor){
    int resultado = 0;
    int sinal = 1;
    
    //sinal
    if (dividendo < 0) {
        sinal *= -1;
        dividendo = -dividendo;
    }
    if (divisor < 0) {
        sinal *= -1;
        divisor = -divisor;
    }

    // Subtrai o divisor ate caso base(dividendo < divisor == 0)
    while (dividendo >= divisor) {
        dividendo -= divisor;
        resultado++;
    }

    return resultado * sinal;
    
}

int main () {
int dividendo, divisor;
cin >> dividendo >> divisor;

if(divisor == 0){
cout << "Erro, entrada não esperada" << endl;
} else {
cout << funcDiv(dividendo, divisor) << endl;
}
return 0;
}