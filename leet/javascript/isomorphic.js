//LeetCode 205.
//Isomorphic Strings
var isIsomorphic = function(s, t) {

    let stor = {};

    for (let i = 0; i<s.length; i++) {
        if (!stor.hasOwnProperty(s[i])) {
            if (Object.values(stor).includes(t[i])) return false;
            stor[s[i]] = t[i];
        } else {
            if (stor[s[i]] != t[i]) return false;
        }
    }

    return true;

};