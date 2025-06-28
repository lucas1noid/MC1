#include <iostream>
#include <math.h>
using namespace std;

/*5. Implementar uma função que retorne um texto cifrado 
utilizando a técnica de criptografia RSA e depois decodifique 
usando os mesmos parâmetros. p e q devem ser dados pelo
usuário e o programa não precisa codificar números e 
caracteres especiais.
*/
//https://www.youtube.com/watch?v=9m8enHN13mw&ab_channel=JeronimoBezerra

long long MDC(long long a, long long b){
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

long long EX_mdc(long long A, long long B, long long &s, long long &t){
    
    //caso base
    if (B == 0) {
        s = 1;
        t = 0;
        return A;
    }
    long long stemp, ttemp;// Variáveis temporárias para armazenar os coeficientes de chamada recursiva
    
    long long mdc = EX_mdc(B, A % B, stemp, ttemp);

    // Atualizando x e y com base nos resultados anteriores
    s = ttemp;
    t = stemp - (A / B) * ttemp; // inverso 

    return mdc;
}

long long inv_mod(long long e, long long z){
long long x, y;
long long g = EX_mdc(e, z, x, y);
    if (g != 1)
    {
        return -1;
    } else {
        return (x % z + z) % z; // garante positivo
    }
}

//scopo global para: cifra, decifra e main
int tam;  
int resultado[100];
//scopo global //
void cifrarRSA(const string& mensagem, int e, long long n) {
    tam = mensagem.size();  
    int pos = 0;
       for (int i = 0; i < mensagem.size(); i++){
        int msg;
        char c = mensagem[i];
        //verificador
        if (c >= 'A' && c <= 'Z'){
            msg = c - 'A';
        } 
        else if (c >= 'a' && c <= 'z'){
            msg = c - 'a' + 26;
        } else if (c == ' ')
        {
            msg = c - ' ' + 52;
        }
        else  {
            continue; 
        }

        //potencia modular para inserir na resposta
        int criptografado = 1;
        for (int j = 0; j < e; j++){
            criptografado = (criptografado * msg) % n;
        }
        resultado[pos++] = criptografado;
    }
    tam = pos;
}

string decifrarRSA(int mensagem_criptografada[], int tamanho, int d, int n){
    string mensagem_decodificada = "";

    for (int i = 0; i < tamanho; i++){
        int criptografado = mensagem_criptografada[i];
        int msg = 1;
        
        //potencia mudular para voltar ao texto
        for (int j = 0; j < d; j++){
            msg = (msg * criptografado) % n;
        }
        //verificador
        if (msg >= 0 && msg <= 25){
            mensagem_decodificada += msg + 'A';    
        } 
        else if (msg >= 26 && msg <= 51){
            mensagem_decodificada += msg - 26 + 'a'; 
        } else if (msg == 52)
        {
            mensagem_decodificada += msg - 52 + ' ';
        } 
        
    }
    return mensagem_decodificada;
}

int main() {
    //1
    int p, q;
    cout << "Digite um primo p: ";
    cin >> p;
    cout << "Digite um primo q: ";
    cin >> q;
    //2 A mistura
    long long n = p * q;
    cout << n << endl;
    //3 totiente
    long long z = (p - 1) * (q - 1);
    
    //4
    int e;
    cout << "Agora digite o 'e': ";
    cin >> e;
    if (MDC(e, z) != 1)
    {
    cout << "O número que voce escolheu para 'e' é incompatível, vamos usar o coprimo com a totiente mais próximo" << endl;
    }
    while (MDC(e, z) != 1) {
        e += 2;
    }
    //5
    //long long s, t;
    
    int d = inv_mod(e, z); // inverso modular de e
    cout << endl;
    cout << "Chave pública (n, e): (" << n << ", " << e << ")" << endl;
    cout << "Chave privada (d): (" << d << ")" << endl;
    cout << endl;
    
    cin.ignore();
    
    string mensagem;
    
    cout << "Digite a mensagem que deseja criptografar: ";
    getline(cin, mensagem);
    
    cifrarRSA(mensagem, e, n);
    cout << endl;
    cout << "A sua mensagem criptografada é: ";
    for (int i = 0; i < tam; i++) {
        cout << resultado[i] << " ";
    }
    cout << endl << endl;
    
    int x = 0;
    cout << "deseja descriptografar sua mensagem usando a chave privada 'D'? sim[1] | não[2]" << endl;
    cin >> x;
    if (x == 1)
    {
    string mensagem_descriptografada = decifrarRSA(resultado, tam, d, n);
    
    cout << "A sua mensagem descriptografada é: " << mensagem_descriptografada << endl;
    } else {
        cout << "ok! encerrando..." << endl;
    }

    return 0;
}