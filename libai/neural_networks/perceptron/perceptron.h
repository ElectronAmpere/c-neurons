#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__

#include "vectors.h"

#ifndef PERCEPTRON_ACTIVE
	#define PERCEPTRON_ACTIVE (1)
#endif

#ifndef PERCEPTRON_INACTIVE
	#define PERCEPTRON_INACTIVE (0)
#endif

int perceptron_single_layer(VectorMatrix_t inputs, VectorMatrix_t weights, float bias);

#endif /* __PERCEPTRON_H__ */
