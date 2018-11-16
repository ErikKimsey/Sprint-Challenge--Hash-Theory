

function prob_three(a,b,c){
  // !(A && B) || ( (A && C) && !(B || !C) )
  return (!(a && b) || ( (a && c) && !(b || !c)));
}

// 1.
console.log(prob_three(false, false, false)); 
// 2.
console.log(prob_three(false, false, true));
// 3
console.log(prob_three(false, true, false));
// 4
console.log(prob_three(false, true, true));
// 5
console.log(prob_three(true, false, false));
// 6
console.log(prob_three(true, false, true));
// 7
console.log(prob_three(true, true, false));
// 8
console.log(prob_three(true, true, true));
