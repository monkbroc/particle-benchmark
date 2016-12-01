/* A library to measure how long code takes to run
 *
 * Copyright 2016, Julien Vanier
 * Released under the MIT license
 */
#pragma once

#include "application.h"
#include "spark_wiring_system.h"

class BenchmarkClass
{
public:
  /* measure
   * Runs the lambda `_work` and returns how long it took in microseconds
   */
  template<typename Work> static uint32_t measure(Work _work) {
    uint32_t start = micros();
    _work();
    return micros() - start;
  }

  /* measure
   * Runs the function `_work` and returns how long it took in microseconds
   */
  static uint32_t measure(void (*_work)(void)) {
    uint32_t start = micros();
    _work();
    return micros() - start;
  }
};

extern BenchmarkClass Benchmark;
