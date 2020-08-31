import React from "react"

function TodoItem(props) {
    console.log(props);
    let todo = props.tasks;
    return (
        <div className="todo-item" >
            {/* but this way we can change checbox status through click */}
            <input type="checkbox" checked={todo.completed} />
            <p>{todo.text}</p>
        </div>
    )
}

export default TodoItem