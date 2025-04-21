#include <math.h>
#include "relu.h"

// ReLU function
float relu_function(float x)
{
    return x > 0 ? x : 0;
}
