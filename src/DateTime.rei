/** 
 * https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html
 */

module Format: {
  type t;

  let fromString: string => t;

  module DateTime: {
    let full: t;
    let fullWithSeconds: t;
    let huge: t;
    let hugeWithSeconds: t;
    let med: t;
    let medWithSeconds: t;
    let medWithWeekday: t;
    let short: t;
    let shortWithSeconds: t;
  };

  module Date: {
    let full: t;
    let huge: t;
    let med: t;
    let short: t;
  };

  module Time: {
    let simple24: t;
    let withLongOffset24: t;
    let withSeconds24: t;
    let withShortOffset24: t;
    let simple: t;
    let withLongOffset: t;
    let withSeconds: t;
    let withShortOffset: t;
  };
};

type t;

let make:
  (
    ~year: int=?,
    ~month: int=?,
    ~day: int=?,
    ~ordinal: int=?,
    ~weekYear: int=?,
    ~weekday: int=?,
    ~hour: int=?,
    ~minute: int=?,
    ~second: int=?,
    ~millisecond: int=?,
    ~zone: Zone.t=?,
    ~locale: string=?,
    ~outputCalendar: string=?,
    ~numberingSystem: string=?,
    unit
  ) =>
  t;

let fromFormat:
  (
    ~zone: Zone.t=?,
    ~setZone: bool=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    string,
    ~format: Format.t
  ) =>
  t;

// type formatExplanation = {};
//let fromFormatExplain:
//  (
//    ~zone: Zone.t=?,
//    ~setZone: bool=?,
//    ~locale: string=?,
//    ~numberingSystem: string=?,
//    ~outputCalendar: string=?,
//    string,
//    ~format: Format.t
//  ) =>
//  formatExplanation;

let fromHTTP:
  (
    ~zone: Zone.t=?,
    ~setZone: bool=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    string
  ) =>
  t;

let fromISO:
  (
    ~zone: Zone.t=?,
    ~setZone: bool=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    string
  ) =>
  t;

let fromJSDate: (~zone: Zone.t=?, Js.Date.t) => t;

let fromMillis:
  (
    ~zone: Zone.t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    float
  ) =>
  t;

type objectDate = {
  year: option(int),
  month: option(int),
  day: option(int),
  ordinal: option(int),
  weekYear: option(int),
  weekday: option(int),
  hour: option(int),
  minute: option(int),
  second: option(int),
  millisecond: option(int),
  zone: option(Zone.t),
  locale: option(string),
  outputCalendar: option(string),
  numberingSystem: option(string),
};

/** You probably want {DateTime.make} which matches the usage of the Luxon API more closely */
[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromObject: objectDate => t = "fromObject";

let fromRFC2822:
  (
    ~zone: Zone.t=?,
    ~setZone: bool=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    string
  ) =>
  t;

let fromSQL:
  (
    ~zone: Zone.t=?,
    ~setZone: bool=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    string
  ) =>
  t;

let fromSeconds:
  (
    ~zone: Zone.t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    float
  ) =>
  t;

let invalid: (~explanation: string=?, string) => t;

let isDateTime: t => bool;

let local:
  (
    ~year: int=?,
    ~month: int=?,
    ~day: int=?,
    ~hour: int=?,
    ~minute: int=?,
    ~second: int=?,
    ~millisecond: int=?,
    unit
  ) =>
  t;

let max: array(t) => t;

let min: array(t) => t;

let utc:
  (
    ~year: int=?,
    ~month: int=?,
    ~day: int=?,
    ~hour: int=?,
    ~minute: int=?,
    ~second: int=?,
    ~millisecond: int=?,
    unit
  ) =>
  t;

[@bs.get] external day: t => int = "days";

[@bs.get] external daysInMonth: t => int = "daysInMonth";

[@bs.get] external daysInYear: t => int = "daysInYear";

[@bs.get] external hour: t => int = "hour";

[@bs.get] external invalidExplanation: t => string = "invalidExplanation";

[@bs.get] external invalidReason: t => string = "invalidReason";

[@bs.get] external isInDST: t => bool = "isInDST";

[@bs.get] external isInLeapYear: t => bool = "isInLeapYear";

[@bs.get] external isInFixedOffset: t => bool = "isInFixedOffset";

[@bs.get] external isValid: t => bool = "isValid";

[@bs.get] external locale: t => string = "locale";

[@bs.get] external millisecond: t => int = "millisecond";

[@bs.get] external minute: t => int = "minute";

[@bs.get] external month: t => int = "month";

[@bs.get] external monthLong: t => string = "monthLong";

[@bs.get] external monthShort: t => string = "monthShort";

[@bs.get] external numberingSystem: t => string = "numberingSystem";

[@bs.get] external offset: t => string = "offset";

[@bs.get] external offsetNameLong: t => string = "offsetNameLong";

[@bs.get] external offsetNameShort: t => string = "offsetNameShort";

[@bs.get] external ordinal: t => int = "ordinal";

[@bs.get] external outputCalendar: t => string = "outputCalendar";

[@bs.get] external quarter: t => int = "quarter";

[@bs.get] external second: t => int = "second";

[@bs.get] external weekNumber: t => int = "weekNumber";

[@bs.get] external weekYear: t => int = "weekYear";

[@bs.get] external weekday: t => int = "weekday";

[@bs.get] external weekdayLong: t => string = "weekdayLong";

[@bs.get] external weekdayShort: t => string = "weekdayShort";

[@bs.get] external weeksInWeekYear: t => int = "weeksInWeekYear";

[@bs.get] external year: t => int = "year";

[@bs.get] external zone: t => Zone.t = "zone";

[@bs.get] external zoneName: t => string = "zoneName";

let diff:
  (
    ~conversionAccuracy: ConversionAccuracy.t=?,
    ~units: array(
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
              =?,
    t,
    t
  ) =>
  Duration.t;

let diffNow:
  (
    ~conversionAccuracy: ConversionAccuracy.t=?,
    ~units: array(
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
              =?,
    t
  ) =>
  Duration.t;

let endOf:
  (
    t,
    [@bs.string] [
      | `year
      | `month
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
  ) =>
  t;

let equals: (t, t) => bool;

let get:
  (
    t,
    [@bs.string] [
      | `year
      | `month
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
  ) =>
  int;

let hasSame:
  (
    t,
    t,
    [@bs.string] [
      | `year
      | `month
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
  ) =>
  bool;

let minus: (t, Duration.t) => t;

let plus: (t, Duration.t) => t;

let reconfigure:
  (
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    t
  ) =>
  t;

// TODO resolvedLocaleOpts

let set:
  (
    t,
    [@bs.string] [
      | `year
      | `month
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
  ) =>
  int;

let setLocale: (t, string) => t;

let setZone: (~keepLocalTime: bool=?, t, Zone.t) => t;

[@bs.send]
external startOf:
  (
    t,
    [@bs.string] [
      | `year
      | `month
      | `week
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
  ) =>
  t =
  "startOf";

let toBSON: t => string;

// TODO this accepts additional options
[@bs.send] external toFormat: (t, Format.t) => string = "toFormat";

let toHTTP: t => string;

let toISO:
  (
    ~suppressMilliseconds: bool=?,
    ~suppressSeconds: bool=?,
    ~includeOffset: bool=?,
    t
  ) =>
  string;

let toISODate: t => string;

let toISOTime:
  (
    ~suppressMilliseconds: bool=?,
    ~suppressSeconds: bool=?,
    ~includeOffset: bool=?,
    t
  ) =>
  string;

let toISOWeekDate: t => string;

let toJSDate: t => Js.Date.t;

let toJSON: t => string;

let toLocale: t => t;

type localePart = {
  [@bs.as "type"]
  type_: string,
  value: string,
};

let toLocaleParts: t => array(localePart);

// TODO this accepts additional configuration
[@bs.send] external toLocaleString: t => string = "toLocaleString";

let toMillis: t => int;

type dateTimeObject = {
  year: option(int),
  month: option(int),
  day: option(int),
  hour: option(int),
  minute: option(int),
  second: option(int),
  millisecond: option(int),
};
[@bs.send] external toObject: t => dateTimeObject = "toObject";

// TODO which extra fields are included when includeConfig is true?
// type dateTimeObjectWithConfig = {
//   year: int,
//   month: int,
//   day: int,
//   hour: int,
//   minute: int,
//   second: int,
//   millisecond: int,
// };
// let toObjectWithConfig: t => dateTimeObjectWithConfig;

let toRFC2822: t => string;

let toRelative:
  (
    ~base: t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    // It's illegal to use both round and padding, can we make this unrepresentable?
    ~padding: int=?,
    ~round: bool=?,
    ~style: [@bs.string] [ | `long | `short | `narrow]=?,
    ~unit: [@bs.string] [
             | `year
             | `month
             | `day
             | `hour
             | `minute
             | `second
             | `millisecond
           ]
             =?,
    t
  ) =>
  string;

let toRelativeCalendar:
  (
    ~base: t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~unit: [@bs.string] [
             | `year
             | `month
             | `day
             | `hour
             | `minute
             | `second
             | `millisecond
           ]
             =?,
    t
  ) =>
  string;

let toSQL: (~includeZone: bool=?, ~includeOffset: bool=?, t) => string;

let toSQLDate: t => string;

let toSQLTime: (~includeZone: bool=?, ~includeOffset: bool=?, t) => string;

let toSeconds: t => int;

[@bs.send] external toString: t => string = "toString";

let toUTC: (~keepLocalTime: bool=?, ~offset: int=?, t) => string;

// Until is not incliuded as it would create a dependency cycle.
// You don't need it since Interval.from has exactly the same signature;
// let until: (t, t) => Interval.t;

[@bs.send] external valueOf: t => float = "valueOf";