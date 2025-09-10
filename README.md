## Push-Swap

My implementation with K sort: [github link](https://github.com/MM1132/push_swap)

### Introduction

A stack is a list of numbers. 
This project is about sorting a stack of numbers. 
There are two stacks in the program: stack A and stack B.
At first, all the entered numbers are in stack A
in the same order they were entered in the command line. 

You must implement an algorithm that prints out a list of
instructions executed on the two stacks that will by the end 
leave all the numbers in stack A and in sorted order. 

When the program is run, all the numbers are given to it as a
command-line argument(s), like this:
> ./push_swap 4 2 3 5 1

or

> ./push_swap "4 2 3 5 1"  

Of course, you must convert the numbers to integers
or longs to be able to sort them. Commonly the `ft_split` 
and `ft_atoi` functions from `libft` are used for this. 

The two most common sorting algorithms for this project are: 
- Turk Sort: The most common algorithm
- K Sort: Performs a bit better than Turk Sort, also
used commonly

Since I myself used K Sort, I will explain that one. 

### K sort explanation
#### 1. Normalizing numbers
The first step is to normalize the numbers. This means
that the lowest number in the list will always be 1. 
And the highest numbers in the list will always be the
count of how many numbers there are in total to be sorted. 

For example:  
`9999 5` becomes `2 1`  
`5 7 21 2 3` becomes `3 4 5 1 2`

#### 2. Decision Median
Before the sorting starts, we also need to calculate something called `const_decision_median`. 
It is a CONSTANT and never changes after the initial calculation. Feel free to use the `ft_sqrt` from `libft` for this. 

The formula for it is the following:  
`double const_decision_median = 1.3 * ft_sqrt(count of numbers in stack A at the very start);`

#### 3. Pushing all numbers to stack B
When the sorting starts, you have a loop. Here is the pseudo-code for it:
```
while (there are still numbers in Stack A)
    if (the first number in Stack A is <= the count of numbers currently in Stack B)
        push one element from Stack A to Stack B
        and rotate Stack B once
    else if (the first number in Stack A is <= the count of numbers currently in Stack B + const_decision_median)
        push one element from Stack A to Stack B
        BUT this time DO NOT rotate Stack B
    else
        // since the number failed the conditions to be pushed to Stack B, we will simple try with another number in Stack A next
        rotate Stack A once
```

After this small alcorithm, all the numbers should end up in Stack B and form a K formation. 
Numbers are smaller in the middle and bigger towards the start and end of the Stack B. 

#### 4. Pushing all numbers back to Stack A
Next, we just push all the numbers back to Stack A, but in a certain order. 
There is a very simple algorithm to do this as well. And here is the pseudocode for it:

```
while (there are still numbers in Stack B)
    1. find the biggest number currently in Stack B and bring it to the very top of the stack (you can use `rb` and `rrb` for this)
    2. push the number on the top of Stack B into Stack A
```

#### 5. You are done
One the 4 above steps have been executed, all the numbers should be stored in Stack A. 
All you have to do is to print out the corresponding instruction whenever you move a number. 

Hope it helped, but if it did not help, feel free to send me an email. Address can be found under [reimann.ee](https://reimann.ee/)
