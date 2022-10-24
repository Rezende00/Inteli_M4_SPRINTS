#include <iostream>
#include <string>
using namespace std;

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e retorna verdadeiro ou falso


int continuar(){
    int resposta;
    cout << "Digite 1 para parar o mapeamento e 0 para continuar o mapeamento:" << endl;
    cin >> resposta;
    return resposta;
    if(resposta == 1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
  int parar = 0;
  
  while (parar == 0){
    parar = continuar();
  }

cout << "Mapeamento parado." << endl;

    return 0;
}
