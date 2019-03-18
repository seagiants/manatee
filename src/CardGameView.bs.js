// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
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

function make(name, _children) {
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
              return React.createElement("div", undefined, React.createElement("a", {
                              className: "waves-effect waves-light btn",
                              onClick: Curry._1(self[/* handle */0], (function ($$event, param) {
                                      return handleClick("/", $$event);
                                    }))
                            }, UIUtils$ReactTemplate.str("__Home__")), React.createElement("h1", undefined, UIUtils$ReactTemplate.str(name + " card game")), React.createElement("a", {
                              className: "waves-effect waves-light btn",
                              onClick: Curry._1(self[/* handle */0], (function ($$event, param) {
                                      return handleClick("/cardgame/" + (name + "/cardlist"), $$event);
                                    }))
                            }, UIUtils$ReactTemplate.str("Cardlist")));
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
