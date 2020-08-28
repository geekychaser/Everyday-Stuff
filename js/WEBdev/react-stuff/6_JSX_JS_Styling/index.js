import React from "react";
import ReactDOM from "react-dom";

// now using es6 

const App = ()=>{
    const date = new Date();
    const hours = date.getHours();
    let time;

    if(hours < 12){
        time = "morning";
    }
    else if(hours >= 12 && hours < 17){
        time = "afternoon"
    }
    else{
        time = "night"
    }

    return(
        // we need to use className instead of class in JSX
    <h2 className="test">Good {time} !</h2>
    )
}

ReactDOM.render(<App />,document.getElementById("root"));