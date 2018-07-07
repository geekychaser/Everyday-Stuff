window.onload = function() {

    $.get("zap.json", function (data) {
        console.log(data);
    });

    console.log("later");
};