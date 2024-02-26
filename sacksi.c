/*
 *  Get ξ(Ray Angle) of PKIKP ray path 
 *  
 *  cos⁡ξ=(cos⁡θ_1-cos⁡θ_2)/√(2-2cos⁡θ_1 cos⁡θ_2-2sin⁡θ_1 sin⁡θ_2 cos⁡(Φ_1-Φ_2 ) )
 *   
 * ⁡ θ_1  = 90° - evla  # evt colatitude  θita 1
 * 
 * ⁡ θ_2  = 90° - stla  # station colatitude 
 * 
 * ⁡ Φ_1  = evlo  # evt longitude  Fai 1
 * 
 * ⁡ Φ_2  = stlo  # station longitude 
 * 
 * 
 *  Author: JandyZ
 *  
 *  Revision:
 *    2023-12-16  JandyZ   Initial coding.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <math.h>
#include "sacio.h"

#define PI 3.14159265358979323846
void usage(void);

void usage() {
    fprintf(stderr, "Get ξ(Ray Angle) of PKIKP ray path.\n");
    fprintf(stderr, "                                                          \n");
    fprintf(stderr, "Usage:                                                    \n");
    fprintf(stderr, "  sacksi sacfiles                                         \n");
    fprintf(stderr, "                                                          \n"); 
    fprintf(stderr, "  eg:  sacksi YT.SIPL..BHZ.sac                            \n");
    fprintf(stderr, "Options:                                                  \n");
    fprintf(stderr, "  -h    show usage.                                       \n");
}

int main(int argc, char* argv[])
{
    int c;
    //int mode;
    int error;
    int i;
    
    error = 0;
    while ((c = getopt(argc, argv, "T:h")) != -1) { /*argc 参数数量 argv 字符串变量数组*/
        switch (c) {
        case 'h':
            usage();
            return -1;
        }
    }

    if (argc - optind < 1 || error) {
        usage();
        exit(-1);
    }


    for (i = optind; i < argc; i++) {  /* loop over files */
        SACHEAD hd;
        double evla, evlo, stla, stlo;
        /*  evla, evlo, stla, stlo; */
        read_sac_head(argv[i], &hd);
        evla = hd.evla;
        evlo = hd.evlo;
        stla = hd.stla;
        stlo = hd.stlo;
        double theta1, theta2,fai1,fai2;
        /*  θ_1  90° - evla , θ_2  90° - stla , 
            Φ_1 = evlo , Φ_2 = stlo; */
        theta1 =  (90 - evla) * PI / 180.0;
        theta2 =  (90 - stla) * PI / 180.0;
        fai1 = evlo * PI / 180.0;
        fai2 = stlo * PI / 180.0;
          
        /* do Ray Angle_cal */
        double up, low;
        double ksi;
        up = fabs(cos(theta1) -cos(theta2));
        low = sqrt(2 - 2*cos(theta1)*cos(theta2) - 2*sin(theta1)*sin(theta2)*cos((fai1-fai2)));
        ksi = acos(up / low) * 180.0 / PI; 
        printf("%s %f\n", argv[i], ksi); 

    }

    return 0;
}