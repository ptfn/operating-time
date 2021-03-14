# This gives an introduction to Python in 15 minutes.


############################################
## 1. Primitive Data Types and Operators
############################################


## Numbers

1234, -24, +42, 0 # interger
1.23, 3.14e-10, 4E210, 4.0e+210 # float
0o177, 0x9ff 0b1111 # binary, octal, hexadecimal
3+4j, 3.0+4.0j, 3J # complex numbers

# Operators

1 + 1  # => 2
7 - 1  # => 6
5 * 2  # => 10
6 / 3  # => 2
3 / 4  # => 0.75
3 / 9  # => 0.3333333333333333
5 // 2  # => 2
5 % 2  # => 1
2 ** 4  # => 16

#Bite Operators

5 | 3  # => 7 Or
3 ^ 9  # => 10 Xor
9 & 5  # => 1 And
~9  # => -10 Bit inversion
5 << 2  # => 20 Bit shift left
5 >> 2  # => 1 Bit shift right

## Booleans

# True and False
not True  # => False
not False  # => True
False and 0  # => False
False or 0  # => 0

## Characters

"Hello World!"
"Benjamin \"Bugsy\" Siegel"
"Foo\tbar\x21\n"
# Print string
print("Hello World!")
# and unicode escapes
"\u004B"  # => 'K'

## Strings

# Basic operations
# Concatenation (addition)
"Hello" + "World!"  # => "HelloWorld!"
# Duplicate a line
"Foo" * 3  # => "FooFooFoo"
# Line length
len("Test")  # => 4
# Index access
S = "Spam"
S[1]  # => "a"
# Format string
"Hello {}".format("World!")


############################################
## 2. Variables
############################################

# You can create a variable using define
# a variable name can use any character except: ()[]{}",'`;#|\
S = "spam"
S  # => "spam"

# Accessing a previously unassigned variable is an exception
# S  => name 's' is not defined

## Type
name = "Tom"
print(type(name))  # => str
num = 123
print(type(num))  # => int

## Assignment operators
num = 4
num1, num2 = 9
num1, num2 = 10, 4
num += 5


############################################
## 3. Structs and Collections
############################################


## Lists
[]
[0, 1, 2, 3]
L = [1 ,[1, 2]]
L = list("spam")
L = [x**2 for x in range(9)]

## Dicts
{}
{"spam":2, "eggs":3}
D = dict(name = "Bob", age = 45, job = ("mgt", "dev"))

## Tuples
()
(0,)
(0, 1, 2, 3)
0, 1, 2, 3


############################################
## 4. Functions
############################################
