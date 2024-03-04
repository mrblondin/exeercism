#!/usr/bin/env node

// The above line is a shebang. On Unix-like operating systems, or environments,
// this will allow the script to be run by node, and thus turn this JavaScript
// file into an executable. In other words, to execute this file, you may run
// the following from your terminal:
//
// ./grep.js args
//
// If you don't have a Unix-like operating system or environment, for example
// Windows without WSL, you can use the following inside a window terminal,
// such as cmd.exe:
//
// node grep.js args
//
// Read more about shebangs here: https://en.wikipedia.org/wiki/Shebang_(Unix)

const fs = require('fs');
const path = require('path');

/**
 * Reads the given file and returns lines.
 *
 * This function works regardless of POSIX (LF) or windows (CRLF) encoding.
 *
 * @param {string} file path to file
 * @returns {string[]} the lines
 */
function readLines(file) {
  const data = fs.readFileSync(path.resolve(file), { encoding: 'utf-8' });
  return data.split(/\r?\n/);
}

const VALID_OPTIONS = [
  'n', // add line numbers
  'l', // print file names where pattern is found
  'i', // ignore case
  'v', // reverse files results
  'x', // match entire line
];

const ARGS = process.argv;
const files = [], flags = [];
let pattern;

for (const arg of ARGS.slice(2)){
  if (arg.startsWith('-') && arg.length === 2){
    if (VALID_OPTIONS.includes(arg.charAt(1)))
      flags.push(arg.charAt(1));
  }
  else if (!pattern) pattern = flags.includes('i') ? arg.toLowerCase() : arg; 
  else files.push(arg)
}

const is_lnumber     = flags.includes('n');
const is_file_name   = flags.includes('l');
const is_ignore_case = flags.includes('i');
const is_reverse     = flags.includes('v');
const is_entire_line = flags.includes('x')

files.forEach(f => {
  readLines(f).every((line, index) => {
    let test_line = is_ignore_case ? line.toLowerCase() : line;
    const is_match = test_line === pattern || 
      (!is_entire_line && test_line.includes(pattern));
    if ((is_match && !is_reverse) || (!is_match && is_reverse)) {
      if (is_file_name) {console.log(f); return false;}
      console.log((files.length > 1 ? `${f}:` : '') + 
        (is_lnumber ? `${index + 1}:` : '') + line);
    }
    return true;
  });
});
