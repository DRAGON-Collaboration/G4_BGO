#include "EventAction.hh"

EventAction::EventAction(DAQManager* aDAQMgr) {

//  eventMessenger = new EventActionMessenger(this);

  DAQMgr = aDAQMgr;

}


EventAction::~EventAction() {

//  delete eventMessenger;

}


void EventAction::BeginOfEventAction(const G4Event* evt) {
  
  DAQMgr->StartOfEvent();

  G4int evtNb = evt->GetEventID();

//  G4cout << "\n---> Begin of event: " << evtNb << G4endl;//verbosity = high

}

void EventAction::EndOfEventAction(const G4Event* evt) {
  
  DAQMgr->EndOfEvent();

  //print per event (modulo n)
  G4int evtNb = evt->GetEventID();

//  G4cout << "---> End of event: " << evtNb << G4endl;	//verbosity = high

}
