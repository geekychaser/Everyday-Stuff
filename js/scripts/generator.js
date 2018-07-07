window.onload = function () {

   generator(function*(){
        var zap = yield $.get("zap.json");
        console.log(zap);

        console.log("done");


    });

    function generator(temp) {

        var gen = temp();

        function checkandprint(output){
            if(!output.done) {
                output.value.then(function (data) {
                    return checkandprint(gen.next(data));
                });

            }


            }

            return checkandprint(gen.next());


    }



};