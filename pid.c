#include <stdio.h>
#include <stdint.h>


float pid(float current, float target)
{
	float p = 100;
	float i = 0;
	float d = 1;

	static float previous=0;

	float prop;
	static float integ=0;
	float diff;


	prop = target - current;
	integ += prop;
	diff = prop - previous;

	previous = prop;

	return p * prop + i * integ + d * diff;
}


int main()
{

	for (int i = 0; i<120; ++i) {
		printf("%d %f \n", i, pid(i, 100));
	}

}

