open UIUtils;

type state = {
    cardName: string
}

type action = 
    | AddCard(string)


let component = ReasonReact.reducerComponent("CardAdder");

let make = (~dispatch, _children) => {
    ...component,
    initialState : () => {cardName: ""},
    reducer: (action, _state) => {
        switch action {
        | AddCard(name) => ReasonReact.Update({cardName : name})
        };
    },
    render: _self => <div>{str("adder")}</div>
}