#include <Arduino.h>
// Programa : Teste basico encoder Arduino
// Autor : Arduino e Cia

// Carrega a biblioteca do encoder
#include <RotaryEncoder.h>

// Pinos de ligacao do encoder
RotaryEncoder encoder(26, 25);

// Variavel para o botao do encoder
int valor = 0;
int newPos = 0;

void setup()
{
	Serial.begin(115200);
	Serial.println("Gire o encoder....");
}

void loop()
{
	// Le as informacoes do encoder
	static int pos = 0;
	encoder.tick();
	int newPos = encoder.getPosition();
	// Se a posicao foi alterada, mostra o valor
	// no Serial Monitor
	if (pos != newPos)
	{
		Serial.print(newPos);
		Serial.println();
		pos = newPos;
	}
}