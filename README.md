# sacksi

Get ξ(Ray Angle) of PKIKP ray path.

$\cos\xi = \frac{\left| \cos\theta_1 - \cos\theta_2 \right|}{\sqrt{2 - 2\cos\theta_1\cos\theta_2 - 2\sin\theta_1\sin\theta_2\cos(\phi_1 - \phi_2)}}$

Calculation of ξ(Ray Angle) PKIKP ray path. 

## SAC I/O functions

- `sacio.h`: Head file for SAC file format, and prototype for SAC IO functions.
- `sacio.c`: Definitions of several SAC IO functions.
  - `read_sac_head`: read SAC header
## SAC Utilities

- [sacksi](#sacksi): Get ξ(Ray Angle) of PKIKP ray path(SAC files).

### `sacksi`
```
Usage:
  sacksi sacfiles
  eg:  sacksi YT.SIPL..BHZ.sac
Options:
  -h    show usage.
```

## Compile and Use
Use the command in this folder:
```
gcc -o sacksi sacksi.c sacio.c sacio.h -lm
```
Place the tool directly into the $SACHOME/bin.

SACHOME refers to the folder where the SAC is installed