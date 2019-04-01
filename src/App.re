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
  activeCardSetId: option(int),
  games: Types.cardGameMap,
};

let app = ReasonReact.reducerComponent("App");

let make = _children => {
  ...app,
  initialState: () => {
    view: HomeView,
    nextId: 1,
    activeGameId: 0,
    activeCardSetId: None,
    games:
      Types.IntMap.add(
        0,
        {
          id: 0,
          name: "Starting game",
          description: "Not to start empty is a good thing",
          cardSets:
            Some(
              Types.IntMap.add(
                0,
                {
                  id: 0,
                  name: "Basic set of cards",
                  description: "yolo",
                  cards:
                    Some(
                      Types.IntMap.add(
                        0,
                        {id: 0, name: "plouf", text: "nothing"}: Types.card,
                        Types.IntMap.empty,
                      ),
                    ),
                }: Types.cardSet,
                Types.IntMap.empty,
              ),
            ),
        }: Types.cardGame,
        Types.IntMap.empty,
      ),
  },
  // FIXME move the reducer to its own file ?
  reducer: (action, state) =>
    switch (action) {
    | GetHome => ReasonReact.Update({...state, view: HomeView})
    | ShowCardGame(id) =>
      ReasonReact.Update({
        ...state,
        view: CardGameView,
        activeGameId: int_of_string(id),
      })
    | ShowCardList(cardset_id) =>
      ReasonReact.Update({
        ...state,
        view: CardSetView,
        activeCardSetId: Some(int_of_string(cardset_id)),
      })
    | Void => ReasonReact.Update({...state, view: Nowhere})
    | AddGame(name) =>
      ReasonReact.Update({
        ...state,
        nextId: state.nextId + 1,
        games:
          Types.IntMap.add(
            state.nextId,
            {id: state.nextId, name, description: "--", cardSets: None}: Types.cardGame,
            state.games,
          ),
      })
    },
  didMount: self => {
    let _watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | [] => self.send(GetHome)
        | ["cardgame", id] => self.send(ShowCardGame(id))
        | ["cardgame", _id, "cardset", cardset_id] =>
          self.send(ShowCardList(cardset_id))
        | _ => self.send(Void)
        }
      );
    ();
  },
  render: self =>
    switch (self.state.view) {
    | HomeView => <HomeView dispatch={self.send} games={self.state.games} />

    | CardGameView =>
      <CardGameView
        game={Types.IntMap.find(self.state.activeGameId, self.state.games)}
      />

    | CardSetView => {
      let currentGame = Types.IntMap.find(self.state.activeGameId, self.state.games);
      let currentCardSet = Types.IntMap.find(
        Belt.Option.getExn(self.state.activeCardSetId), 
        Belt.Option.getExn(currentGame.cardSets));
      <CardSetView cardset={currentCardSet} />
      }

    | Nowhere => <div> {str("...nowhere")} </div>
    },
};