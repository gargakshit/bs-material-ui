type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
  | `Float(f) => toJsUnsafe(f)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  | `Enum(_) => assert false;

let optionMap = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };

module WithStyles = {
  let component = ReasonReact.statelessComponent("WithStyles");
  let make = (~render, ~classes: Js.t({..}), _children) => {
    ...component,
    render: (_self) => render(classes)
  };
  type withStylesComponent('a) = [@bs] ('a => ReasonReact.reactClass);
  [@bs.module "material-ui/styles"]
  external withStylesExt : 'styles => withStylesComponent('component) =
    "withStyles";
  let creteStylesWrapper = (styles: Js.t({..})) => withStylesExt(styles);
  let make = (~styles=Js.Obj.empty(), ~render, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass={
        let wrapper = creteStylesWrapper(styles);
        [@bs]
        wrapper(
          ReasonReact.wrapReasonForJs(
            ~component,
            (jsProps) => make(~render=jsProps##render, ~classes=jsProps##classes, [||])
          )
        )
      },
      ~props={"render": render},
      children
    );
};

module Colors = {
  module BlueGrey = {
    [@bs.module "material-ui/colors/blueGrey"] external blueGreyExt : Js.Dict.t(string) =
      "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(blueGreyExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(blueGreyExt, "A700");
    let a400: string = Js.Dict.unsafeGet(blueGreyExt, "A400");
    let a200: string = Js.Dict.unsafeGet(blueGreyExt, "A200");
    let a100: string = Js.Dict.unsafeGet(blueGreyExt, "A100");
    let c900: string = Js.Dict.unsafeGet(blueGreyExt, "900");
    let c800: string = Js.Dict.unsafeGet(blueGreyExt, "800");
    let c700: string = Js.Dict.unsafeGet(blueGreyExt, "700");
    let c600: string = Js.Dict.unsafeGet(blueGreyExt, "600");
    let c500: string = Js.Dict.unsafeGet(blueGreyExt, "500");
    let c400: string = Js.Dict.unsafeGet(blueGreyExt, "400");
    let c300: string = Js.Dict.unsafeGet(blueGreyExt, "300");
    let c200: string = Js.Dict.unsafeGet(blueGreyExt, "200");
    let c100: string = Js.Dict.unsafeGet(blueGreyExt, "100");
    let c50: string = Js.Dict.unsafeGet(blueGreyExt, "50");
  };
  module Grey = {
    [@bs.module "material-ui/colors/grey"] external greyExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(greyExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(greyExt, "A700");
    let a400: string = Js.Dict.unsafeGet(greyExt, "A400");
    let a200: string = Js.Dict.unsafeGet(greyExt, "A200");
    let a100: string = Js.Dict.unsafeGet(greyExt, "A100");
    let c900: string = Js.Dict.unsafeGet(greyExt, "900");
    let c800: string = Js.Dict.unsafeGet(greyExt, "800");
    let c700: string = Js.Dict.unsafeGet(greyExt, "700");
    let c600: string = Js.Dict.unsafeGet(greyExt, "600");
    let c500: string = Js.Dict.unsafeGet(greyExt, "500");
    let c400: string = Js.Dict.unsafeGet(greyExt, "400");
    let c300: string = Js.Dict.unsafeGet(greyExt, "300");
    let c200: string = Js.Dict.unsafeGet(greyExt, "200");
    let c100: string = Js.Dict.unsafeGet(greyExt, "100");
    let c50: string = Js.Dict.unsafeGet(greyExt, "50");
  };
  module Brown = {
    [@bs.module "material-ui/colors/brown"] external brownExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(brownExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(brownExt, "A700");
    let a400: string = Js.Dict.unsafeGet(brownExt, "A400");
    let a200: string = Js.Dict.unsafeGet(brownExt, "A200");
    let a100: string = Js.Dict.unsafeGet(brownExt, "A100");
    let c900: string = Js.Dict.unsafeGet(brownExt, "900");
    let c800: string = Js.Dict.unsafeGet(brownExt, "800");
    let c700: string = Js.Dict.unsafeGet(brownExt, "700");
    let c600: string = Js.Dict.unsafeGet(brownExt, "600");
    let c500: string = Js.Dict.unsafeGet(brownExt, "500");
    let c400: string = Js.Dict.unsafeGet(brownExt, "400");
    let c300: string = Js.Dict.unsafeGet(brownExt, "300");
    let c200: string = Js.Dict.unsafeGet(brownExt, "200");
    let c100: string = Js.Dict.unsafeGet(brownExt, "100");
    let c50: string = Js.Dict.unsafeGet(brownExt, "50");
  };
  module DeepOrange = {
    [@bs.module "material-ui/colors/deepOrange"] external deepOrangeExt : Js.Dict.t(string) =
      "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(deepOrangeExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(deepOrangeExt, "A700");
    let a400: string = Js.Dict.unsafeGet(deepOrangeExt, "A400");
    let a200: string = Js.Dict.unsafeGet(deepOrangeExt, "A200");
    let a100: string = Js.Dict.unsafeGet(deepOrangeExt, "A100");
    let c900: string = Js.Dict.unsafeGet(deepOrangeExt, "900");
    let c800: string = Js.Dict.unsafeGet(deepOrangeExt, "800");
    let c700: string = Js.Dict.unsafeGet(deepOrangeExt, "700");
    let c600: string = Js.Dict.unsafeGet(deepOrangeExt, "600");
    let c500: string = Js.Dict.unsafeGet(deepOrangeExt, "500");
    let c400: string = Js.Dict.unsafeGet(deepOrangeExt, "400");
    let c300: string = Js.Dict.unsafeGet(deepOrangeExt, "300");
    let c200: string = Js.Dict.unsafeGet(deepOrangeExt, "200");
    let c100: string = Js.Dict.unsafeGet(deepOrangeExt, "100");
    let c50: string = Js.Dict.unsafeGet(deepOrangeExt, "50");
  };
  module Orange = {
    [@bs.module "material-ui/colors/orange"] external orangeExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(orangeExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(orangeExt, "A700");
    let a400: string = Js.Dict.unsafeGet(orangeExt, "A400");
    let a200: string = Js.Dict.unsafeGet(orangeExt, "A200");
    let a100: string = Js.Dict.unsafeGet(orangeExt, "A100");
    let c900: string = Js.Dict.unsafeGet(orangeExt, "900");
    let c800: string = Js.Dict.unsafeGet(orangeExt, "800");
    let c700: string = Js.Dict.unsafeGet(orangeExt, "700");
    let c600: string = Js.Dict.unsafeGet(orangeExt, "600");
    let c500: string = Js.Dict.unsafeGet(orangeExt, "500");
    let c400: string = Js.Dict.unsafeGet(orangeExt, "400");
    let c300: string = Js.Dict.unsafeGet(orangeExt, "300");
    let c200: string = Js.Dict.unsafeGet(orangeExt, "200");
    let c100: string = Js.Dict.unsafeGet(orangeExt, "100");
    let c50: string = Js.Dict.unsafeGet(orangeExt, "50");
  };
  module Amber = {
    [@bs.module "material-ui/colors/amber"] external amberExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(amberExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(amberExt, "A700");
    let a400: string = Js.Dict.unsafeGet(amberExt, "A400");
    let a200: string = Js.Dict.unsafeGet(amberExt, "A200");
    let a100: string = Js.Dict.unsafeGet(amberExt, "A100");
    let c900: string = Js.Dict.unsafeGet(amberExt, "900");
    let c800: string = Js.Dict.unsafeGet(amberExt, "800");
    let c700: string = Js.Dict.unsafeGet(amberExt, "700");
    let c600: string = Js.Dict.unsafeGet(amberExt, "600");
    let c500: string = Js.Dict.unsafeGet(amberExt, "500");
    let c400: string = Js.Dict.unsafeGet(amberExt, "400");
    let c300: string = Js.Dict.unsafeGet(amberExt, "300");
    let c200: string = Js.Dict.unsafeGet(amberExt, "200");
    let c100: string = Js.Dict.unsafeGet(amberExt, "100");
    let c50: string = Js.Dict.unsafeGet(amberExt, "50");
  };
  module Yellow = {
    [@bs.module "material-ui/colors/yellow"] external yellowExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(yellowExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(yellowExt, "A700");
    let a400: string = Js.Dict.unsafeGet(yellowExt, "A400");
    let a200: string = Js.Dict.unsafeGet(yellowExt, "A200");
    let a100: string = Js.Dict.unsafeGet(yellowExt, "A100");
    let c900: string = Js.Dict.unsafeGet(yellowExt, "900");
    let c800: string = Js.Dict.unsafeGet(yellowExt, "800");
    let c700: string = Js.Dict.unsafeGet(yellowExt, "700");
    let c600: string = Js.Dict.unsafeGet(yellowExt, "600");
    let c500: string = Js.Dict.unsafeGet(yellowExt, "500");
    let c400: string = Js.Dict.unsafeGet(yellowExt, "400");
    let c300: string = Js.Dict.unsafeGet(yellowExt, "300");
    let c200: string = Js.Dict.unsafeGet(yellowExt, "200");
    let c100: string = Js.Dict.unsafeGet(yellowExt, "100");
    let c50: string = Js.Dict.unsafeGet(yellowExt, "50");
  };
  module Lime = {
    [@bs.module "material-ui/colors/lime"] external limeExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(limeExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(limeExt, "A700");
    let a400: string = Js.Dict.unsafeGet(limeExt, "A400");
    let a200: string = Js.Dict.unsafeGet(limeExt, "A200");
    let a100: string = Js.Dict.unsafeGet(limeExt, "A100");
    let c900: string = Js.Dict.unsafeGet(limeExt, "900");
    let c800: string = Js.Dict.unsafeGet(limeExt, "800");
    let c700: string = Js.Dict.unsafeGet(limeExt, "700");
    let c600: string = Js.Dict.unsafeGet(limeExt, "600");
    let c500: string = Js.Dict.unsafeGet(limeExt, "500");
    let c400: string = Js.Dict.unsafeGet(limeExt, "400");
    let c300: string = Js.Dict.unsafeGet(limeExt, "300");
    let c200: string = Js.Dict.unsafeGet(limeExt, "200");
    let c100: string = Js.Dict.unsafeGet(limeExt, "100");
    let c50: string = Js.Dict.unsafeGet(limeExt, "50");
  };
  module LightGreen = {
    [@bs.module "material-ui/colors/lightGreen"] external lightGreenExt : Js.Dict.t(string) =
      "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(lightGreenExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(lightGreenExt, "A700");
    let a400: string = Js.Dict.unsafeGet(lightGreenExt, "A400");
    let a200: string = Js.Dict.unsafeGet(lightGreenExt, "A200");
    let a100: string = Js.Dict.unsafeGet(lightGreenExt, "A100");
    let c900: string = Js.Dict.unsafeGet(lightGreenExt, "900");
    let c800: string = Js.Dict.unsafeGet(lightGreenExt, "800");
    let c700: string = Js.Dict.unsafeGet(lightGreenExt, "700");
    let c600: string = Js.Dict.unsafeGet(lightGreenExt, "600");
    let c500: string = Js.Dict.unsafeGet(lightGreenExt, "500");
    let c400: string = Js.Dict.unsafeGet(lightGreenExt, "400");
    let c300: string = Js.Dict.unsafeGet(lightGreenExt, "300");
    let c200: string = Js.Dict.unsafeGet(lightGreenExt, "200");
    let c100: string = Js.Dict.unsafeGet(lightGreenExt, "100");
    let c50: string = Js.Dict.unsafeGet(lightGreenExt, "50");
  };
  module Green = {
    [@bs.module "material-ui/colors/green"] external greenExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(greenExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(greenExt, "A700");
    let a400: string = Js.Dict.unsafeGet(greenExt, "A400");
    let a200: string = Js.Dict.unsafeGet(greenExt, "A200");
    let a100: string = Js.Dict.unsafeGet(greenExt, "A100");
    let c900: string = Js.Dict.unsafeGet(greenExt, "900");
    let c800: string = Js.Dict.unsafeGet(greenExt, "800");
    let c700: string = Js.Dict.unsafeGet(greenExt, "700");
    let c600: string = Js.Dict.unsafeGet(greenExt, "600");
    let c500: string = Js.Dict.unsafeGet(greenExt, "500");
    let c400: string = Js.Dict.unsafeGet(greenExt, "400");
    let c300: string = Js.Dict.unsafeGet(greenExt, "300");
    let c200: string = Js.Dict.unsafeGet(greenExt, "200");
    let c100: string = Js.Dict.unsafeGet(greenExt, "100");
    let c50: string = Js.Dict.unsafeGet(greenExt, "50");
  };
  module Teal = {
    [@bs.module "material-ui/colors/teal"] external tealExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(tealExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(tealExt, "A700");
    let a400: string = Js.Dict.unsafeGet(tealExt, "A400");
    let a200: string = Js.Dict.unsafeGet(tealExt, "A200");
    let a100: string = Js.Dict.unsafeGet(tealExt, "A100");
    let c900: string = Js.Dict.unsafeGet(tealExt, "900");
    let c800: string = Js.Dict.unsafeGet(tealExt, "800");
    let c700: string = Js.Dict.unsafeGet(tealExt, "700");
    let c600: string = Js.Dict.unsafeGet(tealExt, "600");
    let c500: string = Js.Dict.unsafeGet(tealExt, "500");
    let c400: string = Js.Dict.unsafeGet(tealExt, "400");
    let c300: string = Js.Dict.unsafeGet(tealExt, "300");
    let c200: string = Js.Dict.unsafeGet(tealExt, "200");
    let c100: string = Js.Dict.unsafeGet(tealExt, "100");
    let c50: string = Js.Dict.unsafeGet(tealExt, "50");
  };
  module Cyan = {
    [@bs.module "material-ui/colors/cyan"] external cyanExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(cyanExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(cyanExt, "A700");
    let a400: string = Js.Dict.unsafeGet(cyanExt, "A400");
    let a200: string = Js.Dict.unsafeGet(cyanExt, "A200");
    let a100: string = Js.Dict.unsafeGet(cyanExt, "A100");
    let c900: string = Js.Dict.unsafeGet(cyanExt, "900");
    let c800: string = Js.Dict.unsafeGet(cyanExt, "800");
    let c700: string = Js.Dict.unsafeGet(cyanExt, "700");
    let c600: string = Js.Dict.unsafeGet(cyanExt, "600");
    let c500: string = Js.Dict.unsafeGet(cyanExt, "500");
    let c400: string = Js.Dict.unsafeGet(cyanExt, "400");
    let c300: string = Js.Dict.unsafeGet(cyanExt, "300");
    let c200: string = Js.Dict.unsafeGet(cyanExt, "200");
    let c100: string = Js.Dict.unsafeGet(cyanExt, "100");
    let c50: string = Js.Dict.unsafeGet(cyanExt, "50");
  };
  module LightBlue = {
    [@bs.module "material-ui/colors/lightBlue"] external lightBlueExt : Js.Dict.t(string) =
      "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(lightBlueExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(lightBlueExt, "A700");
    let a400: string = Js.Dict.unsafeGet(lightBlueExt, "A400");
    let a200: string = Js.Dict.unsafeGet(lightBlueExt, "A200");
    let a100: string = Js.Dict.unsafeGet(lightBlueExt, "A100");
    let c900: string = Js.Dict.unsafeGet(lightBlueExt, "900");
    let c800: string = Js.Dict.unsafeGet(lightBlueExt, "800");
    let c700: string = Js.Dict.unsafeGet(lightBlueExt, "700");
    let c600: string = Js.Dict.unsafeGet(lightBlueExt, "600");
    let c500: string = Js.Dict.unsafeGet(lightBlueExt, "500");
    let c400: string = Js.Dict.unsafeGet(lightBlueExt, "400");
    let c300: string = Js.Dict.unsafeGet(lightBlueExt, "300");
    let c200: string = Js.Dict.unsafeGet(lightBlueExt, "200");
    let c100: string = Js.Dict.unsafeGet(lightBlueExt, "100");
    let c50: string = Js.Dict.unsafeGet(lightBlueExt, "50");
  };
  module Blue = {
    [@bs.module "material-ui/colors/blue"] external blueExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(blueExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(blueExt, "A700");
    let a400: string = Js.Dict.unsafeGet(blueExt, "A400");
    let a200: string = Js.Dict.unsafeGet(blueExt, "A200");
    let a100: string = Js.Dict.unsafeGet(blueExt, "A100");
    let c900: string = Js.Dict.unsafeGet(blueExt, "900");
    let c800: string = Js.Dict.unsafeGet(blueExt, "800");
    let c700: string = Js.Dict.unsafeGet(blueExt, "700");
    let c600: string = Js.Dict.unsafeGet(blueExt, "600");
    let c500: string = Js.Dict.unsafeGet(blueExt, "500");
    let c400: string = Js.Dict.unsafeGet(blueExt, "400");
    let c300: string = Js.Dict.unsafeGet(blueExt, "300");
    let c200: string = Js.Dict.unsafeGet(blueExt, "200");
    let c100: string = Js.Dict.unsafeGet(blueExt, "100");
    let c50: string = Js.Dict.unsafeGet(blueExt, "50");
  };
  module Indigo = {
    [@bs.module "material-ui/colors/indigo"] external indigoExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(indigoExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(indigoExt, "A700");
    let a400: string = Js.Dict.unsafeGet(indigoExt, "A400");
    let a200: string = Js.Dict.unsafeGet(indigoExt, "A200");
    let a100: string = Js.Dict.unsafeGet(indigoExt, "A100");
    let c900: string = Js.Dict.unsafeGet(indigoExt, "900");
    let c800: string = Js.Dict.unsafeGet(indigoExt, "800");
    let c700: string = Js.Dict.unsafeGet(indigoExt, "700");
    let c600: string = Js.Dict.unsafeGet(indigoExt, "600");
    let c500: string = Js.Dict.unsafeGet(indigoExt, "500");
    let c400: string = Js.Dict.unsafeGet(indigoExt, "400");
    let c300: string = Js.Dict.unsafeGet(indigoExt, "300");
    let c200: string = Js.Dict.unsafeGet(indigoExt, "200");
    let c100: string = Js.Dict.unsafeGet(indigoExt, "100");
    let c50: string = Js.Dict.unsafeGet(indigoExt, "50");
  };
  module DeepPurple = {
    [@bs.module "material-ui/colors/deepPurple"] external deepPurpleExt : Js.Dict.t(string) =
      "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(deepPurpleExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(deepPurpleExt, "A700");
    let a400: string = Js.Dict.unsafeGet(deepPurpleExt, "A400");
    let a200: string = Js.Dict.unsafeGet(deepPurpleExt, "A200");
    let a100: string = Js.Dict.unsafeGet(deepPurpleExt, "A100");
    let c900: string = Js.Dict.unsafeGet(deepPurpleExt, "900");
    let c800: string = Js.Dict.unsafeGet(deepPurpleExt, "800");
    let c700: string = Js.Dict.unsafeGet(deepPurpleExt, "700");
    let c600: string = Js.Dict.unsafeGet(deepPurpleExt, "600");
    let c500: string = Js.Dict.unsafeGet(deepPurpleExt, "500");
    let c400: string = Js.Dict.unsafeGet(deepPurpleExt, "400");
    let c300: string = Js.Dict.unsafeGet(deepPurpleExt, "300");
    let c200: string = Js.Dict.unsafeGet(deepPurpleExt, "200");
    let c100: string = Js.Dict.unsafeGet(deepPurpleExt, "100");
    let c50: string = Js.Dict.unsafeGet(deepPurpleExt, "50");
  };
  module Purple = {
    [@bs.module "material-ui/colors/purple"] external purpleExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(purpleExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(purpleExt, "A700");
    let a400: string = Js.Dict.unsafeGet(purpleExt, "A400");
    let a200: string = Js.Dict.unsafeGet(purpleExt, "A200");
    let a100: string = Js.Dict.unsafeGet(purpleExt, "A100");
    let c900: string = Js.Dict.unsafeGet(purpleExt, "900");
    let c800: string = Js.Dict.unsafeGet(purpleExt, "800");
    let c700: string = Js.Dict.unsafeGet(purpleExt, "700");
    let c600: string = Js.Dict.unsafeGet(purpleExt, "600");
    let c500: string = Js.Dict.unsafeGet(purpleExt, "500");
    let c400: string = Js.Dict.unsafeGet(purpleExt, "400");
    let c300: string = Js.Dict.unsafeGet(purpleExt, "300");
    let c200: string = Js.Dict.unsafeGet(purpleExt, "200");
    let c100: string = Js.Dict.unsafeGet(purpleExt, "100");
    let c50: string = Js.Dict.unsafeGet(purpleExt, "50");
  };
  module Pink = {
    [@bs.module "material-ui/colors/pink"] external pinkExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(pinkExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(pinkExt, "A700");
    let a400: string = Js.Dict.unsafeGet(pinkExt, "A400");
    let a200: string = Js.Dict.unsafeGet(pinkExt, "A200");
    let a100: string = Js.Dict.unsafeGet(pinkExt, "A100");
    let c900: string = Js.Dict.unsafeGet(pinkExt, "900");
    let c800: string = Js.Dict.unsafeGet(pinkExt, "800");
    let c700: string = Js.Dict.unsafeGet(pinkExt, "700");
    let c600: string = Js.Dict.unsafeGet(pinkExt, "600");
    let c500: string = Js.Dict.unsafeGet(pinkExt, "500");
    let c400: string = Js.Dict.unsafeGet(pinkExt, "400");
    let c300: string = Js.Dict.unsafeGet(pinkExt, "300");
    let c200: string = Js.Dict.unsafeGet(pinkExt, "200");
    let c100: string = Js.Dict.unsafeGet(pinkExt, "100");
    let c50: string = Js.Dict.unsafeGet(pinkExt, "50");
  };
  module Red = {
    [@bs.module "material-ui/colors/red"] external redExt : Js.Dict.t(string) = "default";
    let contrastDefaultColor: string = Js.Dict.unsafeGet(redExt, "contrastDefaultColor");
    let a700: string = Js.Dict.unsafeGet(redExt, "A700");
    let a400: string = Js.Dict.unsafeGet(redExt, "A400");
    let a200: string = Js.Dict.unsafeGet(redExt, "A200");
    let a100: string = Js.Dict.unsafeGet(redExt, "A100");
    let c900: string = Js.Dict.unsafeGet(redExt, "900");
    let c800: string = Js.Dict.unsafeGet(redExt, "800");
    let c700: string = Js.Dict.unsafeGet(redExt, "700");
    let c600: string = Js.Dict.unsafeGet(redExt, "600");
    let c500: string = Js.Dict.unsafeGet(redExt, "500");
    let c400: string = Js.Dict.unsafeGet(redExt, "400");
    let c300: string = Js.Dict.unsafeGet(redExt, "300");
    let c200: string = Js.Dict.unsafeGet(redExt, "200");
    let c100: string = Js.Dict.unsafeGet(redExt, "100");
    let c50: string = Js.Dict.unsafeGet(redExt, "50");
  };
  module Common = {
    [@bs.module "material-ui/colors/common"] external commonExt : Js.Dict.t(string) = "default";
    let lightWhite: string = Js.Dict.unsafeGet(commonExt, "lightWhite");
    let darkWhite: string = Js.Dict.unsafeGet(commonExt, "darkWhite");
    let fullWhite: string = Js.Dict.unsafeGet(commonExt, "fullWhite");
    let faintBlack: string = Js.Dict.unsafeGet(commonExt, "faintBlack");
    let minBlack: string = Js.Dict.unsafeGet(commonExt, "minBlack");
    let lightBlack: string = Js.Dict.unsafeGet(commonExt, "lightBlack");
    let darkBlack: string = Js.Dict.unsafeGet(commonExt, "darkBlack");
    let fullBlack: string = Js.Dict.unsafeGet(commonExt, "fullBlack");
    let transparent: string = Js.Dict.unsafeGet(commonExt, "transparent");
    let white: string = Js.Dict.unsafeGet(commonExt, "white");
    let black: string = Js.Dict.unsafeGet(commonExt, "black");
  };
};

module Select = {
  module Margin = {
    type t =
      | Dense
      | None;
    let to_string =
      fun
      | Dense => "dense"
      | None => "none";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Select(string)
      | SelectMenu(string)
      | Disabled(string)
      | Icon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Select(_) => "select"
      | SelectMenu(_) => "selectMenu"
      | Disabled(_) => "disabled"
      | Icon(_) => "icon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Select(className)
               | SelectMenu(className)
               | Disabled(className)
               | Icon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Select/Select"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: option([ | `Object('a) | `String(string) | `Float(float)])=?,
        ~renderValue: option('b)=?,
        ~mMenuProps: option(Js.t({..}))=?,
        ~iInputClasses: option(Js.t({..}))=?,
        ~autoWidth: option(bool)=?,
        ~multiple: option(bool)=?,
        ~native: option(bool)=?,
        ~input: option(ReasonReact.reactElement)=?,
        ~displayEmpty: option(bool)=?,
        ~classes: option(Classes.t)=?,
        ~disableUnderline: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~multiline: option(bool)=?,
        ~type_: option(string)=?,
        ~autoComplete: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~className: option(string)=?,
        ~defaultValue: option([ | `String(string) | `Float(float)])=?,
        ~disabled: option(bool)=?,
        ~endAdornment: option(ReasonReact.reactElement)=?,
        ~error: option(bool)=?,
        ~id: option(string)=?,
        ~inputComponent: option([ | `String(string) | `Object(Js.t({..}))])=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option('c)=?,
        ~margin: option(Margin.t)=?,
        ~name: option(string)=?,
        ~readOnly: option(bool)=?,
        ~onBlur: option((ReactEventRe.Focus.t => unit))=?,
        ~onChange: option((ReactEventRe.Form.t => unit))=?,
        ~onClean: option(unit)=?,
        ~onDirty: option(unit)=?,
        ~onFocus: option((ReactEventRe.Focus.t => unit))=?,
        ~onKeyDown: option((ReactEventRe.Keyboard.t => unit))=?,
        ~onKeyUp: option((ReactEventRe.Keyboard.t => unit))=?,
        ~placeholder: option(string)=?,
        ~rows: option([ | `String(string) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Float(float)])=?,
        ~startAdornment: option(ReasonReact.reactElement)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "renderValue": Js.Nullable.from_opt(renderValue),
        "MenuProps": Js.Nullable.from_opt(mMenuProps),
        "InputClasses": Js.Nullable.from_opt(iInputClasses),
        "autoWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoWidth)),
        "multiple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiple)),
        "native": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, native)),
        "input": Js.Nullable.from_opt(input),
        "displayEmpty": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, displayEmpty)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "disableUnderline":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableUnderline)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "type": Js.Nullable.from_opt(type_),
        "autoComplete": Js.Nullable.from_opt(autoComplete),
        "autoFocus": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoFocus)),
        "className": Js.Nullable.from_opt(className),
        "defaultValue": Js.Nullable.from_opt(optionMap(unwrapValue, defaultValue)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "endAdornment": Js.Nullable.from_opt(endAdornment),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "id": Js.Nullable.from_opt(id),
        "inputComponent": Js.Nullable.from_opt(optionMap(unwrapValue, inputComponent)),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "margin": Js.Nullable.from_opt(optionMap(Margin.to_string, margin)),
        "name": Js.Nullable.from_opt(name),
        "readOnly": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, readOnly)),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClean": Js.Nullable.from_opt(onClean),
        "onDirty": Js.Nullable.from_opt(onDirty),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "placeholder": Js.Nullable.from_opt(placeholder),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "rowsMax": Js.Nullable.from_opt(optionMap(unwrapValue, rowsMax)),
        "startAdornment": Js.Nullable.from_opt(startAdornment)
      },
      children
    );
};

module InputAdornment = {
  module Position = {
    type t =
      | Start
      | End;
    let to_string =
      fun
      | Start => "start"
      | End => "end";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | PositionStart(string)
      | PositionEnd(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PositionStart(_) => "positionStart"
      | PositionEnd(_) => "positionEnd";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PositionStart(className)
               | PositionEnd(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/InputAdornment"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~position: Position.t,
        ~className: option(string)=?,
        ~disableTypography: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "position": Position.to_string(position),
        "className": Js.Nullable.from_opt(className),
        "disableTypography":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTypography)),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module BottomNavigation = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigation"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: 'a,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~className: option(string)=?,
        ~showLabels: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": value,
        "onChange": Js.Nullable.from_opt(onChange),
        "className": Js.Nullable.from_opt(className),
        "showLabels": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, showLabels)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module GridListTileBar = {
  module TitlePosition = {
    type t =
      | Top
      | Bottom;
    let to_string =
      fun
      | Top => "top"
      | Bottom => "bottom";
  };
  module ActionPosition = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | RootBottom(string)
      | RootTop(string)
      | RootWithSubtitle(string)
      | TitleWrap(string)
      | TitleWrapActionLeft(string)
      | TitleWrapActionRight(string)
      | Title(string)
      | Subtitle(string)
      | ActionIconPositionLeft(string)
      | ChildImg(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | RootBottom(_) => "rootBottom"
      | RootTop(_) => "rootTop"
      | RootWithSubtitle(_) => "rootWithSubtitle"
      | TitleWrap(_) => "titleWrap"
      | TitleWrapActionLeft(_) => "titleWrapActionLeft"
      | TitleWrapActionRight(_) => "titleWrapActionRight"
      | Title(_) => "title"
      | Subtitle(_) => "subtitle"
      | ActionIconPositionLeft(_) => "actionIconPositionLeft"
      | ChildImg(_) => "childImg";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | RootBottom(className)
               | RootTop(className)
               | RootWithSubtitle(className)
               | TitleWrap(className)
               | TitleWrapActionLeft(className)
               | TitleWrapActionRight(className)
               | Title(className)
               | Subtitle(className)
               | ActionIconPositionLeft(className)
               | ChildImg(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridListTileBar"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~title: ReasonReact.reactElement,
        ~subtitle: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~actionIcon: option(ReasonReact.reactElement)=?,
        ~titlePosition: option(TitlePosition.t)=?,
        ~classes: option(Classes.t)=?,
        ~actionPosition: option(ActionPosition.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "title": title,
        "subtitle": Js.Nullable.from_opt(subtitle),
        "className": Js.Nullable.from_opt(className),
        "actionIcon": Js.Nullable.from_opt(actionIcon),
        "titlePosition": Js.Nullable.from_opt(optionMap(TitlePosition.to_string, titlePosition)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "actionPosition": Js.Nullable.from_opt(optionMap(ActionPosition.to_string, actionPosition))
      },
      children
    );
};

module TableBody = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableBody"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Fade = {
  [@bs.module "material-ui/transitions/Fade"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~style: option(Js.t({..}))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~in_: bool,
        ~theme: option(Js.t({..}))=?,
        ~timeout: option(Js.t({..}))=?,
        ~appear: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "style": Js.Nullable.from_opt(style),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "in": Js.Boolean.to_js_boolean(in_),
        "theme": Js.Nullable.from_opt(theme),
        "timeout": Js.Nullable.from_opt(timeout),
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear))
      },
      children
    );
};

module CardMedia = {
  module Classes = {
    type classesType =
      | Root(string)
      | RootMedia(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | RootMedia(_) => "rootMedia";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | RootMedia(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardMedia"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~style: option(Js.t({..}))=?,
        ~src: option(string)=?,
        ~image: option(string)=?,
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "style": Js.Nullable.from_opt(style),
        "src": Js.Nullable.from_opt(src),
        "image": Js.Nullable.from_opt(image),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module ListItemAvatar = {
  module Classes = {
    type classesType =
      | Root(string)
      | Icon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Icon(_) => "icon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Icon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemAvatar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Badge = {
  module Color = {
    type t =
      | Default
      | Primary
      | Accent;
    let to_string =
      fun
      | Default => "default"
      | Primary => "primary"
      | Accent => "accent";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Badge(string)
      | ColorPrimary(string)
      | ColorAccent(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Badge(_) => "badge"
      | ColorPrimary(_) => "colorPrimary"
      | ColorAccent(_) => "colorAccent";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Badge(className)
               | ColorPrimary(className)
               | ColorAccent(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Badge/Badge"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~color: option(Color.t)=?,
        ~className: option(string)=?,
        ~badgeContent: ReasonReact.reactElement,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "className": Js.Nullable.from_opt(className),
        "badgeContent": badgeContent,
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module ButtonBase = {
  module Classes = {
    type classesType =
      | Root(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ButtonBase/ButtonBase"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~type_: string,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~rootRef: option('a)=?,
        ~role: option(string)=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyboardFocus: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~focusRipple: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~disabled: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~centerRipple: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "type": type_,
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "role": Js.Nullable.from_opt(role),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onClick": Js.Nullable.from_opt(onClick),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "component": Js.Nullable.from_opt(component),
        "className": Js.Nullable.from_opt(className),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Grow = {
  module Timeout = {
    type t =
      | Auto;
    let to_string =
      fun
      | Auto => "auto";
  };
  [@bs.module "material-ui/transitions/Grow"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~transitionClasses:
           option(
             [
               | `String(string)
               | `Object(
                   {
                     .
                     "appear": string,
                     "appearActive": string,
                     "enter": string,
                     "enterActive": string,
                     "exit": string,
                     "exitActive": string
                   }
                 )
             ]
           )=?,
        ~style: option(Js.t({..}))=?,
        ~rootRef: option('a)=?,
        ~onExited: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~in_: bool,
        ~theme: option(Js.t({..}))=?,
        ~timeout:
           option(
             [ | `Enum(Timeout.t) | `Float(float) | `Object({. "enter": float, "exit": float})]
           )=?,
        ~appear: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "transitionClasses": Js.Nullable.from_opt(optionMap(unwrapValue, transitionClasses)),
        "style": Js.Nullable.from_opt(style),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "in": Js.Boolean.to_js_boolean(in_),
        "theme": Js.Nullable.from_opt(theme),
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Timeout.to_string(e)))
              | x => unwrapValue(x),
              timeout
            )
          ),
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear))
      },
      children
    );
};

module IconButton = {
  module Color = {
    type t =
      | Default
      | Inherit
      | Primary
      | Contrast
      | Accent;
    let to_string =
      fun
      | Default => "default"
      | Inherit => "inherit"
      | Primary => "primary"
      | Contrast => "contrast"
      | Accent => "accent";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | ColorAccent(string)
      | ColorContrast(string)
      | ColorPrimary(string)
      | ColorInherit(string)
      | Disabled(string)
      | Label(string)
      | Icon(string)
      | KeyboardFocused(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorAccent(_) => "colorAccent"
      | ColorContrast(_) => "colorContrast"
      | ColorPrimary(_) => "colorPrimary"
      | ColorInherit(_) => "colorInherit"
      | Disabled(_) => "disabled"
      | Label(_) => "label"
      | Icon(_) => "icon"
      | KeyboardFocused(_) => "keyboardFocused";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorAccent(className)
               | ColorContrast(className)
               | ColorPrimary(className)
               | ColorInherit(className)
               | Disabled(className)
               | Label(className)
               | Icon(className)
               | KeyboardFocused(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/IconButton/IconButton"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~rootRef: option('a)=?,
        ~disableRipple: option(bool)=?,
        ~disabled: option(bool)=?,
        ~color: option(Color.t)=?,
        ~className: option(string)=?,
        ~buttonRef: option('b)=?,
        ~classes: option(Classes.t)=?,
        ~centerRipple: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~type_: string,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "rootRef": Js.Nullable.from_opt(rootRef),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "className": Js.Nullable.from_opt(className),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(component),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": type_
      },
      children
    );
};

module TextField = {
  module Margin = {
    type t =
      | None
      | Dense
      | Normal;
    let to_string =
      fun
      | None => "none"
      | Dense => "dense"
      | Normal => "normal";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | MarginNormal(string)
      | MarginDense(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | MarginNormal(_) => "marginNormal"
      | MarginDense(_) => "marginDense"
      | FullWidth(_) => "fullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | MarginNormal(className)
               | MarginDense(className)
               | FullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/TextField/TextField"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~margin: option(Margin.t)=?,
        ~value: option([ | `String(string) | `Float(float)])=?,
        ~type_: option(string)=?,
        ~sSelectProps: option(Js.t({..}))=?,
        ~select: option(bool)=?,
        ~rowsMax: option([ | `String(string) | `Float(float)])=?,
        ~rows: option([ | `String(string) | `Float(float)])=?,
        ~rootRef: option('a)=?,
        ~required: option(bool)=?,
        ~placeholder: option(string)=?,
        ~onChange: option((ReactEventRe.Form.t => unit))=?,
        ~name: option(string)=?,
        ~multiline: option(bool)=?,
        ~labelClassName: option(string)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~inputRef: option('b)=?,
        ~iInputProps: option(Js.t({..}))=?,
        ~inputProps: option(Js.t({..}))=?,
        ~iInputLabelProps: option(Js.t({..}))=?,
        ~iInputClassName: option(string)=?,
        ~inputClassName: option(string)=?,
        ~id: option(string)=?,
        ~helperTextClassName: option(string)=?,
        ~helperText: option(ReasonReact.reactElement)=?,
        ~fullWidth: option(bool)=?,
        ~fFormHelperTextProps: option(Js.t({..}))=?,
        ~error: option(bool)=?,
        ~disabled: option(bool)=?,
        ~defaultValue: option(string)=?,
        ~className: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~autoComplete: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~component: option(Js.t({..}))=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "margin": Js.Nullable.from_opt(optionMap(Margin.to_string, margin)),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "type": Js.Nullable.from_opt(type_),
        "SelectProps": Js.Nullable.from_opt(sSelectProps),
        "select": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, select)),
        "rowsMax": Js.Nullable.from_opt(optionMap(unwrapValue, rowsMax)),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "placeholder": Js.Nullable.from_opt(placeholder),
        "onChange": Js.Nullable.from_opt(onChange),
        "name": Js.Nullable.from_opt(name),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "labelClassName": Js.Nullable.from_opt(labelClassName),
        "label": Js.Nullable.from_opt(label),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "InputProps": Js.Nullable.from_opt(iInputProps),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "InputLabelProps": Js.Nullable.from_opt(iInputLabelProps),
        "InputClassName": Js.Nullable.from_opt(iInputClassName),
        "inputClassName": Js.Nullable.from_opt(inputClassName),
        "id": Js.Nullable.from_opt(id),
        "helperTextClassName": Js.Nullable.from_opt(helperTextClassName),
        "helperText": Js.Nullable.from_opt(helperText),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "FormHelperTextProps": Js.Nullable.from_opt(fFormHelperTextProps),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "defaultValue": Js.Nullable.from_opt(defaultValue),
        "className": Js.Nullable.from_opt(className),
        "autoFocus": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoFocus)),
        "autoComplete": Js.Nullable.from_opt(autoComplete),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "component": Js.Nullable.from_opt(component),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus)
      },
      children
    );
};

module ListSubheader = {
  module Color = {
    type t =
      | Default
      | Primary
      | Inherit;
    let to_string =
      fun
      | Default => "default"
      | Primary => "primary"
      | Inherit => "inherit";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorInherit(string)
      | Inset(string)
      | Sticky(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorInherit(_) => "colorInherit"
      | Inset(_) => "inset"
      | Sticky(_) => "sticky";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorPrimary(className)
               | ColorInherit(className)
               | Inset(className)
               | Sticky(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListSubheader"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~inset: option(bool)=?,
        ~disableSticky: option(bool)=?,
        ~color: option(Color.t)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "disableSticky": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableSticky)),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module DialogTitle = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogTitle"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~disableTypography: option(bool)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "disableTypography":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTypography)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module DialogContent = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogContent"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Popover = {
  module TransitionDuration = {
    type t =
      | Auto;
    let to_string =
      fun
      | Auto => "auto";
  };
  module Classes = {
    type classesType =
      | Paper(string);
    type t = list(classesType);
    let to_string =
      fun
      | Paper(_) => "paper";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Paper(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Popover/Popover"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~transitionDuration:
           option(
             [
               | `Enum(TransitionDuration.t)
               | `Float(float)
               | `Object({. "enter": float, "exit": float})
             ]
           )=?,
        ~transitionClasses:
           option(
             [
               | `String(string)
               | `Object(
                   {
                     .
                     "appear": string,
                     "appearActive": string,
                     "enter": string,
                     "enterActive": string,
                     "exit": string,
                     "exitActive": string
                   }
                 )
             ]
           )=?,
        ~role: option(string)=?,
        ~pPaperProps: option(Js.t({..}))=?,
        ~open_: bool,
        ~onRequestClose: option(ReasonReact.Callback.t(ReactEventRe.Synthetic.t))=?,
        ~onExited: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~getContentAnchorEl: option('a)=?,
        ~elevation: option(float)=?,
        ~anchorEl: option(Js.t({..}))=?,
        ~marginThreshold: option(float)=?,
        ~transformOrigin: option({. "horizontal": _, "vertical": _})=?,
        ~classes: option(Classes.t)=?,
        ~anchorOrigin: option({. "horizontal": _, "vertical": _})=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(TransitionDuration.to_string(e)))
              | x => unwrapValue(x),
              transitionDuration
            )
          ),
        "transitionClasses": Js.Nullable.from_opt(optionMap(unwrapValue, transitionClasses)),
        "role": Js.Nullable.from_opt(role),
        "PaperProps": Js.Nullable.from_opt(pPaperProps),
        "open": Js.Boolean.to_js_boolean(open_),
        "onRequestClose": Js.Nullable.from_opt(onRequestClose),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "getContentAnchorEl": Js.Nullable.from_opt(getContentAnchorEl),
        "elevation": Js.Nullable.from_opt(elevation),
        "anchorEl": Js.Nullable.from_opt(anchorEl),
        "marginThreshold": Js.Nullable.from_opt(marginThreshold),
        "transformOrigin": Js.Nullable.from_opt(transformOrigin),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "anchorOrigin": Js.Nullable.from_opt(anchorOrigin)
      },
      children
    );
};

module Avatar = {
  module Classes = {
    type classesType =
      | Root(string)
      | ColorDefault(string)
      | Img(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorDefault(_) => "colorDefault"
      | Img(_) => "img";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorDefault(className)
               | Img(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Avatar/Avatar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~srcSet: option(string)=?,
        ~src: option(string)=?,
        ~sizes: option(string)=?,
        ~imgProps: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~childrenClassName: option(string)=?,
        ~alt: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "srcSet": Js.Nullable.from_opt(srcSet),
        "src": Js.Nullable.from_opt(src),
        "sizes": Js.Nullable.from_opt(sizes),
        "imgProps": Js.Nullable.from_opt(imgProps),
        "className": Js.Nullable.from_opt(className),
        "childrenClassName": Js.Nullable.from_opt(childrenClassName),
        "alt": Js.Nullable.from_opt(alt),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Tabs = {
  module TextColor = {
    type t =
      | Accent
      | Primary
      | Inherit;
    let to_string =
      fun
      | Accent => "accent"
      | Primary => "primary"
      | Inherit => "inherit";
  };
  module ScrollButtons = {
    type t =
      | Auto
      | On
      | Off;
    let to_string =
      fun
      | Auto => "auto"
      | On => "on"
      | Off => "off";
  };
  module IndicatorColor = {
    type t =
      | Accent
      | Primary;
    let to_string =
      fun
      | Accent => "accent"
      | Primary => "primary";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | FlexContainer(string)
      | ScrollingContainer(string)
      | Fixed(string)
      | Scrollable(string)
      | Centered(string)
      | ButtonAuto(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FlexContainer(_) => "flexContainer"
      | ScrollingContainer(_) => "scrollingContainer"
      | Fixed(_) => "fixed"
      | Scrollable(_) => "scrollable"
      | Centered(_) => "centered"
      | ButtonAuto(_) => "buttonAuto";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FlexContainer(className)
               | ScrollingContainer(className)
               | Fixed(className)
               | Scrollable(className)
               | Centered(className)
               | ButtonAuto(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tabs/Tabs"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~value: 'a,
        ~textColor: option(TextColor.t)=?,
        ~scrollButtons: option(ScrollButtons.t)=?,
        ~scrollable: option(bool)=?,
        ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t),
        ~indicatorClassName: option(string)=?,
        ~fullWidth: option(bool)=?,
        ~className: option(string)=?,
        ~centered: option(bool)=?,
        ~buttonClassName: option(string)=?,
        ~theme: option(Js.t({..}))=?,
        ~tTabScrollButton: option(Js.t({..}))=?,
        ~indicatorColor: option([ | `Enum(IndicatorColor.t) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": value,
        "textColor": Js.Nullable.from_opt(optionMap(TextColor.to_string, textColor)),
        "scrollButtons": Js.Nullable.from_opt(optionMap(ScrollButtons.to_string, scrollButtons)),
        "scrollable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, scrollable)),
        "onChange": onChange,
        "indicatorClassName": Js.Nullable.from_opt(indicatorClassName),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "className": Js.Nullable.from_opt(className),
        "centered": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centered)),
        "buttonClassName": Js.Nullable.from_opt(buttonClassName),
        "theme": Js.Nullable.from_opt(theme),
        "TabScrollButton": Js.Nullable.from_opt(tTabScrollButton),
        "indicatorColor":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(IndicatorColor.to_string(e)))
              | x => unwrapValue(x),
              indicatorColor
            )
          ),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module List = {
  module Classes = {
    type classesType =
      | Root(string)
      | Padding(string)
      | Dense(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Padding(_) => "padding"
      | Dense(_) => "dense"
      | Subheader(_) => "subheader";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Padding(className)
               | Dense(className)
               | Subheader(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/List"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~subheader: option(ReasonReact.reactElement)=?,
        ~rootRef: option('a)=?,
        ~disablePadding: option(bool)=?,
        ~dense: option(bool)=?,
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "subheader": Js.Nullable.from_opt(subheader),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "disablePadding": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disablePadding)),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableRow = {
  module Classes = {
    type classesType =
      | Root(string)
      | Head(string)
      | Footer(string)
      | Hover(string)
      | Selected(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Head(_) => "head"
      | Footer(_) => "footer"
      | Hover(_) => "hover"
      | Selected(_) => "selected";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Head(className)
               | Footer(className)
               | Hover(className)
               | Selected(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableRow"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~selected: option(bool)=?,
        ~hover: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "hover": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hover)),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Radio = {
  module Classes = {
    type classesType =
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Default(_) => "default"
      | Checked(_) => "checked"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Default(className)
               | Checked(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Radio/Radio"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~value: option(string)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~name: option(string)=?,
        ~inputRef: option('a)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~disableRipple: option(bool)=?,
        ~disabledClassName: option(string)=?,
        ~disabled: option(bool)=?,
        ~defaultChecked: option(bool)=?,
        ~className: option(string)=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~checkedClassName: option(string)=?,
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "onChange": Js.Nullable.from_opt(onChange),
        "name": Js.Nullable.from_opt(name),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "icon": Js.Nullable.from_opt(icon),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "disabledClassName": Js.Nullable.from_opt(disabledClassName),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "defaultChecked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultChecked)),
        "className": Js.Nullable.from_opt(className),
        "checkedIcon": Js.Nullable.from_opt(checkedIcon),
        "checkedClassName": Js.Nullable.from_opt(checkedClassName),
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module SvgIcon = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/SvgIcon/SvgIcon"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~viewBox: option(string)=?,
        ~titleAccess: option(string)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "viewBox": Js.Nullable.from_opt(viewBox),
        "titleAccess": Js.Nullable.from_opt(titleAccess),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Table = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/Table"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormControlLabel = {
  module Classes = {
    type classesType =
      | Root(string)
      | Disabled(string)
      | Label(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Disabled(_) => "disabled"
      | Label(_) => "label";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Disabled(className)
               | Label(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormControlLabel"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~name: option(string)=?,
        ~label: ReasonReact.reactElement,
        ~inputRef: option('a)=?,
        ~disabled: option(bool)=?,
        ~control: ReasonReact.reactElement,
        ~className: option(string)=?,
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "onChange": Js.Nullable.from_opt(onChange),
        "name": Js.Nullable.from_opt(name),
        "label": label,
        "inputRef": Js.Nullable.from_opt(inputRef),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "control": control,
        "className": Js.Nullable.from_opt(className),
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module MuiThemeProvider = {
  [@bs.module "material-ui/styles/MuiThemeProvider"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~theme: 'a,
        ~sheetsManager: option(Js.t({..}))=?,
        ~disableStylesGeneration: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "theme": theme,
        "sheetsManager": Js.Nullable.from_opt(sheetsManager),
        "disableStylesGeneration": Js.Nullable.from_opt(disableStylesGeneration)
      },
      children
    );
};

module Button = {
  module Color = {
    type t =
      | Default
      | Inherit
      | Primary
      | Accent
      | Contrast;
    let to_string =
      fun
      | Default => "default"
      | Inherit => "inherit"
      | Primary => "primary"
      | Accent => "accent"
      | Contrast => "contrast";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Dense(string)
      | Label(string)
      | FlatPrimary(string)
      | FlatAccent(string)
      | FlatContrast(string)
      | ColorInherit(string)
      | Raised(string)
      | KeyboardFocused(string)
      | RaisedPrimary(string)
      | RaisedAccent(string)
      | RaisedContrast(string)
      | Disabled(string)
      | Fab(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Dense(_) => "dense"
      | Label(_) => "label"
      | FlatPrimary(_) => "flatPrimary"
      | FlatAccent(_) => "flatAccent"
      | FlatContrast(_) => "flatContrast"
      | ColorInherit(_) => "colorInherit"
      | Raised(_) => "raised"
      | KeyboardFocused(_) => "keyboardFocused"
      | RaisedPrimary(_) => "raisedPrimary"
      | RaisedAccent(_) => "raisedAccent"
      | RaisedContrast(_) => "raisedContrast"
      | Disabled(_) => "disabled"
      | Fab(_) => "fab";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Dense(className)
               | Label(className)
               | FlatPrimary(className)
               | FlatAccent(className)
               | FlatContrast(className)
               | ColorInherit(className)
               | Raised(className)
               | KeyboardFocused(className)
               | RaisedPrimary(className)
               | RaisedAccent(className)
               | RaisedContrast(className)
               | Disabled(className)
               | Fab(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Button/Button"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~href: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~type_: option(string)=?,
        ~disableRipple: option(bool)=?,
        ~raised: option(bool)=?,
        ~disableFocusRipple: option(bool)=?,
        ~fab: option(bool)=?,
        ~disabled: option(bool)=?,
        ~dense: option(bool)=?,
        ~color: option(Color.t)=?,
        ~classes: option(Classes.t)=?,
        ~centerRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~rootRef: option('a)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "href": Js.Nullable.from_opt(href),
        "component": Js.Nullable.from_opt(component),
        "className": Js.Nullable.from_opt(className),
        "type": Js.Nullable.from_opt(type_),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "disableFocusRipple":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableFocusRipple)),
        "fab": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fab)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex))
      },
      children
    );
};

module Menu = {
  module TransitionDuration = {
    type t =
      | Auto;
    let to_string =
      fun
      | Auto => "auto";
  };
  module Classes = {
    type classesType =
      | Paper(string);
    type t = list(classesType);
    let to_string =
      fun
      | Paper(_) => "paper";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Paper(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/Menu"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~transitionDuration:
           option(
             [
               | `Enum(TransitionDuration.t)
               | `Float(float)
               | `Object({. "enter": float, "exit": float})
             ]
           )=?,
        ~pPopoverClasses: option(Js.t({..}))=?,
        ~pPaperProps: option(Js.t({..}))=?,
        ~open_: option(bool)=?,
        ~onRequestClose: option(ReasonReact.Callback.t(ReactEventRe.Synthetic.t))=?,
        ~onExited: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~mMenuListProps: option(Js.t({..}))=?,
        ~anchorEl: option(Js.t({..}))=?,
        ~theme: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        ~anchorOrigin: option({. "horizontal": _, "vertical": _})=?,
        ~transformOrigin: option({. "horizontal": _, "vertical": _})=?,
        ~marginThreshold: option(float)=?,
        ~elevation: option(float)=?,
        ~getContentAnchorEl: option('a)=?,
        ~role: option(string)=?,
        ~transitionClasses:
           option(
             [
               | `String(string)
               | `Object(
                   {
                     .
                     "appear": string,
                     "appearActive": string,
                     "enter": string,
                     "enterActive": string,
                     "exit": string,
                     "exitActive": string
                   }
                 )
             ]
           )=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(TransitionDuration.to_string(e)))
              | x => unwrapValue(x),
              transitionDuration
            )
          ),
        "PopoverClasses": Js.Nullable.from_opt(pPopoverClasses),
        "PaperProps": Js.Nullable.from_opt(pPaperProps),
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "onRequestClose": Js.Nullable.from_opt(onRequestClose),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "MenuListProps": Js.Nullable.from_opt(mMenuListProps),
        "anchorEl": Js.Nullable.from_opt(anchorEl),
        "theme": Js.Nullable.from_opt(theme),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "anchorOrigin": Js.Nullable.from_opt(anchorOrigin),
        "transformOrigin": Js.Nullable.from_opt(transformOrigin),
        "marginThreshold": Js.Nullable.from_opt(marginThreshold),
        "elevation": Js.Nullable.from_opt(elevation),
        "getContentAnchorEl": Js.Nullable.from_opt(getContentAnchorEl),
        "role": Js.Nullable.from_opt(role),
        "transitionClasses": Js.Nullable.from_opt(optionMap(unwrapValue, transitionClasses))
      },
      children
    );
};

module TableFooter = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableFooter"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Grid = {
  module Xl = {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string =
      fun
      | V_1 => "1"
      | V_2 => "2"
      | V_3 => "3"
      | V_4 => "4"
      | V_5 => "5"
      | V_6 => "6"
      | V_7 => "7"
      | V_8 => "8"
      | V_9 => "9"
      | V_10 => "10"
      | V_11 => "11"
      | V_12 => "12";
  };
  module Lg = {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string =
      fun
      | V_1 => "1"
      | V_2 => "2"
      | V_3 => "3"
      | V_4 => "4"
      | V_5 => "5"
      | V_6 => "6"
      | V_7 => "7"
      | V_8 => "8"
      | V_9 => "9"
      | V_10 => "10"
      | V_11 => "11"
      | V_12 => "12";
  };
  module Md = {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string =
      fun
      | V_1 => "1"
      | V_2 => "2"
      | V_3 => "3"
      | V_4 => "4"
      | V_5 => "5"
      | V_6 => "6"
      | V_7 => "7"
      | V_8 => "8"
      | V_9 => "9"
      | V_10 => "10"
      | V_11 => "11"
      | V_12 => "12";
  };
  module Sm = {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string =
      fun
      | V_1 => "1"
      | V_2 => "2"
      | V_3 => "3"
      | V_4 => "4"
      | V_5 => "5"
      | V_6 => "6"
      | V_7 => "7"
      | V_8 => "8"
      | V_9 => "9"
      | V_10 => "10"
      | V_11 => "11"
      | V_12 => "12";
  };
  module Xs = {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string =
      fun
      | V_1 => "1"
      | V_2 => "2"
      | V_3 => "3"
      | V_4 => "4"
      | V_5 => "5"
      | V_6 => "6"
      | V_7 => "7"
      | V_8 => "8"
      | V_9 => "9"
      | V_10 => "10"
      | V_11 => "11"
      | V_12 => "12";
  };
  module Wrap = {
    type t =
      | Nowrap
      | Wrap
      | Wrap_reverse;
    let to_string =
      fun
      | Nowrap => "nowrap"
      | Wrap => "wrap"
      | Wrap_reverse => "wrap-reverse";
  };
  module Justify = {
    type t =
      | Flex_start
      | Center
      | Flex_end
      | Space_between
      | Space_around;
    let to_string =
      fun
      | Flex_start => "flex-start"
      | Center => "center"
      | Flex_end => "flex-end"
      | Space_between => "space-between"
      | Space_around => "space-around";
  };
  module Spacing = {
    type t =
      | V_0
      | V_8
      | V_16
      | V_24
      | V_40;
    let to_string =
      fun
      | V_0 => "0"
      | V_8 => "8"
      | V_16 => "16"
      | V_24 => "24"
      | V_40 => "40";
  };
  module Direction = {
    type t =
      | Row
      | Row_reverse
      | Column
      | Column_reverse;
    let to_string =
      fun
      | Row => "row"
      | Row_reverse => "row-reverse"
      | Column => "column"
      | Column_reverse => "column-reverse";
  };
  module AlignItems = {
    type t =
      | Flex_start
      | Center
      | Flex_end
      | Stretch
      | Baseline;
    let to_string =
      fun
      | Flex_start => "flex-start"
      | Center => "center"
      | Flex_end => "flex-end"
      | Stretch => "stretch"
      | Baseline => "baseline";
  };
  module AlignContent = {
    type t =
      | Stretch
      | Center
      | Flex_start
      | Flex_end
      | Space_between
      | Space_around;
    let to_string =
      fun
      | Stretch => "stretch"
      | Center => "center"
      | Flex_start => "flex-start"
      | Flex_end => "flex-end"
      | Space_between => "space-between"
      | Space_around => "space-around";
  };
  module Classes = {
    type classesType =
      | TypeContainer(string)
      | TypeItem(string)
      | Direction_xs_column(string)
      | Direction_xs_column_reverse(string)
      | Direction_xs_row_reverse(string)
      | Wrap_xs_nowrap(string)
      | Align_items_xs_center(string)
      | Align_items_xs_flex_start(string)
      | Align_items_xs_flex_end(string)
      | Align_items_xs_baseline(string)
      | Align_content_xs_center(string)
      | Align_content_xs_flex_start(string)
      | Align_content_xs_flex_end(string)
      | Align_content_xs_space_between(string)
      | Align_content_xs_space_around(string)
      | Justify_xs_center(string)
      | Justify_xs_flex_end(string)
      | Justify_xs_space_between(string)
      | Justify_xs_space_around(string)
      | Spacing_xs_8(string)
      | Spacing_xs_16(string)
      | Spacing_xs_24(string)
      | Spacing_xs_40(string)
      | Grid_xs(string)
      | Grid_xs_1(string)
      | Grid_xs_2(string)
      | Grid_xs_3(string)
      | Grid_xs_4(string)
      | Grid_xs_5(string)
      | Grid_xs_6(string)
      | Grid_xs_7(string)
      | Grid_xs_8(string)
      | Grid_xs_9(string)
      | Grid_xs_10(string)
      | Grid_xs_11(string)
      | Grid_xs_12(string);
    type t = list(classesType);
    let to_string =
      fun
      | TypeContainer(_) => "typeContainer"
      | TypeItem(_) => "typeItem"
      | Direction_xs_column(_) => "direction-xs-column"
      | Direction_xs_column_reverse(_) => "direction-xs-column-reverse"
      | Direction_xs_row_reverse(_) => "direction-xs-row-reverse"
      | Wrap_xs_nowrap(_) => "wrap-xs-nowrap"
      | Align_items_xs_center(_) => "align-items-xs-center"
      | Align_items_xs_flex_start(_) => "align-items-xs-flex-start"
      | Align_items_xs_flex_end(_) => "align-items-xs-flex-end"
      | Align_items_xs_baseline(_) => "align-items-xs-baseline"
      | Align_content_xs_center(_) => "align-content-xs-center"
      | Align_content_xs_flex_start(_) => "align-content-xs-flex-start"
      | Align_content_xs_flex_end(_) => "align-content-xs-flex-end"
      | Align_content_xs_space_between(_) => "align-content-xs-space-between"
      | Align_content_xs_space_around(_) => "align-content-xs-space-around"
      | Justify_xs_center(_) => "justify-xs-center"
      | Justify_xs_flex_end(_) => "justify-xs-flex-end"
      | Justify_xs_space_between(_) => "justify-xs-space-between"
      | Justify_xs_space_around(_) => "justify-xs-space-around"
      | Spacing_xs_8(_) => "spacing-xs-8"
      | Spacing_xs_16(_) => "spacing-xs-16"
      | Spacing_xs_24(_) => "spacing-xs-24"
      | Spacing_xs_40(_) => "spacing-xs-40"
      | Grid_xs(_) => "grid-xs"
      | Grid_xs_1(_) => "grid-xs-1"
      | Grid_xs_2(_) => "grid-xs-2"
      | Grid_xs_3(_) => "grid-xs-3"
      | Grid_xs_4(_) => "grid-xs-4"
      | Grid_xs_5(_) => "grid-xs-5"
      | Grid_xs_6(_) => "grid-xs-6"
      | Grid_xs_7(_) => "grid-xs-7"
      | Grid_xs_8(_) => "grid-xs-8"
      | Grid_xs_9(_) => "grid-xs-9"
      | Grid_xs_10(_) => "grid-xs-10"
      | Grid_xs_11(_) => "grid-xs-11"
      | Grid_xs_12(_) => "grid-xs-12";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | TypeContainer(className)
               | TypeItem(className)
               | Direction_xs_column(className)
               | Direction_xs_column_reverse(className)
               | Direction_xs_row_reverse(className)
               | Wrap_xs_nowrap(className)
               | Align_items_xs_center(className)
               | Align_items_xs_flex_start(className)
               | Align_items_xs_flex_end(className)
               | Align_items_xs_baseline(className)
               | Align_content_xs_center(className)
               | Align_content_xs_flex_start(className)
               | Align_content_xs_flex_end(className)
               | Align_content_xs_space_between(className)
               | Align_content_xs_space_around(className)
               | Justify_xs_center(className)
               | Justify_xs_flex_end(className)
               | Justify_xs_space_between(className)
               | Justify_xs_space_around(className)
               | Spacing_xs_8(className)
               | Spacing_xs_16(className)
               | Spacing_xs_24(className)
               | Spacing_xs_40(className)
               | Grid_xs(className)
               | Grid_xs_1(className)
               | Grid_xs_2(className)
               | Grid_xs_3(className)
               | Grid_xs_4(className)
               | Grid_xs_5(className)
               | Grid_xs_6(className)
               | Grid_xs_7(className)
               | Grid_xs_8(className)
               | Grid_xs_9(className)
               | Grid_xs_10(className)
               | Grid_xs_11(className)
               | Grid_xs_12(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Grid/Grid"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~xl: option([ | `Enum(Xl.t) | `Bool(bool)])=?,
        ~lg: option([ | `Enum(Lg.t) | `Bool(bool)])=?,
        ~md: option([ | `Enum(Md.t) | `Bool(bool)])=?,
        ~sm: option([ | `Enum(Sm.t) | `Bool(bool)])=?,
        ~xs: option([ | `Enum(Xs.t) | `Bool(bool)])=?,
        ~wrap: option(Wrap.t)=?,
        ~justify: option(Justify.t)=?,
        ~hidden: option(Js.t({..}))=?,
        ~spacing: option(Spacing.t)=?,
        ~direction: option(Direction.t)=?,
        ~alignItems: option(AlignItems.t)=?,
        ~alignContent: option(AlignContent.t)=?,
        ~item: option(bool)=?,
        ~container: option(bool)=?,
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "xl":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Xl.to_string(e)))
              | x => unwrapValue(x),
              xl
            )
          ),
        "lg":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Lg.to_string(e)))
              | x => unwrapValue(x),
              lg
            )
          ),
        "md":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Md.to_string(e)))
              | x => unwrapValue(x),
              md
            )
          ),
        "sm":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Sm.to_string(e)))
              | x => unwrapValue(x),
              sm
            )
          ),
        "xs":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Xs.to_string(e)))
              | x => unwrapValue(x),
              xs
            )
          ),
        "wrap": Js.Nullable.from_opt(optionMap(Wrap.to_string, wrap)),
        "justify": Js.Nullable.from_opt(optionMap(Justify.to_string, justify)),
        "hidden": Js.Nullable.from_opt(hidden),
        "spacing": Js.Nullable.from_opt(optionMap(Spacing.to_string, spacing)),
        "direction": Js.Nullable.from_opt(optionMap(Direction.to_string, direction)),
        "alignItems": Js.Nullable.from_opt(optionMap(AlignItems.to_string, alignItems)),
        "alignContent": Js.Nullable.from_opt(optionMap(AlignContent.to_string, alignContent)),
        "item": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, item)),
        "container": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, container)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Card = {
  module Classes = {
    type classesType =
      | Root(string)
      | Rounded(string)
      | Shadow0(string)
      | Shadow1(string)
      | Shadow2(string)
      | Shadow3(string)
      | Shadow4(string)
      | Shadow5(string)
      | Shadow6(string)
      | Shadow7(string)
      | Shadow8(string)
      | Shadow9(string)
      | Shadow10(string)
      | Shadow11(string)
      | Shadow12(string)
      | Shadow13(string)
      | Shadow14(string)
      | Shadow15(string)
      | Shadow16(string)
      | Shadow17(string)
      | Shadow18(string)
      | Shadow19(string)
      | Shadow20(string)
      | Shadow21(string)
      | Shadow22(string)
      | Shadow23(string)
      | Shadow24(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Rounded(_) => "rounded"
      | Shadow0(_) => "shadow0"
      | Shadow1(_) => "shadow1"
      | Shadow2(_) => "shadow2"
      | Shadow3(_) => "shadow3"
      | Shadow4(_) => "shadow4"
      | Shadow5(_) => "shadow5"
      | Shadow6(_) => "shadow6"
      | Shadow7(_) => "shadow7"
      | Shadow8(_) => "shadow8"
      | Shadow9(_) => "shadow9"
      | Shadow10(_) => "shadow10"
      | Shadow11(_) => "shadow11"
      | Shadow12(_) => "shadow12"
      | Shadow13(_) => "shadow13"
      | Shadow14(_) => "shadow14"
      | Shadow15(_) => "shadow15"
      | Shadow16(_) => "shadow16"
      | Shadow17(_) => "shadow17"
      | Shadow18(_) => "shadow18"
      | Shadow19(_) => "shadow19"
      | Shadow20(_) => "shadow20"
      | Shadow21(_) => "shadow21"
      | Shadow22(_) => "shadow22"
      | Shadow23(_) => "shadow23"
      | Shadow24(_) => "shadow24";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Rounded(className)
               | Shadow0(className)
               | Shadow1(className)
               | Shadow2(className)
               | Shadow3(className)
               | Shadow4(className)
               | Shadow5(className)
               | Shadow6(className)
               | Shadow7(className)
               | Shadow8(className)
               | Shadow9(className)
               | Shadow10(className)
               | Shadow11(className)
               | Shadow12(className)
               | Shadow13(className)
               | Shadow14(className)
               | Shadow15(className)
               | Shadow16(className)
               | Shadow17(className)
               | Shadow18(className)
               | Shadow19(className)
               | Shadow20(className)
               | Shadow21(className)
               | Shadow22(className)
               | Shadow23(className)
               | Shadow24(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/Card"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~raised: option(bool)=?,
        ~classes: option(Classes.t)=?,
        ~component: option(Js.t({..}))=?,
        ~elevation: option(float)=?,
        ~square: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "component": Js.Nullable.from_opt(component),
        "elevation": Js.Nullable.from_opt(elevation),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square))
      },
      children
    );
};

module ListItem = {
  module Classes = {
    type classesType =
      | Root(string)
      | Container(string)
      | KeyboardFocused(string)
      | Default(string)
      | Dense(string)
      | Disabled(string)
      | Divider(string)
      | Gutters(string)
      | Button(string)
      | SecondaryAction(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Container(_) => "container"
      | KeyboardFocused(_) => "keyboardFocused"
      | Default(_) => "default"
      | Dense(_) => "dense"
      | Disabled(_) => "disabled"
      | Divider(_) => "divider"
      | Gutters(_) => "gutters"
      | Button(_) => "button"
      | SecondaryAction(_) => "secondaryAction";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Container(className)
               | KeyboardFocused(className)
               | Default(className)
               | Dense(className)
               | Disabled(className)
               | Divider(className)
               | Gutters(className)
               | Button(className)
               | SecondaryAction(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItem"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~divider: option(bool)=?,
        ~disableGutters: option(bool)=?,
        ~disabled: option(bool)=?,
        ~dense: option(bool)=?,
        ~className: option(string)=?,
        ~button: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "divider": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, divider)),
        "disableGutters": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableGutters)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "className": Js.Nullable.from_opt(className),
        "button": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, button)),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module MenuList = {
  module Classes = {
    type classesType =
      | Root(string)
      | Padding(string)
      | Dense(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Padding(_) => "padding"
      | Dense(_) => "dense"
      | Subheader(_) => "subheader";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Padding(className)
               | Dense(className)
               | Subheader(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/MenuList"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~onKeyDown: option(((ReactEventRe.UI.t, string) => unit))=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~component: option(Js.t({..}))=?,
        ~dense: option(bool)=?,
        ~disablePadding: option(bool)=?,
        ~rootRef: option('a)=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "component": Js.Nullable.from_opt(component),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "disablePadding": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disablePadding)),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "subheader": Js.Nullable.from_opt(subheader)
      },
      children
    );
};

module CardContent = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardContent"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Icon = {
  module Color = {
    type t =
      | Inherit
      | Accent
      | Action
      | Contrast
      | Disabled
      | Error
      | Primary;
    let to_string =
      fun
      | Inherit => "inherit"
      | Accent => "accent"
      | Action => "action"
      | Contrast => "contrast"
      | Disabled => "disabled"
      | Error => "error"
      | Primary => "primary";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | ColorAccent(string)
      | ColorAction(string)
      | ColorContrast(string)
      | ColorDisabled(string)
      | ColorError(string)
      | ColorPrimary(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorAccent(_) => "colorAccent"
      | ColorAction(_) => "colorAction"
      | ColorContrast(_) => "colorContrast"
      | ColorDisabled(_) => "colorDisabled"
      | ColorError(_) => "colorError"
      | ColorPrimary(_) => "colorPrimary";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorAccent(className)
               | ColorAction(className)
               | ColorContrast(className)
               | ColorDisabled(className)
               | ColorError(className)
               | ColorPrimary(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Icon/Icon"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(Color.t)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Checkbox = {
  module Classes = {
    type classesType =
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Default(_) => "default"
      | Checked(_) => "checked"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Default(className)
               | Checked(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Checkbox/Checkbox"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: option(string)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~name: option(string)=?,
        ~inputRef: option('a)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~indeterminateIcon: option(ReasonReact.reactElement)=?,
        ~indeterminate: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~disableRipple: option(bool)=?,
        ~disabledClassName: option(string)=?,
        ~disabled: option(bool)=?,
        ~defaultChecked: option(bool)=?,
        ~className: option(string)=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~checkedClassName: option(string)=?,
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "onChange": Js.Nullable.from_opt(onChange),
        "name": Js.Nullable.from_opt(name),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "indeterminateIcon": Js.Nullable.from_opt(indeterminateIcon),
        "indeterminate": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, indeterminate)),
        "icon": Js.Nullable.from_opt(icon),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "disabledClassName": Js.Nullable.from_opt(disabledClassName),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "defaultChecked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultChecked)),
        "className": Js.Nullable.from_opt(className),
        "checkedIcon": Js.Nullable.from_opt(checkedIcon),
        "checkedClassName": Js.Nullable.from_opt(checkedClassName),
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Dialog = {
  module MaxWidth = {
    type t =
      | Xs
      | Sm
      | Md;
    let to_string =
      fun
      | Xs => "xs"
      | Sm => "sm"
      | Md => "md";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Paper(string)
      | PaperWidthXs(string)
      | PaperWidthSm(string)
      | PaperWidthMd(string)
      | FullWidth(string)
      | FullScreen(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Paper(_) => "paper"
      | PaperWidthXs(_) => "paperWidthXs"
      | PaperWidthSm(_) => "paperWidthSm"
      | PaperWidthMd(_) => "paperWidthMd"
      | FullWidth(_) => "fullWidth"
      | FullScreen(_) => "fullScreen";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Paper(className)
               | PaperWidthXs(className)
               | PaperWidthSm(className)
               | PaperWidthMd(className)
               | FullWidth(className)
               | FullScreen(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/Dialog"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~open_: option(bool)=?,
        ~onRequestClose: option(ReasonReact.Callback.t(ReactEventRe.Synthetic.t))=?,
        ~onExited: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEscapeKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onBackdropClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~fullWidth: option(bool)=?,
        ~maxWidth: option(MaxWidth.t)=?,
        ~transitionDuration: option(Js.t({..}))=?,
        ~ignoreEscapeKeyUp: option(bool)=?,
        ~ignoreBackdropClick: option(bool)=?,
        ~fullScreen: option(bool)=?,
        ~className: option(string)=?,
        ~transition: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "onRequestClose": Js.Nullable.from_opt(onRequestClose),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEscapeKeyUp": Js.Nullable.from_opt(onEscapeKeyUp),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onBackdropClick": Js.Nullable.from_opt(onBackdropClick),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "maxWidth": Js.Nullable.from_opt(optionMap(MaxWidth.to_string, maxWidth)),
        "transitionDuration": Js.Nullable.from_opt(transitionDuration),
        "ignoreEscapeKeyUp":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ignoreEscapeKeyUp)),
        "ignoreBackdropClick":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, ignoreBackdropClick)),
        "fullScreen": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullScreen)),
        "className": Js.Nullable.from_opt(className),
        "transition": Js.Nullable.from_opt(transition),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableSortLabel = {
  module Direction = {
    type t =
      | Asc
      | Desc;
    let to_string =
      fun
      | Asc => "asc"
      | Desc => "desc";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Active(string)
      | Icon(string)
      | Desc(string)
      | Asc(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Active(_) => "active"
      | Icon(_) => "icon"
      | Desc(_) => "desc"
      | Asc(_) => "asc";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Active(className)
               | Icon(className)
               | Desc(className)
               | Asc(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableSortLabel"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~direction: option(Direction.t)=?,
        ~classes: option(Classes.t)=?,
        ~active: option(bool)=?,
        ~centerRipple: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~rootRef: option('a)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~type_: string,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "direction": Js.Nullable.from_opt(optionMap(Direction.to_string, direction)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(component),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": type_
      },
      children
    );
};

module GridList = {
  module CellHeight = {
    type t =
      | Auto;
    let to_string =
      fun
      | Auto => "auto";
  };
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridList"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~style: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~cellHeight: option([ | `Enum(CellHeight.t) | `Float(float)])=?,
        ~spacing: option(float)=?,
        ~cols: option(float)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "style": Js.Nullable.from_opt(style),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "cellHeight":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(CellHeight.to_string(e)))
              | x => unwrapValue(x),
              cellHeight
            )
          ),
        "spacing": Js.Nullable.from_opt(spacing),
        "cols": Js.Nullable.from_opt(cols),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Paper = {
  module Classes = {
    type classesType =
      | Root(string)
      | Rounded(string)
      | Shadow0(string)
      | Shadow1(string)
      | Shadow2(string)
      | Shadow3(string)
      | Shadow4(string)
      | Shadow5(string)
      | Shadow6(string)
      | Shadow7(string)
      | Shadow8(string)
      | Shadow9(string)
      | Shadow10(string)
      | Shadow11(string)
      | Shadow12(string)
      | Shadow13(string)
      | Shadow14(string)
      | Shadow15(string)
      | Shadow16(string)
      | Shadow17(string)
      | Shadow18(string)
      | Shadow19(string)
      | Shadow20(string)
      | Shadow21(string)
      | Shadow22(string)
      | Shadow23(string)
      | Shadow24(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Rounded(_) => "rounded"
      | Shadow0(_) => "shadow0"
      | Shadow1(_) => "shadow1"
      | Shadow2(_) => "shadow2"
      | Shadow3(_) => "shadow3"
      | Shadow4(_) => "shadow4"
      | Shadow5(_) => "shadow5"
      | Shadow6(_) => "shadow6"
      | Shadow7(_) => "shadow7"
      | Shadow8(_) => "shadow8"
      | Shadow9(_) => "shadow9"
      | Shadow10(_) => "shadow10"
      | Shadow11(_) => "shadow11"
      | Shadow12(_) => "shadow12"
      | Shadow13(_) => "shadow13"
      | Shadow14(_) => "shadow14"
      | Shadow15(_) => "shadow15"
      | Shadow16(_) => "shadow16"
      | Shadow17(_) => "shadow17"
      | Shadow18(_) => "shadow18"
      | Shadow19(_) => "shadow19"
      | Shadow20(_) => "shadow20"
      | Shadow21(_) => "shadow21"
      | Shadow22(_) => "shadow22"
      | Shadow23(_) => "shadow23"
      | Shadow24(_) => "shadow24";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Rounded(className)
               | Shadow0(className)
               | Shadow1(className)
               | Shadow2(className)
               | Shadow3(className)
               | Shadow4(className)
               | Shadow5(className)
               | Shadow6(className)
               | Shadow7(className)
               | Shadow8(className)
               | Shadow9(className)
               | Shadow10(className)
               | Shadow11(className)
               | Shadow12(className)
               | Shadow13(className)
               | Shadow14(className)
               | Shadow15(className)
               | Shadow16(className)
               | Shadow17(className)
               | Shadow18(className)
               | Shadow19(className)
               | Shadow20(className)
               | Shadow21(className)
               | Shadow22(className)
               | Shadow23(className)
               | Shadow24(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Paper/Paper"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~square: option(bool)=?,
        ~elevation: option(float)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "elevation": Js.Nullable.from_opt(elevation),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormGroup = {
  module Classes = {
    type classesType =
      | Root(string)
      | Row(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Row(_) => "row";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Row(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormGroup"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (~row: option(bool)=?, ~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "row": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, row)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module CardHeader = {
  module Classes = {
    type classesType =
      | Root(string)
      | Avatar(string)
      | Content(string)
      | Title(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Avatar(_) => "avatar"
      | Content(_) => "content"
      | Title(_) => "title"
      | Subheader(_) => "subheader";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Avatar(className)
               | Content(className)
               | Title(className)
               | Subheader(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardHeader"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~title: option(ReasonReact.reactElement)=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~avatar: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "title": Js.Nullable.from_opt(title),
        "subheader": Js.Nullable.from_opt(subheader),
        "className": Js.Nullable.from_opt(className),
        "avatar": Js.Nullable.from_opt(avatar),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Toolbar = {
  module Classes = {
    type classesType =
      | Root(string)
      | Gutters(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Gutters(_) => "gutters";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Gutters(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Toolbar/Toolbar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~disableGutters: option(bool)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "disableGutters": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableGutters)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module ListItemText = {
  module Classes = {
    type classesType =
      | Root(string)
      | Inset(string)
      | Dense(string)
      | Text(string)
      | TextDense(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Inset(_) => "inset"
      | Dense(_) => "dense"
      | Text(_) => "text"
      | TextDense(_) => "textDense";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Inset(className)
               | Dense(className)
               | Text(className)
               | TextDense(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemText"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~secondary: option(ReasonReact.reactElement)=?,
        ~primary: option(ReasonReact.reactElement)=?,
        ~inset: option(bool)=?,
        ~disableTypography: option(bool)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "secondary": Js.Nullable.from_opt(secondary),
        "primary": Js.Nullable.from_opt(primary),
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "disableTypography":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTypography)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module CardActions = {
  module Classes = {
    type classesType =
      | Root(string)
      | ActionSpacing(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ActionSpacing(_) => "actionSpacing";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ActionSpacing(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardActions"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableActionSpacing: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableActionSpacing":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableActionSpacing)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Divider = {
  module Classes = {
    type classesType =
      | Root(string)
      | Default(string)
      | Inset(string)
      | Light(string)
      | Absolute(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Default(_) => "default"
      | Inset(_) => "inset"
      | Light(_) => "light"
      | Absolute(_) => "absolute";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Default(className)
               | Inset(className)
               | Light(className)
               | Absolute(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Divider/Divider"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~light: option(bool)=?,
        ~inset: option(bool)=?,
        ~className: option(string)=?,
        ~absolute: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "light": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, light)),
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "className": Js.Nullable.from_opt(className),
        "absolute": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, absolute)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Collapse = {
  module Timeout = {
    type t =
      | Auto;
    let to_string =
      fun
      | Auto => "auto";
  };
  module Classes = {
    type classesType =
      | Container(string)
      | Entered(string)
      | Wrapper(string)
      | WrapperInner(string);
    type t = list(classesType);
    let to_string =
      fun
      | Container(_) => "container"
      | Entered(_) => "entered"
      | Wrapper(_) => "wrapper"
      | WrapperInner(_) => "wrapperInner";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Container(className)
               | Entered(className)
               | Wrapper(className)
               | WrapperInner(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/transitions/Collapse"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~style: option(Js.t({..}))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~in_: bool,
        ~theme: option(Js.t({..}))=?,
        ~timeout:
           option(
             [ | `Enum(Timeout.t) | `Float(float) | `Object({. "enter": float, "exit": float})]
           )=?,
        ~collapsedHeight: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~appear: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "style": Js.Nullable.from_opt(style),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "in": Js.Boolean.to_js_boolean(in_),
        "theme": Js.Nullable.from_opt(theme),
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Timeout.to_string(e)))
              | x => unwrapValue(x),
              timeout
            )
          ),
        "collapsedHeight": Js.Nullable.from_opt(collapsedHeight),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear))
      },
      children
    );
};

module ClickAwayListener = {
  [@bs.module "material-ui/utils/ClickAwayListener"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~onClickAway: ReactEventRe.Synthetic.t => unit, children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props={"onClickAway": onClickAway}, children);
};

module Typography = {
  module Color = {
    type t =
      | Inherit
      | Primary
      | Secondary
      | Accent
      | Error
      | Default;
    let to_string =
      fun
      | Inherit => "inherit"
      | Primary => "primary"
      | Secondary => "secondary"
      | Accent => "accent"
      | Error => "error"
      | Default => "default";
  };
  module Align = {
    type t =
      | Inherit
      | Left
      | Center
      | Right
      | Justify;
    let to_string =
      fun
      | Inherit => "inherit"
      | Left => "left"
      | Center => "center"
      | Right => "right"
      | Justify => "justify";
  };
  module Type = {
    type t =
      | Display4
      | Display3
      | Display2
      | Display1
      | Headline
      | Title
      | Subheading
      | Body2
      | Body1
      | Caption
      | Button;
    let to_string =
      fun
      | Display4 => "display4"
      | Display3 => "display3"
      | Display2 => "display2"
      | Display1 => "display1"
      | Headline => "headline"
      | Title => "title"
      | Subheading => "subheading"
      | Body2 => "body2"
      | Body1 => "body1"
      | Caption => "caption"
      | Button => "button";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Display4(string)
      | Display3(string)
      | Display2(string)
      | Display1(string)
      | Headline(string)
      | Title(string)
      | Subheading(string)
      | Body2(string)
      | Body1(string)
      | Caption(string)
      | Button(string)
      | AlignLeft(string)
      | AlignCenter(string)
      | AlignRight(string)
      | AlignJustify(string)
      | NoWrap(string)
      | GutterBottom(string)
      | Paragraph(string)
      | ColorInherit(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | ColorAccent(string)
      | ColorError(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Display4(_) => "display4"
      | Display3(_) => "display3"
      | Display2(_) => "display2"
      | Display1(_) => "display1"
      | Headline(_) => "headline"
      | Title(_) => "title"
      | Subheading(_) => "subheading"
      | Body2(_) => "body2"
      | Body1(_) => "body1"
      | Caption(_) => "caption"
      | Button(_) => "button"
      | AlignLeft(_) => "alignLeft"
      | AlignCenter(_) => "alignCenter"
      | AlignRight(_) => "alignRight"
      | AlignJustify(_) => "alignJustify"
      | NoWrap(_) => "noWrap"
      | GutterBottom(_) => "gutterBottom"
      | Paragraph(_) => "paragraph"
      | ColorInherit(_) => "colorInherit"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorAccent(_) => "colorAccent"
      | ColorError(_) => "colorError";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Display4(className)
               | Display3(className)
               | Display2(className)
               | Display1(className)
               | Headline(className)
               | Title(className)
               | Subheading(className)
               | Body2(className)
               | Body1(className)
               | Caption(className)
               | Button(className)
               | AlignLeft(className)
               | AlignCenter(className)
               | AlignRight(className)
               | AlignJustify(className)
               | NoWrap(className)
               | GutterBottom(className)
               | Paragraph(className)
               | ColorInherit(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | ColorAccent(className)
               | ColorError(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Typography/Typography"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~paragraph: option(bool)=?,
        ~noWrap: option(bool)=?,
        ~gutterBottom: option(bool)=?,
        ~color: option(Color.t)=?,
        ~component: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~align: option(Align.t)=?,
        ~type_: option(Type.t)=?,
        ~headlineMapping: option({. "unionProp": string})=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "paragraph": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, paragraph)),
        "noWrap": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, noWrap)),
        "gutterBottom": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, gutterBottom)),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "component": Js.Nullable.from_opt(component),
        "className": Js.Nullable.from_opt(className),
        "align": Js.Nullable.from_opt(optionMap(Align.to_string, align)),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, type_)),
        "headlineMapping": Js.Nullable.from_opt(headlineMapping),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module LinearProgress = {
  module Mode = {
    type t =
      | Determinate
      | Indeterminate
      | Buffer
      | Query;
    let to_string =
      fun
      | Determinate => "determinate"
      | Indeterminate => "indeterminate"
      | Buffer => "buffer"
      | Query => "query";
  };
  module Color = {
    type t =
      | Primary
      | Accent;
    let to_string =
      fun
      | Primary => "primary"
      | Accent => "accent";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | PrimaryColor(string)
      | PrimaryColorBar(string)
      | PrimaryDashed(string)
      | AccentColor(string)
      | AccentColorBar(string)
      | AccentDashed(string)
      | Bar(string)
      | Dashed(string)
      | BufferBar2(string)
      | RootBuffer(string)
      | RootQuery(string)
      | IndeterminateBar1(string)
      | IndeterminateBar2(string)
      | DeterminateBar1(string)
      | BufferBar1(string)
      | BufferBar2Primary(string)
      | BufferBar2Accent(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PrimaryColor(_) => "primaryColor"
      | PrimaryColorBar(_) => "primaryColorBar"
      | PrimaryDashed(_) => "primaryDashed"
      | AccentColor(_) => "accentColor"
      | AccentColorBar(_) => "accentColorBar"
      | AccentDashed(_) => "accentDashed"
      | Bar(_) => "bar"
      | Dashed(_) => "dashed"
      | BufferBar2(_) => "bufferBar2"
      | RootBuffer(_) => "rootBuffer"
      | RootQuery(_) => "rootQuery"
      | IndeterminateBar1(_) => "indeterminateBar1"
      | IndeterminateBar2(_) => "indeterminateBar2"
      | DeterminateBar1(_) => "determinateBar1"
      | BufferBar1(_) => "bufferBar1"
      | BufferBar2Primary(_) => "bufferBar2Primary"
      | BufferBar2Accent(_) => "bufferBar2Accent";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PrimaryColor(className)
               | PrimaryColorBar(className)
               | PrimaryDashed(className)
               | AccentColor(className)
               | AccentColorBar(className)
               | AccentDashed(className)
               | Bar(className)
               | Dashed(className)
               | BufferBar2(className)
               | RootBuffer(className)
               | RootQuery(className)
               | IndeterminateBar1(className)
               | IndeterminateBar2(className)
               | DeterminateBar1(className)
               | BufferBar1(className)
               | BufferBar2Primary(className)
               | BufferBar2Accent(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Progress/LinearProgress"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~valueBuffer: option(float)=?,
        ~value: option(float)=?,
        ~mode: option(Mode.t)=?,
        ~color: option(Color.t)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "valueBuffer": Js.Nullable.from_opt(valueBuffer),
        "value": Js.Nullable.from_opt(value),
        "mode": Js.Nullable.from_opt(optionMap(Mode.to_string, mode)),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormLabel = {
  module Classes = {
    type classesType =
      | Root(string)
      | Focused(string)
      | Error(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Focused(_) => "focused"
      | Error(_) => "error"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Focused(className)
               | Error(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormLabel"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~required: option(bool)=?,
        ~focused: option(bool)=?,
        ~error: option(bool)=?,
        ~disabled: option(bool)=?,
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "focused": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focused)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormHelperText = {
  module Classes = {
    type classesType =
      | Root(string)
      | Dense(string)
      | Error(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Dense(_) => "dense"
      | Error(_) => "error"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Dense(className)
               | Error(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormHelperText"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~margin: option(Js.t({..}))=?,
        ~error: option(bool)=?,
        ~disabled: option(bool)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "margin": Js.Nullable.from_opt(margin),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TablePagination = {
  module Padding = {
    type t =
      | Default
      | Checkbox
      | Dense
      | None;
    let to_string =
      fun
      | Default => "default"
      | Checkbox => "checkbox"
      | Dense => "dense"
      | None => "none";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Toolbar(string)
      | Spacer(string)
      | Caption(string)
      | Input(string)
      | SelectRoot(string)
      | Select(string)
      | Actions(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Toolbar(_) => "toolbar"
      | Spacer(_) => "spacer"
      | Caption(_) => "caption"
      | Input(_) => "input"
      | SelectRoot(_) => "selectRoot"
      | Select(_) => "select"
      | Actions(_) => "actions";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Toolbar(className)
               | Spacer(className)
               | Caption(className)
               | Input(className)
               | SelectRoot(className)
               | Select(className)
               | Actions(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TablePagination"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~rowsPerPage: float,
        ~page: float,
        ~onChangeRowsPerPage: ReactEventRe.Form.t => unit,
        ~onChangePage: (_, float) => unit,
        ~count: float,
        ~colSpan: option(float)=?,
        ~theme: option(Js.t({..}))=?,
        ~rowsPerPageOptions: option(Js.t({..}))=?,
        ~labelDisplayedRows:
           option(
             (
               {. "from": float, "to": float, "count": float, "page": float} =>
               ReasonReact.reactElement
             )
           )=?,
        ~labelRowsPerPage: option(ReasonReact.reactElement)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        ~padding: option(Padding.t)=?,
        ~numeric: option(bool)=?,
        ~className: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "rowsPerPage": rowsPerPage,
        "page": page,
        "onChangeRowsPerPage": onChangeRowsPerPage,
        "onChangePage": onChangePage,
        "count": count,
        "colSpan": Js.Nullable.from_opt(colSpan),
        "theme": Js.Nullable.from_opt(theme),
        "rowsPerPageOptions": Js.Nullable.from_opt(rowsPerPageOptions),
        "labelDisplayedRows": Js.Nullable.from_opt(labelDisplayedRows),
        "labelRowsPerPage": Js.Nullable.from_opt(labelRowsPerPage),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "padding": Js.Nullable.from_opt(optionMap(Padding.to_string, padding)),
        "numeric": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, numeric)),
        "className": Js.Nullable.from_opt(className)
      },
      children
    );
};

module Chip = {
  module Classes = {
    type classesType =
      | Root(string)
      | Clickable(string)
      | Deletable(string)
      | Avatar(string)
      | AvatarChildren(string)
      | Label(string)
      | DeleteIcon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Clickable(_) => "clickable"
      | Deletable(_) => "deletable"
      | Avatar(_) => "avatar"
      | AvatarChildren(_) => "avatarChildren"
      | Label(_) => "label"
      | DeleteIcon(_) => "deleteIcon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Clickable(className)
               | Deletable(className)
               | Avatar(className)
               | AvatarChildren(className)
               | Label(className)
               | DeleteIcon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Chip/Chip"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~onRequestDelete: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~deleteIcon: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~avatar: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "onRequestDelete": Js.Nullable.from_opt(onRequestDelete),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onClick": Js.Nullable.from_opt(onClick),
        "label": Js.Nullable.from_opt(label),
        "deleteIcon": Js.Nullable.from_opt(deleteIcon),
        "className": Js.Nullable.from_opt(className),
        "avatar": Js.Nullable.from_opt(avatar),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module RadioGroup = {
  module Classes = {
    type classesType =
      | Root(string)
      | Row(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Row(_) => "row";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Row(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Radio/RadioGroup"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: option(string)=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~name: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~className: option(string)=?,
        ~row: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onChange": Js.Nullable.from_opt(onChange),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "name": Js.Nullable.from_opt(name),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "className": Js.Nullable.from_opt(className),
        "row": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, row))
      },
      children
    );
};

module TableCell = {
  module Padding = {
    type t =
      | Default
      | Checkbox
      | Dense
      | None;
    let to_string =
      fun
      | Default => "default"
      | Checkbox => "checkbox"
      | Dense => "dense"
      | None => "none";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Numeric(string)
      | Head(string)
      | PaddingDefault(string)
      | PaddingDense(string)
      | PaddingCheckbox(string)
      | Footer(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Numeric(_) => "numeric"
      | Head(_) => "head"
      | PaddingDefault(_) => "paddingDefault"
      | PaddingDense(_) => "paddingDense"
      | PaddingCheckbox(_) => "paddingCheckbox"
      | Footer(_) => "footer";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Numeric(className)
               | Head(className)
               | PaddingDefault(className)
               | PaddingDense(className)
               | PaddingCheckbox(className)
               | Footer(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableCell"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~component: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~numeric: option(bool)=?,
        ~padding: option(Padding.t)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "component": Js.Nullable.from_opt(component),
        "className": Js.Nullable.from_opt(className),
        "numeric": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, numeric)),
        "padding": Js.Nullable.from_opt(optionMap(Padding.to_string, padding)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Input = {
  module Margin = {
    type t =
      | Dense
      | None;
    let to_string =
      fun
      | Dense => "dense"
      | None => "none";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | FormControl(string)
      | Inkbar(string)
      | Error(string)
      | Input(string)
      | InputDense(string)
      | Disabled(string)
      | Focused(string)
      | Underline(string)
      | Multiline(string)
      | InputDisabled(string)
      | InputSingleline(string)
      | InputSearch(string)
      | InputMultiline(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FormControl(_) => "formControl"
      | Inkbar(_) => "inkbar"
      | Error(_) => "error"
      | Input(_) => "input"
      | InputDense(_) => "inputDense"
      | Disabled(_) => "disabled"
      | Focused(_) => "focused"
      | Underline(_) => "underline"
      | Multiline(_) => "multiline"
      | InputDisabled(_) => "inputDisabled"
      | InputSingleline(_) => "inputSingleline"
      | InputSearch(_) => "inputSearch"
      | InputMultiline(_) => "inputMultiline"
      | FullWidth(_) => "fullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FormControl(className)
               | Inkbar(className)
               | Error(className)
               | Input(className)
               | InputDense(className)
               | Disabled(className)
               | Focused(className)
               | Underline(className)
               | Multiline(className)
               | InputDisabled(className)
               | InputSingleline(className)
               | InputSearch(className)
               | InputMultiline(className)
               | FullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/Input"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~value: option([ | `String(string) | `Float(float) | `Object(Js.t({..}))])=?,
        ~startAdornment: option(ReasonReact.reactElement)=?,
        ~rowsMax: option([ | `String(string) | `Float(float)])=?,
        ~rows: option([ | `String(string) | `Float(float)])=?,
        ~placeholder: option(string)=?,
        ~onKeyUp: option((ReactEventRe.Keyboard.t => unit))=?,
        ~onKeyDown: option((ReactEventRe.Keyboard.t => unit))=?,
        ~onFocus: option((ReactEventRe.Focus.t => unit))=?,
        ~onDirty: option(unit)=?,
        ~onClean: option(unit)=?,
        ~onChange: option((ReactEventRe.Form.t => unit))=?,
        ~onBlur: option((ReactEventRe.Focus.t => unit))=?,
        ~readOnly: option(bool)=?,
        ~name: option(string)=?,
        ~margin: option(Margin.t)=?,
        ~inputRef: option('a)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputComponent: option([ | `String(string) | `Object(Js.t({..}))])=?,
        ~id: option(string)=?,
        ~error: option(bool)=?,
        ~endAdornment: option(ReasonReact.reactElement)=?,
        ~disabled: option(bool)=?,
        ~defaultValue: option([ | `String(string) | `Float(float)])=?,
        ~className: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~autoComplete: option(string)=?,
        ~type_: option(string)=?,
        ~multiline: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~disableUnderline: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "startAdornment": Js.Nullable.from_opt(startAdornment),
        "rowsMax": Js.Nullable.from_opt(optionMap(unwrapValue, rowsMax)),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "placeholder": Js.Nullable.from_opt(placeholder),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onDirty": Js.Nullable.from_opt(onDirty),
        "onClean": Js.Nullable.from_opt(onClean),
        "onChange": Js.Nullable.from_opt(onChange),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "readOnly": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, readOnly)),
        "name": Js.Nullable.from_opt(name),
        "margin": Js.Nullable.from_opt(optionMap(Margin.to_string, margin)),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputComponent": Js.Nullable.from_opt(optionMap(unwrapValue, inputComponent)),
        "id": Js.Nullable.from_opt(id),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "endAdornment": Js.Nullable.from_opt(endAdornment),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "defaultValue": Js.Nullable.from_opt(optionMap(unwrapValue, defaultValue)),
        "className": Js.Nullable.from_opt(className),
        "autoFocus": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoFocus)),
        "autoComplete": Js.Nullable.from_opt(autoComplete),
        "type": Js.Nullable.from_opt(type_),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "disableUnderline":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableUnderline)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Tooltip = {
  module Placement = {
    type t =
      | Bottom_end
      | Bottom_start
      | Bottom
      | Left_end
      | Left_start
      | Left
      | Right_end
      | Right_start
      | Right
      | Top_end
      | Top_start
      | Top;
    let to_string =
      fun
      | Bottom_end => "bottom-end"
      | Bottom_start => "bottom-start"
      | Bottom => "bottom"
      | Left_end => "left-end"
      | Left_start => "left-start"
      | Left => "left"
      | Right_end => "right-end"
      | Right_start => "right-start"
      | Right => "right"
      | Top_end => "top-end"
      | Top_start => "top-start"
      | Top => "top";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Popper(string)
      | PopperClose(string)
      | Tooltip(string)
      | TooltipLeft(string)
      | TooltipRight(string)
      | TooltipTop(string)
      | TooltipBottom(string)
      | TooltipOpen(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Popper(_) => "popper"
      | PopperClose(_) => "popperClose"
      | Tooltip(_) => "tooltip"
      | TooltipLeft(_) => "tooltipLeft"
      | TooltipRight(_) => "tooltipRight"
      | TooltipTop(_) => "tooltipTop"
      | TooltipBottom(_) => "tooltipBottom"
      | TooltipOpen(_) => "tooltipOpen";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Popper(className)
               | PopperClose(className)
               | Tooltip(className)
               | TooltipLeft(className)
               | TooltipRight(className)
               | TooltipTop(className)
               | TooltipBottom(className)
               | TooltipOpen(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tooltip/Tooltip"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~pPopperProps: option(Js.t({..}))=?,
        ~title: ReasonReact.reactElement,
        ~open_: option(bool)=?,
        ~onRequestOpen: option(ReasonReact.Callback.t(ReactEventRe.Synthetic.t))=?,
        ~onRequestClose: option(ReasonReact.Callback.t(ReactEventRe.Synthetic.t))=?,
        ~id: option(string)=?,
        ~className: option(string)=?,
        ~theme: option(Js.t({..}))=?,
        ~placement: option(Placement.t)=?,
        ~leaveDelay: option(float)=?,
        ~enterDelay: option(float)=?,
        ~disableTriggerTouch: option(bool)=?,
        ~disableTriggerHover: option(bool)=?,
        ~disableTriggerFocus: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "PopperProps": Js.Nullable.from_opt(pPopperProps),
        "title": title,
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "onRequestOpen": Js.Nullable.from_opt(onRequestOpen),
        "onRequestClose": Js.Nullable.from_opt(onRequestClose),
        "id": Js.Nullable.from_opt(id),
        "className": Js.Nullable.from_opt(className),
        "theme": Js.Nullable.from_opt(theme),
        "placement": Js.Nullable.from_opt(optionMap(Placement.to_string, placement)),
        "leaveDelay": Js.Nullable.from_opt(leaveDelay),
        "enterDelay": Js.Nullable.from_opt(enterDelay),
        "disableTriggerTouch":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTriggerTouch)),
        "disableTriggerHover":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTriggerHover)),
        "disableTriggerFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTriggerFocus)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module AppBar = {
  module Position = {
    type t =
      | Static
      | Fixed
      | Absolute;
    let to_string =
      fun
      | Static => "static"
      | Fixed => "fixed"
      | Absolute => "absolute";
  };
  module Color = {
    type t =
      | Inherit
      | Primary
      | Accent
      | Default;
    let to_string =
      fun
      | Inherit => "inherit"
      | Primary => "primary"
      | Accent => "accent"
      | Default => "default";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | PositionFixed(string)
      | PositionAbsolute(string)
      | PositionStatic(string)
      | ColorDefault(string)
      | ColorPrimary(string)
      | ColorAccent(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PositionFixed(_) => "positionFixed"
      | PositionAbsolute(_) => "positionAbsolute"
      | PositionStatic(_) => "positionStatic"
      | ColorDefault(_) => "colorDefault"
      | ColorPrimary(_) => "colorPrimary"
      | ColorAccent(_) => "colorAccent";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PositionFixed(className)
               | PositionAbsolute(className)
               | PositionStatic(className)
               | ColorDefault(className)
               | ColorPrimary(className)
               | ColorAccent(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/AppBar/AppBar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~position: option(Position.t)=?,
        ~color: option(Color.t)=?,
        ~classes: option(Classes.t)=?,
        ~component: option(Js.t({..}))=?,
        ~elevation: option(float)=?,
        ~square: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "position": Js.Nullable.from_opt(optionMap(Position.to_string, position)),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "component": Js.Nullable.from_opt(component),
        "elevation": Js.Nullable.from_opt(elevation),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square))
      },
      children
    );
};

module MobileStepper = {
  module Type = {
    type t =
      | Text
      | Dots
      | Progress;
    let to_string =
      fun
      | Text => "text"
      | Dots => "dots"
      | Progress => "progress";
  };
  module Position = {
    type t =
      | Bottom
      | Top
      | Static;
    let to_string =
      fun
      | Bottom => "bottom"
      | Top => "top"
      | Static => "static";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | PositionBottom(string)
      | PositionTop(string)
      | PositionStatic(string)
      | Dots(string)
      | Dot(string)
      | DotActive(string)
      | Progress(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PositionBottom(_) => "positionBottom"
      | PositionTop(_) => "positionTop"
      | PositionStatic(_) => "positionStatic"
      | Dots(_) => "dots"
      | Dot(_) => "dot"
      | DotActive(_) => "dotActive"
      | Progress(_) => "progress";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PositionBottom(className)
               | PositionTop(className)
               | PositionStatic(className)
               | Dots(className)
               | Dot(className)
               | DotActive(className)
               | Progress(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/MobileStepper/MobileStepper"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~steps: float,
        ~nextButton: ReasonReact.reactElement,
        ~className: option(string)=?,
        ~backButton: ReasonReact.reactElement,
        ~type_: option(Type.t)=?,
        ~position: option(Position.t)=?,
        ~classes: option(Classes.t)=?,
        ~activeStep: option(float)=?,
        ~component: option(Js.t({..}))=?,
        ~elevation: option(float)=?,
        ~square: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "steps": steps,
        "nextButton": nextButton,
        "className": Js.Nullable.from_opt(className),
        "backButton": backButton,
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, type_)),
        "position": Js.Nullable.from_opt(optionMap(Position.to_string, position)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "activeStep": Js.Nullable.from_opt(activeStep),
        "component": Js.Nullable.from_opt(component),
        "elevation": Js.Nullable.from_opt(elevation),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square))
      },
      children
    );
};

module InputLabel = {
  module Classes = {
    type classesType =
      | Root(string)
      | FormControl(string)
      | LabelDense(string)
      | Shrink(string)
      | Animated(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FormControl(_) => "formControl"
      | LabelDense(_) => "labelDense"
      | Shrink(_) => "shrink"
      | Animated(_) => "animated"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FormControl(className)
               | LabelDense(className)
               | Shrink(className)
               | Animated(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/InputLabel"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~shrink: option(bool)=?,
        ~required: option(bool)=?,
        ~margin: option(Js.t({..}))=?,
        ~focused: option(bool)=?,
        ~fFormControlClasses: option(Js.t({..}))=?,
        ~error: option(bool)=?,
        ~className: option(string)=?,
        ~disableAnimation: option(bool)=?,
        ~disabled: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "shrink": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, shrink)),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "margin": Js.Nullable.from_opt(margin),
        "focused": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focused)),
        "FormControlClasses": Js.Nullable.from_opt(fFormControlClasses),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "className": Js.Nullable.from_opt(className),
        "disableAnimation":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAnimation)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormControl = {
  module Margin = {
    type t =
      | None
      | Dense
      | Normal;
    let to_string =
      fun
      | None => "none"
      | Dense => "dense"
      | Normal => "normal";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | MarginNormal(string)
      | MarginDense(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | MarginNormal(_) => "marginNormal"
      | MarginDense(_) => "marginDense"
      | FullWidth(_) => "fullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | MarginNormal(className)
               | MarginDense(className)
               | FullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormControl"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~className: option(string)=?,
        ~required: option(bool)=?,
        ~margin: option(Margin.t)=?,
        ~fullWidth: option(bool)=?,
        ~error: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        ~disabled: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "className": Js.Nullable.from_opt(className),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "margin": Js.Nullable.from_opt(optionMap(Margin.to_string, margin)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled))
      },
      children
    );
};

module MenuItem = {
  module Classes = {
    type classesType =
      | Root(string)
      | Selected(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Selected(_) => "selected";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Selected(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/MenuItem"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~component: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~selected: option(bool)=?,
        ~role: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~button: option(bool)=?,
        ~dense: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableGutters: option(bool)=?,
        ~divider: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "component": Js.Nullable.from_opt(component),
        "className": Js.Nullable.from_opt(className),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "role": Js.Nullable.from_opt(role),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "button": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, button)),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableGutters": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableGutters)),
        "divider": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, divider))
      },
      children
    );
};

module BottomNavigationButton = {
  module Classes = {
    type classesType =
      | Root(string)
      | Selected(string)
      | SelectedIconOnly(string)
      | Wrapper(string)
      | Label(string)
      | SelectedLabel(string)
      | HiddenLabel(string)
      | Icon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Selected(_) => "selected"
      | SelectedIconOnly(_) => "selectedIconOnly"
      | Wrapper(_) => "wrapper"
      | Label(_) => "label"
      | SelectedLabel(_) => "selectedLabel"
      | HiddenLabel(_) => "hiddenLabel"
      | Icon(_) => "icon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Selected(className)
               | SelectedIconOnly(className)
               | Wrapper(className)
               | Label(className)
               | SelectedLabel(className)
               | HiddenLabel(className)
               | Icon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigationButton"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: option('a)=?,
        ~showLabel: option(bool)=?,
        ~selected: option(bool)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~icon: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~centerRipple: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~rootRef: option('b)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~type_: string,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "showLabel": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, showLabel)),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onChange": Js.Nullable.from_opt(onChange),
        "label": Js.Nullable.from_opt(label),
        "icon": Js.Nullable.from_opt(optionMap(unwrapValue, icon)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(component),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": type_
      },
      children
    );
};

module GridListTile = {
  module Classes = {
    type classesType =
      | Root(string)
      | Tile(string)
      | ImgFullHeight(string)
      | ImgFullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Tile(_) => "tile"
      | ImgFullHeight(_) => "imgFullHeight"
      | ImgFullWidth(_) => "imgFullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Tile(className)
               | ImgFullHeight(className)
               | ImgFullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridListTile"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~rows: option(float)=?,
        ~component: option(Js.t({..}))=?,
        ~cols: option(float)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "rows": Js.Nullable.from_opt(rows),
        "component": Js.Nullable.from_opt(component),
        "cols": Js.Nullable.from_opt(cols),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Hidden = {
  module Implementation = {
    type t =
      | Js
      | Css;
    let to_string =
      fun
      | Js => "js"
      | Css => "css";
  };
  [@bs.module "material-ui/Hidden/Hidden"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~initialWidth: option(float)=?,
        ~implementation: option(Implementation.t)=?,
        ~xlDown: option(bool)=?,
        ~lgDown: option(bool)=?,
        ~mdDown: option(bool)=?,
        ~smDown: option(bool)=?,
        ~xsDown: option(bool)=?,
        ~xlUp: option(bool)=?,
        ~lgUp: option(bool)=?,
        ~mdUp: option(bool)=?,
        ~smUp: option(bool)=?,
        ~xsUp: option(bool)=?,
        ~only: option([ | `Object(Js.t({..})) | `Object(Js.t({..}))])=?,
        ~className: option(string)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "initialWidth": Js.Nullable.from_opt(initialWidth),
        "implementation": Js.Nullable.from_opt(optionMap(Implementation.to_string, implementation)),
        "xlDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xlDown)),
        "lgDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, lgDown)),
        "mdDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mdDown)),
        "smDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, smDown)),
        "xsDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xsDown)),
        "xlUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xlUp)),
        "lgUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, lgUp)),
        "mdUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mdUp)),
        "smUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, smUp)),
        "xsUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xsUp)),
        "only": Js.Nullable.from_opt(optionMap(unwrapValue, only)),
        "className": Js.Nullable.from_opt(className)
      },
      children
    );
};

module DialogActions = {
  module Classes = {
    type classesType =
      | Root(string)
      | Action(string)
      | Button(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Action(_) => "action"
      | Button(_) => "button";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Action(className)
               | Button(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogActions"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module ListItemSecondaryAction = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemSecondaryAction"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Tab = {
  module TextColor = {
    type t =
      | Accent
      | Primary
      | Inherit;
    let to_string =
      fun
      | Accent => "accent"
      | Primary => "primary"
      | Inherit => "inherit";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | RootLabelIcon(string)
      | RootAccent(string)
      | RootAccentSelected(string)
      | RootAccentDisabled(string)
      | RootPrimary(string)
      | RootPrimarySelected(string)
      | RootPrimaryDisabled(string)
      | RootInherit(string)
      | RootInheritSelected(string)
      | RootInheritDisabled(string)
      | FullWidth(string)
      | Wrapper(string)
      | LabelContainer(string)
      | Label(string)
      | LabelWrapped(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | RootLabelIcon(_) => "rootLabelIcon"
      | RootAccent(_) => "rootAccent"
      | RootAccentSelected(_) => "rootAccentSelected"
      | RootAccentDisabled(_) => "rootAccentDisabled"
      | RootPrimary(_) => "rootPrimary"
      | RootPrimarySelected(_) => "rootPrimarySelected"
      | RootPrimaryDisabled(_) => "rootPrimaryDisabled"
      | RootInherit(_) => "rootInherit"
      | RootInheritSelected(_) => "rootInheritSelected"
      | RootInheritDisabled(_) => "rootInheritDisabled"
      | FullWidth(_) => "fullWidth"
      | Wrapper(_) => "wrapper"
      | LabelContainer(_) => "labelContainer"
      | Label(_) => "label"
      | LabelWrapped(_) => "labelWrapped";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | RootLabelIcon(className)
               | RootAccent(className)
               | RootAccentSelected(className)
               | RootAccentDisabled(className)
               | RootPrimary(className)
               | RootPrimarySelected(className)
               | RootPrimaryDisabled(className)
               | RootInherit(className)
               | RootInheritSelected(className)
               | RootInheritDisabled(className)
               | FullWidth(className)
               | Wrapper(className)
               | LabelContainer(className)
               | Label(className)
               | LabelWrapped(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tabs/Tab"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~value: option('a)=?,
        ~textColor: option([ | `Enum(TextColor.t) | `String(string)])=?,
        ~style: option(Js.t({..}))=?,
        ~selected: option(bool)=?,
        ~onClick: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onChange: option(((ReactEventRe.Synthetic.t, _) => unit))=?,
        ~label: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~indicator: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~icon: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~fullWidth: option(bool)=?,
        ~disabled: option(bool)=?,
        ~className: option(string)=?,
        ~classes: option(Classes.t)=?,
        ~centerRipple: option(bool)=?,
        ~component: option(Js.t({..}))=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option((ReactEventRe.Synthetic.t => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~rootRef: option('b)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~type_: string,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "textColor":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(TextColor.to_string(e)))
              | x => unwrapValue(x),
              textColor
            )
          ),
        "style": Js.Nullable.from_opt(style),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "onClick": Js.Nullable.from_opt(onClick),
        "onChange": Js.Nullable.from_opt(onChange),
        "label": Js.Nullable.from_opt(optionMap(unwrapValue, label)),
        "indicator": Js.Nullable.from_opt(optionMap(unwrapValue, indicator)),
        "icon": Js.Nullable.from_opt(optionMap(unwrapValue, icon)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(component),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "rootRef": Js.Nullable.from_opt(rootRef),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": type_
      },
      children
    );
};

module ListItemIcon = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemIcon"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Slide = {
  module Direction = {
    type t =
      | Left
      | Right
      | Up
      | Down;
    let to_string =
      fun
      | Left => "left"
      | Right => "right"
      | Up => "up"
      | Down => "down";
  };
  [@bs.module "material-ui/transitions/Slide"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~style: option(Js.t({..}))=?,
        ~onExited: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~in_: bool,
        ~direction: option(Direction.t)=?,
        ~theme: option(Js.t({..}))=?,
        ~timeout: option(Js.t({..}))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "style": Js.Nullable.from_opt(style),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "in": Js.Boolean.to_js_boolean(in_),
        "direction": Js.Nullable.from_opt(optionMap(Direction.to_string, direction)),
        "theme": Js.Nullable.from_opt(theme),
        "timeout": Js.Nullable.from_opt(timeout)
      },
      children
    );
};

module Drawer = {
  module Type = {
    type t =
      | Permanent
      | Persistent
      | Temporary;
    let to_string =
      fun
      | Permanent => "permanent"
      | Persistent => "persistent"
      | Temporary => "temporary";
  };
  module Anchor = {
    type t =
      | Left
      | Top
      | Right
      | Bottom;
    let to_string =
      fun
      | Left => "left"
      | Top => "top"
      | Right => "right"
      | Bottom => "bottom";
  };
  module Classes = {
    type classesType =
      | Docked(string)
      | Paper(string)
      | PaperAnchorLeft(string)
      | PaperAnchorRight(string)
      | PaperAnchorTop(string)
      | PaperAnchorBottom(string)
      | PaperAnchorDockedLeft(string)
      | PaperAnchorDockedTop(string)
      | PaperAnchorDockedRight(string)
      | PaperAnchorDockedBottom(string)
      | Modal(string);
    type t = list(classesType);
    let to_string =
      fun
      | Docked(_) => "docked"
      | Paper(_) => "paper"
      | PaperAnchorLeft(_) => "paperAnchorLeft"
      | PaperAnchorRight(_) => "paperAnchorRight"
      | PaperAnchorTop(_) => "paperAnchorTop"
      | PaperAnchorBottom(_) => "paperAnchorBottom"
      | PaperAnchorDockedLeft(_) => "paperAnchorDockedLeft"
      | PaperAnchorDockedTop(_) => "paperAnchorDockedTop"
      | PaperAnchorDockedRight(_) => "paperAnchorDockedRight"
      | PaperAnchorDockedBottom(_) => "paperAnchorDockedBottom"
      | Modal(_) => "modal";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Docked(className)
               | Paper(className)
               | PaperAnchorLeft(className)
               | PaperAnchorRight(className)
               | PaperAnchorTop(className)
               | PaperAnchorBottom(className)
               | PaperAnchorDockedLeft(className)
               | PaperAnchorDockedTop(className)
               | PaperAnchorDockedRight(className)
               | PaperAnchorDockedBottom(className)
               | Modal(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Drawer/Drawer"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~sSlideProps: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~onRequestClose: option(ReasonReact.Callback.t(ReactEventRe.Synthetic.t))=?,
        ~mModalProps: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~type_: option(Type.t)=?,
        ~open_: option(bool)=?,
        ~transitionDuration: option(Js.t({..}))=?,
        ~elevation: option(float)=?,
        ~classes: option(Classes.t)=?,
        ~anchor: option(Anchor.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "SlideProps": Js.Nullable.from_opt(sSlideProps),
        "theme": theme,
        "onRequestClose": Js.Nullable.from_opt(onRequestClose),
        "ModalProps": Js.Nullable.from_opt(mModalProps),
        "className": Js.Nullable.from_opt(className),
        "type": Js.Nullable.from_opt(optionMap(Type.to_string, type_)),
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "transitionDuration": Js.Nullable.from_opt(transitionDuration),
        "elevation": Js.Nullable.from_opt(elevation),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "anchor": Js.Nullable.from_opt(optionMap(Anchor.to_string, anchor))
      },
      children
    );
};

module Snackbar = {
  module Classes = {
    type classesType =
      | Root(string)
      | AnchorTopCenter(string)
      | AnchorBottomCenter(string)
      | AnchorTopRight(string)
      | AnchorBottomRight(string)
      | AnchorTopLeft(string)
      | AnchorBottomLeft(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | AnchorTopCenter(_) => "anchorTopCenter"
      | AnchorBottomCenter(_) => "anchorBottomCenter"
      | AnchorTopRight(_) => "anchorTopRight"
      | AnchorBottomRight(_) => "anchorBottomRight"
      | AnchorTopLeft(_) => "anchorTopLeft"
      | AnchorBottomLeft(_) => "anchorBottomLeft";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | AnchorTopCenter(className)
               | AnchorBottomCenter(className)
               | AnchorTopRight(className)
               | AnchorBottomRight(className)
               | AnchorTopLeft(className)
               | AnchorBottomLeft(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Snackbar/Snackbar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~transitionDuration: option(Js.t({..}))=?,
        ~transition: option(Js.t({..}))=?,
        ~sSnackbarContentProps: option(Js.t({..}))=?,
        ~open_: bool,
        ~onRequestClose: option(((ReactEventRe.Synthetic.t, string) => unit))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onExited: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExiting: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onExit: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntered: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEntering: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~onEnter: option(ReasonReact.Callback.t(ReactEventRe.Transition.t))=?,
        ~message: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~resumeHideDuration: option(float)=?,
        ~autoHideDuration: option(float)=?,
        ~action: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        ~anchorOrigin: option({. "horizontal": _, "vertical": _})=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "transitionDuration": Js.Nullable.from_opt(transitionDuration),
        "transition": Js.Nullable.from_opt(transition),
        "SnackbarContentProps": Js.Nullable.from_opt(sSnackbarContentProps),
        "open": Js.Boolean.to_js_boolean(open_),
        "onRequestClose": Js.Nullable.from_opt(onRequestClose),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onExit": Js.Nullable.from_opt(onExit),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "message": Js.Nullable.from_opt(message),
        "className": Js.Nullable.from_opt(className),
        "resumeHideDuration": Js.Nullable.from_opt(resumeHideDuration),
        "autoHideDuration": Js.Nullable.from_opt(autoHideDuration),
        "action": Js.Nullable.from_opt(action),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "anchorOrigin": Js.Nullable.from_opt(anchorOrigin)
      },
      children
    );
};

module CircularProgress = {
  module Mode = {
    type t =
      | Determinate
      | Indeterminate;
    let to_string =
      fun
      | Determinate => "determinate"
      | Indeterminate => "indeterminate";
  };
  module Color = {
    type t =
      | Primary
      | Accent
      | Inherit;
    let to_string =
      fun
      | Primary => "primary"
      | Accent => "accent"
      | Inherit => "inherit";
  };
  module Classes = {
    type classesType =
      | Root(string)
      | PrimaryColor(string)
      | AccentColor(string)
      | SvgIndeterminate(string)
      | SvgDeterminate(string)
      | Circle(string)
      | CircleIndeterminate(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PrimaryColor(_) => "primaryColor"
      | AccentColor(_) => "accentColor"
      | SvgIndeterminate(_) => "svgIndeterminate"
      | SvgDeterminate(_) => "svgDeterminate"
      | Circle(_) => "circle"
      | CircleIndeterminate(_) => "circleIndeterminate";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PrimaryColor(className)
               | AccentColor(className)
               | SvgIndeterminate(className)
               | SvgDeterminate(className)
               | Circle(className)
               | CircleIndeterminate(className) =>
                 Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Progress/CircularProgress"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~thickness: option(float)=?,
        ~style: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~max: option(float)=?,
        ~min: option(float)=?,
        ~value: option(float)=?,
        ~mode: option(Mode.t)=?,
        ~size: option(float)=?,
        ~color: option(Color.t)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "thickness": Js.Nullable.from_opt(thickness),
        "style": Js.Nullable.from_opt(style),
        "className": Js.Nullable.from_opt(className),
        "max": Js.Nullable.from_opt(max),
        "min": Js.Nullable.from_opt(min),
        "value": Js.Nullable.from_opt(value),
        "mode": Js.Nullable.from_opt(optionMap(Mode.to_string, mode)),
        "size": Js.Nullable.from_opt(size),
        "color": Js.Nullable.from_opt(optionMap(Color.to_string, color)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Switch = {
  module Classes = {
    type classesType =
      | Root(string)
      | Bar(string)
      | Icon(string)
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Bar(_) => "bar"
      | Icon(_) => "icon"
      | Default(_) => "default"
      | Checked(_) => "checked"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Bar(className)
               | Icon(className)
               | Default(className)
               | Checked(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Switch/Switch"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~value: option(string)=?,
        ~tabIndex: option([ | `Float(float) | `String(string)])=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~name: option(string)=?,
        ~inputRef: option('a)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~disableRipple: option(bool)=?,
        ~disabledClassName: option(string)=?,
        ~disabled: option(bool)=?,
        ~defaultChecked: option(bool)=?,
        ~className: option(string)=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~checkedClassName: option(string)=?,
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "value": Js.Nullable.from_opt(value),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "onChange": Js.Nullable.from_opt(onChange),
        "name": Js.Nullable.from_opt(name),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "icon": Js.Nullable.from_opt(icon),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "disabledClassName": Js.Nullable.from_opt(disabledClassName),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "defaultChecked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultChecked)),
        "className": Js.Nullable.from_opt(className),
        "checkedIcon": Js.Nullable.from_opt(checkedIcon),
        "checkedClassName": Js.Nullable.from_opt(checkedClassName),
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableHead = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableHead"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(component),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module SnackbarContent = {
  module Classes = {
    type classesType =
      | Root(string)
      | Message(string)
      | Action(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Message(_) => "message"
      | Action(_) => "action";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Message(className)
               | Action(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Snackbar/SnackbarContent"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~message: ReasonReact.reactElement,
        ~className: option(string)=?,
        ~action: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        ~component: option(Js.t({..}))=?,
        ~elevation: option(float)=?,
        ~square: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "message": message,
        "className": Js.Nullable.from_opt(className),
        "action": Js.Nullable.from_opt(action),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes)),
        "component": Js.Nullable.from_opt(component),
        "elevation": Js.Nullable.from_opt(elevation),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square))
      },
      children
    );
};

module DialogContentText = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogContentText"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};
