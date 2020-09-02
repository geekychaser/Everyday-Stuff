import React from  "react";

class App extends React.Component{
    constructor(){
        super();

        this.state = {
            count: 0,
        }

        {/*Binding all the methods with this */}

        this.increment = this.increment.bind(this);
        this.decrement = this.decrement.bind(this);
        this.reset = this.reset.bind(this);
    }

    increment(){
        this.setState(prevState =>{
            return {
                count: prevState.count + 1
            }
        })
    }

    decrement(){
        this.setState(prevState =>{
            if(prevState.count){
                return {
                    count: prevState.count - 1
                }
            }

            console.log("counter can not b negative");
        })
    }

    reset(){
        this.setState(() =>{
            return{
                count: 0
            }
        })
    }

    render(){
        return(
            <div>
                <h1>{this.state.count}</h1>
                <button onClick={this.increment}>increment +</button>
                <button onClick={this.decrement}>decrement-</button>
                <button onClick={this.reset}>reset</button>
            </div>
        )
    }
}

export default App;