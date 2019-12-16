# reason-luxon

> [BuckleScript](https://bucklescript.github.io/en) bindings to [Luxon](https://moment.github.io/luxon/index.html)

## Installation

`npm install reason-luxon luxon --save`

Then add `reason-luxon` to `bs-dependencies` in `bsconfig.json`

```json
{  
  "bs-dependencies": [    
    "reason-luxon"
  ],
}
```

## Usage

```reason
open Luxon

let start = DateTime.(
  local()
  ->setZone(Zone.IANA.create("America/New_York"))
  ->minus(Duration.make(~weeks=1., ()))
  ->endOf(`day)  
);

let end_ = start->DateTime.plus(Duration.make(~weeks=1.0, ()))

Interval.fromDateTimes(start, end_)
->Interval.toString
```

## Documentation

Each `.rei` file contains a link to the relevant Luxon documentation:

- [DateTime](./src/DateTime.rei)
- [Duration](./src/Duration.rei)
- [Info](./src/Info.rei)
- [Interval](./src/Interval.rei)
- [Settings](./src/Settings.rei)
- [Zone](./src/Zone.rei)

## Contributing / Status

The following Luxon APIs are not complete, either due to the Luxons docs being a little lacking, the binding being a little tricky or the current binding is missing some options which the Luxon API would accept.

Pull requests are very much appreciated:

- [DateTime.fromFormatExplain](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#static-method-fromFormatExplain)
- [DateTime.resolvedLocaleOpts](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#instance-method-resolvedLocaleOpts)
- [DateTime.toFormat](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#instance-method-toFormat)
- [DateTime.toLocaleString](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#instance-method-toLocaleString)
- [DateTime.toObject](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#instance-method-toObject)
- [DateTime.toRelative](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#instance-method-toRelative)

- [Duration.toObject](https://moment.github.io/luxon/docs/class/src/datetime.js~DateTime.html#instance-method-toObject)
- [Duration.reconfigure](https://moment.github.io/luxon/docs/class/src/duration.js~Duration.html#instance-method-reconfigure)
