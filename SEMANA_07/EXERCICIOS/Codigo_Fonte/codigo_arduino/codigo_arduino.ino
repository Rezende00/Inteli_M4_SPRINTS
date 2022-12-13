#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

// Vetores com nomes de rede e senhas dos Access Points: coloquei acess points do meu celular
const char *ssid = "PedroCrezM62";     // Inteli-COLLEGE
const char *password = "crezende105";  // QazWsx@123

#define LEDred 18 // porta do led vermelho 
#define LEDgreen 17 // porta do led verde

WebServer server(80); // porta do servidor

void player1() { // função que acende o led vermelho
  digitalWrite(LEDred, HIGH);
  delay(1000);
  digitalWrite(LEDred, LOW);
  delay(100);
  digitalWrite(LEDred, HIGH);
  delay(1000);
  digitalWrite(LEDred, LOW);
}

void player2() { // função que acende o led verde
  digitalWrite(LEDgreen, HIGH);
  delay(1000);
  digitalWrite(LEDgreen, LOW);
  delay(100);
  digitalWrite(LEDgreen, HIGH);
  delay(1000);
  digitalWrite(LEDgreen, LOW);
}



void setup() {
  pinMode(LEDred, OUTPUT); // configuração dos pinos dos leds
  pinMode(LEDgreen, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) { // enquanto não estiver conectado, vai tentando até conseguir
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to "); // quando conectar, vai mostrar o nome da rede e o IP
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/win1", player1); // quando o servidor receber a requisição /win1, vai chamar a função player1, ligando o LED vermelho
  server.on("/win2", player2); // quando o servidor receber a requisição /win2, vai chamar a função player2, ligando o LED verde

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient(); // vai ficar verificando se tem requisição do servidor
  delay(2);
}