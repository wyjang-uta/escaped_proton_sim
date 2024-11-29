void convert4doojin()
{
  TFile fInput("TAMU_ALP.root", "read");
  TTree* t = (TTree*)fInput.Get("TAMU_ALP");
  double egamma;
  double px, py, pz;
  char pid[32];
  char proc[64];

  t->SetBranchAddress("Egamma", &egamma);
  t->SetBranchAddress("px", &px);
  t->SetBranchAddress("py", &py);
  t->SetBranchAddress("pz", &pz);
  t->SetBranchAddress("pid", pid);
  t->SetBranchAddress("proc", proc);

  const ULong64_t nEntries = t->GetEntries();
  ULong64_t cnt = 0;

  /*
  ofstream fout_pizero;
  ofstream fout_eta;
  ofstream fout_gamma_eBrem;
  ofstream fout_gamma;
  */
  ofstream fout_nu_e;
  ofstream fout_nu_mu;
  ofstream fout_nu_tau;
  ofstream fout_anti_nu_e;
  ofstream fout_anti_nu_mu;
  ofstream fout_anti_nu_tau;

  /*
  fout_pizero.open("dune_dump_pi0.txt");
  fout_eta.open("dune_dump_eta.txt");
  fout_gamma_eBrem.open("dune_dump_gamma_eBrem.txt");
  fout_gamma.open("dune_dump_gamma.txt");
  */
  fout_nu_e.open("dune_dump_nu_e.txt");
  fout_nu_mu.open("dune_dump_nu_mu.txt");
  fout_nu_tau.open("dune_dump_nu_tau.txt");
  fout_anti_nu_e.open("dune_dump_anti_nu_e.txt");
  fout_anti_nu_mu.open("dune_dump_anti_nu_mu.txt");
  fout_anti_nu_tau.open("dune_dump_anti_nu_tau.txt");

  for(ULong64_t i = 0; i < nEntries; i++)
  {
    t->GetEntry(i);
    /*
    if( strcmp(pid, "gamma") == 0 ) // -- 5
    {
      fout_gamma << px << "\ " << py << "\ " << pz << "\ " << egamma << endl;
    }
    if( strcmp(pid, "pi0") == 0 )
    {
      fout_pizero << px << "\ " << py << "\ " << pz << "\ " << egamma << endl;
    }
    if( strcmp(pid, "eta") == 0 )
    {
      fout_eta << px << "\ " << py << "\ " << pz << "\ " << egamma << endl;
    }
    if( strcmp(pid, "gamma") == 0 && strcmp(proc, "eBrem") == 0 && egamma > 0.005) // -- 5
    {
      fout_gamma_eBrem << px << "\ " << py << "\ " << pz << "\ " << egamma << endl;
    }
    */
    if( strcmp(pid, "nu_e") == 0 )
    {
      fout_nu_e << px << " " << py << " " << pz << " " << egamma << endl;
    }
    if( strcmp(pid, "nu_mu") == 0 )
    {
      fout_nu_mu << px << " " << py << " " << pz << " " << egamma << endl;
    }
    if( strcmp(pid, "nu_tau") == 0 )
    {
      fout_nu_tau << px << " " << py << " " << pz << " " << egamma << endl;
    }
    if( strcmp(pid, "anti_nu_e") == 0 )
    {
      fout_anti_nu_e << px << " " << py << " " << pz << " " << egamma << endl;
    }
    if( strcmp(pid, "anti_nu_mu") == 0 )
    {
      fout_anti_nu_mu << px << " " << py << " " << pz << " " << egamma << endl;
    }
    if( strcmp(pid, "anti_nu_tau") == 0 )
    {
      fout_anti_nu_tau << px << " " << py << " " << pz << " " << egamma << endl;
    }
  }
  fInput.Close();

  /*
  fout_pizero.close();
  fout_eta.close();
  fout_gamma_eBrem.close();
  fout_gamma.close();
  */
  fout_nu_e.close();
  fout_nu_mu.close();
  fout_nu_tau.close();
  fout_anti_nu_e.close();
  fout_anti_nu_mu.close();
  fout_anti_nu_tau.close();
}
