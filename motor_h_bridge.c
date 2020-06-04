
#define MOTOR_EN 3 	// PWM
#define MOTOR_IN1 4	// digital
#define MOTOR_IN2 5	// digital


void initMotor()
{
	pinMode(MOTOR_EN, OUTPUT);
	pinMode(MOTOR_IN1, OUTPUT);
	pinMode(MOTOR_IN2, OUTPUT);
}

// prilagojeno za DRV8837
// https://www.ti.com/lit/gpn/drv8837
//
// funkcija izrabi enable pin za PWM tako,
// da je potreben samo en PWM pin
// ostala dva pina sta lahko normalna digitalna
//
// ce je hitrost negativna se vrti v drugo smer
void motor_zavrti_se (int16_t hitrost, uint32_t cas)
{
	if (hitrost > 0) {
		dititalWrite(MOTOR_IN1, 1);
		dititalWrite(MOTOR_IN2, 0);

	} else if (hitrost < 0) {
		dititalWrite(MOTOR_IN1, 0);
		dititalWrite(MOTOR_IN2, 1);
		hitrost = -hitrost;

	} else {
		digitalWrite(MOTOR_EN, 0);
		return ;
	}

	if (hitrost > 255) hitrost = 255;

	// start
	analogWrite(MOTOR_EN, hitrost);

	delay(cas); // tukaj bi lahko delali kaj bolj pametnega

	// stop
	analogWrite(MOTOR_EN, 0);

	digitalWrite(high_pin, 0);
	digitalWrite(low_pin, 0);
}

void motor_bremzaj(uint8_t intenziteta, uint32_t cas)
{
	analogWrite(MOTOR_EN, intenziteta);
	dititalWrite(MOTOR_IN1, 1);
	dititalWrite(MOTOR_IN2 , 1);

	delay(cas); // tukaj bi lahko delali kaj bolj pametnega

	analogWrite(MOTOR_EN, 0);
	digitalWrite(high_pin, 0);
	digitalWrite(low_pin, 0);
}

void setup()
{
	initMotor();
}

void loop()
{
	delay(2000);
	motor_zavrti_se(128, 3000);
	delay(2000);
	motor_zavrti_se(-255, 5000);
}

