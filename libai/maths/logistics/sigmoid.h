#ifndef __SIGMOID_H__
#define __SIGMOID_H__

#ifndef EULERS_NUMBER
	#define EULERS_NUMBER (2.718f)
#endif

#ifndef SIGMOID_ACTIVE
	#define SIGMOID_ACTIVE (1)
#endif

#ifndef SIGMOID_INACTIVE
	#define SIGMOID_INACTIVE (0)
#endif

float sigmoid_activation(float input);

#endif /* __SIGMOID_H__ */
