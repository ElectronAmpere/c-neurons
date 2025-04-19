#include <stdio.h>

#include "vectors.h"
#include "perceptron.h"

int main()
{

    float input_vect_data[5]= {101.2,200.1, 1224.0, 133.0,103.3};
    float weight_vect_data[5]= {101.2,200.1, 1224.0, 133.0,103.3};
    float bias = 4.0;

    INIT_ROW_VECTORMATRIX(input_vect, input_vect_data);
    INIT_COLUMN_VECTORMATRIX(weight_vect, weight_vect_data);

    printf("Single Layer Perceptron: %d\n", perceptron_single_layer(input_vect, weight_vect, bias));

    return 0;
}
