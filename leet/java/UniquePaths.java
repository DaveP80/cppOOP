//Leetcode 63: Unique Paths II
//https://leetcode.com/problems/unique-paths-ii/
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int [][] g;
        g = new int[obstacleGrid.length][obstacleGrid[0].length];
        for (int i = 0; i<obstacleGrid.length; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            else {
                g[i][0] = 1;
            }
        };
        for (int k = 0; k<obstacleGrid[0].length; k++) {
            if (obstacleGrid[0][k] == 1) {
                break;
            }
            else {
                g[0][k] = 1;
            }
        };

        for (int i = 1; i<obstacleGrid.length; i++) {
            int top = 0;
            int left = 0;
            for (int j = 1; j<obstacleGrid[0].length; j++) {
                top = g[i-1][j];
                left = g[i][j-1];
                if (obstacleGrid[i][j] != 1) {
                g[i][j] = top + left;
                }
            }
        }
        return g[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}