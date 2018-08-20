#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

// HPC program 1

// vary points 50,100,10^5,10^6 -> calc value of pie

void main()
{

double x,y,d,pie;

double start,end;

int iter=1000000000;

int i,cp=0,tp=0;
srand(time(0)); 



// have to set threads here
omp_set_num_threads(8);

start=omp_get_wtime();
#pragma omp parallel for 

for(i=0;i<iter;++i)
{
// generate points


 x = ((double)(rand() % 1000 ))/1000;
 y = ((double)(rand() % 1000 ))/1000;
 
// calculate distance
 //printf("\n x = %lf", x);
 //printf(" y = %lf", y);
 
// if dist<1
// then increment circ points (CP) and total points (TP)
// else increment TP

 if((x*x + y*y)<1)
  ++cp;

}
tp=iter;
end=omp_get_wtime();
// now calculate ratio of 4 * CP / TP 
//printf("\n Cp = %d", cp);
//printf("\n tp = %d", tp);
pie= (double)( 4 * cp )/tp;
printf("\n time = %lf", end-start);
printf("\n Pie = %lf", pie);

}


