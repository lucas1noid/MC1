#include <iostream>
using namespace std;
/* 4. Implementar uma função que recebe a e b como entradas e 
retorna MDC(a,b) e também s e t, de modo que s e t satisfazem 
a identidade de Bézout MDC(a,b)=sa+tb. Seu programa deve printar 
no terminal o passo a passo das operações até chegar no MDC. 
*/

int funcMDC_EX(int A, int B, int &s, int &t){
    
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
    
    int mdc = funcMDC_EX(B, A % B, stemp, ttemp);

    // Atualizando x e y com base nos resultados anteriores
    s = ttemp;
    t = stemp - (A / B) * ttemp; // inverso 

    return mdc;

    //Aritmética - Aula 22 - Relação de Bézout e Aplicações
}

int main () {
    int A, B;
    cout << "digite os números que pretende fazer o MDC(A e B): ";
    cin >> A >> B;
    
    int s, t;
    
    cout << "MDC de " << A << " e " << B << " = " << funcMDC_EX(A, B, s, t) << endl;
    cout << "Coeficientes s e t que satisfazem a identidade de Bezout: " << s << " e " << t << endl;
    cout << "Verificacao: " << A << "*" << s << " + " << B << "*" << t << " = " << (A*s + B*t) << endl;


    return 0;
}