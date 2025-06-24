#include <iostream>
using namespace std;

/*5. Implementar uma função que retorne um texto cifrado 
utilizando a técnica de criptografia RSA e depois decodifique 
usando os mesmos parâmetros. p e q devem ser dados pelo
usuário e o programa não precisa codificar números e 
caracteres especiais.
*/

//https://www.youtube.com/watch?v=9m8enHN13mw&ab_channel=JeronimoBezerra

int MDC(int a, int b){
    if (b > a){
        int temp = a;
        a = b;
        b = temp;
    }

    if (b == 0)
    {
        return a;
    }
    
    return MDC(b, a % b);
}

int inverso_Mod(int A, int B, int &s, int &t){
    
     if (B > A)
    {
        int temp = A;
        A = B;
        B = temp;
    }
    //caso base
    if (B == 0) {
        s = 1;
        t = 0;
        return A;
    }
    int stemp, ttemp;// Variáveis temporárias para armazenar os coeficientes de chamada recursiva
    
    int mdc = inverso_Mod(B, A % B, stemp, ttemp);

    // Atualizando x e y com base nos resultados anteriores
    s = ttemp;
    t = stemp - (A / B) * ttemp; // inverso 

    return s;


}

int main() {
    //1
    int p, q;
    cout << "Digite um primo p: ";
    cin >> p;
    cout << "Digite um primo q: ";
    cin >> q;
    //2 A mistura
    int n = p * q;

    //3 totiente
    int z = (p - 1) * (q - 1);
    
    //4
    int e = 3;
    while (MDC(e, z) != 1) {
        e++;
    }
    cout << e << endl;
    //5
    int s = 0, t = 0;
    inverso_Mod(3, 7, s, t);
    int d = s; // inverso modular de e
    
    cout << d << endl;
    //chave publica
    /*
    par n E e
    */
    
    //chave privada
    /*
    tripla p q E d
    */

    // privada na pratica + d


    return 0;
}