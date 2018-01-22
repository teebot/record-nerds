[%bs.raw {|require('./Tops.css')|}];
open Utils;


type state = {
  topRecords: option(RecordsData.topRecords)
};


type action =
  | Loaded(RecordsData.topRecords)
  | Sort;


let component = ReasonReact.reducerComponent("Tops");
let make = (_children) => {

  let renderRecordList = (records: option(RecordsData.topRecords)) => {
    switch records {
    | Some(topRecords) =>
      topRecords
      |> Array.mapi((index, record: RecordsData.record) =>
        <Record key=(index |> string_of_int) record />)
      |> arrayEl
    | None => ReasonReact.nullElement
    }
  };

  {
  ...component,

  initialState: () => {
    topRecords: None
  },

  reducer: (action, state) => {
    let sortRecords = (state) => state.topRecords;

    switch action {
    | Loaded(data) => ReasonReact.Update({
        topRecords: Some(data)
      })
    | Sort => ReasonReact.Update({
        topRecords: sortRecords(state)
    })
    }
  },

  didMount: (self) => {
    RecordsData.fetchTopRecords(self.reduce(records => Loaded(records)));
    ReasonReact.NoUpdate
  },

  render: ({state}) => {
    <div>
      <h2>("My Top Albums" |> textEl)</h2>
      <div className="TopRecords">
        (renderRecordList(state.topRecords))
      </div>
    </div>
    }
  }
};