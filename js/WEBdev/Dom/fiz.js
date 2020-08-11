
let num = document.getElementById('amt');
let list = document.getElementById('list');

let amount = num.value;


function print(){
    for(let i=1;i<=amount;i++){
        let str = '';
        if(i%3 == 0) str += 'Fizz';
        if(i%5 == 0) str += 'Buzz';

        if(str == '') create_list(i);
        else create_list(str);
    }
}

function create_list(val){
    let x = document.createElement('li');
    x.innerText = val;
    list.appendChild(x);
}
