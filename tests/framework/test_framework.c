#include <stdio.h>

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
