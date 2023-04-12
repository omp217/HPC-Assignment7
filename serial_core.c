#include <stdio.h>
#include <time.h>

#define INTERVAL 100000

int main()
{
    srand(time(NULL));
    int N = 1000000;
    int circle_points = 0;
    int square_points = 0;
    double randx, randy, origin_dist, pi;
    for(int i=0;i<N;i++)
    {
        randx = (double)(rand() % (INTERVAL + 1)) / INTERVAL;
        randy = (double)(rand() % (INTERVAL + 1)) / INTERVAL;
        origin_dist = randx * randx + randy * randy;
        if(origin_dist <= 1)
            circle_points++;
        square_points++;
        pi = (double)(4 * circle_points) / square_points;
        
        // Print pi
        printf("%f\n", pi);
    }
}