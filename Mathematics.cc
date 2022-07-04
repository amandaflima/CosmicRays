//Mathematics.cc

// System Headers:
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// Local Headers:
#include "Mathematics.h"

// Constructor
Mathematics::Mathematics ( )       
{
  
}

// Destructor
Mathematics::~Mathematics ( )
{
        
}

//Vector Product
double Mathematics::VecProd(double prod[3],double vec1[3], double vec2[3])
{
  
  prod[0]=(vec1[1]*vec2[2]-vec1[2]*vec2[1]);
  prod[1]=-(vec1[0]*vec2[2]-vec1[2]*vec2[0]);
  prod[2]=(vec1[0]*vec2[1]-vec1[1]*vec2[0]);
  return 0;
}
  
//Modulus
double Mathematics::Mod(double vec[3])
{
	double modulus=sqrt(vec[0]*vec[0]+vec[1]*vec[1]+vec[2]*vec[2]);
 	return modulus;
}


//Normalizes a vector
void Mathematics::Norm(double versor[3], double vector[3])
{
	double m;
 	int i;
 	m=Mod(vector);
 	if (m!=0)
	{
  		for(i=0;i<=2;i++)
		{
			versor[i]=vector[i]/m;
		}
	}
}

//Scalar product
double Mathematics::ScalarProd(double vec1[3],double vec2[3])
{
	//cross é a projeção de um no outro.
	double scalar,mod1, mod2;
	scalar=(vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2]);
 	
	return scalar;
}

//Angle between vectors
double Mathematics::Angle2Vec(double vec1[3], double vec2[3]){
	
	double theta, scalar, mod1, mod2;

	scalar=ScalarProd(vec1,vec2);
	mod1=Mod(vec1);
	mod2=Mod(vec2);
	theta=acos(scalar/(mod1*mod2));
	
	return theta;
	
}

//parallel vector and perpendicular(pe=perpendicular/pa=parallel)
void Mathematics::Projections(double vpar[3],double vper[3],double vec1[3], double vec2[3]){
	//vec1=v(velocity), vec2=B(magnetic field)
	
	int i,k;
	double v2[3],v3[3];
	
	VecProd(v2,vec1,vec2);
	VecProd(v3,vec2,v2);
    double vec2mod=Mod(vec2);
    
	for(i=0;i<=2;i++) vper[i]=v3[i]/(vec2mod*vec2mod);	
	for(i=0;i<=2;i++) vpar[i]=vec1[i]-vper[i];
}

//Cartesian coordinate transformation for spherical
void Mathematics::CoordinateTransform(double vec1[3], double vec2[3]){   
	//vec1[3] = spherical coordinates: r, theta, phi  
	//vec2[3] = cartesian coordinates: rx, ry, rz
	
	vec1[0] = Mod(vec2); //r
	vec1[1] = atan((sqrt(vec2[0]*vec2[0]+vec2[1]*vec2[1]))/vec2[2]); //theta
	vec1[2] = atan(vec2[1]/vec2[2]); //phi
	
	printf("Spherical Coordinates");
	printf("r=%.9e ,",vec1[0]);
	printf("theta=%.9e \n",vec1[1]);
	printf("phi=%.9e ",vec1[2]);


}       
 
  
