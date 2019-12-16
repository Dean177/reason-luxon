/** https://moment.github.io/luxon/docs/class/src/interval.js~Interval.html */

type t;

let after: (DateTime.t, Duration.t) => t;

let before: (DateTime.t, Duration.t) => t;

let fromDateTimes: (DateTime.t, DateTime.t) => t;

// TODO docs suck, which options are permitted?
let fromISO:
  (
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~conversionAccuracy: ConversionAccuracy.t=?,
    // TODO are these valid
    ~zone: Zone.t=?,
    ~setZone: bool=?,
    ~outputCalendar: string=?,
    // TODO end ???
    string
  ) =>
  t;

let invalid: (~explanation: string=?, string) => t;

let isInterval: t => bool;

let merge: array(t) => t;

let xor: array(t) => array(t);

let end_: t => DateTime.t;

let invalidExplanation: t => string;

let invalidReason: t => string;

let isValid: t => bool;

let start: t => DateTime.t;

let abutsEnd: (t, t) => bool;

let abutsStart: (t, t) => bool;

let contains: (t, DateTime.t) => bool;

let count:
  (
    ~unit: [@bs.string] [
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
             =?,
    t
  ) =>
  int;

let difference: (t, array(t)) => bool;

let divideEqually: (t, int) => array(t);

let engulfs: (t, t) => bool;

let equals: (t, t) => bool;

let hasSame:
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
  bool;

let intersection: (t, t) => t;

let isAfter: (t, DateTime.t) => bool;

let isBefore: (t, DateTime.t) => bool;

let isEmpty: t => bool;

// TODO can this only return integers?
let length:
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
  float;

[@bs.send]
external mapEndpoints: (t, DateTime.t => DateTime.t) => t = "mapEndpoints";

let overlaps: (t, t) => bool;

let set: (~start: DateTime.t=?, ~end_: DateTime.t=?, t) => t;

let splitAt: (t, array(DateTime.t)) => array(t);

let splitBy: (t, Duration.t) => array(t);

let toDuration:
  (
    ~conversionAccuracy: ConversionAccuracy.t=?,
    ~unit: [@bs.string] [
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
             =?,
    t
  ) =>
  Duration.t;

let toFormat: (~separator: string=?, t, DateTime.Format.t) => string;

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

let toString: t => string;

let union: (t, t) => t;