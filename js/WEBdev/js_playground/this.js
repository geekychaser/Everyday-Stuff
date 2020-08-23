// This referes to the object that is executed in the current function in case of objects 
// example :

// Make sure to write complete function syntax rather than arrow functions
const vedio = {
    title : 'a',
    play(){
        console.log(this);
    }
}

vedio.stop = function(){
    console.log(this);
}

// vedio.stop();


// In a regular function this refers to windows in js and global in node and if you create a new instance using new operator than this 
// point to empty object util it has some property added
// not to use arrow function in methods and constructors

let k =()=>{
    this.x = 1;
   console.log(this);
}

function check(){
    let x = 1;
    console.log(this.x);
}

check();
k();