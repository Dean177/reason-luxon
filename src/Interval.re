type t;

[@bs.module "luxon"] [@bs.scope "Interval"]
external after: (DateTime.t, Duration.t) => t = "after";

[@bs.module "luxon"] [@bs.scope "Interval"]
external before: (DateTime.t, Duration.t) => t = "after";

[@bs.module "luxon"] [@bs.scope "Interval"]
external fromDateTimes: (DateTime.t, DateTime.t) => t = "fromDateTimes";

type fromISOOptions = {
  locale: option(string),
  numberingSystem: option(string),
  conversionAccuracy: option(ConversionAccuracy.t),
  zone: option(Zone.t),
  setZone: option(bool),
  outputCalendar: option(string),
};

[@bs.module "luxon"] [@bs.scope "Interval"]
external fromISOBase: (string, fromISOOptions) => t = "fromISO";

let fromISO =
    (
      ~locale=?,
      ~numberingSystem=?,
      ~conversionAccuracy=?,
      ~zone=?,
      ~setZone=?,
      ~outputCalendar=?,
      string,
    ) =>
  fromISOBase(
    string,
    {
      locale,
      numberingSystem,
      conversionAccuracy,
      zone,
      setZone,
      outputCalendar,
    },
  );

[@bs.module "luxon"] [@bs.scope "Interval"]
external invalid: (string, option(string)) => t = "invalid";

let invalid = (~explanation=?, reason) => invalid(reason, explanation);

[@bs.module "luxon"] [@bs.scope "Interval"]
external isInterval: t => bool = "isInterval";

[@bs.module "luxon"] [@bs.scope "Interval"] external merge: array(t) => t = "merge";

[@bs.module "luxon"] [@bs.scope "Interval"]
external xor: array(t) => array(t) = "xor";

[@bs.send] external end_: t => DateTime.t = "end";

[@bs.send] external invalidExplanation: t => string = "invalidExplanation";

[@bs.send] external invalidReason: t => string = "invalidReason";

[@bs.send] external isValid: t => bool = "isValid";

[@bs.send] external start: t => DateTime.t = "start";

[@bs.send] external abutsEnd: (t, t) => bool = "abutsEnd";

[@bs.send] external abutsStart: (t, t) => bool = "abutsStart";

[@bs.send] external contains: (t, DateTime.t) => bool = "contains";

[@bs.send]
external count:
  (
    t,
    option(
      [@bs.string] [
        | `years
        | `quarters
        | `months
        | `weeks
        | `days
        | `hours
        | `minutes
        | `seconds
        | `milliseconds
      ],
    )
  ) =>
  int =
  "count";

let count = (~unit=?, t) => count(t, unit);

[@bs.send] [@bs.variadic]
external difference: (t, array(t)) => bool = "difference";

[@bs.send] external divideEqually: (t, int) => array(t) = "divideEqually";

[@bs.send] external engulfs: (t, t) => bool = "engulfs";

[@bs.send] external equals: (t, t) => bool = "equals";

[@bs.send]
external hasSame:
  (
    t,
    [@bs.string] [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
  ) =>
  bool =
  "hasSame";

[@bs.send] external intersection: (t, t) => t = "intersection";

[@bs.send] external isAfter: (t, DateTime.t) => bool = "isAfter";

[@bs.send] external isBefore: (t, DateTime.t) => bool = "isBefore";

[@bs.send] external isEmpty: t => bool = "isEmpty";

// TODO can this only return integers?
[@bs.send]
external length:
  (
    t,
    [@bs.string] [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
  ) =>
  float =
  "length";

[@bs.send]
external mapEndpoints: (t, DateTime.t => DateTime.t) => t = "mapEndpoints";

[@bs.send] external overlaps: (t, t) => bool = "overlaps";

type setValues = {
  start: option(DateTime.t),
  [@bs.as "end"]
  end_: option(DateTime.t),
};

[@bs.send] external set: (t, setValues) => t = "set";

let set = (~start=?, ~end_=?, t) => set(t, {start, end_});

[@bs.send] [@bs.variadic]
external splitAt: (t, array(DateTime.t)) => array(t) = "splitAt";

[@bs.send] external splitBy: (t, Duration.t) => array(t) = "splitBy";

type toDurationOptions = {conversionAccuracy: option(ConversionAccuracy.t)};

[@bs.send]
external toDuration:
  (
    t,
    option(
      [@bs.string] [
        | `years
        | `quarters
        | `months
        | `weeks
        | `days
        | `hours
        | `minutes
        | `seconds
        | `milliseconds
      ],
    ),
    toDurationOptions
  ) =>
  Duration.t =
  "toDuration";

let toDuration = (~conversionAccuracy=?, ~unit=?, t) =>
  toDuration(t, unit, {conversionAccuracy: conversionAccuracy});

type toFormatOptions = {separator: option(string)};

[@bs.send]
external toFormat: (t, DateTime.Format.t, toFormatOptions) => string =
  "toFormat";
let toFormat = (~separator=?, t, format) =>
  toFormat(t, format, {separator: separator});

type toISOOptions = {
  suppressMilliseconds: option(bool),
  suppressSeconds: option(bool),
  includeOffset: option(bool),
};

[@bs.send] external toISO: (t, toISOOptions) => string = "toISO";

let toISO = (~suppressMilliseconds=?, ~suppressSeconds=?, ~includeOffset=?, t) =>
  toISO(t, {suppressMilliseconds, suppressSeconds, includeOffset});

[@bs.send] external toISODate: t => string = "toISODate";

[@bs.send] external toISOTime: (t, toISOOptions) => string = "toISOTime";
let toISOTime =
    (~suppressMilliseconds=?, ~suppressSeconds=?, ~includeOffset=?, t) =>
  toISOTime(t, {suppressMilliseconds, suppressSeconds, includeOffset});

[@bs.send] external toString: t => string = "toString";

[@bs.send] external union: (t, t) => t = "union";