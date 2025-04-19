#include "perceptron.h"
#include "sigmoid.h"


int perceptron_activation(float input)
{
	int result = PERCEPTRON_INACTIVE;

	result = (sigmoid_function(input) >= 0.0) ? PERCEPTRON_ACTIVE : PERCEPTRON_INACTIVE;

	return (result);
}

int perceptron_single_layer(VectorMatrix_t inputs, VectorMatrix_t weights, float bias)
{
	float result = 0.0;

	/* z = w.x + b */
	result = vectors_dot_product(inputs, weights) + bias;

	/**
	 * Activation:
	 * -------
	 * a = f(z) = { 0 if z <= 0,
	 * 				1 if z > 0 }
	 */	
	return (perceptron_activation(result));
}
