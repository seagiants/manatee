open UIUtils;
open Actions;
open Types;

type state = {cardName: string};

type action =
  | SetCardName(string);

let addGameHandler = (dispatch, state) =>
  if (state.cardName !== "") {
    dispatch(AddCard({id: Random.int(9999), name: "The new card", text: "New and shiny", keyword: GEAR}: card));
  };

let component = ReasonReact.reducerComponent("CardAdder");

let make = (~dispatch, _children) => {
  ...component,
  initialState: () => {cardName: " "},
  reducer: (action, _state) => {
    switch (action) {
    | SetCardName(name) => ReasonReact.Update({cardName: name})
    };
  },
  render: self =>
    <div className="row">
      <h2> {str("Add a card")} </h2>
      <div className="row">
        <input
          type_="text"
          placeholder="Name your card"
          onChange={event =>
            self.send(SetCardName(ReactEvent.Form.target(event)##value))
          }
        />
        <button
          className="btn waves-effect waves-light pink"
          onClick={_event => addGameHandler(dispatch, self.state)}>
          {str("Add a card")}
          <i className="material-icons right"> {str("add")} </i>
        </button>
        <p> {str(self.state.cardName)} </p>
      </div>
    </div>,
};