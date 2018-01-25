[%bs.raw {|require('./Tops.css')|}];
[@bs.module] external grid : string = "./grid.svg";
[@bs.module] external list : string = "./list.svg";
open Utils;


type state = {
  topRecords: option(RecordsData.topRecords),
  viewMode: RecordsData.view
};


type action =
  | Loaded(RecordsData.topRecords)
  /* | Sort */
  | ToggleView;


let component = ReasonReact.reducerComponent("Tops");
let make = (_children) => {

  let renderRecordList = (state) => {
    switch state.topRecords {
    | Some(records) =>
      records
      |> Array.mapi((index, record: RecordsData.record) =>
        <Record key=(index |> string_of_int) record viewMode=(state.viewMode) />)
      |> arrayEl
    | None => ReasonReact.nullElement
    }
  };

  let renderViewIcon = (viewMode, ~clickAction) => {
    switch viewMode {
    | RecordsData.Card =>
      (<img src=list onClick=clickAction className="ViewModeIcon" alt="logo" />)
    | RecordsData.List =>
      (<img src=grid onClick=clickAction className="ViewModeIcon" alt="logo" />)
    }
  };

  {
  ...component,

  initialState: () => {
    topRecords: None,
    viewMode: Card
  },

  reducer: (action, state) => {
    /* let sortRecords = (records: option(RecordsData.topRecords)) => {
      switch records {
      | Some(records) =>
        records
        |> Array.sort((recordA: RecordsData.record, recordB: RecordsData.record) => 1)
      | None => [||]
      }
    }; */
    

    let toggleState = view =>
      switch view {
      | RecordsData.List => RecordsData.Card
      | RecordsData.Card  => RecordsData.List
      };

    switch action {
    | Loaded(data) => ReasonReact.Update({...state,
        topRecords: Some(data)
      })
    /* | Sort => ReasonReact.Update({
        topRecords: sortRecords(state.topRecords)
    }) */
    | ToggleView => ReasonReact.Update({...state,
        viewMode: toggleState(state.viewMode)
      })
    }
  },

  didMount: (self) => {
    RecordsData.fetchTopRecords(self.reduce(records => Loaded(records)));
    ReasonReact.NoUpdate
  },

  render: (self) => {
    <div>
      <div className="TopsHeader">
        <h2>("My Top Albums" |> textEl)</h2>
        (renderViewIcon(self.state.viewMode, ~clickAction=self.reduce((_event) => ToggleView)))
      </div>
      
      <div className="TopRecords">
        (renderRecordList(self.state))
      </div>
    </div>
    }
  }
};