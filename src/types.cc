/**!
 * nan-example - src/types.cc
 *
 * Copyright(c) 2014 fengmk2 and other contributors.
 * MIT Licensed
 *
 * Authors:
 *   fengmk2 <fengmk2@gmail.com> (http://fengmk2.github.com)
 */

#include <nan.h>
#include "./types.h"

// function showTypes() {}
NAN_METHOD(showTypes) {
  NanScope();

  // var foo;
  // var bar = null;
  v8::Local<v8::Value> foo = NanUndefined();
  v8::Local<v8::Value> bar = NanNull();
  v8::Handle<v8::Value> bar2 = NanNull();

  // var t = true;
  // var f = false;
  v8::Local<v8::Boolean> t = NanTrue();
  v8::Local<v8::Boolean> f = NanFalse();

  // var v1 = 100;
  // var v2 = 1024.123;
  // var v3 = 0.123456789;
  v8::Local<v8::Number> v1 = NanNew<v8::Number>(100);
  v8::Local<v8::Number> v2 = NanNew<v8::Number>(1024.123);
  v8::Handle<v8::Number> v3 = NanNew<v8::Number>(0.123456789);

  // var s1 = '';
  // var s2 = 'hello world';
  // var s3 = 'no ascii 还有中文';
  v8::Local<v8::String> s1 = NanNew<v8::String>("");
  v8::Local<v8::String> s2 = NanNew<v8::String>("hello world");
  v8::Local<v8::String> s3 = NanNew<v8::String>("no ascii 还有中文");

  // var now = new Date(1399273631054);
  double timestamp = 1399273631054;
  v8::Local<v8::Date> now = NanNew<v8::Date>(timestamp);

  // var result = {};
  // result['undefined'] = foo;
  // result['null'] = bar;
  // result['null2'] = bar2;
  // result['true'] = t;
  // result['false'] = f;
  // result['v1'] = v1;
  // result['v2'] = v2;
  // result['v3'] = v3;
  // result['s1'] = s1;
  // result['s2'] = s2;
  // result['s3'] = s3;
  // result.now = now;
  v8::Local<v8::Object> result = NanNew<v8::Object>();
  result->Set(NanSymbol("undefined"), foo);
  result->Set(NanSymbol("null"), bar);
  result->Set(NanSymbol("null2"), bar2);
  result->Set(NanSymbol("true"), t);
  result->Set(NanSymbol("false"), f);
  result->Set(NanSymbol("v1"), v1);
  result->Set(NanSymbol("v2"), v2);
  result->Set(NanSymbol("v3"), v3);
  result->Set(NanSymbol("s1"), s1);
  result->Set(NanSymbol("s2"), s2);
  result->Set(NanSymbol("s3"), s3);
  result->Set(NanSymbol("now"), now);

  // var arr = [];
  // arr.push(foo);
  // arr.push(bar);
  // arr.push(bar2);
  // arr.push(t);
  // arr.push(f);
  // arr.push(v1);
  // arr.push(v2);
  // arr.push(v3);
  // arr.push(s1);
  // arr.push(s2);
  // arr.push(s3);
  // arr.push(now);
  int index = 0;
  v8::Local<v8::Array> arr = NanNew<v8::Array>();
  arr->Set(index++, foo);
  arr->Set(index++, bar);
  arr->Set(index++, bar2);
  arr->Set(index++, t);
  arr->Set(index++, f);
  arr->Set(index++, v1);
  arr->Set(index++, v2);
  arr->Set(index++, v3);
  arr->Set(index++, s1);
  arr->Set(index++, s2);
  arr->Set(index++, s3);
  arr->Set(index++, now);

  result->Set(NanSymbol("array"), arr);
  result->Set(NanSymbol("array-length"), NanNew<v8::Number>(arr->Length()));

  NanReturnValue(result);
}
