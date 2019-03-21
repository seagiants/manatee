open UIUtils;
open Actions;

/* Defining routes */
type view =
  | HomeView
  | CardSetView
  | CardGameView
  | Nowhere;

type state = {
  view,
  gameName: string,
  games: list(Types.cardGame),
};

let appName = "Manatee";

let app = ReasonReact.reducerComponent("App");

let make = _children => {
  ...app,
  initialState: () => {
    view: HomeView,
    gameName: "",
    games: [{name: "test game", description: "super card game", cardSets: None}],
  },
  // FIXME move the reducer to its own file ?
  reducer: (action, state) =>
    switch (action) {
    | GetHome => ReasonReact.Update({...state, view: HomeView})
    | ShowCardGame(name) =>
      ReasonReact.Update({...state, view: CardGameView, gameName: name})
    | ShowCardList(_name) =>
      ReasonReact.Update({...state, view: CardSetView})
    | Void => ReasonReact.Update({...state, view: Nowhere})
    | AddGame(name) =>
      ReasonReact.Update({
        ...state,
        gameName: name,
        games: List.concat([state.games, [{name, description:"yahoo", cardSets: None}]]),
      })
    },
  didMount: self => {
    let _watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | [] => self.send(GetHome)
        | ["cardgame", name] => self.send(ShowCardGame(name))
        | ["cardgame", name, "cardset"] => self.send(ShowCardList(name))
        | _ => self.send(Void)
        }
      );
    ();
  },
  render: self =>
    switch (self.state.view) {
    | HomeView =>
      <div>
        <h1 className="center-align">
          <span className="blue-grey-text text-lighten-2">
            {str(appName)}
          </span>
        </h1>
        <CardGameAdd dispatch={self.send} />
        <GamesList games={self.state.games} />
      </div>

    | CardGameView => <CardGameView name={self.state.gameName} />

    | CardSetView => <div> {str("card list")} </div>

    | Nowhere => <div> {str("...nowhere")} </div>
    },
};