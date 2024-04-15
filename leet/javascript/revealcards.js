//LeetCode No. 950 Medium
var deckRevealedIncreasing = function(deck) {

    let deq = Array.from({length: deck.length}).map((_,i) => i);
    deck.sort((a,b) => a-b);
    let ans = Array.from({length: deck.length});

    for (let d of deck) {
        let i = deq.shift();
        ans[i] = d;
        if (deq.length) {
            let n = deq.shift();
            deq.push(n);
        }
    }
    return ans;
    
};