//LeetCode No. 1700
var countStudents = function(students, sandwiches) {

    let stor = {}
    for (let s of students) {
        stor[s] = (stor[s] || 0) + 1;
    }
    let res = students.length;
    for (let z of sandwiches) {
        if (stor[z] > 0) {
            res -= 1;
            stor[z] -= 1;
        } else return res;
    }
    return res;
    
};