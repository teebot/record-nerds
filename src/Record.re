[%bs.raw {|require('./Record.css')|}];
open Utils;


let component = ReasonReact.statelessComponent("Record");


let make = (~record: RecordsData.record, ~viewMode: RecordsData.view, _children) => {
    let renderArtistsList = (artists: array(RecordsData.artist)) => {
        artists
        |> Array.mapi((index, artist: RecordsData.artist) =>
            <div key=(index |> string_of_int)>(artist.name |> textEl)</div>
        )
        |> arrayEl
    };

    let timeFromNow = record.timeReleased |> fromNow;

    {
    ...component,
    render: (_self) =>
        switch viewMode {
        | RecordsData.List =>
            <div className="RecordListItem">
                <div className="RecordName">(record.name |> textEl)</div>
                <div className="RecordArtists">(record.artists |> renderArtistsList)</div>
                <div className="RecordUserInfo">({j| Added $timeFromNow |j} |> textEl)</div>
            </div>
        | RecordsData.Card =>
            <div className="RecordCard">
                <div className="RecordName">(record.name |> textEl)</div>
                <div className="RecordArtists">(record.artists |> renderArtistsList)</div>
                <div className="RecordUserInfo">({j| Added $timeFromNow |j} |> textEl)</div>
            </div>
        }
    }
}