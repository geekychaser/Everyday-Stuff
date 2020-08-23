// Here we are going to talk about what the heck is event loop

/* JS runtime is single threaded still works asynchronuosly and non-blocing nature because of 
    these 3 main components

    1. Call stack
    2. Web Apis
    3. callback queue

    * Web Apis handles 
        1. setTimeout() features
        2. Ajax calls i.e XHr requests
        3. DOM things
    
    so these stuffs are pushed to web Apis rather than call stack this is how async works

    Now when these thing get completed they are pushed to callback queue and here comes the use of event loop
    event loop pushes the queue elements one by one after the call stack is empty and this process continues
    */

    // Some brain fuck example

    console.log("yha pe start!");

    setTimeout(() => {
        console.log("inside setTimeout!"); // ye sabse last mai print hoga kyuki ye phele web Api mai jaega , 0 sec hai esley
    }, 0);                                // hatho hath execute hokar callback queue mai chla jayega or jab stack se sab print hoke
                                        //  Khali ho jayega uske baad ye stack mai jayega 

    console.log("here i finish!")

    // ek or khatarnak example

    const arr = [1,2,3,4];

    arr.forEach(i =>{
        console.log(i);     // ye stack ko block kr deta hai and jab ye chalega render bhi rukk jayega cheeze UI pe kaam ni karengi
    });

    console.log("after sync for each!") // this will print after loop

    function asyncforEach(array){
        array.forEach((i)=>{
            setTimeout(()=>{
                console.log(i);
            },0);
        })
    }

    asyncforEach([1,2,3,4]);

    console.log("after async for each!") // this will print before the loop and setTimeout