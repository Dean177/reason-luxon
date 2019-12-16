open Jest;
open Expect;

describe("Interval", () => {
  test("fromDateTime", () => {
    let start =
      DateTime.(
        make(~year=2006, ~month=Month.january, ~day=23, ~zone=Zone.utc, ())
        ->plus(Duration.make(~weeks=1., ()))
        ->endOf(`day)
      );

    let end_ = start->DateTime.plus(Duration.make(~weeks=1.0, ()));
    
    expect(Interval.fromDateTimes(start, end_)->Interval.toISO)
    |> toEqual("2006-01-30T23:59:59.999Z/2006-02-06T23:59:59.999Z");
  });
});
