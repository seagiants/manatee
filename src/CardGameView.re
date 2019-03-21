open UIUtils;

let component = ReasonReact.statelessComponent("CardGameView");

/** FIXME factorize this code, see App.re */
let handleClick = (href, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let make = (~name, _children) => {
  ...component,
  render: self => {
    <div>
      <a
        className="waves-effect waves-light btn"
        onClick={self.handle((event, _) => handleClick("/", event))}>
        {str("__Home__")}
      </a>
      <h1> {str(name ++ " card game")} </h1>
      <a
        className="waves-effect waves-light btn"
        onClick={self.handle((event, _) => handleClick("/cardgame/"++ name ++"/cardset", event))}>
        {str("Card set")}
      </a>
    </div>;
  },
};