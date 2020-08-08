const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const app = express();

let todos = [];
// let task_counter = 0;

app.use('/',express.static(path.join(__dirname,'static')));
// app.use(bodyParser.json()); 
app.use(bodyParser.urlencoded({ extended: true }));

// route to add todos
app.get('/addTodo',(req,res)=>{

    let task = req.query.q;
    
    //Check if task is empty
    if(!task) 
        res.send("Task can not be empty !");
    
    //check if the task is already present
    else if(todos.includes(task) == true) 
        res.send("task is alread present !");
    else{
        todos.push(task);
        // task_counter++;
        res.send("success");
    }
})

// route to get complete list of todos
app.get('/todo',(req,res)=>{

    //Spread operator to pass map and make it as obj string so that we can send it as a response as map can not be send
    res.send( JSON.stringify([...todos]));
})

// route to update the todos value
app.post('/update',(req,res)=>{
    res.send("success update");
    todos = req.body.data;
})

app.listen(3000,()=>{
    console.log('server has started on port 3000 !')
})