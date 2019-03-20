open UIUtils;

let handleClick = (href, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let component = ReasonReact.statelessComponent("GamesList");

let make = (~games, _children) => {
  ...component,
  render: self =>
    <div className="row">
      <h2> {str("List of games")} </h2>
      <div className="collection">
        {ReasonReact.array(
           componentsListToArray(games, game =>
             <a
               key=game
               className="collection-item avatar"
               href="#"
               onClick={
                 self.handle((event, _) =>
                   handleClick("/cardgame/" ++ game, event)
                 )
               }>
               <i className="material-icons circle">
                 {str("videogame_asset")}
               </i>
               <span className="title blue-text text-darken-2">
                 {str(String.uppercase(game))}
               </span>
               <p> {str("2 cardsets")} <br /> {str("10 cards")} </p>
             </a>
           ),
         )}
      </div>
    </div>,
};