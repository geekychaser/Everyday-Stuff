// call, apply, bind are used as function borrowing or function reusing

let name = {
    firstName: "Rishabh Kumar",
    lastName : "Bothra"
}

let name2 = {
    firstName : "Abhishek",
    lastName : "Jain"
}

function printName(city){
    console.log(this.firstName + " "+ this.lastName + " from "+ city);
} 

// call method
printName.call(name,"Rajasthan") // this directly calls the function where this will refer to object (that we pass) and later on other arg

// apply - this is exactly same as call just differe by syntax
printName.apply(name2,["UP"]) // later args are passed as an array list

// Bind - this is same as call method just we can have a state to call later rather than directly calling function
let for_later = printName.bind(name,"Rajasthan");

for_later();