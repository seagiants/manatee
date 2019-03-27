open UIUtils;

let handleClick = (href, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let component = ReasonReact.statelessComponent("GamesList");

let make = (~games: Types.cardGameMap, _children) => {
  ...component,
  render: self =>
    <div className="row">
      <h2> {str("List of games")} </h2>
      <div className="collection">
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (x: Types.binding) => {
                 let (key, cardGame) = x;
                 <a
                   key={string_of_int(key)}
                   className="collection-item avatar"
                   href="#"
                   onClick={
                     self.handle((event, _) =>
                       handleClick(
                         "/cardgame/" ++ string_of_int(cardGame.id),
                         event,
                       )
                     )
                   }>
                   <i className="material-icons circle">
                     {str("videogame_asset")}
                   </i>
                   <span className="title blue-text text-darken-2">
                     {str(String.uppercase(cardGame.name))}
                   </span>
                   <p>
                     {str(
                        Belt.Option.isNone(cardGame.cardSets) ?
                          "No cardset yet" :
                          string_of_int(
                            Types.IntMap.cardinal(
                              // Extract value of Some type
                              Belt.Option.getExn(cardGame.cardSets),
                            ),
                          )
                          ++ " cardset(s)",
                      )}
                     <br />
                     {str("10 cards")}
                   </p>
                 </a>;
               },
               Types.IntMap.bindings(games),
             ),
           ),
         )}
      </div>
    </div>,
};