//LeetCode No. 1275 Find Winner on a Tic Tac Toe Game
/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function (moves) {

    let board = Array.from({ length: 3 }, () => Array.from({ length: 3 }));

    moves.forEach((item, idx) => {
        if (idx % 2 == 0) board[item[0]][item[1]] = "x";
        else board[item[0]][item[1]] = "o";
    })

    const primaryDiag = board[0][0];
    const secondaryDiag = board[0][2];

    var checkGame = function () {

        let stor = { "x": [0, 0], "o": [0, 0] };
        let diag_stor = { "x": [0, 0], "o": [0, 0] };

        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                let cellValue = board[i][j];
                let col_cellValue = board[j][i];
                if (cellValue) {
                    stor[cellValue][0]++;
                }
                if (col_cellValue) {
                    stor[col_cellValue][1]++;
                }
                if (j == 0 && board[i][i] && board[i][i] === primaryDiag) {
                    diag_stor[primaryDiag][0]++;
                }
                if (j == 0 && board[i][2 - i] && board[i][2 - i] === secondaryDiag) {
                    diag_stor[secondaryDiag][1]++;
                }
                if (diag_stor["x"].includes(3)) return "A";
                if (diag_stor["o"].includes(3)) return "B";
            }
            if (stor["x"].includes(3)) return "A";
            else if (stor["o"].includes(3)) return "B";
            stor = { "x": [0, 0], "o": [0, 0] };
        }
    };

    let res = checkGame();
    if (res == "A" || res == "B") return res;
    else if (moves.length == 9) return "Draw";
    return "Pending";
};