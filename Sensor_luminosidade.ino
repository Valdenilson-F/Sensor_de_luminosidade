// Definir os pinos
const int relePin = 2;    // Pino do relé (D2)
const int ldrPin = A0;    // Pino do LDR (A0)

int ldrValor = 0;         // Variável para armazenar o valor lido do LDR

void setup() {
  // Configuração dos pinos
  pinMode(relePin, OUTPUT);  // Pino do relé como saída
  pinMode(ldrPin, INPUT);    // Pino do LDR como entrada

  // Iniciar a comunicação serial para monitorar o valor do LDR
  Serial.begin(9600);
}

void loop() {
  // Ler o valor do LDR
  ldrValor = analogRead(ldrPin);

  // Exibir o valor do LDR no monitor serial para depuração
  Serial.print("Valor LDR: ");
  Serial.println(ldrValor);

  // Se o valor do LDR for maior que 500, liga o relé (lâmpada)
  if (ldrValor > 300) {
    digitalWrite(relePin, HIGH); // Relé ativado (lâmpada acesa)
  } else {
    digitalWrite(relePin, LOW);  // Relé desativado (lâmpada apagada)
  }

  // Aguardar um pouco antes de fazer a próxima leitura
  delay(100); // Delay de 100 ms
}
