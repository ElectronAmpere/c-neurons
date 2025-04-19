#include <stdio.h>
#include "perceptron.h"

/**
 * @brief      { function_description }
 *
 * @param[in]  test_name  The test name
 * @param[in]  expected   The expected
 * @param[in]  actual     The actual
 */
void test_assertion(const char *test_name, int expected, int actual)
{
	if (expected == actual){
		printf("[PASS] %s\n", test_name);
	} else {
		printf("[FAIL] %s: Expected %d, but got %d\n", test_name, expected, actual);
	}
}

int main()
{
    int result = 0;

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

	return 0;
}
