import React from "react";
import ReactDOM from "react-dom";

// now using es6 

const App = ()=>{
    const date = new Date();
    const hours = date.getHours();
    let time;
    let goodStyle = {
        
    }

    if(hours < 12){
        time = "morning";
        goodStyle.color = "blue";
    }
    else if(hours >= 12 && hours < 17){
        time = "afternoon";
        goodStyle.color = "orange";
    }
    else{
        time = "night";
        goodStyle.color = "grey"
    }

    let spanStyles = {
        backgroundColor:"black",
        color:"white",
    }

    return(
      <div>
      {/* we need to use className instead of class in JSX */}
      <h2 className="test">Good {time} !</h2>

      {/* iniline style are applied using objects and style with "-" are replaced by camelCase */}
      <p style={{color:"red",backgroundColor:"lightblue"}}>Just to test some inline styling</p>

      {/*Simply attaching style object as complete looks odd */}
      <span style={spanStyles}>This is another test text</span>

      {/* Now making good moring n all dyanmic color change*/}
    <h3 style={goodStyle}>Good {time} !</h3>
    </div>
    )
}

ReactDOM.render(<App />,document.getElementById("root"));