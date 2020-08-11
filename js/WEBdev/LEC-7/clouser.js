
// A closure is the combination of a function bundled together (enclosed) with references to its surrounding state 
// (the lexical environment). In other words, a closure gives you access to an outer function's scope from an inner function.
function test(){
    let x = 0;
    function fun(){
        // let x = 2;
        x++;
        function inner(){
            x++;
            console.log(x);
        }

        return inner;
    }
    
    return fun;
}

let f1 = test();
let f4 = test();

console.log(f1);
let f2 = f1();
let f3 = f1();

let f5 = f4();

f2();
f2();
f2();
f3();
f5();

// clouser sirf ek hi baar banta for a single call jese yha oe 2 baar f1 caal hua isley 2 baar increment ho gya 
//kyuki clouser ek hi baar banta hai toh dusri call pe puraani value update ho gyi thi


