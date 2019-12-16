// https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html

module Format = {
  type t;

  external fromString: string => t = "%identity";

  module DateTime = {
    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external full: t = "DATETIME_FULL";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external fullWithSeconds: t = "DATETIME_FULL_WITH_SECONDS";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external huge: t = "DATETIME";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external hugeWithSeconds: t = "DATETIME_HUGE";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external med: t = "DATETIME_MED";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external medWithSeconds: t = "DATETIME_MED_WITH_SECONDS";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external medWithWeekday: t = "DATETIME_MED_WITH_WEEKDAY";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external short: t = "DATETIME_SHORT";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external shortWithSeconds: t = "DATETIME_SHORT_WITH_SECONDS";
  };

  module Date = {
    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external full: t = "DATE_FULL";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external huge: t = "DATE_HUGE";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external med: t = "DATE_MED";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external short: t = "DATE_SHORT";
  };

  module Time = {
    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external simple24: t = "TIME_24_SIMPLE";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external withLongOffset24: t = "TIME_24_WITH_LONG_OFFSET";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external withSeconds24: t = "TIME_24_WITH_SECONDS";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external withShortOffset24: t = "TIME_24_WITH_SHORT_OFFSET";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external simple: t = "TIME_SIMPLE";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external withLongOffset: t = "TIME_WITH_LONG_OFFSET";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external withSeconds: t = "TIME_WITH_SECONDS";

    [@bs.module "luxon"] [@bs.scope "DateTime"] [@bs.val]
    external withShortOffset: t = "TIME_WITH_SHORT_OFFSET";
  };
};

type t;

type fromStringOptions = {
  zone: option(Zone.t),
  setZone: option(bool),
  locale: option(string),
  numberingSystem: option(string),
  outputCalendar: option(string),
};

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromFormat: (string, Format.t, fromStringOptions) => t = "fromFormat";

let fromFormat =
    (
      ~zone=?,
      ~setZone=?,
      ~locale=?,
      ~numberingSystem=?,
      ~outputCalendar=?,
      string,
      ~format: Format.t,
    ) =>
  fromFormat(
    string,
    format,
    {zone, setZone, locale, numberingSystem, outputCalendar},
  );

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromHTTP: (string, fromStringOptions) => t = "fromHTTP";

let fromHTTP =
    (
      ~zone=?,
      ~setZone=?,
      ~locale=?,
      ~numberingSystem=?,
      ~outputCalendar=?,
      string,
    ) =>
  fromHTTP(string, {zone, setZone, locale, numberingSystem, outputCalendar});

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromISO: (string, fromStringOptions) => t = "fromISO";

let fromISO =
    (
      ~zone=?,
      ~setZone=?,
      ~locale=?,
      ~numberingSystem=?,
      ~outputCalendar=?,
      string,
    ) =>
  fromISO(string, {zone, setZone, locale, numberingSystem, outputCalendar});

type fromJSDateOptions = {zone: option(Zone.t)};

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromJSDate: (Js.Date.t, fromJSDateOptions) => t = "fromJSDate";

let fromJSDate = (~zone=?, date) => fromJSDate(date, {zone: zone});

type fromFloatOptions = {
  zone: option(Zone.t),
  locale: option(string),
  numberingSystem: option(string),
  outputCalendar: option(string),
};

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromMillis: (float, fromFloatOptions) => t = "fromMillis";

let fromMillis =
    (~zone=?, ~locale=?, ~numberingSystem=?, ~outputCalendar=?, float) =>
  fromMillis(float, {zone, locale, numberingSystem, outputCalendar});

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

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromObject: objectDate => t = "fromObject";

let make =
    (
      ~year=?,
      ~month=?,
      ~day=?,
      ~ordinal=?,
      ~weekYear=?,
      ~weekday=?,
      ~hour=?,
      ~minute=?,
      ~second=?,
      ~millisecond=?,
      ~zone=?,
      ~locale=?,
      ~outputCalendar=?,
      ~numberingSystem=?,
      (),
    ) =>
  fromObject({
    year, 
    month, 
    day, 
    ordinal,
    weekYear,
    weekday,
    hour, 
    minute, 
    second, 
    millisecond,
    zone,
    locale,
    outputCalendar,
    numberingSystem,
  });

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromRFC2822: (string, fromStringOptions) => t = "fromRFC2822";

let fromRFC2822 =
    (
      ~zone=?,
      ~setZone=?,
      ~locale=?,
      ~numberingSystem=?,
      ~outputCalendar=?,
      string,
    ) =>
  fromRFC2822(
    string,
    {zone, setZone, locale, numberingSystem, outputCalendar},
  );

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromSQL: (string, fromStringOptions) => t = "fromSQL";

let fromSQL =
    (
      ~zone=?,
      ~setZone=?,
      ~locale=?,
      ~numberingSystem=?,
      ~outputCalendar=?,
      string,
    ) =>
  fromSQL(string, {zone, setZone, locale, numberingSystem, outputCalendar});

[@bs.module "luxon"] [@bs.scope "DateTime"]
external fromSeconds: (float, fromFloatOptions) => t = "fromSeconds";

let fromSeconds =
    (~zone=?, ~locale=?, ~numberingSystem=?, ~outputCalendar=?, float) =>
  fromSeconds(float, {zone, locale, numberingSystem, outputCalendar});

[@bs.module "luxon"] [@bs.scope "DateTime"]
external invalid: (string, option(string)) => t = "invalid";

let invalid = (~explanation=?, reason) => invalid(reason, explanation);

[@bs.module "luxon"] [@bs.scope "DateTime"]
external isDateTime: t => bool = "isDateTime";

[@bs.module "luxon"] [@bs.scope "DateTime"]
external local:
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
  t =
  "local";

[@bs.module "luxon"] [@bs.scope "DateTime"]
external max: array(t) => t = "max";

[@bs.module "luxon"] [@bs.scope "DateTime"]
external min: array(t) => t = "min";

[@bs.module "luxon"] [@bs.scope "DateTime"]
external utc:
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
  t =
  "utc";

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

[@bs.send]
external diff:
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
  Duration.t =
  "diff";

[@bs.send]
external diffNow:
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
  Duration.t =
  "diffNow";

[@bs.send]
external endOf:
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
  t =
  "endOf";

[@bs.send] external equals: (t, t) => bool = "equals";

[@bs.send]
external get:
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
  int =
  "get";

[@bs.send]
external hasSame:
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
  bool =
  "hasSame";

[@bs.send] external minus: (t, Duration.t) => t = "minus";

[@bs.send] external plus: (t, Duration.t) => t = "plus";

type reconfigureOptions = {
  locale: option(string),
  numberingSystem: option(string),
  outputCalendar: option(string),
};

[@bs.send] external reconfigure: (t, reconfigureOptions) => t = "reconfigure";

let reconfigure = (~locale=?, ~numberingSystem=?, ~outputCalendar=?, t) =>
  reconfigure(t, {locale, numberingSystem, outputCalendar});

[@bs.send]
external set:
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
  int =
  "set";

[@bs.send] external setLocale: (t, string) => t = "setLocale";

type setZoneOptions = {keepLocalTime: option(bool)};

[@bs.send] external setZone: (t, Zone.t, setZoneOptions) => t = "setZone";

let setZone = (~keepLocalTime=?, t, zone) =>
  setZone(t, zone, {keepLocalTime: keepLocalTime});

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

[@bs.send] external toBSON: t => string = "toBSON";

[@bs.send] external toFormat: (t, Format.t) => string = "toFormat";

[@bs.send] external toHTTP: t => string = "toHTTP";

type timeOptions = {
  suppressMilliseconds: option(bool),
  suppressSeconds: option(bool),
  includeOffset: option(bool),
};

[@bs.send] external toISO: (t, timeOptions) => string = "toISO";
let toISO = (~suppressMilliseconds=?, ~suppressSeconds=?, ~includeOffset=?, t) =>
  toISO(t, {suppressMilliseconds, suppressSeconds, includeOffset});

[@bs.send] external toISODate: t => string = "toISODate";

[@bs.send] external toISOTime: (t, timeOptions) => string = "toISOTime";
let toISOTime =
    (~suppressMilliseconds=?, ~suppressSeconds=?, ~includeOffset=?, t) =>
  toISOTime(t, {suppressMilliseconds, suppressSeconds, includeOffset});

[@bs.send] external toISOWeekDate: t => string = "toISOWeekDate";

[@bs.send] external toJSDate: t => Js.Date.t = "toJSDate";

[@bs.send] external toJSON: t => string = "toJSON";

[@bs.send] external toLocale: t => t = "toLocale";

type localePart = {
  [@bs.as "type"]
  type_: string,
  value: string,
};

[@bs.send] external toLocaleParts: t => array(localePart) = "toLocaleParts";

[@bs.send] external toLocaleString: t => string = "toLocaleString";

[@bs.send] external toMillis: t => int = "toMillis";

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

[@bs.send] external toRFC2822: t => string = "toRFC2822";

type toRelativeOptions = {
  base: option(t),
  locale: option(string),
  numberingSystem: option(string),
  padding: option(int),
  round: option(bool),
  style: option([@bs.string] [ | `long | `short | `narrow]),
  unit:
    option(
      [@bs.string] [
        | `year
        | `month
        | `day
        | `hour
        | `minute
        | `second
        | `millisecond
      ],
    ),
};

[@bs.send]
external toRelative: (t, toRelativeOptions) => string = "toRelative";

let toRelative =
    (
      ~base=?,
      ~locale=?,
      ~numberingSystem=?,
      ~padding=?,
      ~round=?,
      ~style=?,
      ~unit=?,
      t,
    ) =>
  toRelative(
    t,
    {base, style, unit, round, padding, locale, numberingSystem},
  );

type toRelativeCalendarOptions = {
  base: option(t),
  locale: option(string),
  numberingSystem: option(string),
  unit:
    option(
      [@bs.string] [
        | `year
        | `month
        | `day
        | `hour
        | `minute
        | `second
        | `millisecond
      ],
    ),
};

[@bs.send]
external toRelativeCalendar: (t, toRelativeCalendarOptions) => string =
  "toRelativeCalendar";

let toRelativeCalendar = (~base=?, ~locale=?, ~numberingSystem=?, ~unit=?, t) =>
  toRelativeCalendar(t, {base, unit, locale, numberingSystem});

type toSQLTimeOptions = {
  includeZone: option(bool),
  includeOffset: option(bool),
};

[@bs.send] external toSQL: (t, toSQLTimeOptions) => string = "toSQL";

let toSQL = (~includeZone=?, ~includeOffset=?, t) =>
  toSQL(t, {includeOffset, includeZone});

[@bs.send] external toSQLDate: t => string = "toSQLDate";

[@bs.send] external toSQLTime: (t, toSQLTimeOptions) => string = "toSQLTime";

let toSQLTime = (~includeZone=?, ~includeOffset=?, t) =>
  toSQLTime(t, {includeOffset, includeZone});

[@bs.send] external toSeconds: t => int = "toSeconds";

[@bs.send] external toString: t => string = "toString";

type toUTCOptions = {
  keepLocalTime: option(bool),
  offset: option(int),
};

[@bs.send] external toUTC: (t, toUTCOptions) => string = "toUTC";

let toUTC = (~keepLocalTime=?, ~offset=?, t) =>
  toUTC(t, {keepLocalTime, offset});

[@bs.send] external valueOf: t => float = "valueOf";