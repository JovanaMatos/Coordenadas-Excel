#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string numeros = "0123456789";
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (true){
    string coluna= " ";
    string linha =" ";
    int resultadoColu = 0; // resultado final
    string coordUltilizador= "";
    cout << "Indique as coordenadas: ";
    getline(cin, coordUltilizador);
    for (int i = 0; i < coordUltilizador.length(); ++i) { // Converter para maiúsculas
        coordUltilizador[i] = toupper(coordUltilizador[i]);
    }

    if (coordUltilizador == "SAIR" ){//Se escrever sair termina o programa
        cout<<"Encerrando";
        break;
    }
        int encontrarEspacos = coordUltilizador.find(' '); // Encontra espaço em coordUltilizador
        if  (encontrarEspacos != std::string::npos){
            coluna = coordUltilizador.substr(0, encontrarEspacos);    // Extrai a parte da string coluna
            linha = coordUltilizador.substr(encontrarEspacos + 1); // Extrai a parte da string linha
        }
        else
        {
            int n = 0;
            for (; n < coordUltilizador.size(); n++) {
                if (numeros.find(coordUltilizador[n]) != std::string::npos) {
                        break; // Quando Usuario digita sem epaçamento /procurando numeros
                }
            }
            linha = coordUltilizador.substr(n); // Posição da parte numérica encontrada adiante.
            coluna =  coordUltilizador.substr(0, n);
        }

        for (int l = 0; l < coluna.size(); l++) { // Loop através de cada Ch na string coluna
            char Ch = coluna[l]; // Atribui o caractere na posição l à variável Ch
            int posLetra = alfabeto.find(Ch); // Encontra a posição de Ch no alfabeto

            if (posLetra != string::npos) { // Verifica se o caractere está presente no alfabeto
                int valor = posLetra + 1; // Calcula o valor do Ch com base na sua posição no alfabeto
                for (int j = coluna.size() - l - 1; j > 0; --j) { // Considerando a posição na Coluna e ajustando para base 0
                    valor *= 26; // Multiplica o valor por 26
                }
                resultadoColu += valor; // Adicionando valor ao resultado final
            }
        }
        resultadoColu--; // Subtraindo 1 para voltar à posição de origem
        int linha1 = stoi(linha);  // Converter linha de string para inteiro
        linha1 = linha1 - 1; // Subtraindo 1 para voltar à posição de origem


        cout << "Linha: " << linha1 << " Coluna: " << resultadoColu << endl;
         cout<<"--"<<endl;
   }
    return 0;
}
