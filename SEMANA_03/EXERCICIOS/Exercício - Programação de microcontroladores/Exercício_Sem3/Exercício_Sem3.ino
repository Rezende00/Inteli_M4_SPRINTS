// Link para a simulação no Wokwi: https://wokwi.com/projects/347347049799221843

#define LEDR 18
#define LEDY 19
#define LEDB 21
#define LEDG 5
#define Buzzer 2
#define ButtonG 38
#define ButtonB 37
#define LDR 12

int binario[4];

int frequencia[100];
int x = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(ButtonG, INPUT_PULLUP); // irá ficar LOW somente quando for pressionado
  pinMode(ButtonB, INPUT_PULLUP);
  pinMode(LDR, INPUT); // pois irá receber energia/dados constantemente
}

void conversor(int valor) {
  int i = 0;
  while (i < 4) {
    binario[i] = valor % 2;
    valor = valor / 2;
    i += 1;
  }
}

void armazenarf(int freq) {
  tone(Buzzer, freq * 200, 250);
  frequencia[x] = freq;
  x += 1;
}

void toca() {
  int i = 0;
  while (i <= (x - 1)) {
    tone(Buzzer, frequencia[i]*200, 250);
    conversor(frequencia[i]);
    delay(1000);
    ligaled();
    i += 1;
  }
}


void ligaled() {
  if (binario[0] == 1) {
    digitalWrite(LEDR, HIGH);
  } else {
    digitalWrite(LEDR, LOW);
  }
  if (binario[1] == 1) {
    digitalWrite(LEDY, HIGH);
  } else {
    digitalWrite(LEDY, LOW);
  }
  if (binario[2] == 1) {
    digitalWrite(LEDB, HIGH);
  } else {
    digitalWrite(LEDB, LOW);
  }
  if (binario[3] == 1) {
    digitalWrite(LEDG, HIGH);
  } else {
    digitalWrite(LEDG, LOW);
  }
}


void loop() {
  int ldr = analogRead(LDR);

  int intervalo = (ldr / 260); //separando os intervalos 0-15
  conversor(intervalo);

  ligaled();

  if (digitalRead(ButtonG) == LOW) {
    armazenarf(intervalo);
  }

  if (digitalRead(ButtonB) == LOW) {
    toca();
  }
  delay(100);
}
