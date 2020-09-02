import React from "react"

// Given a stateless functional component, add state to it
// state should have a property called `isLoggedIn` which is a boolean
// (true if logged in, false if not)
// Then, give your best shot at rendering the word "in" if the user is logged in
// or "out" if the user is logged out.


// converting to class based component
class App extends React.Component{

    constructor(){
        super();
        this.state = {
            isLoggin: true,
        }
    }

    render(){
        let text = "";
        if(this.state.isLoggin){
            text = "In";
        }
        else{
            text = "Out";
        }

        return(
            <div>
                <h1>You are currently logged {text}</h1>
            </div>
        )
    }
} 
// function App() {
//     constructor(){

//     }
//     return (
//         <div>
//             <h1>You are currently logged (in/out)</h1>
//         </div>
//     )
// }

export default App
