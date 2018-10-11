#include <stdio.h>
 
#define MAXROW      10
#define MAXCOL      10
 
int main()
{
    int matrix[MAXROW][MAXCOL];
    int i,j,r,c;
     
    
    scanf("%d %d",&r,&c);
 
    
    for(i=0;i< r;i++)
    {
        for(j=0;j< c;j++)
        {            
            scanf("%d",&matrix[i][j]);
        }
    }
 
    /*Transpose a matrix */
    
    for(i=0;i< c;i++)
    {
        for(j=0;j< r;j++)
        {
            printf("%d ",matrix[j][i]);    /*print elements*/
        }
        printf("\n");   /*after each row print new line*/      
    }
    return 0;       
}
