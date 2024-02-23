//Codewars 5263a84ffcadb968b6000513
//Multiply Matrix
//Parameters, Matrix[] Matrix[] Matrix.length == Matrix.length
function matrixMultiplication(a, b){
    const c = a.length;
    const ans = [];
    for (let i = 0; i<c; i++) {
      ans[i] = Array.from({length: c}).fill(0);
    for (let j = 0; j<c; j++) {
      
      for (let z = 0; z<c; z++) {
        ans[i][j] += a[i][z] * b[z][j];
      }       
    }   
    }
    return ans;
  }