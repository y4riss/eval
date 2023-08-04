This is a little project that evaluates an arithmetic expression and produces the expected result.

I made this project as a manner of practice after reading about `recursive descent parsing` in [craftinginterpreters](https://craftinginterpreters.com/) , which is a very good resource for those interested in compilers.


# Compiling

Straight forward as it is , just type make :)
```
make
```

if everything is ok, the following message should appear :
```
eval created
```

# Example of Usage

```
./eval

Welcome to eval, a simple arithmetic expression evaluator !
If you want to quit, type exit.

> 1 + 1
2
> (8 - 2) * ((9 + 3) - 7) / 5
6
> exit
```

# Theory

for the nerds out there , here is how the parser works :
First, we need a grammar, i came up with this one :

```
expression -> term
term       -> factor ( '+' | '-' factor )*
factor     -> unary  ( '*' | '/' | '%' unary )*
unary      -> '-'* primary
primary    -> NUMBER
```

Now for this parser, a correct arithmetic expression is one that can be derived from this grammar.
The implementation is replacing each production rule with a function.

For example , `expression -> term` becomes `function expression() {return term() }` (pseudo code)
