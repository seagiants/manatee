open UIUtils;

let component = ReasonReact.statelessComponent("CardGameView");

/** FIXME factorize this code, see App.re */
let handleClick = (href, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let make = (~game: Types.cardGame, _children) => {
  ...component,
  render: self => {
    <div>
      <a
        className="waves-effect waves-light btn"
        onClick={self.handle((event, _) => handleClick("/", event))}>
        {str("__Home__")}
      </a>
      <h1> {str(game.name)} </h1>
      <p> {str(string_of_int(game.id))} </p>
      <blockquote> {str(game.description)} </blockquote>
      
      // TODO refactoring needed =)
      {Belt.Option.isNone(game.cardSets) ?
         <div> {str("no card set")} </div> :
         <div>
           <ul>
             {ReasonReact.array(
                Array.of_list(
                  List.map(
                    (binding: Types.cardSetMapBinding) => {
                      let (key, cardset) = binding;
                      <li key={string_of_int(key)}>
                        <a
                          className="waves-effect waves-light btn"
                          onClick={
                            self.handle((event, _) =>
                              handleClick(
                                "/cardgame/"
                                ++ string_of_int(game.id)
                                ++ "/cardset/"
                                ++ string_of_int(cardset.id),
                                event,
                              )
                            )
                          }>
                          {str(cardset.name ++ " - " ++ cardset.description)}
                        </a>
                      </li>;
                    },
                    Types.IntMap.bindings(Belt.Option.getExn(game.cardSets)),
                  ),
                ),
              )}
           </ul>
         </div>}
    </div>;
  },
};