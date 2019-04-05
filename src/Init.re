/** Example cards */
let woodplate : Types.card = {
  id: 0,
  name: "Wood plate",
  text: "A simple but robust plate made of wood",
  keyword: Types.GEAR,
};

let mechaBunny: Types.card = {
    id:1,
    name: "Mecha Bunny",
    text: "Hopping mech style",
    keyword: Types.CREATURE
}

let startingCards: Types.cardMap = Types.IntMap.add(1, mechaBunny, Types.IntMap.empty)

let simpleInitialState = (): State.state => {
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
                  Some(startingCards),
              }: Types.cardSet,
              Types.IntMap.empty,
            ),
          ),
      }: Types.cardGame,
      Types.IntMap.empty,
    ),
};