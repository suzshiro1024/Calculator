# Calculator

A simple calculator using stack.

## How to use?

1. Compile each file individually.
```
gcc stack.c -c
gcc parse.c -c
gcc calc.c -c
gcc main.c -c
```

2. Link all executable files.
```
gcc -o ${hoge} stack.o parse.o calc.o main.o
```

3. Prepare a file "calc.txt" with the calculation formula. -> You can skip this step.

For example, the contents of calc.txt should be as follows.
```
100+100
```

4. Run the executable file created in (2.)

When you open calc.txt, the contents should change as follows!
```
100+100=200
```

## Specifications

### Operators you can use

You can use the five operators '+', '-', '*', '/', '()'.

#### +

The operator + adds the two numbers to the left and right of itself.

However, if the operator *,/ takes either the left or right number as its argument, it will take precedence.

#### -

The operator - subtracts the two numbers to the left and right of itself.

However, if the operator *,/ takes either the left or right number as its argument, it will take precedence.

- **Caution**

  If you want to use a negative number, be sure to subtract it from other numbers.

  Don't put the number with a minus sign by itself.

  - Example

        Bad : -2200+2000
        Good: 2000-2200

        Bad : -2000
        Good: 0-2000

#### *

The operator * times the two numbers to the left and right of itself.

#### /

The operator / divides the two numbers to the left and right of itself.

- **Caution**
  This calculator only supports integers, so if the result of division is not an integer, truncation will occur.

  - Example

        10/2 = 5
        10/3 = 3
        2/3 = 0

#### ()

The operator() makes the computation in it take precedence over all other computations.

This is not related to the rule that '*,/' takes precedence over '+,-'.