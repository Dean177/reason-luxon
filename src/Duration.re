// https://moment.github.io/luxon/docs/class/src/duration.js~Duration.html

type t;

type durationObject = {
  years: option(float),
  quarters: option(float),
  months: option(float),
  weeks: option(float),
  days: option(float),
  hours: option(float),
  minutes: option(float),
  seconds: option(float),
  milliseconds: option(float),
};

[@bs.module "luxon"] [@bs.scope "Duration"]
external fromObject: durationObject => t = "fromObject";

let make =
    (
      ~years=?,
      ~quarters=?,
      ~months=?,
      ~weeks=?,
      ~days=?,
      ~hours=?,
      ~minutes=?,
      ~seconds=?,
      ~milliseconds=?,
      (),
    ) =>
  fromObject({
    years,
    quarters,
    months,
    weeks,
    days,
    hours,
    minutes,
    seconds,
    milliseconds,
  });

[@bs.module "luxon"] [@bs.scope "Duration"]
external invalid: (string, option(string)) => t = "invalid";

let invalid = (~explanation=?, reason) => invalid(reason, explanation);

type fromISOOptions = {
  locale: option(string),
  numberingSystem: option(string),
  conversionAccuracy: option(ConversionAccuracy.t),
};

[@bs.module "luxon"] [@bs.scope "Duration"]
external fromISO: (string, fromISOOptions) => t = "fromISO";

let fromISO =
    (~locale=?, ~numberingSystem=?, ~conversionAccuracy=?, isoString) =>
  fromISO(isoString, {locale, numberingSystem, conversionAccuracy});

[@bs.module "luxon"] [@bs.scope "Duration"]
external fromMillis: float => t = "fromMillis";

[@bs.module "luxon"] [@bs.scope "Duration"]
external isDuration: t => bool = "isDuration";

[@bs.get] external days: t => float = "days";

[@bs.get] external hours: t => float = "hours";

[@bs.get] external invalidExplanation: t => string = "invalidExplanation";

[@bs.get] external invalidReason: t => string = "invalidReason";

[@bs.get] external isValid: t => bool = "isValid";

[@bs.get] external locale: t => string = "locale";

[@bs.get] external milliseconds: t => float = "milliseconds";

[@bs.get] external minutes: t => float = "minutes";

[@bs.get] external months: t => float = "months";

[@bs.get] external numberingSystem: t => string = "numberingSystem";

[@bs.get] external quarters: t => float = "quarters";

[@bs.get] external seconds: t => float = "seconds";

[@bs.get] external weeks: t => float = "weeks";

[@bs.get] external years: t => float = "years";

[@bs.send]
external as_:
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
  "as";

[@bs.send] external equals: (t, t) => bool = "equals";

[@bs.send]
external get:
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
  "get";

[@bs.send]
external mapUnits:
  (
    t,
    (
      float,
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
    float
  ) =>
  t =
  "mapUnits";

[@bs.send] external minus: (t, t) => t = "minus";

[@bs.send] external negate: t => t = "negate";

[@bs.send] external normalise: t => t = "normalise";

[@bs.send] external plus: (t, t) => t = "plus";

// TODO
//let reconfigure

[@bs.send] external set: (t, durationObject) => t = "set";

let set =
    (
      ~years=?,
      ~quarters=?,
      ~months=?,
      ~weeks=?,
      ~days=?,
      ~hours=?,
      ~minutes=?,
      ~seconds=?,
      ~milliseconds=?,
      t,
    ) =>
  set(
    t,
    {
      years,
      quarters,
      months,
      weeks,
      days,
      hours,
      minutes,
      seconds,
      milliseconds,
    },
  );

[@bs.send] [@bs.variadic]
external shiftTo:
  (
    t,
    array(
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
  t =
  "shiftTo";

type toFormatOptions = {floor: option(bool)};

[@bs.send]
external toFormat: (t, string, toFormatOptions) => string = "toFormat";
let toFormat = (~floor=?, t, ~format) =>
  toFormat(t, format, {floor: floor});

[@bs.send] external toISO: t => string = "toISO";

[@bs.send] external toJSON: t => string = "toJSON";

[@bs.send] external toObject: t => durationObject = "toObject";

type durationObjectWithConfig = {
  years: option(float),
  months: option(float),
  days: option(float),
  hours: option(float),
  minutes: option(float),
  seconds: option(float),
  milliseconds: option(float),
  //  TODO check the extra fields
};

type toObjectConfig = {includeConfig: bool};

[@bs.send]
external toObjectWithConfig: (t, toObjectConfig) => durationObjectWithConfig =
  "toObject";

let toObjectWithConfig = t => toObjectWithConfig(t, {includeConfig: true});

[@bs.send] external toString: t => string = "toString";

[@bs.send] external valueOf: t => int = "valueOf";