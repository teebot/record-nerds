[@bs.val] external currentTime : unit => int = "Date.now";
/* format a timestamp in seconds as relative humanised time sentence */
let fromNow = (unixtime) => {
  let delta = currentTime() / 1000 - unixtime;
  if (delta < 3600) {
    string_of_int(delta / 60) ++ " minutes ago"
  } else if (delta < 86400) {
    string_of_int(delta / 3600) ++ " hours ago"
  } else {
    string_of_int(delta / 86400) ++ " days ago"
  }
};


let intEl = (n) =>
  n |> string_of_int
    |> ReasonReact.stringToElement;


let textEl = ReasonReact.stringToElement;


let arrayEl = ReasonReact.arrayToElement;