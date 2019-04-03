
/******** Card game types */
/* Maps */
module IntMap =
  Map.Make({
    type t = int;
    let compare = compare;
  });

type keyword = GEAR | CREATURE

// TODO here we implement specific types of card for sake of simplicity
// in the future, we would like the ability to define card types for each game
type card = {
  id: int,
  name: string,
  text: string,
  keyword
};

type cardMap = IntMap.t(card);

type cardSet = {
  id: int,
  name: string,
  description: string,
  cards: option(cardMap)
};

type cardSetMap = IntMap.t(cardSet);

type cardGame = {
  id: int,
  name: string,
  description: string,
  cardSets: option(cardSetMap)
};

type cardGameMap = IntMap.t(cardGame);

type binding = (IntMap.key, cardGame);
type cardSetMapBinding = (IntMap.key, cardSet)