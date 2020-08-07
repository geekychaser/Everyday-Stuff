const express = require('express');
const path = require('path');
const app = express();

let todos = new Map();
let task_counter = 0;

app.use('/',express.static(path.join(__dirname,'static')));

// route to add todos
app.get('/addTodo',(req,res)=>{

    let task = req.query.q;
    
    //Check if task is empty
    if(!task) 
        res.send("Task can not be empty !");
    
    //check if the task is already present
    else if(todos.has(task) == true) 
        res.send("task is alread present !");
    else{
        todos.set(task,task_counter);
        task_counter++;
        res.send("success");
    }
})

// route to get complete list of todos
app.get('/todo',(req,res)=>{

    //Spread operator to pass map and make it as obj string so that we can send it as a response as map can not be send
    res.send( JSON.stringify([...todos]));
})

app.listen(3000,()=>{
    console.log('server has started on port 3000 !')
})