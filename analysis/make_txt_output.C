//void make_txt_output(const char* infile = "DUNE_DumpSim_POT1e2_AllParticles_QGSP_BERT.root")
void make_txt_output(const char* infile = "DUNE_DumpSim_POT1e2_AllParticles_QGSP_BERT_VERSION2.root")
{
	double KE;
	double x, y, z;
	double px, py, pz;
	char pid[32];
	ULong64_t nEntries = 0;
	TFile fInput(infile, "READ");
	TTree* fTree = (TTree*)fInput.Get("DUNE_DumpSim");
	fTree->SetBranchAddress("KE", &KE);
	fTree->SetBranchAddress("x", &x);
	fTree->SetBranchAddress("y", &y);
	fTree->SetBranchAddress("z", &z);
	fTree->SetBranchAddress("px", &px);
	fTree->SetBranchAddress("py", &py);
	fTree->SetBranchAddress("pz", &pz);
	fTree->SetBranchAddress("pid", pid);

	nEntries = fTree->GetEntries();

	ofstream out_txt_gamma("gamma_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_electron("electron_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_positron("positron_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_numu("numu_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_numubar("numubar_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_pim("pim_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_pip("pip_dump_escapedProton_QGSP_BERT_POT1e2.txt");
	ofstream out_txt_pizero("pizero_dump_escapedProton_QGSP_BERT_POT1e2.txt");

	for(ULong64_t i = 0; i < nEntries; ++i ) {
		fTree->GetEntry(i);
		if( KE < 0.03 ) continue;		// energy threshold cut
		if( strcmp("gamma", pid) == 0 )
		{
			out_txt_gamma << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if( strcmp("e-", pid) == 0 )
		{
			out_txt_electron << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if( strcmp("e+", pid) == 0 )
		{
			out_txt_positron << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if(strcmp("nu_mu", pid) == 0)
		{
			out_txt_numu << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if(strcmp("anti_nu_mu", pid) == 0)
		{
			out_txt_numubar << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if(strcmp("pi-", pid) == 0)
		{
			out_txt_pim << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if(strcmp("pi+", pid) == 0)
		{
			out_txt_pip << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
		else if(strcmp("pi0", pid) == 0)
		{
			out_txt_pizero << KE << " " << px << " " << py << " " << pz << " " << x << " " << y << " " << " " << z << std::endl;
		}
	}

	out_txt_numu.close();
	out_txt_numubar.close();
	out_txt_pim.close();
	out_txt_pip.close();
	out_txt_pizero.close();
	fInput.Close();
}
