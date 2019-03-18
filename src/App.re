open UIUtils;
open Actions;

/* Defining routes */
type route =
  | Home
  | CardList
  | CardGame
  | Nowhere;

type state = {
  route,
  gameName: string,
  games: list(string),
};

let appName = "Manatee"

let app = ReasonReact.reducerComponent("App");

let make = _children => {
  ...app,
  initialState: () => {route: Home, gameName: "", games: ["test", "bidule"]},
  reducer: (action, state) =>
    switch (action) {
    | GetHome => ReasonReact.Update({...state, route: Home})
    | ShowCardGame(name) =>
      ReasonReact.Update({...state, route: CardGame, gameName: name})
    | ShowCardList(_name) => ReasonReact.Update({...state, route: CardList})
    | Void => ReasonReact.Update({...state, route: Nowhere})
    | AddGame(name) => { 
        Js.log(state)
        ReasonReact.Update({...state, gameName: name})
        }
    },
  didMount: self => {
    let _watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | [] => self.send(GetHome)
        | ["cardgame", name] => self.send(ShowCardGame(name))
        | ["cardgame", name, "cardlist"] => self.send(ShowCardList(name))
        | _ => self.send(Void)
        }
      );
    ();
  },
  render: self =>
    switch (self.state.route) {
    | Home =>
      <div>
        <h1 className="center-align">
          <span className="blue-grey-text text-lighten-2">
            {str(appName)}
          </span>
        </h1>
        <CardGameAdd dispatch=self.send/>
        <GamesList games={self.state.games} />
      </div>

    | CardGame => <CardGameView name={self.state.gameName} />

    | CardList => <div> {str("card list")} </div>

    | Nowhere => <div> {str("...nowhere")} </div>
    },
};