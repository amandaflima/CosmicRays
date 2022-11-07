// System Headers
//#include <iostream.h>
//#include <strstream.h>
#include <math.h>
#include <stdio.h>
class Physics
{
 private:
  //double ;
    
 public:
  //! Constructor of the class.
  Physics ( );

  //! Destructor of the class.
  ~Physics ( );
  
  //Lorentz force
  double FLorentz(double F[3], double q, double v[3], double B[3]);
  
  //Velocity
  double Velocity(double v[3],double v0[3],double a[3],double t);
  
  //Trajectory
  double Trajectory(double r[3],double r0[3],double v0[3],double a[3], double t);
  
  //Angular velocity
  double Angvelocity(double w,double q, double b, double m);

  //Moviment period
  double period(double T,double w);

  //Larmor radius
  double Larmor(double rL, double m, double q, double vmod, double Bmod);
  
  //Pitch angle
  double Pitch(double vper[3], double vpar[3]);
  
  //Variable field
  double VarB(double B[3],double B0[3],double r[3],double rL0);
  
  //Dipole field
  double Dipole(double BD[3], double r[3]);
  
  //Relativity mass
  double Relativity(double mr, double modv, double m);
  
  //Galactic field
  double GalacticField(double BG[3], double r[3]);
};









