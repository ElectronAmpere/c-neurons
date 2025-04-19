#ifndef __VECTORS_H__
#define __VECTORS_H__

#include <stdio.h>

typedef struct 
{
	size_t rows;
	size_t cols;
	float *data;
}VectorMatrix_t;


#ifndef ARRAY_SIZE
	#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0])) 
#endif

/**
 * To initialise the row vector matrix of (row=1,column=n)
 */
#ifndef INIT_ROW_VECTORMATRIX
	#define INIT_ROW_VECTORMATRIX(a_vector, a_data) \
		VectorMatrix_t a_vector = {					\
			.rows = 1,								\
			.cols = ARRAY_SIZE(a_data),				\
			.data = a_data,							\
		};
#endif	

/**
 * To initialise the column vector matrix of (row=n,column=1)
 */
#ifndef INIT_COLUMN_VECTORMATRIX
	#define INIT_COLUMN_VECTORMATRIX(a_vector, a_data) \
		VectorMatrix_t a_vector = {					   \
			.rows = ARRAY_SIZE(a_data),				   \
			.cols = 1,								   \
			.data = a_data,							   \
		};
#endif

/* Function Prototypes */
float vectors_dot_product(VectorMatrix_t vector_a, VectorMatrix_t vector_b);





#endif /* __VECTORS_H__ */
