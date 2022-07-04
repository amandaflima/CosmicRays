{
    gROOT->Reset();

//gStyle->SetOptLogx();
//gStyle->SetOptLogy();
//gStyle->SetOptFit(1011);

ifstream in;
in.open("Positions.dat");

//Int_t nlines=0;

//Int_t nlines=0;
Double_t x,y,z;
Double_t x_min,x_max,y_min,y_max,z_min,z_max;

TCanvas *c1 = new TCanvas("c1");

//c1->SetLogx(1);

//TH3F *h123 = new TH3F("h123","Trajetoria da part0cula",100,-10,10,100, -10, 10,100,0,120);

TView *view = TView::CreateView(1);
in >> x_min >> y_min >> z_min >> x_max >> y_max >> z_max;

view->SetRange(x_min, y_min, z_min, x_max, y_max, z_max);
//view->SetRange(-interval,-interval, -interval, interval, interval, interval);

TPolyLine3D *h123 = new TPolyLine3D(100000); 
     
     //fscanf(fp1,"%f %f %f %f %f %f %f %f %f ",&Event,&Theta,&Phi,&RA,&Dec,&GalLong,&GalLat,&EmEnergy,&Energy); 
     //     cout << Theta << endl;
    const Int_t n =100000;  
    for (Int_t i=0;i<n;i++){
    in >> x >> y >> z;
    //h123->Fill(x,y,z);
   
    h123->SetPoint(i,x,y,z);
   }

//c1->Update();
//hpx->GetXaxis()->SetTitle("EeV");
//c1->SetLogx();
h123->Draw();


TPaveText *title = new TPaveText(0.1,0.75,0.8,0.97);
   title->SetFillColor(24);
   title->AddText("Trajectory of a proton in a variable magnetic field");
   //TText *click=title->AddText("total deviation = 71.442 degrees   q = 1.602x10^-19 [c]   B = 100 [uG]   m = 938x10^6 [eV/c^2]   energy = 1 [EeV]   radius = 5.726x10^3 [UA]");
   //TText *click=title->AddText("q = 1.6E-19 [C], m = 1.67E-27 [kg] ");
   //TText *click=title->AddText("B=B0/(r/r0)");
   TText *click=title->AddText("B=B0/(r/r0)");
   TText *click=title->AddText("v=2.996E+8 m/s , B=2.00E-6 T, rL0=1.565E+6 m");
   click->SetTextColor(9);
   title->Draw();

   TAxis3D *rulers = new TAxis3D();
    rulers->SetXTitle("x [UA]");
    rulers->SetYTitle("y [UA]");
    rulers->SetZTitle("z [UA]"); 
    rulers->Draw();  
   
   //TMarker(Double_t x,Double_t y,Int_t marker) // os parametros x e y são as coordenadas
   
  // ma->SetMarkerSize(6)
   
   //TMarker(Double_t z,Double_t j,Int_t marker) // os parametros x e y são as coordenadas
   
  // ma->SetMarkerSize(6)
    

 in.close();
}




