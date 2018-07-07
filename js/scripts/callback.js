window.onload = function() {

    function checkerror(err) {
        console.log(err);
    }

    $.ajax({
        type:"GET",
        url:"zap.json",
        success:friends,
        error:checkerror
    });

    function friends(data) {
        console.log(data);

        $.ajax({
            type: "GET",
            url: "test.json",
            success: test,
            error: checkerror
        });

    }

        function test(data) {
            console.log(data);

            $.ajax({
                type: "GET",
                url: "test2.json",
                success: function (data) {
                    console.log(data);
                },
                error: checkerror
            })


        }




};