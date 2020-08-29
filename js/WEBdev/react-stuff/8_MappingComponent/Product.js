import React from "react";

function Product(props){
    console.log(props)
    let product = props.ProductDetails;
    let detail = false;
    return(
        <div>
            {/*only show price when it is not zero and make the product heading orange */}
            <h2 style={{color: !product.price && "orange"}}>{product.name}</h2>
            {product.price!=0 &&
                <h3>Price:{product.price}</h3>
            }

            {/* button error to be resolved */}
            {/* <button onClick={{detail = !detail}}>Details</button> */}
            
            <small style={{display: detail ? "block" : "none"}}>Description: {product.description}</small>
            <hr/>
        </div>
    )
}


export default Product