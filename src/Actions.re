type action =
  | GetHome
  | ShowCardGame(string)
  | ShowCardList(string)
  | Void
  | AddGame(string);