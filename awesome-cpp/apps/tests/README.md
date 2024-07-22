# A Quick Guide for gtest

This page was created based on GoogleTest(gtest).

## Test

* unit test
* integration test

## Simple Tests

To create a test:

1. Use the TEST() macro to define and name a test function. These are ordinary C++ functions that don’t return a value.
2. In this function, along with any valid C++ statements you want to include, use the various googletest assertions to check values.
3. The test’s result is determined by the assertions; if any assertion in the test fails (either fatally or non-fatally), or if the test crashes, the entire test fails. Otherwise, it succeeds.

```cpp
TEST(TestSuiteName, TestName) {
  ... test body ...
}
```

## Reference

<https://google.github.io/googletest/>
