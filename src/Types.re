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
  text: string
  };

type cardSet = {
  name: string,
  description: string,
  cards: array(card),
};


type cardGame = {
  id:int,
  name: string,
  description: string,
  cardSets: option(string),
};