

// dc motor
#define MOTOR_ENABLE = 11;
#define MOTOR_1 = 10;
#define MOTOR_2 = 9;

// encoder
#define ENCODER_A = 3;


// PID controler
float target = 500.0; // referenca za RPM
float sum_error = 0.0;
float error_previous;
float kp = 0.5;
float ki = 0.55;
float kd = 0.0;


// volatile, ker spreminjamo v interruptu
volatile int count = 0;

long currentMillis;
long previousMillis;


void setup()
{
	// beremo samo en kanal enkoderja (lame)
	pinMode(ENCODER_A, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(ENCODER_A), count_pulses, FALLING);


	pinMode(MOTOR_1, OUTPUT);
	pinMode(MOTOR_2, OUTPUT);
	pinMode(MOTOR_ENABLE, OUTPUT);

	// one direction
	digitalWrite(MOTOR_1, 1);
	digitalWrite(MOTOR_2, 0);


	Serial.begin(9600);
	Serial.println("loading...\n");
}

void loop()
{

	long currentMillis = millis(); // trenuten cas

	if (currentMillis >= 7000) {
		target = 700.0; // po 7 sekundah sprememba referenca za rpm
	}

	float dt = (float) (currentMillis - previousMillis)/1000.0;
	if (dt >= 0.010) {

		float f_actual = (float) count * 60 / 62.184 / dt;

		// proportional
		float error = target - f_actual; // trenutna napak

		// integral
		sum_error += error*dt; // integracijska napaka
		sum_error = constrain(sum_error, -10000, 10000); // omejitev integralskega clena, da nam ne pobegne

		// differential
		float rateError = (error - error_previous)/dt; // diferencialni del

		uint8_t pwm = kp*error + ki*sum_error + kd*rateError;
		pwn = constrain(pwm, 0, 255); // omejitev pwm clena
		analogWrite(MOTOR_ENABLE, pwm);


		previousMillis = currentMillis;

		// reset pulse counter
		count = 0;

		error_previous = error;

		Serial.println(f_actual);
	}
}

// interrupt handler
void coutn_pulses()
{
	count+=1;
}

