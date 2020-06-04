
#define SHUNT_PIN 	2

float R_shunt = 0.22; 	// ohm
float R1 = 1000.0; 	// ohm
float R2 = 10000.0;	// ohm
float gain = 1.0 + R2/R1; // ojacanje


void setup()
{
	Serial.begin(9600);
}

void loop()
{

	int ain = analogRead(SHUNT_PIN);

	// pretvorba v volte
	float u = (float)ain * 5.0/1023.0;

	// izracunamo pravo (neojacano) vrednost
	float u_shunt = u/gain;

	// izracunamo tok v amperih
	float I = u_shunt/R_shunt;


	Serial.println( (String)(I*1000.0) + "mA" );
	delay(100);
}

