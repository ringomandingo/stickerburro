open Type;
open Action;

open Belt;

[@bs.val] external unsafeJsonParse: string => 'a = "JSON.parse";

let localStorageNamespace = "stickerburro";

let saveLocally = cart =>
  switch (Js.Json.stringifyAny(cart)) {
  | None => ()
  | Some(cart) =>
    Dom.Storage.(
      localStorage |> setItem(localStorageNamespace, cart)
    )
  };

type state =  {
status: string,
account: option(account),
categories: categories,
products: products,
current_category: option(category),
current_product: option(product),
cart: cart,
currency: option(string),
token: option(string),
page: string
};



let reducer = (action, state) =>
switch(action){
   | ADDTOCART(product, option) => let newcart = None;
                        ReasonReact.Update({ ...state, page: "cart", cart: newcart})
   | PAGE(page) => ReasonReact.Update({ ...state, page: page })
   | SAVE() => saveLocally(state.cart);
                ReasonReact.Update({ ...state, page: page })
   | PRODUCT(product) => let product_with_options = product;
   ReasonReact.Update({ ...state, page: "product", current_product: Some(product) })
   | CATEGORY(category) =>  let products = Data.demo_products;
                            ReasonReact.Update({ ...state, page: "gallery", current_category: Some(category), products: products })
   }

let component = ReasonReact.reducerComponent("Main");

let make = (~status, ~categories:Type.categories, ~cart: Type.cart, _children) => {
  ...component,
  initialState: () => { status: status, account: None, categories: categories, products: None, current_category: None, current_product: None, cart: cart, token: None, page: "index", currency: Some("USD") },
  reducer,
  render: self =>
    <div className="app">
    <Categorybar categories = self.state.categories send = self.send />
<div id="page" className="page content">
    (
    switch (self.state.page) {
      | "gallery" => <Category category = self.state.current_category data = self.state.products send = self.send />
      | "product" => <Product data = self.state.current_product  send = self.send />
      | "cart" => <Cart data = self.state.cart  send = self.send />
      | "featured" => <Featured />
      | "index" => <Frontpage />
      | "careers" => <Careers />
      | "contact" => <Contact />
      | "checkout" => <Checkout cart = self.state.cart send = self.send  />
      | "support" => <Support />
      | "press" => <Press />
      | "about" => <About />
      | "shipping" => <Shipping />
      | "orders" => <Orders />
      | "order" => <Order />
      | "register" => <Register />
      | "login" => <Login />
      | _ => <Frontpage />
      }
    )
</div>
    <Footer send = self.send />
    </div>
    }