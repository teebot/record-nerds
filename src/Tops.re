[%bs.raw {|require('./Tops.css')|}];
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
      <h2>("My Top Albums" |> textEl)</h2>
      <button onClick=(self.reduce((_event) => ToggleView))>("Toggle View" |> textEl)</button>
      <div className="TopRecords">
        (renderRecordList(self.state))
      </div>
    </div>
    }
  }
};