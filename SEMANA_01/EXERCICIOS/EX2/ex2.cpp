#include <iostream>
#include <string>
using namespace std;

// 2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor


int input(){
    int valorEntrada;
    cin >> valorEntrada; // pega o input usando o cin
    return valorEntrada;
}


int main(){
  cout << "Digite o Comando (0 ou 1):";
	int cmd = input();
	cout << "Comando Recebido: " << cmd << endl;
}
