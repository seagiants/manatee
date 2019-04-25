// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Random = require("bs-platform/lib/js/random.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var UIUtils$ReactTemplate = require("./UIUtils.bs.js");

function addGameHandler(dispatch, state) {
  if (state[/* cardName */0] !== "") {
    return Curry._1(dispatch, /* AddCard */Block.__(3, [/* record */[
                    /* id */Random.$$int(9999),
                    /* name */"The new card",
                    /* text */"New and shiny",
                    /* keyword : GEAR */0
                  ]]));
  } else {
    return 0;
  }
}

var component = ReasonReact.reducerComponent("CardAdder");

function make(dispatch, _children) {
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
              return React.createElement("div", {
                          className: "row"
                        }, React.createElement("h2", undefined, UIUtils$ReactTemplate.str("Add a card")), React.createElement("div", {
                              className: "row"
                            }, React.createElement("input", {
                                  placeholder: "Name your card",
                                  type: "text",
                                  onChange: (function ($$event) {
                                      return Curry._1(self[/* send */3], /* SetCardName */[$$event.target.value]);
                                    })
                                }), React.createElement("button", {
                                  className: "btn waves-effect waves-light pink",
                                  onClick: (function (_event) {
                                      return addGameHandler(dispatch, self[/* state */1]);
                                    })
                                }, UIUtils$ReactTemplate.str("Add a card"), React.createElement("i", {
                                      className: "material-icons right"
                                    }, UIUtils$ReactTemplate.str("add"))), React.createElement("p", undefined, UIUtils$ReactTemplate.str(self[/* state */1][/* cardName */0]))));
            }),
          /* initialState */(function (param) {
              return /* record */[/* cardName */" "];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _state) {
              return /* Update */Block.__(0, [/* record */[/* cardName */action[0]]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.addGameHandler = addGameHandler;
exports.component = component;
exports.make = make;
/* component Not a pure module */
