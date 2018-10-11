#include <stdio.h>

#define ROW 5
#define COL 5

int main() {
	int M, N, i, j;
	int matrix[ROW][COL];

    scanf("%d%d",&M,&N);
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d",&matrix[i][j]);
        }
    }



	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			if(i>=j)
				printf("%d ", matrix[i][j]);
			else
				printf("%d ", 0);
		}
		printf("\n");
	}

	return 0;
}
