//util.promisfy we convert our read write functions into promises and apply async await
// functions which has callback as last argument and callback having argumets as data and error can be converted into promise using above fn


//Async await helps us to write asynchronous function in sunchronous manner

const fs = require('fs');
const path = require('path');
const util = require('util');

const F1 = path.join(__dirname,'inp1.txt');
const F2 = path.join(__dirname,'inp2.txt');
const F3 = path.join(__dirname,'output.txt');

let read = util.promisify(fs.readFile);
let write = util.promisify(fs.writeFile);

async function solve(){
    let data1 = await read(F1);
    let data2 = await read(F2);

    let ans = data1.toString().split('\n');

    ans = ans.concat(data2.toString().split('\n'));
    ans.sort((a,b)=>a-b);

    await write(F3,ans.join('\n'));
    console.log("All done !");
}

solve();