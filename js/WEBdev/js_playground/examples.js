
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


//filter function is used to filter out some element for original array according to our need as its name suggests
// it only accepts true and false , adds the elemt if recieves true and leave the element is recieves false

let filter_arr = arr.filter((item) => {
    return item%2 == 0;
});

console.log(filter_arr);


// Array function find and findIndex both are used to find no. and its index based on some conditions (similar as linear search based on some conditon)

// find first even number in the arr list
let find_num = arr.find((item) => {
    return item%2 == 0;
});

// find index of first even number in arr list
let find_idx = arr.findIndex((item) =>{
    return item%2 == 0;
})

console.log(find_num);
console.log(find_idx);
