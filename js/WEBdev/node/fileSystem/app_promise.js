// taking input from 2 inut files and putting them in third file after sorting them using promises to avoid callback hell

const fs = require('fs');
const path = require('path');
const F1 = path.join(__dirname,'inp1.txt');
const F2 = path.join(__dirname,'inp2.txt');
const F3 = path.join(__dirname,'output.txt');

function read1(){
    return new Promise((resolve,reject)=>{
        fs.readFile(F1,(err,data)=>{
            if(err) throw err;
            data = data.toString().split('\n');
            resolve(data);
        })
    })
}

function read2(){
    return new Promise((resolve,reject)=>{
        fs.readFile(F2,(err,data)=>{
            if(err) throw err;
            data = data.toString().split('\n'); // toString is used to convert the buffer data into string
            resolve(data);
        })
    })
}

function write(ans){
    return new Promise((resolve,reject)=>{
        fs.writeFile(F3,ans,(err)=>{
            if(err) throw err;
            resolve();
        })
    })
}

let ans;

read1()
    .then((data)=>{
        ans = data;
        console.log("data read from file 1 successfull !");
        return read2();
    })
    .then((data)=>{
        ans = ans.concat(data);
        console.log("read from file 2 successfull !");
        ans.sort((a,b)=>a-b);
        ans = ans.join('\n');
        return write(ans);
    })
    .then(()=>{
        console.log("write is successfull !");
    })