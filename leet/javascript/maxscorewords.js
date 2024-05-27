//LeetCode No. 1255
//Hard
var maxScoreWords = function (words, letters, score) {

    let stor = new Map();
    let gw_stor = new Map();

    for (let l of letters) {
        stor[l] = (stor[l] || 0) + 1;
    }

    function gw(w) {
        if (!gw_stor.hasOwnProperty(w)) {
            gw_stor[w] = {};
            for (let d of w) {
                gw_stor[w][d] = (gw_stor[w][d] || 0) + 1;
            }
        }
        for (let z of w) {
            if (gw_stor[w][z] > (stor[z] || 0)) return false;
        }
        return true;
    }

    function getScore(w) {
        let total = 0;
        for (let z of w) {
            let g = z.charCodeAt(0);
            total += score[g - 97]
        }
        return total;
    }



    function dfs(i) {
        if (i == words.length) {
            return 0;
        }

        let res = dfs(i + 1)
        if (gw(words[i])) {
            for (let z of words[i]) {
                stor[z] -= 1;
            }
            res = Math.max(res, getScore(words[i]) + dfs(i + 1));
            for (let z of words[i]) {
                stor[z] += 1;
            }
        }
        return res || 0;
    }

    return dfs(0);

};