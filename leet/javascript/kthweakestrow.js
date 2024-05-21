//LeetCode No. 1337
var kWeakestRows = function(mat, k) {
    let pq = new PriorityQueue({
        compare: (a, b) => {
            if (a.val < b.val) return -1;
            if (a.val > b.val) return 1;
            return a.index < b.index ? -1 : 1;
            }
    });

    for (let z = 0; z < mat.length; z++) {
        let val = mat[z].indexOf(0) === -1 ? mat[0].length : mat[z].indexOf(0);
        pq.enqueue({ val: val, index: z });
    }

    let ans = [];
    for (let i = 0; i < k; i++) {
        ans.push(pq.dequeue().index);
    }

    return ans;
};