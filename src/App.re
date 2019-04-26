open UIUtils;
open Actions;
open State;

let app = ReasonReact.reducerComponent("App");

let make = _children => {
  ...app,
  initialState: Init.simpleInitialState,
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
    | AddCard(card) =>
      // FIXME put that in a state handling module
      let activeGame = Types.IntMap.find(state.activeGameId, state.games);
      let activeCardSet =
        Types.IntMap.find(
          Belt.Option.getExn(state.activeCardSetId),
          Belt.Option.getExn(activeGame.cardSets),
        );

      let updatedCards =
        Types.IntMap.add(
          card.id,
          card,
          Belt.Option.getExn(activeCardSet.cards),
        );
      let updatedCardSet = {...activeCardSet, cards: Some(updatedCards)};
      let updatedCardSets =
        Types.IntMap.add(
          Belt.Option.getExn(state.activeCardSetId),
          updatedCardSet,
          Belt.Option.getExn(activeGame.cardSets),
        );

      let updatedGame = {...activeGame, cardSets: Some(updatedCardSets)};

      ReasonReact.Update({
        ...state,
        games: Types.IntMap.add(state.activeGameId, updatedGame, state.games),
      });
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

    | CardSetView =>
      let currentGame =
        Types.IntMap.find(self.state.activeGameId, self.state.games);
      let currentCardSet =
        Types.IntMap.find(
          Belt.Option.getExn(self.state.activeCardSetId),
          Belt.Option.getExn(currentGame.cardSets),
        );
      <CardSetView cardset=currentCardSet dispatch={self.send} />;

    | Nowhere => <div> {str("...nowhere")} </div>
    },
};