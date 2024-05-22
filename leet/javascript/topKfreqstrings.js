//LeetCode No. 692
//Javascript PriorityQueue
var topKFrequent = function (words, k) {
    let stor = {};
    let pq = new PriorityQueue({
        compare: (a, b) => {
            if (a.freq < b.freq) return 1;
            if (a.freq > b.freq) return -1;
            return a.char < b.char ? -1 : 1;
        }
    });

    for (let z = 0; z < words.length; z++) {
        stor[words[z]] = (stor[words[z]] || 0) + 1;
    }

    for (let [k, v] of Object.entries(stor)) {
        pq.enqueue({ char: k, freq: v });
    }

    let ans = [];
    for (let i = 0; i < k; i++) {
        ans.push(pq.dequeue().char);
    }
    
    return ans;
};