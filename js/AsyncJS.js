window.onload = function() {

    $.get("test.json", function (data) {
        console.log(data);
    });

    console.log("later");
};