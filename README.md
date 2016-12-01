# Benchmark

A simple code execution time library for Particle devices (Photon, Electron)

## Usage

```
#include "benchmark.h"

void loop() {
  uint32_t duration = Benchmark.measure([&] {
    // do long stuff here
  });

  // or measure a whole function
  uint32_t fnDuration = Benchmark.measure(longFunction);
}
```

See [complete example](examples/measure/measure.ino) in the examples directory.

## License
Copyright 2016 Julien Vanier
Released under the MIT license
