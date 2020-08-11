const express = require('express');
const app = express();
const student = require('./routes/student').route;
const teacher = require('./routes/teacher').route;



app.use(express.urlencoded({extended:true}));
app.use(express.json());

app.use('/student',student);
app.use('/teacher',teacher);

app.listen(3000,()=>{
    console.log("server has started at port:3000");
})
