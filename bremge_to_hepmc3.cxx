#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TROOT.h"
#include "TMath.h"
#include "TRint.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "/usr/include/HepMC3/Attribute.h"
#include "/usr/include/HepMC3/GenEvent.h"
#include "/usr/include/HepMC3/GenParticle.h"
#include "/usr/include/HepMC3/GenVertex.h"
#include "/usr/include/HepMC3/Setup.h"
#include "/usr/include/HepMC3/WriterAscii.h"
#include "HepMC3/Print.h"

using namespace HepMC3;

void bremge_to_hepmc3() {

ifstream ifile(" ... ",ifstream::in); 
string line; 
double ee, ethx, ethy, eg, gthx, gthy;
double m_e=0.000510999, m_p=0.938272, e_beam=10., p_beam=275.;
int nevt=0; //number of events
double e_px, e_py, e_pz, g_px, g_py, g_pz, q_px, q_py, q_pz, q_e;

HepMC3::WriterAscii outputfile(" ... ");

while( getline(ifile,line) ) {
  stringstream ss(line);
  ss >> eg >> gthx >> gthy >> ee >> ethx >> ethy;

  nevt = nevt+1;
  GenEvent evt(Units::GEV,Units::MM);
  evt.set_event_number(nevt);

  GenParticlePtr p1 = std::make_shared<GenParticle>(FourVector(0,0,-sqrt(e_beam*e_beam-m_e*m_e),e_beam),-11,4); 

  e_px = sqrt(ee*ee-m_e*m_e)*sin(ethx);
  e_py = sqrt(ee*ee-m_e*m_e)*sin(ethy);
  e_pz = sqrt(ee*ee-m_e*m_e)*cos(TMath::Pi()-sqrt(ethx*ethx+ethy*ethy));
  GenParticlePtr p3 = std::make_shared<GenParticle>(FourVector(e_px,e_py,e_pz,ee),-11,1); 

  g_px = eg*sin(gthx);
  g_py = eg*sin(gthy);
  g_pz = eg*cos(TMath::Pi()-sqrt(gthx*gthx+gthy*gthy));
  GenParticlePtr p4 = std::make_shared<GenParticle>(FourVector(g_px,g_py,g_pz,eg),22,1);

  GenVertexPtr v1 = std::make_shared<GenVertex>();
  v1->add_particle_in (p1);
  v1->add_particle_out(p3);
  v1->add_particle_out(p4);
  evt.add_vertex(v1);

  GenParticlePtr p2 = std::make_shared<GenParticle>(FourVector(0,0,sqrt(p_beam*p_beam-m_p*m_p),p_beam),2212,4); 

  q_px = -e_px-g_px;
  q_py = -e_py-g_py;
  q_pz = -sqrt(e_beam*e_beam-m_e*m_e)-e_pz-g_pz;
  q_e  = e_beam-ee-eg;
  GenParticlePtr p5 = std::make_shared<GenParticle>(FourVector(q_px,q_py,sqrt(p_beam*p_beam-m_p*m_p)+q_pz,p_beam+q_e),2212,1); 

  GenVertexPtr v2 = std::make_shared<GenVertex>();
  v2->add_particle_in (p2);
  v2->add_particle_out(p5);
  evt.add_vertex(v2);

  if (nevt<3) {Print::listing(evt);}

  outputfile.write_event(evt);
  evt.clear();
} 
ifile.close();
outputfile.close();
}
