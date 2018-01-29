type artist = {
    name: string,
    id: string
};


type record = {
    id: string,
    artists: array(artist),
    name: string,
    timeReleased: int,
    backgroundColor: option(string),
    reviews: int
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
            timeReleased: 1516628555,
            reviews: 2
        },
        { 
            id: "a2", 
            artists: [|{
                name: "Arcade Fire",
                id: "z10"
            }|],
            name: "Reflektor",
            timeReleased: 1516622555,
            backgroundColor: None,
            reviews: 2
        },
        { 
            id: "a3", 
            artists: [|{
                name: "Talib Kweli",
                id: "z10"
            }|],
            name: "Liberation",
            timeReleased: 1516540000,
            backgroundColor: Some("#82ad8a"),
            reviews: 5
        },
        { 
            id: "a4", 
            artists: [|{
                name: "The Beach Boys",
                id: "z10"
            }|],
            name: "Pet Sounds",
            timeReleased: 1516000000,
            backgroundColor: Some("#829ea2"),
            reviews: 22
        },
        { 
            id: "a5", 
            artists: [|{
                name: "Thelonious Monk",
                id: "z10"
            }|],
            name: "Underground",
            timeReleased: 1516620055,
            backgroundColor: Some("#82ad8a"),
            reviews: 0
        },
        { 
            id: "a6", 
            artists: [|{
                name: "Lavvi Ebbel",
                id: "z10"
            }|],
            name: "Guns and Crepe Flambee",
            timeReleased: 1516600000,
            backgroundColor: Some("#829ea2"),
            reviews: 1
        },
        { 
            id: "a7", 
            artists: [|{
                name: "Total Control",
                id: "z9"
            }|],
            name: "Laughing at the system",
            backgroundColor: Some("#82ad8a"),
            timeReleased: 1516628555,
            reviews: 0
        },
        { 
            id: "a8", 
            artists: [|{
                name: "Arcade Fire",
                id: "z10"
            }|],
            name: "Reflektor",
            timeReleased: 1516622555,
            backgroundColor: None,
            reviews: 5
        },
        { 
            id: "a9", 
            artists: [|{
                name: "Talib Kweli",
                id: "z10"
            }|],
            name: "Liberation",
            timeReleased: 1516540000,
            backgroundColor: Some("#98493b"),
            reviews: 2
        },
        { 
            id: "a99", 
            artists: [|{
                name: "The Beach Boys",
                id: "z10"
            }|],
            name: "Pet Sounds",
            timeReleased: 1516000000,
            backgroundColor: Some("#829ea2"),
            reviews: 22
        },
        { 
            id: "a999", 
            artists: [|{
                name: "Thelonious Monk",
                id: "z10"
            }|],
            name: "Underground",
            timeReleased: 1516620055,
            backgroundColor: Some("#98493b"),
            reviews: 0
        },
        { 
            id: "a9999", 
            artists: [|{
                name: "Lavvi Ebbel",
                id: "z10"
            }|],
            name: "Guns and Crepe Flambee",
            timeReleased: 1516600000,
            backgroundColor: Some("#829ea2"),
            reviews: 4
        }
    |]);
};
