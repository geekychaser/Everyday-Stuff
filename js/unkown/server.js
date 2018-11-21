var express = require('express');
var bodyParser = require('body-parser');
var mongoClient = require('mongodb').MongoClient;
var mongoose = require('mongoose');
var session = require('express-session');
var expressValidator = require('express-validator');
var app = express();
var User = require('./models/user');
var bcrypt = require('bcryptjs');
const port = process.env.PORT || 8000;

app.set('view engine','ejs');
//app.set('views', path.join(__dirname, 'views'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.use(expressValidator());

var dburl = "mongodb://localhost:27017/budhi";
mongoose.Promise = global.Promise;
mongoose.connect(dburl);

// app.use(session({
//     secret: "budhi bhai",
//     resave: true,
//     saveUninitialized: false
// }));

// const uri = "mongodb+srv://Budhiraja:9811809871@cluster0-apyn6.mongodb.net/test?retryWrites=true"

// mongoClient.connect(uri,{ useNewUrlParser: true },(err,client)=>{
//     if(err){
//         console.log(err);
//     }
//     console.log("connected..");
//     const collection = client.db("test").collection("devices");
//     client.close();
// })

app.get('/',(req,res)=>{
    //res.send("started again");
    res.render('home');
})

app.get('/signup',(req,res)=>{
    res.render('signup');
})

app.post('/signup',(req,res)=>{
    // console.log(req.body);
    // console.log(req.body.email);
    // console.log(req.body.password);
    // req.checkBody('name', 'Name is required').notEmpty();
    // req.checkBody('email', 'Email is required').notEmpty();
    // req.checkBody('email', 'Please enter a valid email').isEmail();
    // req.checkBody('password','Please enter password').notEmpty();


    var myData = new User(req.body);
    console.log("this is fucking password " + myData.password);
    myData.password =  bcrypt.hashSync(myData.password,8);
    console.log("this is fucking hash " + myData.password);
    myData.save().then(()=>{
        res.redirect('/');
    })
    .catch((err)=>{
        console.log(err);
        res.send("operation failed try again");
    });

    
    
    
})

app.get('/login',(req,res)=>{
    res.render('login');
})

app.post('/login',(req,res)=>{
    console.log(req.body);
    res.redirect('/');
})

app.listen(port,()=>{
    console.log("server started and listening to port " + port);
})

//mongodb+srv://Budhiraja:<PASSWORD>@cluster0-apyn6.mongodb.net/test?retryWrites=true