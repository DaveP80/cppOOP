// LeetCode No. 73 Set Matrix Zeroes
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int sentinel = 65845784873739; 

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {

                for (int a = 0; a < *matrixColSize; a++) {
                    if (matrix[i][a] != 0) {
                        matrix[i][a] = sentinel;
                    }
                }
                for (int b = 0; b < matrixSize; b++) {
                    if (matrix[b][j] != 0) {
                        matrix[b][j] = sentinel;
                    }
                }
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == sentinel) {
                matrix[i][j] = 0;
            }
        }
    }
}