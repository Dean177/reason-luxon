open Jest;
open Expect;

let significantDate = "1991-09-24T00:00:00.000Z";

describe("DateTime", () => {
  test("make", () => {
    expect(
      DateTime.toISO(DateTime.make(
        ~year=1991, 
        ~month=Month.september, 
        ~day=24,
        ~zone=Zone.utc,
        ()
      )) 
    )
    |>toEqual(significantDate)
  });

  test("fromISO", () => {
    expect(
      DateTime.toISO(
        DateTime.fromISO(
          significantDate,          
          ~zone=Zone.IANA.create("GMT")
        ),
        
      )
    )
    |> toEqual("1991-09-24T00:00:00.000+00:00")
  })

   test("toISO", () => {
     expect(
       DateTime.toISO(
         DateTime.fromISO(
           significantDate,
           ~setZone=true,
         ),
         ~suppressMilliseconds=true,
       ),
     )
     |> toEqual("1991-09-24T00:00:00Z")
   });

  test("fromHTTP", () => {
    expect(
      DateTime.toISO(
        DateTime.fromHTTP("Sun, 06 Nov 1994 08:49:37 GMT"),
      ),
    )
    |> toEqual("1994-11-06T08:49:37.000-00:00")
  });

  test("startOf", () => {
    expect(
      DateTime.fromISO(significantDate, ~zone=Zone.utc)
      ->DateTime.plus(Duration.make(~hours=36.,()))      
      ->DateTime.startOf(`day)
      ->DateTime.toISO,
    )
    |> toEqual("1991-09-25T00:00:00.000Z")
  });

  test("endOf", () => {
    expect(
      DateTime.fromISO(significantDate, ~zone=Zone.utc)
      ->DateTime.endOf(`day)
      ->DateTime.toISO
    )
    |>toEqual("1991-09-24T23:59:59.999Z")
  })
});
