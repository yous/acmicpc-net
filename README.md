# Baekjoon Online Judge

[![Build Status](https://travis-ci.org/yous/acmicpc-net.svg?branch=master)](https://travis-ci.org/yous/acmicpc-net)

Solutions of [Baekjoon Online Judge][].

## Languages

- C++11
- Ruby 1.8.7 (2011-06-30 patchlevel 352) [i686-linux]
- Ruby 1.9.3p0 (2011-10-30 revision 33570) [i686-linux]
- Ruby 2.6.5p114 (2019-10-01 revision 67812) [x86_64-linux]

## About

Each project directory has some of these files:

- `input*`: STDIN input to the program
- `output*`: STDOUT output of the program that should be printed
- `main.cpp`: Code compatible with C++11
- `ruby-1.8*.rb`: Code compatible with Ruby 1.8.7-p352
- `ruby-1.9*.rb`: Code compatible with Ruby 1.9.3p0
- `ruby-2.5*.rb`: Code compatible with Ruby 2.6.5p114
- `*.short*.rb`: Compressed Ruby code

## Testing

To run the test of the problem 1000:

``` sh
rake spec SPEC_OPTS="-E '^1000 '"
```

``` sh
rake spec SPEC_OPTS='-e 1000'
```

``` sh
rspec -e 1000
```

``` sh
cd problem/1000
g++ main.cpp -O2 -Wall -lm -std=c++11 && diff -y --suppress-common-lines output <(./a.out input)
```

You can also run all tests with:

``` sh
rake spec
```

## [Help][]

[Baekjoon Online Judge]: https://www.acmicpc.net
[Help]: https://www.acmicpc.net/help/judge
