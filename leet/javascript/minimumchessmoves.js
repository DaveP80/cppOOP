// LeetCode No. 3001.
// There is a 1-indexed 8 x 8 chessboard containing 3 pieces.

// You are given 6 integers a, b, c, d, e, and f where:

// (a, b) denotes the position of the white rook.
// (c, d) denotes the position of the white bishop.
// (e, f) denotes the position of the black queen.
// Given that you can only move the white pieces, return the minimum number of 
// moves required to capture the black queen.
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @param {number} d
 * @param {number} e
 * @param {number} f
 * @return {number}
 */
var minMovesToCaptureTheQueen = function (a, b, c, d, e, f) {

    function bishopMove(x, y, flag) {
        if (x > 8 || y > 8 || x < 1 || y < 1 || (x == a && y == b)) {
            return 0;
        }

        if (x == e && y == f) {
            return 1;
        }
        switch(flag) {
            case "tl":
                let tl = bishopMove(x - 1, y + 1, flag);
                return tl;
            case "br":
                let br = bishopMove(x + 1, y - 1, flag);
                return br;
            case "tr":
                let tr = bishopMove(x + 1, y + 1, flag);
                return tr;
            case "bl":
                let bl = bishopMove(x - 1, y - 1, flag);
                return bl;
        }
    }

    function rookMove(x, y) {
        if (y == f && y == d && c < e && c > a) {
            return 0;
        }
        if (y == f && y == d && c > e && c < a) {
            return 0;
        }
        if (x == e && x == c && d < f && d > b) {
            return 0;
        }
        if (x == e && x == c && d > f && d < b) {
            return 0;
        }
        if (x == e || y == f) {
            return 1;
        }
    }

    let t = rookMove(a, b);

    if (t == 1) {
        return 1;
    }

    let tl = bishopMove(c-1, d+1, "tl");
    if (tl == 1) {
        return 1;
    }

    let br = bishopMove(c+1, d-1, "br");
    if (br == 1) {
        return 1;
    }

    let bl = bishopMove(c-1, d-1, "bl");
    if (bl == 1) {
        return 1;
    }

    let tr = bishopMove(c+1, d+1, "tr");
    if (tr == 1) {
        return 1;
    }
    return 2;
};