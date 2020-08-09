const express = require('express');
const app = express();

// pot ki body ko parse krne k liye
app.use(express.urlencoded({extended: true})); // extended true matlb saare char utf-8 vgera

// Json parse krne k liye
app.use(express.json())

// Global middleware
function m1(req,res,next){  
    console.log(req.url) // url mil jaata hai 
    console.log("m1 runs")

    next() // agar next ka use nhi karenge toh agla middleware pe nhi jayega site nhi khulegi 
}

function m2(req,res,next){
    console.log("bye pe m2 chla");
    console.log(req.url); // isme bas /bye k aage vaali cheez ayegi
    next();
}

function m3(req,res,next){
    console.log("m3 runs");
    next();
}

app.use(m1); //  yahi toh ek normal function ko middleware banata hai and global hai 
app.use('/bye',m2); // yeh vlaa global nhi hai bas '/bye pe chalega 
app.use(m3);

// ye bhi ek tareeke ka middleware hota hai jisme path define kra hua hota hai 
// chahe toh isme mai next use karlo
app.get('/',(req,res)=>{
    res.send("<h1>Hello World !</h1>")
})

// post request
app.post('/',(req,res)=>{
    console.log(req.body);
    res.send("post request success");
})

// Starting the server
app.listen(3000,()=>{
    console.log("server started on port 3000")
})
