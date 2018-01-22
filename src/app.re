[%bs.raw {|require('./app.css')|}];
[@bs.module] external logo : string = "./logo.svg";
open Utils;


type route =
  | Home
  | Tops;


type state = {route};


type action =
  | ChangeRoute(route);


let reducer = (action, _state) =>
    switch action {
    | ChangeRoute(route) => ReasonReact.Update({route: route})
    };


let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => Home
  | ["tops"] => Tops
  | _ => Home
  };


let component = ReasonReact.reducerComponent("App");


let make = (_children) => {

  let renderRoute = route => 
    switch route {
      | Home =>
        <a href="/tops">
          <h2>("Top Albums" |> textEl)</h2>
        </a>
      | Tops =>
        <Tops />
    };

  {
    ...component,
    reducer,
    subscriptions: (self) => [
      Sub(
        () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url |> mapUrlToRoute))),
        ReasonReact.Router.unwatchUrl
      )
    ],
    initialState: () => {route: Home},
    render: (self) => {
      <div className="App">
        <div className="App-header">
          <div className="Container">
            <a href="/">
              <h1>("Record Nerds" |> textEl)</h1>
            </a>
          </div>
        </div>
        <div className="Container">
        (self.state.route |> renderRoute)
        </div>
      </div>
    }
  }
};