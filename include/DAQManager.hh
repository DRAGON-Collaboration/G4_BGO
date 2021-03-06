#ifndef DAQManager_h
#define DAQManager_h 1

#include <memory>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "G4UnitsTable.hh"
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "InputManager.hh"
#include "CascadeGenerator.hh"
#include <TTree.h>
#include <TBranch.h>

class DAQManager {

  public:

  DAQManager(InputManager* InMgr, CascadeGenerator* CasGen);
 ~DAQManager();

  void StartOfEvent();
  void EndOfEvent();

  void StartOfRun();
  void EndOfRun();

  void SetGammaE(double E);
  void SetDetNum(int n);
  void Write();
  void MultLikelihood();
  void EtotLikelihood();
  float gaus(float energy[200], float counts[200], int j);

  private:

  struct Data_Event {
    Float_t sum;
    Float_t esort[10];
    Float_t ecal[30];
    Int_t Mult;
  };

  struct Data_Run {
    Int_t Event;
    Int_t Run;
    Float_t cascade[5];
  };

  Data_Event data_event;
  Data_Run data_run;

  TTree* EventTree;
  TTree* RunTree;
  TBranch* EventBranch;
  TBranch* RunBranch;
  TFile* f1;

//  std::vector<double> E_gamma;//energy of each gamma detected
  InputManager* InMgr;
  CascadeGenerator* CasGen;
  double threshold;
  int N_coinc;
  int N_run;
  int N_event;
  int mult;//multiplicity of event
  double eff;

  TH2F* h_E;//Gamma energy histo
  TH1F* h_Etot;//Total energy histo
  TH1F* h_Etotconv;//Total energy histo convoluted
  TH1F* h_mult;//Multiplicity histo

};

#endif
