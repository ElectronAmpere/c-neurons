#include "perceptron.h"
#include "sigmoid.h"


int perceptron_activation(float input)
{
	int result = PERCEPTRON_INACTIVE;

	result = (sigmoid_activation(input) >= 0.0) ? 1 : 0;

	return (result);
}

int perceptron_single_layer(VectorMatrix_t inputs, VectorMatrix_t weights, float bias)
{
	float result = 0.0;

	result = vectors_dot_product(inputs, weights) + bias;

	return (perceptron_activation(result));
}
