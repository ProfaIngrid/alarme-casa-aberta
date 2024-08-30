//armazenamento dos pinos
int sensor = A0; 
int luminosidade = 0; 
int ledAzul = 8; 
int ledLaranja = 2; 

void setup() {
    //Inicializa a comunicação serial
    Serial.begin(9600); 

    // configuração dos pinos dos LED's como saída
  	pinMode(ledAzul, OUTPUT); 
    pinMode(ledLaranja, OUTPUT);
}

void loop() {
    int luminosidade = analogRead(sensor); //Lê o valor do sensor
    Serial.println(luminosidade); //Imprime o valor coletado

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

        // Repete o processo na direção inversa da frequência
        // Acende o LED azul e emite beep
        for (int freq = 1000; freq >= 500; freq -= 10) {
            igitalWrite(ledAzul, HIGH); // Acende o LED azul
            beep(freq, 15); // Emite o som
            digitalWrite(ledAzul, LOW); // Apaga o LED azul
            delay(10); 
        }

        // Em seguida, acenda o LED laranja e faça o beep
        for (int freq = 1000; freq >= 500; freq -= 10) {
             digitalWrite(ledLaranja, HIGH); // Acende o LED laranja
            beep(freq, 15); // Emite o som
            digitalWrite(ledLaranja, LOW); // Apaga o LED laranja
            delay(10); 
        }
    }

    delay(1000); // Aguarda 1 segundo antes de ler novamente
}


void beep(int frequency, int duration) {
    tone(7, frequency, duration); // Usa o pino 7 para emitir som
    delay(duration); // Aguarda a conclusão do beep
}


