
// using map for acessing the arr element dircetly i.e shortcut for for loop

let arr = [1,2,3,4,5,6];

let new_arr = arr.map((item) => {
    return item*2;
})

console.log(new_arr);


// we can also access position of particular element in the arr using map 

let pos_arr = arr.map((item,pos) =>{
    console.log(`pos is ${pos}`);
    return pos;
});

console.log(pos_arr,'\n');


// Array method reduce is same as map but the only difference is accumulator in reduce which is passed as callback in function body

let result = arr.reduce((acc,item) =>{
    console.log(item);
    return acc + item;
},0)

console.log(result);
