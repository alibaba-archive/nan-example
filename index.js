/**!
 * nan-example - index.js
 *
 * Copyright(c) fengmk2 and other contributors.
 * MIT Licensed
 *
 * Authors:
 *   fengmk2 <fengmk2@gmail.com> (http://fengmk2.github.com)
 */

'use strict';

/**
 * Module dependencies.
 */

var addon = require('./build/Release/addon');

console.log(addon);

console.log(addon.showTypes());

function fibonacci(n) {
  if (arguments.length === 0) {
    n = 40;
  }
  if (n === 0 || n === 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

var start = Date.now();
var v = addon.fibonacci();
var use = Date.now() - start;
console.log('fibonacci()   cpp: %d, %dms', v, use);
var start = Date.now();
var v = addon.fibonacci(40);
var use = Date.now() - start;
console.log('fibonacci(40) cpp: %d, %dms', v, use);

var start = Date.now();
var v = fibonacci();
var use = Date.now() - start;
console.log('fibonacci()    js: %d, %dms', v, use);
var start = Date.now();
var v = fibonacci(40);
var use = Date.now() - start;
console.log('fibonacci(40)  js: %d, %dms', v, use);
