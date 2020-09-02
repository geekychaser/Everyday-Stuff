/*
In the previous iteration of this todo list app, we pulled in todos data from a JSON file and mapped over it to display the todo items.

Eventually we'll want to be able to modify the data, which will only happen if we've "loaded" the data in to the component's state

Challenge: Change the <App /> component into a stateful class component and load the imported `todosData` into state.
*/

import React from "react";

import TodoItem from "./TodoItem";
import todosData from "./todosData";

class App extends React.Component {
    constructor(){
        super();
        this.state = {
            todos: todosData
        };
    }

    render(){

        let tasks = this.state.todos.map((item)=>{
            return <TodoItem key= {item.id} task={item} />
        })
        return(
            <div>
                {tasks}
            </div>
        )
    }
}



export default App;