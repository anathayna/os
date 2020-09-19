/**********************************************************
* PROGRAM: buffon.c
* DATE: 15-05-2004
* DESC.: APROXIMATE PI BY SIMULATING BUFFON’S
* NEEDLE EXPERIMENT.
*********************************************************/
#include <time.h> /* for timing the code */
#include <stdio.h> /* for writing to files */
#include <math.h> /* for exponentials and logs */

/* George Marsaglia´s uniform random number generator */
/* (has a very large period, > 2^60, and passes Diehard tests; */
/* uses a multiply-with-carry method) */
#define s1new (s1=(18000*(s1&0xFFFF)+(s1>>16)))
#define s2new (s2=(30903*(s2&0xFFFF)+(s2>>16)))
#define UNI (((s1new<<16)+(s2new&0xFFFF))*2.32830643708e-10)
unsigned long s1=362436069, s2=521288629;
#define setseed(seed1,seed2) {s1=seed1;s2=seed2;}

int main(void) {
    double theta, distance;
    
    /* time store locations */
    clock_t startTime, endTime;
    
    /* set seed of UNI */
    setseed(362436069,521288629);

    /* log Pi aproximation on these iterations */
    long log_points[] = { 10, 100, 1000, 10000, 100000,
    1000000, 10000000, 100000000, 1000000000};
    int numLogPoints = 9;

    /* start time count */
    startTime = clock();

    /* simulate throws of a 1 unit needle on a sheet with one */
    /* unit distant parallel lines and acumulate the number of */
    /* hits (i.e. needle crossing/touching a line) */
    long i=1;
    int hits = 0;
    int logIndex = 0;

    while (logIndex < numLogPoints) {
        /* set next log point */
        int nextLogPoint = log_points[logIndex];
        logIndex++;
        
        /* iterate */
        for (;i<=nextLogPoint;i++) {
            /* get a sample from a U(0,PI) */
            theta = UNI * M_PI;

            /* get a sample from a U(0,0.5) */
            distance = UNI * 0.5;

            /* see if it falls on the hit area */
            if (distance <= 0.5 * sin(theta))
            hits++;
        }

        /* elapsed time */
        endTime = clock();

        /* log current aprox*/
        printf("NThrows: %11d Hits: %11d Pi Aprox.: %1.7f (%8.2f s.)\n",
                nextLogPoint, 
                hits, 
                (2.0*nextLogPoint)/hits,
                ((double)(endTime-startTime))/CLOCKS_PER_SEC);
    }
    return(0);
}