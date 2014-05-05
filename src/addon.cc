/**!
 * nan-example - src/addon.h
 *
 * Copyright(c) 2014 fengmk2 and other contributors.
 * MIT Licensed
 *
 * Authors:
 *   fengmk2 <fengmk2@gmail.com> (http://fengmk2.github.com)
 */

#include <nan.h>
#include "./types.h"
#include "./fibonacci.h"

// Expose functions
void InitAll(v8::Handle<v8::Object> exports) {
  exports->Set(NanSymbol("showTypes"),
    NanNew<v8::FunctionTemplate>(showTypes)->GetFunction());
  exports->Set(NanSymbol("fibonacci"),
    NanNew<v8::FunctionTemplate>(fibonacci)->GetFunction());
}

NODE_MODULE(addon, InitAll)
