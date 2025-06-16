#include <iostream>
#include <string>
using namespace std;
/*2. Implementar uma função que cifre uma string utilizando 
a cifra de César; 
*/
string cifra_cesar(string frase, int x){
    string cifrada = "";

    for (int i = 0; i < frase.size(); i++)
    {
        char c = frase[i];
        
        if ('A' <= c and 'Z' >= c) //maiusculo
        {
            cifrada += char('A' + (c - 'A' + x) % 26);
        } else if ('a' <= c and 'z' >= c) //minusculo
        {
            cifrada += char('a' + (c - 'a' + x) % 26);
        } else {
            cifrada += c;
        }
        
    }

    return cifrada;
}

int main () {
    string original;
    int deslocamento;

    cin >> deslocamento;
    //'\n'
    cin.ignore();
    
    getline(cin, original);

    
    string cifrada = cifra_cesar(original, deslocamento);

    cout << cifrada << endl;

    return 0;
}