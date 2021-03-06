// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var UIUtils$ReactTemplate = require("./UIUtils.bs.js");
var GamesList$ReactTemplate = require("./GamesList.bs.js");
var CardGameAdd$ReactTemplate = require("./CardGameAdd.bs.js");

var appName = "Manatee";

var component = ReasonReact.statelessComponent("HomeView");

function make(games, dispatch, _children) {
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
          /* render */(function (_self) {
              return React.createElement("div", undefined, React.createElement("h1", {
                              className: "center-align"
                            }, React.createElement("span", {
                                  className: "blue-grey-text text-lighten-2"
                                }, UIUtils$ReactTemplate.str(appName))), ReasonReact.element(undefined, undefined, CardGameAdd$ReactTemplate.make(dispatch, /* array */[])), ReasonReact.element(undefined, undefined, GamesList$ReactTemplate.make(games, /* array */[])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.appName = appName;
exports.component = component;
exports.make = make;
/* component Not a pure module */
