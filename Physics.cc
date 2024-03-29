//Physics.cc

// System Headers:
#include <stdlib.h>

// Local Headers:
#include "Physics.h"
#include "Mathematics.h"

// Constructor
Physics::Physics ( )       
{
  
}

// Destructor
Physics::~Physics ( )
{
        
}

//Lorentz force
double Physics::FLorentz(double F[3], double q, double v[3], double B[3])
{
	
	Mathematics * Math = new Mathematics();
	double prod[3],modF;
	Math->VecProd(prod,v,B);
	
	for(int i=0;i<=2;i++) F[i]=q*prod[i];	
	modF=Math->Mod(F);
	
  return modF;
}

//Velocity
double Physics::Velocity(double v[3],double v0[3],double a[3],double t)
{
	Mathematics * Math = new Mathematics();
	int i,k;
	double v2[3];
	  
	for(i=0;i<=2;i++) {
		v[i]=v0[i]+(a[i]*t);
	} 
	
	double vv=Math->Mod(v);    
	Math->Norm(v2,v); 
	
	double v0n=Math->Mod(v0); 
			
	for(k=0;k<=2;k++) v[k]=v2[k]*v0n; 
	return 0;
}

//Particle trajectory
double Physics::Trajectory(double r[3],double r0[3],double v0[3],double a[3], double t)
{
	for(int i=0;i<=2;i++) r[i]=r0[i]+v0[i]*t+0.5*(a[i]*t*t);
	return 0;
}

//Angular velocity
double Physics::Angvelocity(double w,double q, double b, double m)
{
	Mathematics * Math = new Mathematics();
	w=(q*b)/m;
	
	
	return w;
}

//Moviment period
double Physics::period(double T,double w)
{	
	T=(2*pi)/w;
	return T;
}

//Larmor Radius
double Physics::Larmor(double rL, double m, double q, double vmod, double Bmod){
	
	Mathematics * Math = new Mathematics();
	rL=(m*vmod)/(q*Bmod);
	return rL;
}

//Pitch angle

double Physics::Pitch(double vper[3],double vpar[3]){
	
	Mathematics * Math = new Mathematics();
	double vmodper,vmodpar, angle;
	
	vmodpar=Math->Mod(vpar);
	vmodper=Math->Mod(vper);
	angle=atan(vmodpar/vmodper)*rad2deg;
	
	return angle;

}

//Variable field

double Physics::VarB(double B[3],double B0[3],double r[3],double rL0){
	
	Mathematics * Math = new Mathematics();
	int i,k;
	double rmod,rb; //r1 = factor to decrease rmod
	double modB,modB0; 
	
	rb=3*rL0;
	
	rmod=Math->Mod(r);
		
	for(k=0;k<=2;k++) B[k]=B0[k];		
	if(rmod>.01){
		for(k=0;k<=2;k++) B[k]=(B0[k]*rb/rmod);
	}
	
	modB=Math->Mod(B);	
	return modB;
}

//Dipole field
double Physics::Dipole(double BD[3], double r[3]){
	//BS[3] - dipole field in spherical polar coordinates
	//BD[3] - dipole field cartesian coordinates
	
	Mathematics * Math = new Mathematics();
	double spherical[3], BS[3], mi, mi0, E[3], r1;
	mi0 = 8.00*pow(10.0,22); //magnetic permeability of vacuum, Tm/A
	mi = 12.5663706143592*pow(10.0,-7); //field dipole moment 
	r1= 7*pow(10.0,6); 
	Math->CoordinateTransform(spherical, r);
	
	BS[0] = (r1*mi0*mi*cos(spherical[1]))/(2*pi*E[0]*E[0]*E[0]); //Br
	BS[1] = (r1*mi0*mi*sin(spherical[1]))/(4*pi*E[0]*E[0]*E[0]); //Btheta
	BS[2] = 0; //Bphi
	
	BD[0] = (BS[1]*cos(spherical[1]) + BS[0]*sin(spherical[1]))*cos(spherical[1]);
	BD[1] = (BS[0]*cos(spherical[1])) - (BS[1]*sin(spherical[1]));
	BD[2] = (BS[1]*cos(spherical[1]) + BS[0]*sin(spherical[1]))*sin(spherical[1]);
	return 0;
}


//Relativity
double Physics::Relativity(double mr, double modv, double m){
	
	double c, gama;
	c = 299792458;  //  (m/s)
	//Mathematics * Math = new Mathematics();
	
	gama = 1/sqrt(1-(pow(modv,2)/pow(c,2))); 
	mr = gama * m; //relativistic mass
	
	return mr;
}

//Galactic field
double Physics::GalacticField(double BG[3], double r[3]){
	//BG[3] - galactic field cartesian coordinates
	//BC[3] - galactic field cylindrical coordinates
	//cylindrical[0] =  r�  
	//cylindrical[1]=   phi   
	//cylindrical[2]=   z
	double cylindrical[3], Bsp, p=-10/rad2deg, beta=-5.67, B0p, BC[3],z;
	double e,r0,p1, z1,z2,modB,modR;
	e= 3.25539e20;
	r0=2.623e20;
	p1=6.171e19;
	z1=9.257e18;
	z2=1.234e20;
	
	Mathematics * Math = new Mathematics();
	modR=Math->Mod(r);	
	Math->CylindricalTransform(cylindrical, r);
	
	
	//ASS MODEL
	if (modR<1e-3*kpc){ //correction for small initial position values, for example at the origin
		B0p = 3.19e-6 * pow(10,-10);
		Bsp = B0p*0.41;
	}
	else{
		B0p = (3*r0/cylindrical[0]) * pow(tanh(cylindrical[0]/p1),3) * pow(10,-10);	
		Bsp = B0p*cos(cylindrical[1] - beta*log(cylindrical[0]/e))*cos(cylindrical[1] - beta*log(cylindrical[0]/e)); //ASS
	}
	
	/* BSS MODEL
	B0p = (3*r0/cylindrical[0]) * pow(tanh(cylindrical[0]/p1),3) * pow(10,-10);	
	Bsp = B0p*cos(cylindrical[1] - beta*log(cylindrical[0]/e))*cos(cylindrical[1] - beta*log(cylindrical[0]/e));
	Bsp = B0p*cos(cylindrical[0] - beta*log(cylindrical[1]/e)); 
	*/
	
	//galactic field cylindrical coordinates
	z=r[2];
	BC[0] = Bsp*sin(p) *((1/(2*cosh(z/z1)))+  (1/(2*cosh(z/z2))));                               //br�
	BC[1] = Bsp*cos(p) * ((1/(2*cosh(z/z1)))+  (1/(2*cosh(z/z2))));                             //bphi 
	BC[2] =  0;                //bz

 	//galactic field cartesian coordinates
	BG[0] = BC[0]*cos(BC[1]);     //BX              
	BG[1] = BC[0]*sin(BC[1]) ;   //BY
	BG[2] = 0;       //BZ

	modB=Math->Mod(BG);		
	return modB;
}



