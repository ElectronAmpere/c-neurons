#include <math.h>
#include "sigmoid.h"

float sigmoid_function(float input)
{
	float result = 0.0;

	result = 1 / (1 + exp(-input));

	return (result);
}
