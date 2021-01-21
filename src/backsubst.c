#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */
				
				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
	if (mat->c == x->r && mat->r == b->r)
	{
		int i, l = x->r;
		for (i =0; i < l; i++) {
			x->data[l-i-1] = b->data[l-i-1][0];
			int j;
			for (j = 0; j < i; j++)
				x->data[l-i-1][0] -= mat->data[l-i-1][l-j-1] * x->data[l-j-1][0];
			if(mat->data[l-i-1][l-i-1] != 0)
				x->data[l-i-1][0] /= mat->data[l-i-1][l-i-1];
			else
				return 1;
		}
		return 0;
	}
	return 2;
}


