// set interval and set timeout -> both are used for async js as JS is single threaded so these functions work on 
// browser and handled by browser so this way js can perform multitasks (asynchronously) being single threaded .

let x = setInterval(()=>{ // it runs in every one sec
    console.log('set interval is running in every 1 sec');
},1000);

// to clear the interval directly we can use clear interval but to clear interval in sometime we can use setimeout

setTimeout(()=>{
    clearInterval(x);
},3000);
