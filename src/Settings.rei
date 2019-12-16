// let defaultLocale: ref(string);

// let defaultNumberingSystem: ref(string);

// let defaultOutputCalendar: ref(string);

// // TODO can one not set the default zone?
// let defaultZone: Zone.t;

// let defaultZoneName: ref(string);

// let now: ref(unit => int);

// let throwOnInvalid: ref(bool);

[@bs.module "luxon"] [@bs.scope "Settings"]
external resetCaches: unit => unit = "resetCaches";