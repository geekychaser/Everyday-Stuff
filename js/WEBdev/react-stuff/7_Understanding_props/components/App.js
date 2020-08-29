import React from "react";

import DisplayCard from "./DisplayCard";

function App(){
    return(
        <DisplayCard
            contact = {{name:"Rishabh Kumar Bothra" ,
                imgUrl: "https://btichly.herokuapp.com/H4sEakO",
                phone: "9999999999",
                email: "rbothra77@gmail.com"
            }}
        />
    )
}

export default App;