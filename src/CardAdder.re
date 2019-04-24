open UIUtils;

type state = {cardName: string};

type action =
  | SetCardName(string);

let component = ReasonReact.reducerComponent("CardAdder");

let make = (~dispatch, _children) => {
  ...component,
  initialState: () => {cardName: ""},
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
          placeholder="Name your game"
          onChange={event =>
            self.send(SetCardName(ReactEvent.Form.target(event)##value))
          }
        />
        <p>{str(self.state.cardName)}</p>
      </div>
    </div>,
};