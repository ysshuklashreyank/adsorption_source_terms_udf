#include "udf.h"


DEFINE_EXECUTE_AT_END(print)
{

	Domain *d;
	Thread *t;
	cell_t  c;
	real	uptake = 0.0;
	real	m = 0.0;
	real	tot_v = 0.0;
	real	time,dt;
	real	T = 0.0;
	real	sum_weighted_pressure = 0.0;
	real	avg_temp;
	real	avg_pressure;
	// real 	P_op, Pmin;
	real 	poperating;
	poperating = RP_Get_Real("operating-pressure");
	int	time_step;
	FILE	*fp;
	int     ID=3;
	Thread  *tf;

	d = Get_Domain(1);

	time = CURRENT_TIME;
	time_step = N_TIME;
	// P_op = RP_Get_Float("operating-pressure");
	tf=Lookup_Thread(d,ID);

	if (time <= 1.0)
	{
		if (time_step%10 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;

			fp = fopen("Ads_phase.txt","a");

			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);

	
		}

	}
	

	else if (time <= 5.0)
	{
		if (time_step%100 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;

			fp = fopen("Ads_phase.txt","a");

			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);

	
		}

	}

	else if (time <= 50.0)
	{
		
		if (time_step%1000 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;

			fp = fopen("Ads_phase.txt","a");

			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);

	
		}

	}
	
	else if(time <= 600.0)
	{
		
		if (time_step%1000 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;

			fp = fopen("Ads_phase.txt","a");

			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);

	
		}

	}

	else if(time <= 605.0)
	{	
		if (time_step%100 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;
			fp = fopen("Ads_phase.txt","a");
			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);
		}

	}
	else if(time <= 650.0)
	{	
		if (time_step%1000 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;
			fp = fopen("Ads_phase.txt","a");
			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);
		}

	}
	else 
	{	
		if (time_step%1000 == 0)
		{
			thread_loop_c(t,d)
			{
				if(t==tf)
				{
				begin_c_loop(c,t)
				{
					m = m + C_UDMI(c,t,0)*C_VOLUME(c,t);
					T = T + C_T(c,t)*C_VOLUME(c,t);
					tot_v = tot_v + C_VOLUME(c,t);
					sum_weighted_pressure = sum_weighted_pressure + (C_P(c,t) + poperating) * C_VOLUME(c,t);
				}
				end_c_loop(c,t)
				}
			}
			uptake = m/tot_v;
			avg_temp = T/tot_v;
			avg_pressure = sum_weighted_pressure/tot_v;
			fp = fopen("Ads_phase.txt","a");
			fprintf(fp,"%f\t %f\t %f\t %f\n",time,uptake,avg_temp, avg_pressure); 
			fclose(fp);
		}

	}
}

