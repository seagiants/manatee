open UIUtils;
open Actions;
open Types;

type state = {
  cardName: string,
  cardText: string,
  cardKeyword: string,
};

type action =
  | SetCardName(string)
  | SetCardText(string)
  | SetCardKeyword;

let addGameHandler = (dispatch, state) =>
  if (state.cardName !== "") {
    dispatch(
      AddCard(
        {
          id: Random.int(9999),
          name: state.cardName,
          text: state.cardText,
          keyword: GEAR,
        }: card,
      ),
    );
  };

let component = ReasonReact.reducerComponent("CardAdder");

let make = (~dispatch, _children) => {
  ...component,
  initialState: () => {cardName: "", cardText: "", cardKeyword: ""},
  reducer: (action, state) => {
    switch (action) {
    | SetCardName(name) => ReasonReact.Update({...state, cardName: name})
    | SetCardText(text) => ReasonReact.Update({...state, cardText: text})
    | SetCardKeyword => ReasonReact.Update({...state, cardKeyword: "KEYWORD"})
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
        <input
          type_="text"
          placeholder="Give a text description"
          onChange={event =>
            self.send(SetCardText(ReactEvent.Form.target(event)##value))
          }
        />
        <button
          className="btn waves-effect waves-light pink"
          onClick={_event => addGameHandler(dispatch, self.state)}>
          {str("Add a card")}
          <i className="material-icons right"> {str("add")} </i>
        </button>
      </div>
    </div>,
};