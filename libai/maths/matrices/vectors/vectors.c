#include "vectors.h"


/**
 * @brief      Vector Dot Product
 *
 * @param[in]  vector_a  The vector a
 * @param[in]  vector_b  The vector b
 *
 * @return     dot product of two vector matrices
 */
float vectors_dot_product(VectorMatrix_t vector_a, VectorMatrix_t vector_b)
{	
	float result = 0.0;
	size_t iteration = 0;

	if ((vector_a.rows != vector_b.cols) || (vector_a.cols != vector_b.rows))
		return (result);

	for (iteration = 0; iteration < vector_a.rows; ++iteration)
	{
		result += vector_a.data[iteration] * vector_b.data[iteration];
	}

	return (result);
}
