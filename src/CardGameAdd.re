open UIUtils;
open Actions;

let addToStorage = (name :string) => {
    Dom.Storage.setItem(name, "yo")
}

type state = {
    gameName: string
}

type action = Add


let component = ReasonReact.reducerComponent("CardGameAdd");

let make = (~dispatch, _children) => {
  ...component,
  initialState: () => {gameName: ""},
  reducer: (action, _state) => {
      switch action {
      | Add => {
          ReasonReact.Update({gameName: "yo"})
          }
      };
  },
  render: _self =>
    <div className="row">
      <h2> {str("Add a game")} </h2>
      <div className="row">
        <button className="btn waves-effect waves-light pink" onClick=(_event => dispatch(AddGame("testagame")))>{str("Add yo")}</button>
      </div>
    </div>,
};