import React from "react";

class App extends React.Component{
    constructor(){
        super();
    }

    render(){
        function handleClick(){
            console.log("i was clicked!")
        }
        function HoveredMe(){
            console.log("I am hovered")
        }

        function ONKeyPress(){
            console.log("A key was pressed!")
        }

        return (
            <div>
                <img onMouseOver={HoveredMe} onKeyPress={ONKeyPress} src="https://www.fillmurray.com/200/100"/>
                <br />
                <br />
                <button onClick={handleClick}>Click me</button>
            </div>
        )
       
    }
}
export default App;