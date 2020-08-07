
$(document).ready(()=>{

    function refreshTodos(){
        $('#list').empty();

        $.get('/todo',(info)=>{
            
            // Converting the string object back into map
            let data = new Map(JSON.parse(info));
            
            for(let [key,value] of data){
                console.log(key);
                $('#list').append(
                    $('<li>').text(key)
                )
            }
        });

    }
    
    refreshTodos();

    $('#btn').click(()=>{

        let task = $('#inp').val();
        console.log(task);
            $.get(`/addTodo?q=${task}`,(message)=>{
                console.log('req toh gyi')
                refreshTodos();
                alert(message);
            })
    })
})
