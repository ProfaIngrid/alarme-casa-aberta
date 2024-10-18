int sensor = A0; // pino A0 para entrada do RDL
int ledAzul = 8; // pino 8 para a saída do LED azul
int ledLaranja = 2; // pino 2 para a saída do LED laranja
int luminosidade = 0; // variável para armazenar o valor lido do sensor

void setup() {
    // Inicializa a comunicação serial
    Serial.begin(9600); 

    // configuração dos pinos dos LEDs como saída
    pinMode(ledAzul, OUTPUT); 
    pinMode(ledLaranja, OUTPUT);
}

void loop() {
    luminosidade = analogRead(sensor); // Lê o valor do LDR e armazena na variável luminosidade.
    Serial.println(luminosidade); // Imprime o valor coletado

    if (luminosidade > 20) {
        // Loop para criar som de sirene com LEDs
        // Acende o LED azul e emite beep
        for (int freq = 500; freq <= 1000; freq += 10) {
            digitalWrite(ledAzul, HIGH); // Acende o LED azul
            beep(freq, 15); // Emite o som
            digitalWrite(ledAzul, LOW); // Apaga o LED azul
            delay(10); 
        }

        // Acende o LED laranja e emite beep
        for (int freq = 500; freq <= 1000; freq += 10) {
            digitalWrite(ledLaranja, HIGH); // Acende o LED laranja
            beep(freq, 15); // Emite o som
            digitalWrite(ledLaranja, LOW); // Apaga o LED laranja
            delay(10); 
        }       
    }

    delay(500); // Aguarda meio segundo antes de ler novamente
}

void beep(int frequency, int duration) {
    tone(7, frequency, duration); // Usa o pino 7 para emitir som
    delay(duration); // Aguarda a conclusão do beep
}
