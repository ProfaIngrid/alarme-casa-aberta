int sensor = A0; // Pino do sensor de luminosidade
int luminosidade = 0; 
int ledAzul = 8; // Pino do led azul
int ledLaranja = 2; // Pino do led laranja

void setup() {
    Serial.begin(9600); //Inicializa a comunicação serial
  	pinMode(ledAzul, OUTPUT); // Configura o pino do LED como saída
    pinMode(ledLaranja, OUTPUT); // Configura o pino do LED como saída
}

void loop() {
    int luminosidade = analogRead(sensor); //Lê o valor do sensor
    Serial.println(luminosidade); //Imprime o valor da luminosidade

    if (luminosidade > 20) {
        // Loop para criar som de sirene com LEDs alternados
        // Primeiro, acenda o LED azul e faça o beep
        for (int freq = 500; freq <= 1000; freq += 10) {
            digitalWrite(ledAzul, HIGH); // Acende o LED azul
            beep(freq, 15); // Emite o som com a frequência atual
            digitalWrite(ledAzul, LOW); // Apaga o LED azul
            delay(10); // Pequeno atraso para garantir que o LED apagado seja visível antes de acender o próximo
        }

        // Em seguida, acenda o LED laranja e faça o beep
        for (int freq = 500; freq <= 1000; freq += 10) {
            digitalWrite(ledLaranja, HIGH); // Acende o LED laranja
            beep(freq, 15); // Emite o som com a frequência atual
            digitalWrite(ledLaranja, LOW); // Apaga o LED laranja
            delay(10); // Pequeno atraso para garantir que o LED apagado seja visível antes de acender o próximo
        }

        // Repetir o processo na direção inversa da frequência
        // Primeiro, acenda o LED azul e faça o beep
        for (int freq = 1000; freq >= 500; freq -= 10) {
            digitalWrite(ledAzul, HIGH); // Acende o LED azul
            beep(freq, 15); // Emite o som com a frequência atual
            digitalWrite(ledAzul, LOW); // Apaga o LED azul
            delay(10); // Pequeno atraso para garantir que o LED apagado seja visível antes de acender o próximo
        }

        // Em seguida, acenda o LED laranja e faça o beep
        for (int freq = 1000; freq >= 500; freq -= 10) {
            digitalWrite(ledLaranja, HIGH); // Acende o LED laranja
            beep(freq, 15); // Emite o som com a frequência atual
            digitalWrite(ledLaranja, LOW); // Apaga o LED laranja
            delay(10); // Pequeno atraso para garantir que o LED apagado seja visível antes de acender o próximo
        }
    }

    delay(1000); // Aguarda 1 segundo antes de ler novamente
}


void beep(int frequency, int duration) {
    tone(7, frequency, duration); // Usa o pino 7 para emitir som
    delay(duration); // Aguarda a conclusão do beep
}


