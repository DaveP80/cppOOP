//LeetCode No. 999
//0(n^2)
var numRookCaptures = function(board) {

    let ans = 0;
    function helper(x,y) {
        if (board[x][y] == "B") return true;
        return false;
    }
    function helper_b(x,y) {
        if (board[x][y] == "p") {
            ans++;
            return true
            };
        return false;
    }

    for (let i = 0; i<8; i++) {
        for (let j = 0; j<8; j++) {
            if (board[i][j] == "R") {
                let n = i+1;
                let o = j+1;
                let p = i-1;
                let q = j-1;

                while (n < 8) {
                    if (helper(n,j)) break;
                    if (helper_b(n,j)) {
                        break;
                    }
                        n++;
                }
                while (p > -1) {
                    if (helper(p,j)) break;
                    if (helper_b(p,j)) {
                        break;
                    }
                        p--;
                }
                while (o < 8) {
                    if (helper(i,o)) break;
                    if (helper_b(i,o)) {
                        break;
                    }
                        o++;
                }
                while (q > -1) {
                    if (helper(i,q)) break;
                    if (helper_b(i,q)) {
                        break;
                    }
                        q--;
                }
                break;
            }
        }
    }
    return ans;
};