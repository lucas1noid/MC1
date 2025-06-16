#include <iostream>
#include <string>
using namespace std;
/* 3.  Implementar uma função que recebe a e b como entradas e 
calcula o MDC(a,b) entre dois números. Seu programa deve printar 
no terminal o passo a passo das operações até chegar no MDC.
*/
int funcMDC(int A, int B){
    
    if (B > A)
    {
        int temp = A;
        A = B;
        B = temp;
    }
    
    if (A % B == 0)
    {
     cout << "como " << A << " dividido por " << B << " da 0, nosso MDC é o próprio: " << B << endl;
        return B;
    }
    cout << "como seu A dividido por B ainda não da 0, vamos chamar a função novamente, mas agora com os valores de A = " << B << " e B = " << (A % B) << endl;
    return funcMDC(B, A % B);
}

int main () {
    int A, B;
    cout << "digite os números que pretende fazer o MDC(A e B): ";
    cin >> A >> B;
    cout << "para calcular o MDC utilizaremos o algoritmo de Euclides, Ele baseia-se na ideia de que o MDC de dois números é o mesmo do MDC do menor número e do resto da divisão do maior pelo menor até o 0. " << endl;
    funcMDC(A, B); 

    return 0;
}