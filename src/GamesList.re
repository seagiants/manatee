open UIUtils;

let handleClick = (href, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let component = ReasonReact.statelessComponent("GamesList");

let make = (~games: list(Types.cardGame), _children) => {
  ...component,
  render: self =>
    <div className="row">
      <h2> {str("List of games")} </h2>
      <div className="collection">
        {ReasonReact.array(
           componentsListToArray(games, game =>
             <a
               key=game.name
               className="collection-item avatar"
               href="#"
               onClick={
                 self.handle((event, _) =>
                   handleClick("/cardgame/" ++ string_of_int(game.id), event)
                 )
               }>
               <i className="material-icons circle">
                 {str("videogame_asset")}
               </i>
               <span className="title blue-text text-darken-2">
                 {str(String.uppercase(game.name))}
               </span>
               <p> {str("2 cardsets")} <br /> {str("10 cards")} </p>
             </a>
           ),
         )}
      </div>
    </div>,
};