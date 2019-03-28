open UIUtils;

let appName = "Manatee";

let component = ReasonReact.statelessComponent("HomeView")

let make = (~games, ~dispatch, _children) => {
    ...component,
    render: _self => 
    <div>
        <h1 className="center-align">
          <span className="blue-grey-text text-lighten-2">
            {str(appName)}
          </span>
        </h1>
        <CardGameAdd dispatch={dispatch} />
        <GamesList games={games} />
      </div>
}