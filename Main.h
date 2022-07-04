// System Headers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Mathematics.h"
#include "Physics.h"
//#include "Atmosphere.h"

//Global variables

//char ch;
//char string[8],line[100];
//double altitude[1481],temperature[1481],pressure[1481],density[1481];

const double q=1.602*pow(10.0,-19);
const double m=1.673*pow(10.0,-27);
const double UA=1.495978707*pow(10.0,11);
const int c=299792458;



int i,j,k,l;
double t,w,T;
double modr,modv,modB,modF, mr;

double O[3]={0,0,0};
double F[3],B[3],B0[3];
double r[3],r0[3],v[3],v0[3],a[3],angle,modvper,modvpar;

double vpar[3],vper[3];
double x_min,y_min,z_min,x_max,y_max,z_max;
double prod[3],rL,rL0;














