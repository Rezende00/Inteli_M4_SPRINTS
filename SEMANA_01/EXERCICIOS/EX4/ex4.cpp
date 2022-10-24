#include <iostream>
#include <string>
using namespace std;

// 4 - Faça uma função que recebe um vetor com 4 posições que contém o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a segunda é esta maior distância.



char* dirMaiorDist(int *Vetor){
    int maiorDist = 0;
    int indice = 0;
    char* direcoes = new char[10];
    for(int i = 0; i < 4; i++){
        if(Vetor[i] > maiorDist){
            maiorDist = Vetor[i];
            indice = i;
        }
    }
    if(indice == 0){
        direcoes = "Direita";
    }
    else if(indice == 1){
        direcoes = "Esquerda";
    }
    else if(indice == 2){
        direcoes = "Frente";
    }
    else if(indice == 3){
        direcoes = "Tras";
    }
    return direcoes;
}

int maiorDist(int *Vetor){
    int maiorDist = 0;
    for(int i = 0; i < 4; i++){
        if(Vetor[i] > maiorDist){
            maiorDist = Vetor[i];
        }
    }
    return maiorDist;
}



int main(){
  //Considere que os valores sempre serão distintos
  //Considere valores de distância inteiros entre 0 e 100
  
  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes [4] = {0, 20, 100, 50};
  
  cout << dirMaiorDist(posicoes) << endl;
  //valor esperado: Frente

  cout << maiorDist(posicoes) << endl;
  //valor esperado: 100


  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes2 [4] = {95, 70, 80, 50};
  
  cout << dirMaiorDist(posicoes2) << endl;
  //valor esperado: Direita

  cout << maiorDist(posicoes2) << endl;
  //valor esperado: 95


  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes3 [4] = {10, 0, 50, 60};
  
  cout << dirMaiorDist(posicoes3) << endl;
  //valor esperado: Tras

  cout << maiorDist(posicoes3) << endl;
  //valor esperado: 60


  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes4 [4] = {54, 55, 30, 0};
  
  cout << dirMaiorDist(posicoes4) << endl;
  //valor esperado: Esquerda

  cout << maiorDist(posicoes4) << endl;
  //valor esperado: 55
}
