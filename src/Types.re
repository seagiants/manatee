/* Story Point def */
type storyPoint = {
  id: int,
  text: string,
  linkTo: option(int),
};

/* Story */
type story = {
  name: string,
  storyPoints: list(storyPoint),
};

/******** Card game types */
/* Maps */
module IntMap =
  Map.Make({
    type t = int;
    let compare = compare;
  });

type card = {
  name: string,
  text: string,
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