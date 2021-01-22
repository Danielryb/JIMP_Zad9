#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int l = mat->r;
	for(int k = 0; k < l-1; k++){
		int max = k;
		for(int i = k + 1; i < l; i++)
		{
			if(fabs(mat->data[i][k]) > fabs(mat->data[max][k]))
				max = i;
		}
		if (mat->data[max][k] == 0)
			return 1;
		if (max != k)
		{
			double *tmp;
			tmp = mat->data[k];
			mat->data[k] = mat->data[max];
			mat->data[max] = tmp;
			tmp = b->data[k];
			b->data[k] = b->data[max];
			b->data[max] = tmp;
		}

		for(int i = k+1; i < l; i++){
			if(mat->data[i][k] == 0)
				continue;
			double fc = mat->data[k][k] / mat->data[i][k];
			for(int j =k; j< l; j++){
				mat->data[i][j] = mat->data[k][j] - mat->data[i][j]*fc;
			}
			b->data[i][0] = b->data[k][0] - b->data[i][0]*fc;
		}
		if(mat->data[k][k] == 0)
			return 1;
	}

		return 0;
}

