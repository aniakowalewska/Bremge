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
* 
  theta angle for photons from Bremge and GETaLM
![THphot_BvsG](https://github.com/aniakowalewska/Bremge/assets/117586016/7cb78157-c334-4a6b-92bc-977fd5dfa0b3)

phi angle for photons from Bremge and GETaLM
![Phi_phot_BvsG](https://github.com/aniakowalewska/Bremge/assets/117586016/3182e982-97d7-4a66-a073-ad038f8df8b3)
phi angle for electrons from Bremge and GETaLM
![Phiel_BvsG](https://github.com/aniakowalewska/Bremge/assets/117586016/f4c35ae4-713d-4897-a0d6-2a605f43b290)
energy for photons from Bremge and GETaLM
![Ephot_BvsG](https://github.com/aniakowalewska/Bremge/assets/117586016/de91b2cd-90ee-40c0-bd56-be04b527b5f5)
energy for electrons from Bremge and GETaLM
![Eel_BvsG](https://github.com/aniakowalewska/Bremge/assets/117586016/54882f7b-359b-46fe-b008-42eb1d4f1acf)





