// Prog.cc
// This Program is
#include "Main.h"
int main (int par_exec1, char* pars_exec[])
{    
//Objects creation
	Mathematics * Math = new Mathematics();
    Physics * Phys = new Physics();
    
	FILE * outfile;
	outfile = fopen("Positions.dat","w"); //Positions for the trajectory graph
	
	FILE * outfile2;
	outfile2 = fopen("RaioPeriodo_relat5.dat","w"); //Radius and period data for the graphics

    printf("*******PROPAGATION OF COSMIC RAYS*******\n\n");   

	for(k=0;k<=2;k++) r0[k]=O[k];        //Original position
	v0[0]=173e6,v0[1]=173e6,v0[2]=173e6; //Initial velocity
    B0[0]=0,B0[1]=2e-6,B0[2]=0;          //Initial magnetic field
   
    modv=Math->Mod(v0);	//Velocity module
   	modB=Math->Mod(B0); //Constant Magnetic field module (If your simulation is another field type, change the called function)
   	
   	rL0=Phys->Larmor(rL,m,q,modv,modB); //Initial Larmor radius
   	
   	//Graphic scale
    x_max=O[0]+3*rL0,y_max=O[1]+3*rL0,z_max=O[2]+9*rL0;
    x_min=O[0]-3*rL0,y_min=O[1]-3*rL0,z_min=O[2]-0*rL0;	
    fprintf(outfile,"%.3e %.3e %.3e %.3e %.3e %.3e\n",x_min/UA,y_min/UA,z_min/UA,x_max/UA,y_max/UA,z_max/UA); //Give the max and minimum values
   	
   	
   	w=Phys->Angvelocity(w,q,modB,m); //Angular velocity
   	T=Phys->period(T,w); //Period
    t=T/10000; //time
   		
	printf("v0[1]=%.6e m/s = %.6f*c \n",v0[1],v0[1]/c); 
	printf("v0=%.6e m/s = %.6f*c \n",modv,modv/c);
	printf("rL0=%.3e m = %.3e UA\n\n",rL0,rL0/UA);
	printf("w=%e rad/s\n",w);	
    printf("T=%e s\n",T);
    printf("t=%e s\n",t);
    
	int NP=3*int(T/t); //iterations
	printf("NP=%d \n\n",NP);	
	int maxprt=9; //maximum of iterations outputs
	
    //MAIN LOOP
	for(i=1;i<=NP;i++){
		if(i<=maxprt)	printf("%d \n",i);
		 
		modr=Math->Mod(r0);		//position module
		if(i<=maxprt)	 printf(" r0=%.3e ",modr);

		/* TYPE OF MAGNETIC FIELD
		//---Constant 
		modB=Math->Mod(B0);
		
		//---Variable magnetic field
		modB=Phys->VarB(B,B0,r0,rL0);
		
		//---Dipole magnetic field
		modB=Phys->Dipole(B,r0);
		
		//---Galactic magnetic Field
		modB=Phys->GalacticField(B,r0);
		*/

		modB=Phys->VarB(B,B0,r0,rL0); //Type of magnetic field 
		if(i<=maxprt)	 printf("B=%.3e ",modB);
		
		Math->Projections(vpar,vper,v0,B); //For the constant field: Math->Projections(vpar,vper,v0,B0);
		modvpar=Math->Mod(vpar);
		modvper=Math->Mod(vper);
		if(i<=maxprt)	 printf("\n vper=%.3e vpar=%.3e \n",modvper,modvpar);		
			
		rL=Phys->Larmor(rL,m,q,modvper,modB);		
		if(i<=maxprt)	 printf(" rL=%.3e \n",rL);
				
		w=Phys->Angvelocity(w,q,modB,m);
    	T=Phys->period(T,w);
    	
    	if(i>1){
    		fprintf(outfile2,"%.3e %.3e %.3e \n",t*i,rL,T);
		}
		
		angle=Phys->Pitch(vper,vpar);		
		
		modF=Phys->FLorentz(F,q,vper,B); //For the constant field: modF=Phys->FLorentz(F,q,vper,B0); 
		if(i<=maxprt)	 printf(" F=%.3e \n",modF);
		
		
		//In non relativistic cases remove the line below 
		mr=Phys->Relativity(mr,modv,m);   //relativity mass
		
		
		//In non relativistic cases: for(k=0;k<=2;k++) a[k]=F[k]/m;
		for(k=0;k<=2;k++) a[k]=F[k]/mr; //acceleration
		Phys->Velocity(v,vper,a,t); 

  		for(k=0;k<=2;k++) v[k]=v[k]+vpar[k];
		modv=Math->Mod(v); 
		if(i<=maxprt)	 printf(" vf=%.3e ",modv);
		
		Phys->Trajectory(r,r0,v0,a,t);
		modr=Math->Mod(r); 
		if(i<=maxprt)	 printf(" rf=%.3e \n",modr);

		fprintf(outfile,"%.3e %.3e %.3e \n",r[0]/UA,r[1]/UA,r[2]/UA);
		if(i<=maxprt) printf("%.3e %.3e %.3e \n",r[0]/UA,r[1]/UA,r[2]/UA);

		for(k=0;k<=2;k++) {
			v0[k]=v[k];
			r0[k]=r[k];

		}
				
	}
	
	fclose(outfile);
	fclose(outfile2);
    printf("\n\n*******END OF RUN*******\n\n");
 	
	system("pause");
	return 0;
}
