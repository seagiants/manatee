let str = ReasonReact.string;

let componentsListToArray = (components: list('a), componentfn) =>
  Array.of_list(List.map(componentfn, components));