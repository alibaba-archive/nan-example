/**!
 * nan-example - src/fibonacci.cc
 *
 * Copyright(c) 2014 fengmk2 and other contributors.
 * MIT Licensed
 *
 * Authors:
 *   fengmk2 <fengmk2@gmail.com> (http://fengmk2.github.com)
 */

#include <nan.h>
#include "./fibonacci.h"

int _fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return _fibonacci(n - 1) + _fibonacci(n - 2);
}

// function fibonacci(n = 40) {}
NAN_METHOD(fibonacci) {
  NanScope();

  int n;

  if (args.Length() == 0 || !args[0]->IsNumber()) {
    n = 40;
  } else {
    n = args[0]->ToNumber()->Value();
  }

  NanReturnValue(NanNew<v8::Number>(_fibonacci(n)));
}
