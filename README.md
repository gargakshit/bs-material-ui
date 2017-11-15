# Reason bindings for material-ui
This library provides Reason bindings for
[material-ui](https://material-ui-1dab0.firebaseapp.com/). It's automatically generated by
[reason-mui-binding-generator](https://github.com/jsiebern/reason-mui-binding-generator) which is an adaption of  [reason-rt-binding-generator](https://github.com/astrada/reason-rt-binding-generator) (created by [astrada](https://github.com/astrada)).

**Important:** These bindings are not yet complete, they mostly expose the standard Components. You are welcome to contribute or open issues about more in-depth bindings of the original library.

## Installation (for your Reason project)

Run:

    yarn add bs-material-ui

to add the library to your project dependencies. And add `bs-material-ui` to the `bs-dependencies` node of your `bsconfig.json`.

## Example

```ml
let component = ReasonReact.statelessComponent("Example");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <MaterialUi.Card>
      <MaterialUi.CardHeader
        title=(ReasonReact.stringToElement("Example Title"))
        subheader=(ReasonReact.stringToElement("A Subtitle"))
      />
      <MaterialUi.CardContent> <MaterialUi.List /> </MaterialUi.CardContent>
      <MaterialUi.CardActions>
        <MaterialUi.Button
          color=MaterialUi.Button.Color.Primary raised=true href="#/example/route">
          (ReasonReact.stringToElement("Go to example"))
        </MaterialUi.Button>
      </MaterialUi.CardActions>
    </MaterialUi.Card>
};
```

## withStyles Example

In material-ui, the `withStyles` [HOC](https://reactjs.org/docs/higher-order-components.html) takes care of turning React styles into CSS via [react-jss](https://github.com/cssinjs/react-jss). It passes a `classes` prop onto the component with the first level keys of the style object passed on.

HOC do not translate well into Reason which is why we are using a [render prop](http://reactpatterns.com/#render-callback) to make things easier. [(More information on the topic).](https://www.youtube.com/watch?v=BcVAq3YFiuc)

You need to pass a `styles` prop of type `Js.t({..})` and a `render` function to the component. See the following example:

```ml
let component = ReasonReact.statelessComponent("Example");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <MaterialUi.WithStyles
      styles={"alignRight": {"width": "100%", "textAlign": "right"}}
      render=(
        (classes) =>
          <div className=classes##alignRight>
            (ReasonReact.stringToElement("Example text aligned right"))
          </div>
      )
    />
};
```

## Colors

All Colors are accessible in Submodules of the Module `Colors`. Color keys that are a pure number begin with a `c`. [(MUI Docs Reference).](https://material-ui-1dab0.firebaseapp.com/style/color/)

Example:

```ml
<MaterialUi.WithStyles
  styles={"bgColor": {"backgroundColor": MaterialUi.Colors.Red.c300}}
  render=(
    (classes) =>
      <div className=classes##bgColor />
  )
/>
```

## Overriding with classes

To take advantage of Reasons type system when overriding classes directly on components they have been converted into Variants and need to be passed as a `list` to the components `classes` prop. It is best used in combination with the `MaterialUi.WithStyles` component.

[(MUI Docs Reference).](https://material-ui-1dab0.firebaseapp.com/customization/overrides/#overriding-with-classes)

Example:
```ml
<MaterialUi.WithStyles
  styles={"fSize": {"fontSize": "30px"}, "bgColor": {"backgroundColor": MaterialUi.Colors.Red.c300}}
  render=(
    (classes) =>
      <MaterialUi.Button color=MaterialUi.Button.Color.Primary raised=true classes=[MaterialUi.Button.Classes.Root(classes##fSize), MaterialUi.Button.Classes.RaisedPrimary(classes##bgColor)]>
        (ReasonReact.stringToElement(Helpers.translate("Example Button")))
      <MaterialUi.Button />
  )
/>
```

## Todo

- [x] ~~Expose a nested `Colors` module~~ (2017-11-15)
- [ ] Think of a way to use `theme => object` pattern as `withStyles` argument
- [ ] Add `WithTheme` component
- [ ] Add `ThemeProvider` component
- [x] ~~Think of a way to type classname overrides~~ (2017-11-15)