#include "udf.h"

#define Rp 5.0e-4
#define Do 2.9e-4
#define Ea 41661
#define R 81.49 		/* Specific gas const for R134a*/
#define Ru 8.314
#define tm 0.9			
#define rho_b 310.0
#define qst 260000
#define Co 0.94
#define Dso 7.356e-5
#define bo 8e-5

/*Constants for D-A eqn*/
#define Tb 246.78
#define Tcrit 374.21
#define vb 0.72643		/* [cc/g] */
#define B 0.939			/* [cc/g] */
#define Wo 1.591		/* [cc/g] */
#define D 9.56e-4		/* = R/E */		
#define n 1.17

/* Constants for Antoine Equation */
#define A_ant 14.41
#define B_ant 2094
#define C_ant -33.06

DEFINE_SOURCE(mass_source,c,t,dS,eqn)
{
	real source,time;
	real K;
	real Def;
	real q,qe;
	real x,y,z,b;
	real dt,P,T,iter,Pv;
	real Teff,theta,poperating;
	real alpha,va,P_s,W;


	time = CURRENT_TIME; 
	T = C_T(c,t);
	dt = CURRENT_TIMESTEP;
	poperating = RP_Get_Real("operating-pressure");
	Pv = (C_P(c,t)+ poperating);	
	P = Pv/1000.0;

	/*Toth eqn
	 b = bo*exp(qst/(R*T));
	 x = b*P;
	 y = pow(1 + pow(x,tm), 1/tm);
	 qe = Co * x / y;*/				/* phi* of Toth equation*/

	/* D-A eqn */
	alpha = log(B/vb) / (Tcrit - Tb);		/* [1/K] */
	va = vb * exp(alpha * (T - Tb));		/* [cc/g]*/
	P_s = exp(A_ant - B_ant / (T + C_ant));	        /* [kPa]*/
	W = Wo * exp(- pow(D*T*log(P_s / P), n));	/* [cc/g]*/
	qe = W / va;			                /* phi* of D-A equation*/


	/* kinetics*/
	Def = Dso*exp(-Ea/(Ru*T)); 
	theta = Def/(Rp*Rp);
	K = 15*theta;
	q = C_UDMI(c,t,0);


	C_UDMI(c,t,1) = K*(qe - q);

	C_UDMI(c,t,0) = q + C_UDMI(c,t,1)*dt;
	C_UDMI(c,t,2) = qe;
	C_UDMI(c,t,3) = Pv;
	
	source = -C_UDMI(c,t,1)*rho_b;
	/*if (time > 0.01)		
	{
		Message("The value of K is %.6f \n",K);
	}*/

	return source; 
}

