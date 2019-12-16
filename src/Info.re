type localeOptions = {locale: option(string)};

type localeAndNumberingSystemOptions = {
  locale: option(string),
  numberingSystem: option(string),
};

module Eras = {
  type t = string;
  let narrow = "narrow";
  let short = "short";
  let long = "long";
  external fromString: t => string = "%identity";
};

[@bs.module "luxon"] [@bs.scope "Info"]
external eras: (option(Eras.t), localeOptions) => array(string) = "eras";

let eras = (~length=?, ~locale=?, ()) => eras(length, {locale: locale});

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

[@bs.module "luxon"] [@bs.scope "Info"]
external meridiems: localeOptions => array(string) = "meridiems";

let meridiems = (~locale=?, ()) => meridiems({locale: locale});

module Month = {
  type t = string;
  let narrow: t = "narrow";
  let short: t = "short";
  let long: t = "long";
  let numeric: t = "numeric";
  let twoDigit: t = "2-digit";
  external fromString: t => string = "%identity";
};

type monthsOptions = {
  locale: option(string),
  numberingSystem: option(string),
  outputCalendar: option(string),
};

[@bs.module "luxon"] [@bs.scope "Info"]
external months: (option(Month.t), monthsOptions) => array(string) =
  "months";

let months = (~length=?, ~locale=?, ~numberingSystem=?, ~outputCalendar=?, ()) =>
  months(length, {locale, numberingSystem, outputCalendar});

[@bs.module "luxon"] [@bs.scope "Info"]
external monthsFormat: (option(Month.t), monthsOptions) => array(string) =
  "monthsFormat";

let monthsFormat =
    (~length=?, ~locale=?, ~numberingSystem=?, ~outputCalendar=?, ()) =>
  monthsFormat(length, {locale, numberingSystem, outputCalendar});

[@bs.module "luxon"] [@bs.scope "Info"]
external normalizeZone:
  ([@bs.unwrap] [ | `IANA(string) | `Zone(Zone.t) | `FixedOffset(int)]) =>
  Zone.t =
  "normalizeZone";

module Weekday = {
  type t = string;
  let narrow: t = "narrow";
  let short: t = "short";
  let long: t = "long";
  let numeric: t = "numeric";
  external fromString: t => string = "%identity";
};

[@bs.module "luxon"] [@bs.scope "Info"]
external weekdays:
  (option(Weekday.t), localeAndNumberingSystemOptions) => array(string) =
  "weekdays";

let weekdays = (~length=?, ~locale=?, ~numberingSystem=?, ()) =>
  weekdays(length, {locale, numberingSystem});

[@bs.module "luxon"] [@bs.scope "Info"]
external weekdaysFormat:
  (option(Weekday.t), localeAndNumberingSystemOptions) => array(string) =
  "weekdaysFormat";

let weekdaysFormat = (~length=?, ~locale=?, ~numberingSystem=?, ()) =>
  weekdaysFormat(length, {locale, numberingSystem});