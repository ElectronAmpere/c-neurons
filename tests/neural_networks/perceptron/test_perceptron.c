#include "test_framework.h"
#include "perceptron.h"

int main(void)
{
    int result = 0;

    //Perceptron:
    //z = w.x + b
    // Test 1: Simple Test
    float x_data1[3]= {0.2, 1.4, 23.3};
    float w_data1[3]= {3.1, 1.33, 5.0};
    float bias = 5.0;

    INIT_ROW_VECTORMATRIX(x_vect, x_data1);
    INIT_COLUMN_VECTORMATRIX(w_vect, w_data1);

    result = perceptron_single_layer(x_vect, w_vect, bias);
    test_assertion("Test 1: Simple perceptron", 1, result);

	// Test 2: Negative weights
    float x_data2[3]= {1.0, -2.0, 3.0};
    float w_data2[3]= {-1.0, 2.0, -3.0};
    bias = -1.0;

    INIT_ROW_VECTORMATRIX(x_vect2, x_data2);
    INIT_COLUMN_VECTORMATRIX(w_vect2, w_data2);

    result = perceptron_single_layer(x_vect2, w_vect2, bias);
    test_assertion("Test 2: Negative weights", 0, result);

    // Test 3: Zero weights and inputs
    float x_data3[3]= {0.0};
    float w_data3[3]= {0.0};
    bias = 0.0;

    INIT_ROW_VECTORMATRIX(x_vect3, x_data3);
    INIT_COLUMN_VECTORMATRIX(w_vect3, w_data3);

    result = perceptron_single_layer(x_vect3, w_vect3, bias);
    test_assertion("Test 3: Zero weights and inputs", 0, result);

    // Test 4: NAND Gate
    float x_data4[4][2]= {{0.0, 0.0},
                          {0.0, 1.0},
                          {1.0, 0.0},
                          {1.0, 1.0}};
    float w_data4[2]= {-2.0, -2.0};
    bias = 3.0;

    INIT_ROW_VECTORMATRIX(x_vect4, x_data4[0]);
    INIT_COLUMN_VECTORMATRIX(w_vect4, w_data4);

    result = perceptron_single_layer(x_vect4, w_vect4, bias);
    test_assertion("Test 4: NAND Gate", 1, result);

    x_vect4.data = x_data4[1];
    result = perceptron_single_layer(x_vect4, w_vect4, bias);
    test_assertion("Test 4: NAND Gate", 1, result);

    x_vect4.data = x_data4[2];
    result = perceptron_single_layer(x_vect4, w_vect4, bias);
    test_assertion("Test 4: NAND Gate", 1, result);

    x_vect4.data = x_data4[3];
    result = perceptron_single_layer(x_vect4, w_vect4, bias);
    test_assertion("Test 4: NAND Gate", 0, result);

	return 0;
}
