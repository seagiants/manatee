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
type card = {
  name: string,
  text: string,
};

type cardSet = {
  name: string,
  description: string,
  cards: array(card) // TODO implement with cardMap
};

type cardGame = {
  id: int,
  name: string,
  description: string,
  cardSets: option(string) // TODO implement with cardSetMap
};

/* Maps */
module IntMap =
  Map.Make({
    type t = int;
    let compare = compare;
  });

type cardGameMap = IntMap.t(cardGame);
type cardSetMap = IntMap.t(cardSet);
type cardMap = IntMap.t(card);

type binding = (IntMap.key, cardGame);