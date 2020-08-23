// building own bind function, lets name it as mybind

let Myname = {
    firstName : 'Rishabh Kumar',
    lastName : 'Bothra',
};

function printMyName(city){
    console.log(`${this.firstName} ${this.lastName} , ${city}`);
}

let later_print = printMyName.bind(Myname);

later_print("Delhi");

// here goes my bind implementation

Function.prototype.MyBind = function(...args){
    let params = args.slice(1);
    let obj = this;
    return function(...args2){
        obj.apply(args[0],[...params,...args2]);
    }
}

let my_later_print = printMyName.MyBind(Myname);

my_later_print("Delhi")