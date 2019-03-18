open UIUtils;

type state = {
  count: int,
  story: Types.story,
};
type action =
  | Add;

// Mock storypoint for testing
let addon: Types.storyPoint = {
  id: 999,
  text: "Im the addon",
  linkTo: Some(1000),
};

let storyComponent = ReasonReact.reducerComponent("StoryComponent");

let make = (~initialStory, _children) => {
  ...storyComponent,

  initialState: () => {count: 0, story: initialStory},

  reducer: (action, state) => {
    switch (action) {
    | Add =>
      ReasonReact.Update({
        ...state,
        story: {
          name: state.story.name,
          // The only way to append at the end of a list is via List.concat(list_of_lists)
          storyPoints: List.concat([state.story.storyPoints, [addon]]),
        },
      })
    };
  },

  render: self =>
    <div>
      <p> {ReasonReact.string(self.state.story.name)} </p>
      <p>
        {ReasonReact.string("Story points:")}
        {ReasonReact.string(
           string_of_int(List.length(self.state.story.storyPoints)),
         )}
      </p>
      <button onClick={_event => self.send(Add)}>
        {ReasonReact.string("Add a story point")}
      </button>
      <div>
        {ReasonReact.array(
           componentsListToArray(
             self.state.story.storyPoints, (storypoint: Types.storyPoint) =>
             <StoryPointComponent
               key={string_of_int(storypoint.id)}
               id={storypoint.id}
               text={storypoint.text}
             />
           ),
         )}
      </div>
    </div>,
};