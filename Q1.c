#include "exam.h"

int getNumFlowers(int mat[][COLS], int rows)
{
	int sum = 0;
	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < COLS - 1; j++) {
			int sumPetals = mat[i - 1][j - 1]
				+ mat[i - 1][j + 1] + mat[i + 1][j - 1] + mat[i + 1][j + 1];
			if (mat[i][j] == sumPetals) {
				sum++;
			}
		}
	}
	return sum;
}
