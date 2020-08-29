import React from "react";

function DisplayCard(props){
    return(
        <div>
            <img src={props.contact.imgUrl} />
            <h3>{props.contact.name}</h3>
            <p>Phone No. {props.contact.phone}</p>
            <p>Email id. {props.contact.email}</p>
        </div>
    )
}

export default DisplayCard;