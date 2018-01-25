type artist = {
    name: string,
    id: string
};


type record = {
    id: string,
    artists: array(artist),
    name: string,
    timeReleased: int,
    backgroundColor: option(string)
};


type view = List | Card;


type topRecords = array(record);


let fetchTopRecords = (callback) => {
    callback([|
        { 
            id: "a1", 
            artists: [|{
                name: "Total Control",
                id: "z9"
            }|],
            name: "Laughing at the system",
            backgroundColor: Some("#98493b"),
            timeReleased: 1516628555
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Arcade Fire",
                id: "z10"
            }|],
            name: "Reflektor",
            timeReleased: 1516622555,
            backgroundColor: None
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Talib Kweli",
                id: "z10"
            }|],
            name: "Liberation",
            timeReleased: 1516540000,
            backgroundColor: Some("#82ad8a"),
        },
        { 
            id: "a2", 
            artists: [|{
                name: "The Beach Boys",
                id: "z10"
            }|],
            name: "Pet Sounds",
            timeReleased: 1516000000,
            backgroundColor: Some("#829ea2"),
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Thelonious Monk",
                id: "z10"
            }|],
            name: "Underground",
            timeReleased: 1516620055,
            backgroundColor: Some("#82ad8a"),
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Lavvi Ebbel",
                id: "z10"
            }|],
            name: "Guns and Crepe Flambee",
            timeReleased: 1516600000,
            backgroundColor: Some("#829ea2"),
        },
        { 
            id: "a1", 
            artists: [|{
                name: "Total Control",
                id: "z9"
            }|],
            name: "Laughing at the system",
            backgroundColor: Some("#82ad8a"),
            timeReleased: 1516628555
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Arcade Fire",
                id: "z10"
            }|],
            name: "Reflektor",
            timeReleased: 1516622555,
            backgroundColor: None
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Talib Kweli",
                id: "z10"
            }|],
            name: "Liberation",
            timeReleased: 1516540000,
            backgroundColor: Some("#98493b"),
        },
        { 
            id: "a2", 
            artists: [|{
                name: "The Beach Boys",
                id: "z10"
            }|],
            name: "Pet Sounds",
            timeReleased: 1516000000,
            backgroundColor: Some("#829ea2"),
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Thelonious Monk",
                id: "z10"
            }|],
            name: "Underground",
            timeReleased: 1516620055,
            backgroundColor: Some("#98493b"),
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Lavvi Ebbel",
                id: "z10"
            }|],
            name: "Guns and Crepe Flambee",
            timeReleased: 1516600000,
            backgroundColor: Some("#829ea2"),
        },
    |]);
};
