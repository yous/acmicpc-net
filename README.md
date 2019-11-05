# Baekjoon Online Judge

[Baekjoon Online Judge][] in Ruby.

## Requirements

- Ruby 1.8.7 (2011-06-30 patchlevel 352) [i686-linux]
- Ruby 1.9.3p0 (2011-10-30 revision 33570) [i686-linux]
- Ruby 2.6.5p114 (2019-10-01 revision 67812) [x86_64-linux]

## About

Each project directory has some of these files:

- `input*`: STDIN input to `.rb` file
- `output*`: STDOUT output `.rb` file should print
- `ruby-1.8*.rb`: Code compatible with Ruby 1.8.7-p352
- `ruby-1.9*.rb`: Code compatible with Ruby 1.9.3p0
- `ruby-2.5*.rb`: Code compatible with Ruby 2.6.5p114
- `*.short*.rb`: Compressed code

## Testing

To run the test of the problem 1000:

``` sh
rake test[1000]
```

You can also run all tests with:

``` sh
rake test
```

## [Help][]

[Baekjoon Online Judge]: https://www.acmicpc.net
[Help]: https://www.acmicpc.net/help/judge
