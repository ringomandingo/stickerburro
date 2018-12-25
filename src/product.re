type action =
| ADDTOCART(string)

let component = ReasonReact.statelessComponent("Product");

let make = (~data, ~send, _children) => {
  ...component,
  render: _self =>
    <div  className = "product">

    <div className = "product-image"></div>
    <div className = "product-description">

    </div>
    <div className = "buttons">
       <button id = "add_to_cart" onClick=(_event => send(ADDTOCART(data)))> (ReasonReact.string("Add To Cart")) </button>
    </div>
 
    </div>
};
