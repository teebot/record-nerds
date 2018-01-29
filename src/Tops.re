[%bs.raw {|require('./Tops.css')|}];
[@bs.module] external grid : string = "./grid.svg";
[@bs.module] external list : string = "./list.svg";
[@bs.module] external caretDown : string = "./caret-down.svg";
open Utils;


type sortType = DateAdded | Reviews | Custom;


type state = {
  topRecords: option(RecordsData.topRecords),
  viewMode: RecordsData.view,
  activeSort: sortType
};


type action =
  | Loaded(RecordsData.topRecords)
  | Sort(sortType)
  | ToggleView;


let component = ReasonReact.reducerComponent("Tops");
let make = (_children) => {

  let renderRecordList = (state) =>
    switch state.topRecords {
    | Some(records) =>
      records
      |> Array.mapi((index, record: RecordsData.record) =>
        <Record key=(index |> string_of_int) record viewMode=(state.viewMode) />)
      |> arrayEl
    | None => ReasonReact.nullElement
    };

  let renderViewIcon = (viewMode, ~clickAction) =>
    switch viewMode {
    | RecordsData.Card =>
      (<img src=list onClick=clickAction className="ViewModeIcon" alt="logo" />)
    | RecordsData.List =>
      (<img src=grid onClick=clickAction className="ViewModeIcon" alt="logo" />)
    };

  let renderSortCaret = (activeSort: sortType, sort: sortType) =>
    (activeSort == sort ? <img src=caretDown /> : ReasonReact.nullElement);

  {
    ...component,

    initialState: () => {
      topRecords: None,
      viewMode: Card,
      activeSort: Custom
    },

    reducer: (action, state) => {
      
      let toggleState = view =>
        switch view {
        | RecordsData.List => RecordsData.Card
        | RecordsData.Card  => RecordsData.List
        };

      switch action {
      | Loaded(data) => 
        Js.log(data);
        ReasonReact.Update({...state,
          topRecords: Some(data)
        })
      | Sort(DateAdded) => switch state.topRecords {
          | Some(records) =>
            let sorted = sortRecordsByDate(Array.copy(records));
            ReasonReact.Update({...state,
              topRecords: Some(sorted),
              activeSort: DateAdded
            })
          | None => ReasonReact.NoUpdate
        }
      | Sort(Custom) => switch state.topRecords {
          | Some(records) =>
            let sorted = sortRecordsByCustom(Array.copy(records));
            ReasonReact.Update({...state,
              topRecords: Some(sorted),
              activeSort: Custom
            })
          | None => ReasonReact.NoUpdate
        }
      | Sort(Reviews) => switch state.topRecords {
          | Some(records) =>
            let sorted = sortRecordsByReviews(Array.copy(records));
            ReasonReact.Update({...state,
              topRecords: Some(sorted),
              activeSort: Reviews
            })
          | None => ReasonReact.NoUpdate
        }
      | ToggleView => ReasonReact.Update({...state,
          viewMode: toggleState(state.viewMode)
        })
      }
    },

    didMount: (self) => {
      RecordsData.fetchTopRecords(self.reduce(records => Loaded(records)));
      ReasonReact.NoUpdate;
    },

    render: (self) => {
      <div>
        <div className="TopsHeader">
          <h2>("My Top Albums" |> textEl)</h2>
          (renderViewIcon(self.state.viewMode, ~clickAction=self.reduce((_event) => ToggleView)))
        </div>
        <div className="TopsSorts">
          <div className="TopsSortsLink">
            <a href="#" onClick=(self.reduce(_records => Sort(Custom)))>("Custom" |> textEl)</a>(renderSortCaret(self.state.activeSort, Custom))
          </div>
          <div className="TopsSortsLink">
            <a href="#" onClick=(self.reduce(_records => Sort(DateAdded)))>("Most recent" |> textEl)</a>(renderSortCaret(self.state.activeSort, DateAdded))
          </div>
          <div className="TopsSortsLink">
            <a href="#" onClick=(self.reduce(_records => Sort(Reviews)))>("# Reviews" |> textEl)</a>(renderSortCaret(self.state.activeSort, Reviews))
          </div>
        </div>
        
        <div className="TopRecords">
          (renderRecordList(self.state))
        </div>
      </div>
    }
  }
};