module Eras: {
  type t;
  let narrow: t;
  let short: t;
  let long: t;
  let fromString: string => t;
};

let eras: (~length: Eras.t=?, ~locale: string=?, unit) => array(string);

type features = {
  intl: bool,
  intlTokens: bool,
  zones: bool,
  relative: bool,
};

[@bs.module "luxon"] [@bs.scope "Info"]
external features: unit => features = "features";

[@bs.module "luxon"] [@bs.scope "Info"]
external hasDST: Zone.t => bool = "hasDST";

[@bs.module "luxon"] [@bs.scope "Info"]
external isValidIANAZone: string => bool = "isValidIANAZone";

let meridiems: (~locale: string=?, unit) => array(string);

module Month: {
  type t;
  let narrow: t;
  let short: t;
  let long: t;
  let numeric: t;
  let twoDigit: t;
  let fromString: string => t;
};

let months:
  (
    ~length: Month.t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    unit
  ) =>
  array(string);

let monthsFormat:
  (
    ~length: Month.t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    ~outputCalendar: string=?,
    unit
  ) =>
  array(string);

[@bs.module "luxon"] [@bs.scope "Info"]
external normalizeZone:
  ([@bs.unwrap] [ | `IANA(string) | `Zone(Zone.t) | `FixedOffset(int)]) =>
  Zone.t =
  "normalizeZone";

module Weekday: {
  type t;
  let narrow: t;
  let short: t;
  let long: t;
  let numeric: t;
  let fromString: string => t;
};

let weekdays:
  (
    ~length: Weekday.t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    unit
  ) =>
  array(string);

let weekdaysFormat:
  (
    ~length: Weekday.t=?,
    ~locale: string=?,
    ~numberingSystem: string=?,
    unit
  ) =>
  array(string);