const moment = require("moment");

let m = moment();


// to get local time
console.log("local time = ",m.toString());

// ISO time
console.log("ISO time = ",m.toISOString());

// using a format
console.log(moment("30/07/1998","DD/MM/YYYY").toString());

//to get what was iso time during my birth xD
console.log(moment("30/07/1998","DD/MM/YYYY").toISOString())

//UTC method
m = moment.utc();

console.log("UTC time = ",m.toString());

console.log("================Getting & Setting units===============================================");

// getting units to get current min,hr or sec
m = moment();

console.log("current hours = ",m.hour());
console.log("current min = ",m.minute());
console.log("current sec = ",m.second());

// setting hr,min, sec, week or day and get changed date
m.minute("24");
m.hour("9");
m.day(3);

// can also be done like this
m.set("day",4)

console.log("getting some new randome date according to our constraints = ",m.toString());

// moment.min, moment.max is used to get min and max date out of two

console.log("======================================Manipulating dates and time===========================");

m = moment();

console.log("current time = ",m.toString());

m.add({
    "hours": 3,
    "minutes": 5
})

console.log("changed time = ",m.toString());

console.log("UTCoffset = ",m.utcOffset())

