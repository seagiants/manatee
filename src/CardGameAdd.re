open UIUtils;
open Actions;

type state = {gameName: string};

type action =
  | SetGameName(string);

let addGameHandler = (dispatch, state) =>
  if (state.gameName !== "") {
    dispatch(AddGame(state.gameName));
  };

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
          onKeyUp={event =>
            if (ReactEvent.Keyboard.key(event) == "Enter") {
              addGameHandler(dispatch, self.state)
            }
          }
        />
        <button
          className="btn waves-effect waves-light pink"
          onClick={_event => addGameHandler(dispatch, self.state)}>
          {str("Add a game")}
          <i className="material-icons right"> {str("add")} </i>
        </button>
      </div>
    </div>,
};