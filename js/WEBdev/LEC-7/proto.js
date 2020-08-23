// dunder proto and prototypes

/* 
    Khatarnak prototype chain bhai (refer the diagram) ek arr define krlo [1,2,3] ab
    arr.__proto__ == Array.prototype // true
    arr.__proto__.__proto__ == Object.prototype == fun().__proto.__proto // true
    arr.__proto__.__proto.__proto == null == object.prototype().__proto__ //true
    
    This whole prototype refering prototype is called prototype chaining
    */


    Function.Prototype.mybind = function(){ // this is added to prototyoe of function and can be used my any function
        console.log("global proto!")
    }

    var fun = function(){

    }

    fun.mybind(); // this will console.log

    