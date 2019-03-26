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
  nextId: int,
  activeGameId: int,
  games: list(Types.cardGame),
  test_: Types.cardGameMap // TODO temporary, will replace the "games" field
};

let appName = "Manatee";

let app = ReasonReact.reducerComponent("App");

let make = _children => {
  ...app,
  initialState: () => {
    view: HomeView,
    nextId: 1,
    activeGameId: 0,
    games: [
      {
        id: 0,
        name: "test game",
        description: "super card game",
        cardSets: None,
      },
    ],
    test_:
      Types.IntMap.add(
        0,
        {id: 0, name: "With IntMap", description: "--", cardSets: None}: Types.cardGame,
        Types.IntMap.empty,
      ) // TODO temporary, will replace the "games" field
  },
  // FIXME move the reducer to its own file ?
  reducer: (action, state) =>
    switch (action) {
    | GetHome =>
      Types.IntMap.iter((k, _v) => Js.log(k), state.test_); // FIXME delete when test is finished
      ReasonReact.Update({...state, view: HomeView});
    | ShowCardGame(id) =>
      ReasonReact.Update({
        ...state,
        view: CardGameView,
        activeGameId: int_of_string(id),
      })
    | ShowCardList(_name) =>
      ReasonReact.Update({...state, view: CardSetView})
    | Void => ReasonReact.Update({...state, view: Nowhere})
    | AddGame(name) =>
      ReasonReact.Update({
        ...state,
        nextId: state.nextId + 1,
        games:
          List.concat([
            state.games,
            [{id: state.nextId, name, description: "--", cardSets: None}],
          ]),
        test_:
          Types.IntMap.add(
            state.nextId,
            {id: state.nextId, name, description: "--", cardSets: None}: Types.cardGame,
            state.test_,
          ),
      })
    },
  didMount: self => {
    let _watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | [] => self.send(GetHome)
        | ["cardgame", id] => self.send(ShowCardGame(id))
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
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (x: Types.binding) => { 
                 let (k, cg) = x;
                 <div key={string_of_int(cg.id)}> {str(cg.name)} </div> 
                 },
               Types.IntMap.bindings(self.state.test_),
             ),
           ),
         )}
      </div>

    | CardGameView =>
      <CardGameView
        game={List.nth(self.state.games, self.state.activeGameId)}
      />

    | CardSetView => <div> {str("card list")} </div>

    | Nowhere => <div> {str("...nowhere")} </div>
    },
};