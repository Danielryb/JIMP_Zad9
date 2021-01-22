#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int l = mat->r;
	for(int k = 0; k < l-1; k++){
//		int ind_max = k;
//		double max_max = fabs(mat->data[k][k]);
//		for(int d = k+1; d<= l-1; d++){
//			if(fabs(mat->data[d][k]) > max_max){
//				max_max = fabs(mat->data[d][k]);
//				ind_max = d;
//			}
//		}
//		if(max_max == 0)
//			return 1;
//		if(ind_max != k){
//			double *arr = mat->data[k];
//			double *tmp = b->data[k];
//			mat->data[k] = mat->data[ind_max];
//			mat->data[ind_max] = arr;
//			b->data[k] = b->data[ind_max];
//			b->data[ind_max] = tmp;
//		}
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

