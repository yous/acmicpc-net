# Baekjoon Online Judge

[Baekjoon Online Judge][] in Ruby.

## Requirements

- Ruby 1.8.7 (2011-06-30 patchlevel 352) [i686-linux]
- Ruby 1.9.3p0 (2011-10-30 revision 33570) [i686-linux]

## About

Each project directory has some of these files:

- `input`: STDIN input to `.rb` file
- `output`: STDOUT output `.rb` file should print
- `main.new.rb`: Code compatible with Ruby 1.9.3p0
- `short.new.rb`: Compressed code compatible with Ruby 1.9.3p0
- `main.old.rb`: Code compatible with Ruby 1.8.7-p352
- `short.old.rb`: Compressed code compatible with Ruby 1.8.7-p352

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
