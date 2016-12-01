/* Measure how long something took in your firmware
 */

#include "benchmark.h"

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

// A long operation: averaging many analog readings
uint16_t averageAnalog(pin_t pin, uint16_t count)
{
    uint32_t total = 0;
    for (uint16_t i = 0; i < count; i++) {
      total += analogRead(pin);
    }

    return total / count;
}

void anotherLongOperation()
{
  pinMode(D7, OUTPUT);
  for (int i = 0; i < 1000; i++) {
    digitalWrite(D7, HIGH);
    digitalWrite(D7, LOW);
  }
}

void loop()
{
  // Measure a long operation
  uint16_t average;
  // The stuff inside the [&]{ } is called a lambda. It allows passing
  // code as function arguments. Cool!
  uint32_t duration = Benchmark.measure([&] {
    average = averageAnalog(A0, 1000);
  });
  Serial.printlnf("It took %d us to get this average reading: %d", duration, average);

  // You can also measure a void function() { } directly
  uint32_t fnDuration = Benchmark.measure(anotherLongOperation);
  Serial.printlnf("It took %d us to toggle the D7 LED a bunch of times");
}
