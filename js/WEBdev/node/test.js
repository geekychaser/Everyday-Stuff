const fs = require('fs');
const path = require('path');
const F1 = path.join(__dirname,'inp1.txt');
const F2 = path.join(__dirname,'inp2.txt');
const F3 = path.join(__dirname,'output.txt');

function read(filePath){
    console.log("file path is ",filePath);
    return new Promise((resolve,reject)=>{
        fs.readFile(filePath,(err,data)=>{
            if(err) throw err;

            resolve(data.toString().split(' '));
        })
    })
}

function write(data){
    return new Promise((resolve,reject)=>{
        fs.writeFile(F3,data,(err)=>{
            if(err) throw err;
            resolve();
        })
    })
}

const readf1 = read.bind(this);
const readf2 = read.bind(this);

let ans;

readf1(F1)
    .then((data)=>{
        ans = data;
        console.log("data successfully retrieved from file 1");
        console.log(data);
        console.log("===============================================================");
        return readf2(F2);
    })
    .then((data)=>{
        ans = ans.concat(data);
        console.log("data successfully retrieved from file 2");
        console.log(data);
        ans.sort((a,b)=>a-b);
        console.log("===============================================================");
        console.log(ans);
        console.log("===================================================================");
        return write(ans.join(' '));
    })
    .then(()=>{
        console.log("data successfully written in file 3");
    })



