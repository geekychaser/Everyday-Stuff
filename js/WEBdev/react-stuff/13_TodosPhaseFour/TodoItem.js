import React from "react"

function TodoItem(props) {
    console.log(props);
    let todo = props.task;
    return (
        <div className="todo-item" >
            {/* but this way we can change checbox status through click */}
            <input type="checkbox" checked={todo.completed} onChange={()=>console.log("tick changed!")} />
            <p>{todo.text}</p>
        </div>
    )
}

export default TodoItem