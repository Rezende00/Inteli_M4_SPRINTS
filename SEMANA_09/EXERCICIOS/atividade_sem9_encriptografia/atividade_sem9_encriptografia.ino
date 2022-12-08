#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <String>

//Vetores com nomes de rede e senhas dos Access Points
const char* SSID = "Inteli-COLLEGE";
const char* PWD = "QazWsx@123";
int parar = 0;
String guardaRede;

char converter(char ch, int chave) { // Função para converter caracteres
    if (!isalpha(ch)) return ch; // Se não for uma letra, retorna o caractere
    char offset = isupper(ch) ? 'A' : 'a'; // Se for maiúsculo, retorna A, se não, retorna a
    return (char)((((ch + chave) - offset) % 26) + offset); // Retorna o caractere convertido
}


String criptografar(String entrada, int chave ) { // Função para criptografar
    String saida = ""; // String para armazenar a saída
    size_t len = entrada.length(); // Tamanho da string de entrada
    for( size_t i = 0; i < len; i++ ) // Para cada caractere da string de entrada
        saida += converter(entrada[i], chave ); // adiciona o caractere convertido na string de saída
    return saida; // Retorna a string de saída
}


void postDataToServer() { // Função para enviar dados para o servidor

  Serial.println("Posting JSON data to server...");
  String encript = criptografar("Eu sou o Pablinhu", 8); // Chama a função para criptografar

  // Block until we are able to connect to the WiFi access point
  HTTPClient http;
    http.begin("https://ur524n-3000.preview.csb.app/teobaldo");  
    http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<200> doc; // Cria um documento JSON
  doc["Nome do Aluno"] = "Pedro de Carvalho Rezende";
  doc["Turma"] = 3;
  doc["Grupo"] = 1;
  doc["Mensagem_Texto"] = "Eu sou o Pablinhu";
  doc["Mensagem_criptografada"] = encript; 

  // Add an array.
  JsonArray data = doc.createNestedArray("data");
 
  String requestBody; // Variável para armazenar o JSON
  serializeJson(doc, requestBody); // Serializa o JSON

  int httpResponseCode = http.POST(requestBody);

  if (httpResponseCode > 0) { // Se o código de resposta for maior que 0, então o POST foi bem sucedido
    String response = http.getString();

    Serial.println(httpResponseCode);
    Serial.println(response);
  }
}

int menu()
{
  Serial.println(F("\nEscolha uma opção:"));
  Serial.println(F("Digite 0 para mandar as informações"));
  //fica aguardando enquanto o usuário nao enviar algum dado
  while(!Serial.available()){};
  //recupera a opção escolhida
  int op = (int)Serial.read();
  //remove os proximos dados (como o 'enter ou \n' por exemplo) que vão por acidente
  while(Serial.available()) {
    if(Serial.read() == '\n') break; 
    Serial.read();
  }
  return (op-48);//do valor lido, subtraimos o 48 que é o ZERO da tabela ascii
}


//Utilizado na função CONECTAR, para continuar mostrando os dados da conexão enquanto permanecer
//conectado. 
int menu2()
{
  Serial.println(F("\nEscolha uma opção 2:"));
  //fica aguardando enquanto o usuário nao enviar algum dado
  while(!Serial.available()){};
  //recupera a opção escolhida
  int op = (int)Serial.read();
  //remove os proximos dados (como o 'enter ou \n' por exemplo) que vão por acidente
  while(Serial.available()) {
    if(Serial.read() == '\n') break; 
    Serial.read();
  }
  return (op-48);//do valor lido, subtraimos o 48 que é o ZERO da tabela ascii
}

//Função para conectar em APs sem medição FTM
void EnviarDados(int rede)
{
  Serial.println("Conectando na rede: ");
  Serial.println(rede);
  WiFi.begin(SSID,PWD);
      while (WiFi.status() != WL_CONNECTED) {
        Serial.print("Tentando novamente!");
        delay(500);
      }
      while(parar==0)
      {
        Serial.println("WiFi connected");
        //DadosConexao();
        postDataToServer();      
        parar = menu2();
      }
      parar=0;
      WiFi.disconnect();
      Serial.println("Desconectei!");
}

//Função para conectar num AP sem medição FTM. Futuramente para conectar na internet e enviar 
//os dados dos sensores
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); 
}

void loop() {
  int opcao = menu();
  switch(opcao)
  {
    case 0:
      Serial.println("Conectar na internet e enviar dados para o servidor!");
      EnviarDados(0);
      break;
    default:
      Serial.println("Opção fora do padrão!");
      break;
  }
  Serial.println("Escrevendo letras");
  for(int i=0;i<3;i++)
  {
    Serial.println(guardaRede[i]);
  }
}
