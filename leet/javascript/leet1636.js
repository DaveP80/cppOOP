//LeetCode No. 1636 Sort Array by Increasing Frequency
var frequencySort = function(nums) {
    let frequencyMap = {};
    let pq = new PriorityQueue({
        compare: (a, b) => {
            if (a.freq !== b.freq) {
                return a.freq - b.freq;
            }
            return b.num - a.num; 
        }
    });

    for (let num of nums) {
        frequencyMap[num] = (frequencyMap[num] || 0) + 1;
    }

    for (let [k, v] of Object.entries(frequencyMap)) {
        pq.enqueue({ num: parseInt(k), freq: v });
    }

    let ans = [];
    while (pq.size()) {
        let { num, freq } = pq.dequeue();
        for (let i = 0; i < freq; i++) {
            ans.push(num);
        }
    }

    return ans;
};