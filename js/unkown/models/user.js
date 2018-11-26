var mongoose = require('mongoose');
var bcrypt = require('bcryptjs');
var Schema = mongoose.Schema;

var userSchema = new Schema({
    name: {
        type: String,
        required: true,
        unique: true,
    },
    age:{
        type: Number,
        required: true,
    },
    adhaar: {
        type: Number,
        minlength:12,
        maxlength:12,
        required: true,
    },
    marital:{
        type: String,
        required: true,
    },
    email: {
        type: String,
        required: true,
        unique: true,
    },
    password: {
        type: String,
        minlength:5,
        required: true,
    }
});

userSchema.statics.authenticate = function (email, password, callback) {
    User.findOne({ email: email })
      .exec(function (err, user) {
        if (err || !user) {
          var err = new Error('User not found.');
          err.status = 401;
          return callback(err);
        }
        bcrypt.compare(password, user.password, function (err, result) {
          if (result === true) {
            return callback(null, user);
          } else {
            return callback();
          }
        })
      });
  }


userSchema.pre('save',function(next){
    // console.log(this);
    var user = this;
    console.log(user);
    // this.password = bcrypt.hashSync(this.password,8);
    bcrypt.genSalt(10, (err,salt)=>{
        bcrypt.hash(user.password, salt, (err,hash)=>{
            if(err) console.log("this is fucking error" + err);
            console.log("this is fucking password " + user.password);
            console.log("this is fucking hash "+ hash);
            user.password = hash;

            console.log("\n this is fucking new password " + user.password);
            next();
        });
});
})

module.exports = mongoose.model("User",userSchema);