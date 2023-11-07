# Bremge
Monte Carlo generator of high energy electron-proton and electron-nucleus bremsstrahlung events

The structure of the generator is described in a pdf file: bremge_short_description.pdf . It was written as a FORTRAN 77 package. 

After downloading the directory the compilation is needed: gfortran bremge.F brebldt.F -o main main.F

In order to run the generator inside eic-environment just execute:
./main 

* brebldt.F - the cuts are set
* main.F - number of events are set
* fort.7 - is the output of the generation:
* eg0, ee: photon and electron energy
* tgx, tgy: photon scattering angles
* tex, tey: electron scattering angles

hepMC3:
Bremge generates the scattering angles of the electron and photon with respect to the positive direction of the z-axis. 

In the program: bremge_to_hepmc3.cxx they are reversed to be compatible with EIC geometry simulation programs.  

Validation

* is performed by comparison of the resulting particle distributions with GETaLM beam effects simulation.
* cross-checks: outputs conversion to hepMC3 format: root[0] .x bremge_to_hepmc3_to_root.cxx  
