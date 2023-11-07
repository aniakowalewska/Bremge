      Subroutine brebldt

*#include "copyright.inc"
*
* initials for bremge. Instead of block data. Adopted from BREMGE generator.
*
#include "brempa1.inc"
      common/BREMPA2/ PI,EMASS,PMASS
      common/BREMPA3/ FGEGP,EE0M,EHL,DSDUMA,DMIN,DMAX,DMIN2,DMAX2,DU3
      common /LUMTLT/ vert,tilt,prob,tbthxi,tbthyi
      real xvert(6),xtilt(7)
      data prob/0.2/
      DATA xVERT/3*0.,.436E-01,.1273E-01,24./
      
*LUMTLT

      call ucopy(xvert,vert,7)
      call uzero(tilt,1,7)
      TBTHXI = -10.
      TBTHYI = -10.

*brempa1

      EE0 = 10.0
      EP0 = 275.
      EGMIN = 0.1
      EGMAX = 9.99

      XEP = .00001
      YEP = .00001
      TGMAX = 0.001
      MODEBR = 0
      ZETGAS = 4.2

*brempa2

      pi = acos(-1.0)
      emass = 0.510999E-3
      pmass = 0.938272

      END
