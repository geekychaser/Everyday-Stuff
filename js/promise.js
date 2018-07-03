window.onload = function(){

    $.get("zap.json").then(function (value) {
        console.log(value);
        return  $.get("test.json");
    }).then(function (value) {
        console.log(value);
        return  $.get("test2.json")
    }).then(function (value) {
        console.log(value);

    })



}