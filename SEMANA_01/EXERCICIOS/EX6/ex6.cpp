#include <iostream>
#include <string>
using namespace std;

	//ERROR

// ----------------------------------------------------------------------------------------------------------------------------------
// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
// ----------------------------------------------------------------------------------------------------------------------------------


//1 ----------------------------------------------------------------------------------------------------------------------------------
float converteSensor(int medida, int min, int max){
    float diff = 0;
	diff = (medida - min) * 100 / (max - min);
	return diff;
}

//2 ----------------------------------------------------------------------------------------------------------------------------------
int input(){
    int valorEntrada;
    cin >> valorEntrada; // pega o input usando o cin
    return valorEntrada;
}

//3 ----------------------------------------------------------------------------------------------------------------------------------
int insereVetor(int elemento, int valorMax, int lastPos, int *Vetor){
    if(lastPos+1 >= valorMax){
        cout << "Erros: valorMax: "<<valorMax<<endl;
    }
    else{
        Vetor[lastPos +1] = elemento;
    }
    return *Vetor; 
    }

//4 ----------------------------------------------------------------------------------------------------------------------------------
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

//5 ----------------------------------------------------------------------------------------------------------------------------------
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

//6 ----------------------------------------------------------------------------------------------------------------------------------
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;	
		
	while(dirigindo){	
		cout << "Direita: ";
		int medida = input(); // Chama a função para "Direita"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = insereVetor(*vetorMov, maxVetor, posAtualVetor, medida);  // Chame a função para armazenar a medida no vetor
		posAtualVetor++;

		cout << "Esquerda: ";
		medida = input(); // Chama a função para "Esquerda"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = insereVetor(*vetorMov, maxVetor, posAtualVetor, medida);  
		posAtualVetor++;

		cout << "Frente: ";
		medida = input(); // Chama a função para "Frente"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = insereVetor(*vetorMov, maxVetor, posAtualVetor, medida);  
		posAtualVetor++;

		cout << "Trás: ";
		medida = input(); // Chama a função para "Trás"
		medida = converteSensor(medida, 0, 830);
		posAtualVetor = insereVetor(*vetorMov, maxVetor, posAtualVetor, medida);  
		posAtualVetor++;

		
		dirigindo = continuar();		
	}
	return posAtualVetor;
}




// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = dirMaiorDist(&(vetorMov[i]),maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}


int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}