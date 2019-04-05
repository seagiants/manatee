
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