// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Types$ReactTemplate = require("./Types.bs.js");
var UIUtils$ReactTemplate = require("./UIUtils.bs.js");
var HomeView$ReactTemplate = require("./HomeView.bs.js");
var CardGameView$ReactTemplate = require("./CardGameView.bs.js");

var app = ReasonReact.reducerComponent("App");

function make(_children) {
  return /* record */[
          /* debugName */app[/* debugName */0],
          /* reactClassInternal */app[/* reactClassInternal */1],
          /* handedOffState */app[/* handedOffState */2],
          /* willReceiveProps */app[/* willReceiveProps */3],
          /* didMount */(function (self) {
              ReasonReact.Router[/* watchUrl */1]((function (url) {
                      var match = url[/* path */0];
                      if (match) {
                        if (match[0] === "cardgame") {
                          var match$1 = match[1];
                          if (match$1) {
                            var match$2 = match$1[1];
                            var id = match$1[0];
                            if (match$2) {
                              if (match$2[0] === "cardset" && !match$2[1]) {
                                return Curry._1(self[/* send */3], /* ShowCardList */Block.__(1, [id]));
                              } else {
                                return Curry._1(self[/* send */3], /* Void */1);
                              }
                            } else {
                              return Curry._1(self[/* send */3], /* ShowCardGame */Block.__(0, [id]));
                            }
                          } else {
                            return Curry._1(self[/* send */3], /* Void */1);
                          }
                        } else {
                          return Curry._1(self[/* send */3], /* Void */1);
                        }
                      } else {
                        return Curry._1(self[/* send */3], /* GetHome */0);
                      }
                    }));
              return /* () */0;
            }),
          /* didUpdate */app[/* didUpdate */5],
          /* willUnmount */app[/* willUnmount */6],
          /* willUpdate */app[/* willUpdate */7],
          /* shouldUpdate */app[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* view */0];
              switch (match) {
                case 0 : 
                    return ReasonReact.element(undefined, undefined, HomeView$ReactTemplate.make(self[/* state */1][/* games */3], self[/* send */3], /* array */[]));
                case 1 : 
                    return React.createElement("div", undefined, UIUtils$ReactTemplate.str("card list"));
                case 2 : 
                    return ReasonReact.element(undefined, undefined, CardGameView$ReactTemplate.make(Curry._2(Types$ReactTemplate.IntMap[/* find */21], self[/* state */1][/* activeGameId */2], self[/* state */1][/* games */3]), /* array */[]));
                case 3 : 
                    return React.createElement("div", undefined, UIUtils$ReactTemplate.str("...nowhere"));
                
              }
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* view : HomeView */0,
                      /* nextId */1,
                      /* activeGameId */0,
                      /* games */Curry._3(Types$ReactTemplate.IntMap[/* add */3], 0, /* record */[
                            /* id */0,
                            /* name */"Starting game",
                            /* description */"Not to start empty is a good thing",
                            /* cardSets */Caml_option.some(Curry._3(Types$ReactTemplate.IntMap[/* add */3], 0, /* record */[
                                      /* id */0,
                                      /* name */"Basic set of cards",
                                      /* description */"yolo",
                                      /* cards */undefined
                                    ], Types$ReactTemplate.IntMap[/* empty */0]))
                          ], Types$ReactTemplate.IntMap[/* empty */0])
                    ];
            }),
          /* retainedProps */app[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                if (action === 0) {
                  return /* Update */Block.__(0, [/* record */[
                              /* view : HomeView */0,
                              /* nextId */state[/* nextId */1],
                              /* activeGameId */state[/* activeGameId */2],
                              /* games */state[/* games */3]
                            ]]);
                } else {
                  return /* Update */Block.__(0, [/* record */[
                              /* view : Nowhere */3,
                              /* nextId */state[/* nextId */1],
                              /* activeGameId */state[/* activeGameId */2],
                              /* games */state[/* games */3]
                            ]]);
                }
              } else {
                switch (action.tag | 0) {
                  case 0 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* view : CardGameView */2,
                                  /* nextId */state[/* nextId */1],
                                  /* activeGameId */Caml_format.caml_int_of_string(action[0]),
                                  /* games */state[/* games */3]
                                ]]);
                  case 1 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* view : CardSetView */1,
                                  /* nextId */state[/* nextId */1],
                                  /* activeGameId */state[/* activeGameId */2],
                                  /* games */state[/* games */3]
                                ]]);
                  case 2 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* view */state[/* view */0],
                                  /* nextId */state[/* nextId */1] + 1 | 0,
                                  /* activeGameId */state[/* activeGameId */2],
                                  /* games */Curry._3(Types$ReactTemplate.IntMap[/* add */3], state[/* nextId */1], /* record */[
                                        /* id */state[/* nextId */1],
                                        /* name */action[0],
                                        /* description */"--",
                                        /* cardSets */undefined
                                      ], state[/* games */3])
                                ]]);
                  
                }
              }
            }),
          /* jsElementWrapped */app[/* jsElementWrapped */13]
        ];
}

exports.app = app;
exports.make = make;
/* app Not a pure module */
