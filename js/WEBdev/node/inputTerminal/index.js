// proces.argv to get input from terminal

function add(a,b){
    return a+b;
}

console.log(add(parseInt(process.argv[2]),parseInt(process.argv[3])));
console.log(process.argv);
