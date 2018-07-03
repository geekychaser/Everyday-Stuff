window.onload = function() {

    $.ajax({
        type:"GET",
        url:"zap.json",
        success:function(data){
            console.log(data);

            $.ajax({
                type:"GET",
                url:"test.json",
                success:function(data){
                    console.log(data);

                    $.ajax({
                        type:"GET",
                        url:"test2.json",
                        success:function(data){
                            console.log(data);
                        },
                        error:function (err) {
                            console.log(err);
                        }
                    })


                },
                error:function (err) {
                    console.log(err);
                }
            })


        },
        error:function (err) {
            console.log(err);
        }
    })
};