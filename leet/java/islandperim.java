//LeetCode No. 463 Island Perimeter
class Solution {
    public int islandPerimeter(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int per = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int p = 0;
                if (grid[i][j] == 1) {

                    if (i - 1 < 0 || grid[i - 1][j] == 0) {
                        p++;
                    }
                    if (i + 1 == row || grid[i + 1][j] == 0) {
                        p++;
                    }
                    if (j - 1 < 0 || grid[i][j - 1] == 0) {
                        p++;
                    }
                    if (j + 1 == col || grid[i][j + 1] == 0) {
                        p++;
                    }
                    per += p;
                }
            }
        }
        return per;
        
    }
}
