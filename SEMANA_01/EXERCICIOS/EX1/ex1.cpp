#include <iostream>
#include <string>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor

/*
--> Fazer uma função que receba 3 valores: [um valor mínimo], [um valor máximo] e um [terceiro valor]. 
A função deve retornar [se o terceiro valor inserido] está *mais próximo* (do valor mínimo) ou (do máximo), {em porcentagem}
*/

float converteSensor(int medida, int min, int max){
    float diff = 0;
	diff = (medida - min) * 100 / (max - min);
	return diff;
}


int main(){
  cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  //valor esperado: 0
  
	cout << converteSensor(400,100,400) << endl;
  //valor esperado: 100%
  
	cout << converteSensor(250,100,400) << endl;
  //valor esperado: 50%
}


