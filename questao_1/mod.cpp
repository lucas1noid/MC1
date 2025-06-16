#include <iostream>
using namespace std;
/*Implementar uma função que retorne o mod entre dois inteiros 
sem usar a operação da linguagem que retorne o resto da divisão 
de dois números.
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

int funcMod(int dividendo, int divisor){
    int quociente = funcDiv(dividendo, divisor);
    
    int resto = dividendo - (divisor * quociente);

return resto;
}
int main () {
int dividendo, divisor;
cin >> dividendo >> divisor;

if(divisor == 0){
cout << "Erro, entrada não esperada" << endl;
} else {
cout << funcMod(dividendo, divisor) << endl;
}
return 0;
}