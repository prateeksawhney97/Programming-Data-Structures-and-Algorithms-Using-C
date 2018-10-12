#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    
    
        float n, v1, v2;
        scanf("%f%f%f", &n, &v1, &v2);
        if (((n * sqrt(2)) / v1) >((2*n) / v2))
            printf("Taxi");
        else
            printf("Walk");
            
            
            
    
    return 0;
 
} 
