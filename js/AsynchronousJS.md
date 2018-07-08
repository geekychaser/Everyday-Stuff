![JS logo](images/asyncJS/js.png)

Javascript code runs on a single thread and hence should be synchronous 
in nature. synchronous code waits for one action to complete before moving
 on to next task. But even after JS is considered as single threaded 
 we are able to perform tasks parallely **HOW?**  

```angular2html
var test = readSync(file_loc);
		console.log(test);
		var test2 = readSync(file_loc2);
		console.log(test2);
```
This task is done synchronously first file is fetched and test is logged then  
next file is fetched and logged. What if the file1 is huge file and lets say  
take **10sec** to be fetched then this become blocking i/o and decreases UX.  
 So to get rid of this situation we can do same task **asynchronously** 
 
 ```angular2html
readAsync(file_loc,(test)=>{
			console.log(test);	
			});

			readAsync(file_loc2,(test2)=>{
			console.log(test2);	
			});
```
In this case file1 and file2 both are fetched parallely and file which is 
fetched first is being logged first this becomes non-blocking code and takes
lesser time to execute.

<div class="row">
        <img class="responsive-img col s12" src="/images/asyncJS/async.jpeg">
    </div>



##What is Asynchronous JavaScript?
Asynchronous JS basically means, codes which starts now, and finishes 
at a later point in time and can perform any other task simultaneously 
in the time.
Fetching data from a json file using AJAX request:
```angular2html

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Ajax</title>
    <script src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
    <script>
        window.onload = function() {

            $.get("zap.json", function (data) {
                console.log(data);
            });

            console.log("later");
        };
    </script>
</head>
<body>

</body>
</html>
```
**output**


![alt etxt](images/asyncJS/Async.png "asynchronous js")

Here `later` is printed first while the data is being fetched from json file and 
as soon as the data is fetched then the callback function is fired and data
is being printed.


**AJAX** : Asynchronous JavaScript And XML  
 Communicate with server by making http request and retrieves data from server
 No without reloading the page which we can use in our code. XML refers to as
 the data which we try to fetch , we can also use JSON instead of XML.
 Consider google maps we are able to fetch different locations without
 refreshing the page,thats how AJAX is advantageous. 


###How AsyncJS works?
  
* Callback
* Promises
* Generators

####Callback function

A callback function, also known as a higher-order function, is a function 
that is passed to another function as a parameter, and the callback function is called 
inside the otherFunction. A callback function is essentially a pattern,
  and therefore, the use of a callback function is also known as a 
  callback pattern.  
  Callback implemented using jQuery
  ```angular2html
window.onload = function() {

    $.ajax({
        type:"GET",
        url:"zap.json",
        success:function(data){
            console.log(data);

            $.ajax({
                type:"GET",
                url:"test.json",
                success:function(data){
                    console.log(data);

                    $.ajax({
                        type:"GET",
                        url:"test2.json",
                        success:function(data){
                            console.log(data);
                        },
                        error:function (err) {
                            console.log(err);
                        }
                    })


                },
                error:function (err) {
                    console.log(err);
                }
            })


        },
        error:function (err) {
            console.log(err);
        }
    })
};
```
Here function inside a function is being called only if the previous
 function executes without any error this is called **callback functions**. 
See the pyramid shape and all the `})` at the end? Eek! This is 
 affectionately known as **callback hell**. :fearful:
 
 
 
**Output**

![callbackhell](images/asyncJS/callbackhell.png)

Callback hell can be resolved by **Modularizing** our code and handling
every single error.
Above code be rewritten by resolving callback hell as:
```angular2html
window.onload = function() {

    function checkerror(err) {
        console.log(err);
    }

    $.ajax({
        type:"GET",
        url:"zap.json",
        success:friends,
        error:checkerror
    });

    function friends(data) {
        console.log(data);

        $.ajax({
            type: "GET",
            url: "test.json",
            success: test,
            error: checkerror
        });

    }

        function test(data) {
            console.log(data);

            $.ajax({
                type: "GET",
                url: "test2.json",
                success: function (data) {
                    console.log(data);
                },
                error: checkerror
            })


        }
};
```
Here errors are handled as different function and every callback function is 
declared outside which keeps the code tidy and readable.
Output remains the same :relieved:

###Promises
Promise is an object which showes a particular task has been completed 
or not(i.e. state of a particular task).  
 A promise may be in one of 3 possible states:
 * Fulfilled: the operation completed successfully.
 * Rejected: the operation failed.
 * Pending: initial state, neither fulfilled nor rejected.  
 
 Promise users can attach callbacks to handle the fulfilled value or
  the reason for rejection.  
  Promise is better than simple call back as we can directly use return 
  statement and pass new promise directly, it makes code more readable
   and understandable and easy to execute.
   
   ![chart](images/asyncJS/promises.png)
  
  Let us consider an example to understand better that how it is better
  than normal callbacks.  
  ```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Promises</title>
    <script src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
    <script>
        window.onload = function(){

            $.get("zap.json").then(function (value) {
                console.log(value);
                return  $.get("test.json");
            }).then(function (value) {
                console.log(value);
                return  $.get("test2.json")
            }).then(function (value) {
                console.log(value);

            })
        }
    </script>
</head>
<body>

</body>
</html>
```
*output* remains the same  
![promises output](images/asyncJS/callbackhell.png)  
function in `.then` is called when the data is retrieved and we can return 
new promise, hence it makes our code readable and output remains the same.
 






[Zap](http://zapcircle.net) 
 



This is image as link click it to got zapcircle website.

[alt txt](https://youtu.be/GaT8uMDtEZo)
Don't know how to add vedio 

col1 | col2 | col3
-----:|:------|:-----:
xt1 | txt2 | txt3 
acb|



`<this is inline code>`jbfkjbkfbwejkbfkw
```
this is big block of code 
```





