import React from "react"

function TodoItem(props) {
    function handleChange(){
        props.handleChange(props.item.id);
    }
    return (
        <div className="todo-item">
            <input 
                type="checkbox" 
                checked={props.item.completed} 
                onChange={handleChange}
            />
            <p>{props.item.text}</p>
        </div>
    )
}

export default TodoItem