
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

console.log(f1);
let f2 = f1();
f2();
f2();
f2();