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
      {ReasonReact.array(
         componentsListToArray(games, game =>
           <div key=game className="row">
             <a
               className="waves-effect waves-light btn green lighten-1"
               onClick={
                 self.handle((event, _) =>
                   handleClick("/cardgame/" ++ game, event)
                 )
               }>
               {str(game)}
             </a>
           </div>
         ),
       )}
    </div>,
};