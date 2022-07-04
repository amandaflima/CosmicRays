void graph_from_data() {
   //Draw a simple graph
   // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
   //Author: Rene Brun
   //gStyle->SetOptFit(0111);
   //gStyle->SetOptLogy();
   
   TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);


   c1->SetFillColor(42);
   c1->SetGrid();
	
   TMultiGraph *mg = new TMultiGraph(); 

   FILE *fp1 = fopen("RaioPeriodo_relat1.dat","r");
   FILE *fp2 = fopen("RaioPeriodo_relat2.dat","r");
   FILE *fp3 = fopen("RaioPeriodo_relat3.dat","r");
   FILE *fp4 = fopen("RaioPeriodo_relat4.dat","r");
   FILE *fp5 = fopen("RaioPeriodo_relat5.dat","r");



   Int_t n=0;
   const Int_t nlines = 1000;
   Double_t x1[nlines],y1[nlines],z1[nlines];
   Double_t x2[nlines],y2[nlines],z2[nlines];
   Double_t x3[nlines],y3[nlines],z3[nlines];
   Double_t x4[nlines],y4[nlines],z4[nlines];
   Double_t x5[nlines],y5[nlines],z5[nlines];
   Double_t ex[0*nlines],ey[0*nlines];
   Float_t xr,yr,zr,wr;


    while (n<nlines) {

    fscanf(fp1,"%f %f %f",&xr,&yr,&zr);
    printf("x=%.3e  y=%.3e \n",xr,yr);
    x1[n]=xr;
    y1[n]=yr;
    n++;
   }

   TGraphErrors *gr1 = new TGraphErrors(n,x1,y1,ex,ey);  //vermelho
   gr1->SetLineColor(2);
   gr1->SetLineWidth(4);
   gr1->SetMarkerColor(2);
   gr1->SetMarkerStyle(21);
   gr1->SetTitle("Raio de Larmor x tempo");
   gr1->GetXaxis()->SetTitle("t [s]");
   gr1->GetYaxis()->SetTitle("rL [m]");
   mg->Add(gr1);

   ///gr1->Draw("AP");

   n=0;
   while (n<nlines) {

    fscanf(fp2,"%f %f %f",&xr,&yr,&zr);
    //cout << xr << " " << yr << endl;
    x2[n]=xr;
    y2[n]=yr;
    n++;
   }

   TGraphErrors *gr2 = new TGraphErrors(n,x2,y2,ex,ey); //AMARELO
   gr2->SetLineColor(5); 
   gr2->SetLineWidth(4);
   gr2->SetMarkerColor(5); 
   gr2->SetMarkerStyle(21);
   gr2->SetTitle("Raio de Larmor x tempo");
   gr2->GetXaxis()->SetTitle("t [s]");
   gr2->GetYaxis()->SetTitle("rL [m]");
   mg->Add(gr2);
   //gr2->Draw("AP");
   
   
   
   n=0;
   while (n<nlines) {

    fscanf(fp3,"%f %f %f",&xr,&yr,&zr);   //ROSAA
    //cout << xr << " " << yr << endl;
    x3[n]=xr;
    y3[n]=yr;
    n++;
   }

   gr3 = new TGraph(n,x3,y3);
   gr3->SetLineColor(6); 
   gr3->SetLineWidth(4);
   gr3->SetMarkerColor(6); 
   gr3->SetMarkerStyle(21);
   gr3->SetTitle("Raio de Larmor x tempo");
   gr3->GetXaxis()->SetTitle("t [s]");
   gr3->GetYaxis()->SetTitle("rL [m]");
   mg->Add(gr3);
   //gr3->Draw("SAME");
   
   n=0;
      while (n<nlines) {

    fscanf(fp4,"%f %f %f",&xr,&yr,&zr);
    //cout << xr << " " << yr << endl;
    x4[n]=xr;
    y4[n]=yr;
    n++;
   }

   gr4 = new TGraph(n,x4,y4); //ciano
   gr4->SetLineColor(7);
   gr4->SetLineWidth(4);
   gr4->SetMarkerColor(7);
   gr4->SetMarkerStyle(21);
   gr4->SetTitle("Raio de Larmor x tempo");
   gr4->GetXaxis()->SetTitle("t [s]");
   gr4->GetYaxis()->SetTitle("rL [m]");
   mg->Add(gr4);
   //gr4->Draw("SAME");
   
 
   n=0;
      while (n<nlines) {

    fscanf(fp5,"%f %f %f",&xr,&yr,&zr);
    //cout << xr << " " << yr << endl;
    x5[n]=xr;
    y5[n]=yr;
    n++;
   }

   gr5 = new TGraph(n,x5,y5); //verde
   gr5->SetLineColor(8);
   gr5->SetLineWidth(4);
   gr5->SetMarkerColor(8);
   gr5->SetMarkerStyle(21);
   gr5->SetTitle("Raio de Larmor x tempo");
   gr5->GetXaxis()->SetTitle("t [s]");
   gr5->GetYaxis()->SetTitle("rL [m]");
   mg->Add(gr5);
   //gr5->Draw("SAME");*/

   mg->Draw("AP");
   mg->GetYaxis()->SetTitle("rL [m]");
   mg->GetXaxis()->SetTitle("t [s]");
   mg->GetHistogram()->SetTitle("Raio de Larmor x Tempo");
   leg = new TLegend(0.1,0.5,0.3,0.3);
   leg->AddEntry(gr1,"v=0.3c","l");
   leg->AddEntry(gr2,"v=0.7c","l");
   leg->AddEntry(gr3,"v=0.9c","l");
   leg->AddEntry(gr4,"v=0.99c","l");
   leg->AddEntry(gr5,"v=0.999c","l");
 //  leg->AddEntry("gr","Graph with error bars","lep");
   leg->Draw();


   //mg->AddEntry(gr2,"Function abs(#frac{sin(x)}{x})","l");
//fit ---------------------------------------------
   
 /*  TF1 *f1 = new TF1("f1", "[0]+[1]*(x)", 0.,11.);
   f1->SetParameter (0,0);
   f1->SetParameter (1,5e-7);
//   f1->SetParameter (2,0);
   //gr2->Fit("f1","R");
   gr->Fit("f1","R");
   
 */ //----------------------------------------------  
   
   
   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
}
