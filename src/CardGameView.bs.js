// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Types$ReactTemplate = require("./Types.bs.js");
var UIUtils$ReactTemplate = require("./UIUtils.bs.js");

var component = ReasonReact.statelessComponent("CardGameView");

function handleClick(href, $$event) {
  if ($$event.defaultPrevented) {
    return 0;
  } else {
    $$event.preventDefault();
    return ReasonReact.Router[/* push */0](href);
  }
}

function make(game, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = Belt_Option.isNone(game[/* cardSets */3]);
              return React.createElement("div", undefined, React.createElement("a", {
                              className: "waves-effect waves-light btn",
                              onClick: Curry._1(self[/* handle */0], (function ($$event, param) {
                                      return handleClick("/", $$event);
                                    }))
                            }, UIUtils$ReactTemplate.str("__Home__")), React.createElement("h1", undefined, UIUtils$ReactTemplate.str(game[/* name */1])), React.createElement("p", undefined, UIUtils$ReactTemplate.str(String(game[/* id */0]))), React.createElement("blockquote", undefined, UIUtils$ReactTemplate.str(game[/* description */2])), match ? React.createElement("div", undefined, UIUtils$ReactTemplate.str("no card set")) : React.createElement("div", undefined, React.createElement("ul", undefined, $$Array.of_list(List.map((function (binding) {
                                              var cardset = binding[1];
                                              return React.createElement("li", {
                                                          key: String(binding[0])
                                                        }, React.createElement("a", {
                                                              className: "waves-effect waves-light btn",
                                                              onClick: Curry._1(self[/* handle */0], (function ($$event, param) {
                                                                      return handleClick("/cardgame/" + (String(game[/* id */0]) + ("/cardset/" + String(cardset[/* id */0]))), $$event);
                                                                    }))
                                                            }, UIUtils$ReactTemplate.str(cardset[/* name */1] + (" - " + cardset[/* description */2]))));
                                            }), Curry._1(Types$ReactTemplate.IntMap[/* bindings */16], Belt_Option.getExn(game[/* cardSets */3])))))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.handleClick = handleClick;
exports.make = make;
/* component Not a pure module */
