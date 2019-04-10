open UIUtils;
let component = ReasonReact.statelessComponent("CardSetView");

let make = (~cardset: Types.cardSet, _children) => {
  ...component,
  render: _self =>
    <div className="row">
      <h2> {str(cardset.name)} </h2>
      <h3> {str(cardset.description)} </h3>
      <CardAdder dispatch=None />
      <p>
        {Belt.Option.isNone(cardset.cards) ?
           str("No card yet in this card set") :
           str(
             string_of_int(
               Types.IntMap.cardinal(Belt.Option.getExn(cardset.cards)),
             )
             ++ " card(s) in this set",
           )}
      </p>
      {ReasonReact.array(
         Array.of_list(
           List.map(
             ((key: Types.IntMap.key, card: Types.card)) =>
               <div className="card" key={string_of_int(key)}>
                 <div className="card-content">
                   <h4> {str(card.name)} </h4>
                 </div>
                 <div className="card-content grey lighten-4">
                   {str(card.text)}
                 </div>
                 <div className="card-content indigo lighten-2">
                 {switch(card.keyword) {
                 | GEAR => <p>{str("GEAR")}</p>
                 | CREATURE => <p>{str("CREATURE")}</p>
                 };}
                 </div>
               </div>,
             Types.IntMap.bindings(Belt.Option.getExn(cardset.cards)),
           ),
         ),
       )}
    </div>,
};