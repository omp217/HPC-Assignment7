#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <stdlib.h>

#define INTERVAL 100000

int main()
{
    int P = 10;
	omp_set_num_threads(P);
    int N = (int)1e7;
    int circle_points = 0;
    double randx, randy, origin_dist, pi;
    unsigned int seed[P];
	int i;
    for(i = 0; i < P; i++)
        seed[i] = time(NULL) + i;
#pragma omp parallel private(randx, randy, origin_dist) reduction(+:circle_points)
    {
        #pragma omp for
        for(i=0;i<N;i++)
        {
            // randx = (double)rand_r(&seed) / RAND_MAX;
            // randy = (double)rand_r(&seed) / RAND_MAX;
            randx = (double)rand_r(&seed[omp_get_thread_num()]) / RAND_MAX;
            randy = (double)rand_r(&seed[omp_get_thread_num()]) / RAND_MAX;
            origin_dist = randx * randx + randy * randy;
            if(origin_dist <= 1)
                ++circle_points;
        }
    }
	
    pi = (double)(4 * circle_points) / N;
    printf("%f", pi);
}