const express = require('express');
const path = require('path');
const { handlebars } = require('hbs');
const app = express();


app.use(express.urlencoded({extended:true}));
app.use(express.json());
app.use(express.static('public'));
app.set('view engine','hbs');

// Array to save todos
let todos = ['hello','world'];

//Handlebar helper function to print list
handlebars.registerHelper("list",function(options){
    var res = '<ul>';

    for(let i=0;i<todos.length;i++){
        res = res + `<form action="/del" method="POST"><input name="name" value="${todos[i]}" style="display: none;">`
        res = res + `<li> ${todos[i]}<button type="submit">del</button></li></form>`;
    }

    return res + '</ul>';
})



app.get('/',(req,res)=>{
    // res.send(todos);
    res.render('index');
})

// post request to add task in todos
app.post('/',(req,res)=>{

    todos.push(req.body.task);
    res.redirect('/');
})

app.post('/del',(req,res)=>{
    // delet the task requested
    console.log(req.body);
    const idx = todos.indexOf(req.body.name);
    todos.splice(idx,1);
    res.redirect('/');
})

app.listen(3000,()=>{
    console.log("server started at port 3000");
})