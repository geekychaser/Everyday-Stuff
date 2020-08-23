// curry using bind function

function multiply(x,y){
    console.log(x*y);
}

let curry_2 = multiply.bind(this,2);
curry_2(3);


// curry using clousers

let multi = function(x){
    return function(y){
        console.log(x*y);
    }
}

let clouser_curry = multi(2);

clouser_curry(3);