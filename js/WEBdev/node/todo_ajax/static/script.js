
$(document).ready(()=>{

    let data;

    function Swap(list, iA, iB){
        [list[iA], list[iB]] = [list[iB], list[iA]];
        return list;
      }
    function refreshTodos(){
        $('#list').empty();

        $.get('/todo',(info)=>{
            
            // Converting the string object back into map
            data = JSON.parse(info);
            
            for(let key of data){
                // console.log(key);
                $('#list').append(
                    $('<li>').text(key).append([
                        $('<i>',{"class": "arrow up"}).click((ev)=>{
                            $(ev.target).parent().insertBefore($(ev.target).parent().prev())

                            //Finding the index of elment which is to be swapped
                            let iA = data.indexOf($(ev.target).parent().text());
                            data = Swap(data,iA,iA-1);

                            //Post request to update the data array on server
                            $.post('/update',{data :data},(message)=>{
                                console.log(message);
                            })

                        }),
                        $('<i>',{"class": "arrow down"}).click((ev)=>{
                            $(ev.target).parent().insertAfter($(ev.target).parent().next())

                            //Finding the index of elment which is to be swapped
                            let iA = data.indexOf($(ev.target).parent().text());
                            data = Swap(data,iA,iA+1);

                            //Post request to update the data array on server
                            $.post('/update',{data :data},(message)=>{
                                console.log(message);
                            })
                        }),

                        $('<i>',{"class": "fas fa-trash"}).click((ev)=>{
                            let iA = data.indexOf($(ev.target).parent().text());

                            // Removing that element from list
                            $(ev.target).parent().remove();

                            // Romving that element from data array
                            data.splice(iA,1);

                            //Post request to update the data array on server
                            $.post('/update',{data :data},(message)=>{
                                console.log(message);
                            })

                        })
                    ])
                )
            }
        });

    }
    
    refreshTodos();

    $('#btn').click(()=>{

        let task = $('#inp').val();
        // console.log(task);
            $.get(`/addTodo?q=${task}`,(message)=>{
                refreshTodos();
                alert(message);
            })
    })
})
