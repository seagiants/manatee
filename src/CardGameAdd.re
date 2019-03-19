open UIUtils;
open Actions;

type state = {gameName: string};

type action =
  | SetGameName(string);

let component = ReasonReact.reducerComponent("CardGameAdd");

let make = (~dispatch, _children) => {
  ...component,
  initialState: () => {gameName: ""},
  reducer: (action, _state) => {
    switch (action) {
    | SetGameName(name) => ReasonReact.Update({gameName: name})
    };
  },
  render: self =>
    <div className="row">
      <h2> {str("Add a game")} </h2>
      <div className="row">
        <input
          type_="text"
          placeholder="Name your game"
          onChange={event =>
            self.send(SetGameName(ReactEvent.Form.target(event)##value))
          }
        />
        <button
          className="btn waves-effect waves-light pink"
          onClick={_event => dispatch(AddGame(self.state.gameName))}>
          {str("Add a game (yo)")}
          <i className="material-icons right"> {str("add")} </i>
        </button>
      </div>
    </div>,
};