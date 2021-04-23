#include "udf.h"


#define H 260000.0
#define rho_bed 310.0


DEFINE_SOURCE(energy_source,c,t,dS,eqn)
{
	real source;

	source = H*rho_bed*C_UDMI(c,t,1);
	C_UDMI(c,t,4) = source;


	return source; 
}

