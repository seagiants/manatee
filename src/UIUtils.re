let str = ReasonReact.string;

let toto = "yo"

let componentsListToArray = (components: list('a), componentfn) =>
  Array.of_list(List.map(componentfn, components));

let extractCG: (Types.IntMap.key, Types.cardGame) => ReasonReact.reactElement = (key, cardGame) =>
  <div key={string_of_int(key)}>{str(cardGame.name)}</div>
  
