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
mongoose.connect(dburl,{ useNewUrlParser: true });

app.use(session({
    secret: "budhi bhai",
    resave: true,
    saveUninitialized: false
}));

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
    User.findById(req.session.userId)
    .exec(function (error, user) {
      if (error) {
        return next(error);
      } else {
        if (user === null) {
         return res.redirect('/signup');
        } else {
          return res.send('<h1>Name: </h1>' + user.name + '<h2>Mail: </h2>' + user.email + '<br><a type="button" href="/logout">Logout</a>')
        }
      }
    });
});

app.get('/signup',(req,res)=>{
    res.render('signup');
})

app.post('/signup',(req,res,next)=>{

   
    var myData ={
        name:req.body.name,
        age:req.body.age,
        adhaar:req.body.adhaar,
        marital:req.body.marital,
        email:req.body.email,
        password:req.body.password,
    }

    User.create(myData,function(err,user){
        if(err){
            return next(err);
        }
        else{
            req.session.userId = user._id;
            res.redirect('/');
        }
    })

    // myData.save().then(()=>{
    //     res.redirect('/');
    // })
    // .catch((err)=>{
    //     console.log(err);
    //     res.send("operation failed try again");
    // });

    
    
    
});


app.post('/login',(req,res,next)=>{
    if(req.body.email&&req.body.password){
        User.authenticate(req.body.email,req.body.password,function(err,user){
            if(err || !user){
                var err = new Error('wrong email or password');
                err.status = 401;
                return next(err);
            } else{
                req.session.userId = user._id;
                return res.redirect('/');
            }
        })
    }
})

app.get('/login',(req,res)=>{
    res.render('login');
})

app.get('/logout',(req,res,next)=>{
    if(req.session){
        req.session.destroy(function(err){
            if(err){
                return next(err);
            }else {
                res.redirect('/login');
            }
        })
    }
})

app.post('/login',(req,res)=>{
    console.log(req.body);
    res.redirect('/');
})

app.listen(port,()=>{
    console.log("server started and listening to port " + port);
})

//mongodb+srv://Budhiraja:<PASSWORD>@cluster0-apyn6.mongodb.net/test?retryWrites=true