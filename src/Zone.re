/** https://moment.github.io/luxon/docs/class/src/zone.js~Zone.html */

type t;

[@bs.send] external isValid: t => bool = "isValid";

[@bs.send] external name: t => string = "name";

[@bs.send] external type_: t => string = "type";

[@bs.send] external universal: t => bool = "universal";

[@bs.send] external equals: (t, t) => bool = "name";

module OffsetFormat = {
  type t = string;

  [@bs.inline]
  let long = "long";

  [@bs.inline]
  let short = "short";
};

[@bs.send]
external formatOffset: (t, float, OffsetFormat.t) => bool = "formatOffset";

[@bs.send] external offset: (t, float) => float = "offset";

type options = {
  format: OffsetFormat.t,
  locale: string,
};

[@bs.send] external offsetName: (t, float, options) => string = "name";

module IANA = {
  /** https://moment.github.io/luxon/docs/class/src/zones/IANAZone.js~IANAZone.html */ 

  [@bs.module "luxon"] [@bs.scope "IANAZone"]
  external create: string => t = "create";

  [@bs.module "luxon"] [@bs.scope "IANAZone"]
  external isValidSpecifier: string => bool = "isValidSpecifier";

  [@bs.module "luxon"] [@bs.scope "IANAZone"]
  external isValidZone: string => bool = "isValidZone";

  [@bs.module "luxon"] [@bs.scope "IANAZone"]
  external resetCache: unit => unit = "resetCache";
};

module FixedOffset = {
  /** https://moment.github.io/luxon/docs/class/src/zones/fixedOffsetZone.js~FixedOffsetZone.html */

  [@bs.module "luxon"] [@bs.scope "FixedOffsetZone"] [@bs.val]
  external utcInstance: t = "utcInstance";

  [@bs.module "luxon"] [@bs.scope "FixedOffsetZone"]
  external instance: float => t = "instance";

  [@bs.module "luxon"] [@bs.scope "FixedOffsetZone"]
  external parseSpecifier: string => t = "parseSpecifier";

  [@bs.send]
  external formatOffset: t => string = "formatOffset";

  [@bs.send]
  external offset: t => int = "offset";

  [@bs.send]
  external offsetName: t => string = "offsetName";
};
[@bs.module "luxon"] [@bs.scope "FixedOffsetZone"] [@bs.val]
external utc: t = "utcInstance";

module Invalid = {
  /** https://moment.github.io/luxon/docs/class/src/zones/invalidZone.js~InvalidZone.html */
  [@bs.module "luxon"]
  [@bs.new] external make: unit => t = "InvalidZone";
};

[@bs.module "luxon"] [@bs.new] 
external invalid: unit => t = "InvalidZone";

module Local = {
  /** https://moment.github.io/luxon/docs/class/src/zones/localZone.js~LocalZone.html */
  [@bs.module "luxon"] [@bs.scope "LocalZone"] [@bs.val]
  external instance: t = "instance";
};
[@bs.module "luxon"] [@bs.scope "LocalZone"] [@bs.val]
external local: t = "create";