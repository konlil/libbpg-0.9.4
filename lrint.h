#ifndef LRINT_H
#define LRINT_H
#include "math.h"

static __inline double round(double val)
{    
	return floor(val + 0.5);
}

static __inline long lrint( double x )
{
	double rounded = round( x );
	long result = (long)rounded;

	if (fabs(result - x) != 0.5)
		return result;
	else {
		// Exact halfway case
		if (result & 1L) {
			// If the trailing bit is set, we rounded the wrong way
			long step = (result >> 30) | 1L;// x < 0 ? -1 : 1
			return result - step;			// x < 0 ? result + 1 : result - 1
		}
		else {
			return result;
		}
	}
}


#endif
