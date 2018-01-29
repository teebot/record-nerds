open Jest;


test("addition", (_) => { 
    let comp = Record.make(
        ~record = {
            id: "a1", 
            artists: [|{
                name: "Total Control",
                id: "z9"
            }|],
            name: "Laughing at the system",
            backgroundColor: Some("#FF0000"),
            timeReleased: 1516628555,
            reviews: 2
        },
        ~viewMode = RecordsData.Card
    );
    Expect.(expect(3 + 4) |> toBe(7));
});