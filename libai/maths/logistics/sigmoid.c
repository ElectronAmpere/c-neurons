#include <math.h>
#include "sigmoid.h"

float sigmoid_activation(float input)
{
	float result = SIGMOID_INACTIVE;

	result = 1 / (1 + exp(-input));

	return (result);
}
