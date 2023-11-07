# Bremge
Monte Carlo generator of high energy electron-proton and electron-nucleus bremsstrahlung events

The structure of the generator is described in a pdf file: bremge_short_description.pdf . It was written as a FORTRAN 77 package. 

After downloading the directory the compilation is needed: gfortran bremge.F brebldt.F -o main main.F
In order to run the generator inside eic-environment just execute:
./main 


* brebldt.F - the cuts are set
* number of events are set
* fort.7 - is the output of the generation:
         * eg0, ee: photon and electron energy
         * tgx, tgy: photon scattering angles
         * tex, tey: electron scattering angles
