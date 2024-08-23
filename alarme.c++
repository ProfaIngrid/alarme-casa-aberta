int sensor = A0; // Pino do sensor de luminosidade
int luminosidade = 0;
int led = 8;

void setup() {
    Serial.begin(9600); // Inicializa a comunicação serial
  	pinMode(led, OUTPUT); // Configura o pino do LED como saída
}

void loop() {
    luminosidade = analogRead(sensor); // Lê o valor do sensor
    Serial.println(luminosidade); // Imprime o valor da luminosidade

    if (luminosidade > 20) {
        // Loop para criar som de sirene
        for (int freq = 500; freq <= 1000; freq += 10) {
            digitalWrite(led, HIGH);
            beep(freq, 15); // Aumenta a frequência gradualmente
        	digitalWrite(led, LOW); // Apaga o LED
        }
        for (int freq = 1000; freq >= 500; freq -= 10) {
            digitalWrite(led, HIGH); // Acende o LED
            beep(freq, 15); // Diminui a frequência gradualmente
            digitalWrite(led, LOW); // Apaga o LED
       }
    }

    delay(1000); // Aguarda 1 segundo antes de ler novamente
}

void beep(int frequency, int duration) {
    tone(7, frequency, duration); // Usa o pino 7 para emitir som
    delay(duration); // Aguarda a conclusão do beep
}

// Funções adicionais, se necessário, podem ser definidas aqui
