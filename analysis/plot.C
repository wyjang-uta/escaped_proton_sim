void plot(const char* input = "DUNE_DumpSim_POT1e2_AllParticles_QGSP_BERT_VERSION2.root",
const char* output = "Analysis_EscapedProton_POT1e2_AllParticles_QGSP_BERT.root")
{
	double KE;
	double x, y, z;
	double px, py, pz;
	char pid[32];
	ULong64_t nEntries = 0;

	TFile* fInput = new TFile(input, "READ");
	TTree* fTree = (TTree*)fInput->Get("DUNE_DumpSim");
	fTree->SetBranchAddress("KE", &KE);
	fTree->SetBranchAddress("x", &x);
	fTree->SetBranchAddress("y", &y);
	fTree->SetBranchAddress("z", &z);
	fTree->SetBranchAddress("px", &px);
	fTree->SetBranchAddress("py", &py);
	fTree->SetBranchAddress("pz", &pz);
	fTree->SetBranchAddress("pid", pid);
	TFile* fOutput = new TFile(output, "RECREATE");
	nEntries = fTree->GetEntries();

  TH2D *h_yx_gamma, *h_xz_gamma;
  h_yx_gamma = new TH2D("h_yx_gamma", "y-x distribution(#gamma);x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_gamma = new TH2D("h_xz_gamma", "x-z distribution(#gamma);z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_electron, *h_xz_electron;
  h_yx_electron = new TH2D("h_yx_electron", "y-x distribution(e^{-});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_electron = new TH2D("h_xz_electron", "x-z distribution(e^{-});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_positron, *h_xz_positron;
  h_yx_positron = new TH2D("h_yx_positron", "y-x distribution(e^{+});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_positron = new TH2D("h_xz_positron", "x-z distribution(e^{+});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_pizero, *h_xz_pizero;
  h_yx_pizero = new TH2D("h_yx_pizero", "y-x distribution(#pi^{0});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_pizero = new TH2D("h_xz_pizero", "x-z distribution(#pi^{0});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_pim, *h_xz_pim;
  h_yx_pim = new TH2D("h_yx_pim", "y-x distribution(#pi^{-});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_pim = new TH2D("h_xz_pim", "x-z distribution(#pi^{-});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_pip, *h_xz_pip;
  h_yx_pip = new TH2D("h_yx_pip", "y-x distribution(#pi^{+});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_pip = new TH2D("h_xz_pip", "x-z distribution(#pi^{+});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_numubar, *h_xz_numubar;
  h_yx_numubar = new TH2D("h_yx_numubar", "y-x distribution(#bar{#nu}_{#mu});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_numubar = new TH2D("h_xz_numubar", "x-z distribution(#bar{#nu}_{#mu});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_numu, *h_xz_numu;
  h_yx_numu = new TH2D("h_yx_numu", "y-x distribution(#nu_{#mu});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_numu = new TH2D("h_xz_numu", "x-z distribution(#nu_{#mu});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_nuebar, *h_xz_nuebar;
  h_yx_nuebar = new TH2D("h_yx_nuebar", "y-x distribution(#bar{#nu}_{e});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_nuebar = new TH2D("h_xz_nuebar", "x-z distribution(#bar{#nu}_{e});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);
  TH2D *h_yx_nue, *h_xz_nue;
  h_yx_nue = new TH2D("h_yx_nue", "y-x distribution(#nu_{e});x (cm);y (cm)", 420, -210, 210, 420, -210, 210);
  h_xz_nue = new TH2D("h_xz_nue", "x-z distribution(#nu_{e});z (cm);x (cm)", 420, -210, 210, 420, -210, 210);


  gROOT->SetBatch(kTRUE);
  TCanvas* canvas = new TCanvas("cPosition", "Position Canvas", 800, 800, 0, 0);
	for(ULong64_t i = 0; i < nEntries; ++i ) {
		fTree->GetEntry(i);
    if( i % 1000 == 0 ) std::cout << "Progress (" << (float)i/nEntries * 100 << "%)\n";
    // reject events that does not meet the energy threshold condition
    if( KE < 0.03 ) continue;
    if( strcmp(pid, "gamma") == 0 )
    {
      h_yx_gamma->Fill(x,y);
      h_xz_gamma->Fill(z,x);
    }
    else if ( strcmp(pid, "e-") == 0 ) {
      h_yx_electron->Fill(x,y);
      h_xz_electron->Fill(z,x);
    }
    else if ( strcmp(pid, "e+") == 0 ) {
      h_yx_positron->Fill(x,y);
      h_xz_positron->Fill(z,x);
    }
    else if ( strcmp(pid, "pi0") == 0 ) {
      h_yx_pizero->Fill(x,y);
      h_xz_pizero->Fill(z,x);
    }
    else if ( strcmp(pid, "pi-") == 0 ) {
      h_yx_pim->Fill(x,y);
      h_xz_pim->Fill(z,x);
    }
    else if ( strcmp(pid, "pi+") == 0 ) {
      h_yx_pip->Fill(x,y);
      h_xz_pip->Fill(z,x);
    }
    else if ( strcmp(pid, "anti_nu_mu") == 0 ) {
      h_yx_numubar->Fill(x,y);
      h_xz_numubar->Fill(z,x);
    }
    else if ( strcmp(pid, "nu_mu") == 0 ) {
      h_yx_numu->Fill(x,y);
      h_xz_numu->Fill(z,x);
    }
    else if ( strcmp(pid, "anti_nu_e") == 0 ) {
      h_yx_nuebar->Fill(x,y);
      h_xz_nuebar->Fill(z,x);
    }
    else if ( strcmp(pid, "nu_e") == 0 ) {
      h_yx_nue->Fill(x,y);
      h_xz_nue->Fill(z,x);
    }
	}
	
  h_yx_gamma->Write();
  h_xz_gamma->Write();
  h_yx_electron->Write();
  h_xz_electron->Write();
  h_yx_positron->Write();
  h_xz_positron->Write();
  h_yx_pizero->Write();
  h_xz_pizero->Write();
  h_yx_pim->Write();
  h_xz_pim->Write();
  h_yx_pip->Write();
  h_xz_pip->Write();
  h_yx_numubar->Write();
  h_xz_numubar->Write();
  h_yx_numu->Write();
  h_xz_numu->Write();
  h_yx_nuebar->Write();
  h_xz_nuebar->Write();
  h_yx_nue->Write();
  h_xz_nue->Write();
	fOutput->Close();
	fInput->Close();

  /*
  delete fInput;
  delete fOutput;
  delete h_yx;
  delete h_zx;
  */
}
