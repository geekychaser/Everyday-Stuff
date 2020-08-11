const express = require('express');
const route = express.Router();

let students = [];

route.get('/',(req,res)=>{
    res.send(students);
})

route.post('/',(req,res)=>{
    students.push({
        name:req.body.name,
        roll:req.body.roll
    })
    res.send("success");
})

module.exports = {
    route
};