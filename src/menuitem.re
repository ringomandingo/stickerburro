let component = ReasonReact.statelessComponent("Menu Item");

open Actions;

let make = (~data:Types.category, ~send,  _children) => {
  ...component,
  render: _self =>
    <div id = data.name className = "menu-item" onClick=(_event => send(CATEGORY(data))) >
    (ReasonReact.string(data.name))
    </div>
};
