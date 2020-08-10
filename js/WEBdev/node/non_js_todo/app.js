const express = require('express');
const app = express();


app.use(express.urlencoded({extended:true}));
app.use(express.json());

let todos = [];

app.get('/',(req,res)=>{
    res.send(todos);
})

app.post('/',(req,res)=>{
    // console.log(req.body);
    todos.push(req.body.task);
    res.send(todos);
})

app.put('/',(req,res)=>{
    // logic for swapping the elements
})

app.listen(3000,()=>{
    console.log("server started at port 3000");
})