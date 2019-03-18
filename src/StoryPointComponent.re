let storyPointComponent =
  ReasonReact.statelessComponent("StoryPointComponent");

let make = (~id: int, ~text: string, _children) => {
  ...storyPointComponent,
  render: _self =>
    <div className="row">
      <div className="col s12 m7">
        <div className="card">
          <div className="card-content">
            <span className="card-title">
              {ReasonReact.string(string_of_int(id))}
            </span>
            {ReasonReact.string(text)}
          </div>
        </div>
      </div>
    </div>,
};