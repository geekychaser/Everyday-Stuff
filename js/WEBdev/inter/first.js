const a = "hello";

// will give error for changing constant variable
// a = "changed";

console.log(a);
console.log("==========================================================================");

const b = {
    name: "rishabh"
}

b.name = "abhishek" // this will not give err as we have change the value of key not the const

console.log(b);
console.log("==============================================================================");

if(true){
    // this will also give err as c is not defined
    // console.log(c); 

    let c = 23;
    console.log(c);
}

// this will give err as c is not defined because let has block scope only
// console.log(c); 
console.log("==================================================================================");

if(true){
    // this will give undefined as var has global scope and hoisting the d is done but value to d is assigned after this console
    console.log(d);
    var d = 5;
    console.log(d); // 5
}

console.log(d); // 5
console.log("=====================================================================================");

function check(){

    if(true){
        var e = 3;
        let f = 1;
    }

    console.log(e);

    // wil give err as f is not defined as let has only block scope that is if here
    // console.log(f);

}

check();
console.log("===========================================================================================");

// async function(){
//     let a = await getWeather().then(()=>{
//         console.log("this happens when getWeather is returnig a promise as response");
//     })
// }

// this will give as num is not defined as without var the variable is not hoisted
// console.log(num);
 num = 6;