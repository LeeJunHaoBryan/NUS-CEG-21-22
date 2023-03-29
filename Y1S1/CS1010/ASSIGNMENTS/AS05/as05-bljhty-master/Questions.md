# Question 1: Kendall (8 Marks)
-------------------------------

Suppose that we are given a set of items and we ask two
different parties to rank the items according to some order.
We may get two different orders of the items. How do we
measure how similar (or dissimilar) the two rankings are?

For example, consider a search engine that returns a list of
web pages ranked by their relevance to the search query. A
user may not always agree with the ranking of the search
engine and may judge the relevance of the search result
differently, i.e., the user may have his or her own ranking.
This measurement of similarity between the ranking by the
search engine and the ranking by the user gives us a metric
on how good the search engine result is. The more similar it
is to the ranking of the user, the better the search engine
is in ranking in the search results.

One way to measure the similarity of two rankings is the
Kendall tau distance. You will write a program `kendall` that
calculates the normalized Kendall tau distance for this
question.

We will represent a ranking by the order of the items. The
first item is ranked 1, the second is ranked 2, and so on. To
simplify the problem, we take one of the rankings that we
want to calculate the Kendall tau distance on, and label the
items sequentially, as the sequence 1, 2, 3, 4, 5, ... n,
where n is the number of items. We call this the base
ranking. The other ranking will then be a permutation of the
numbers 1 to n.

For example, suppose we have three items A, B, C. The first
ranking ranks the items as B, C, A. The second ranking ranks
the items C, A, B. After relabelling the first ranking as 1,
2, 3, the second ranking becomes 2, 3, 1.

The Kendall tau distance counts the number of pairs of items
in one ranking that are ranked in a different order in the other
ranking. In the example above, we have three possible pairs:

Pair | Ranking 1 | Ranking 2
-----|-----------|----------
A-B  | B then A  | A then B
A-C  | C then A  | C then A
B-C  | B then C  | C then B

Out of the three pairs, the pair A-B and B-C are ordered
differently in the two rankings, so that Kendall tau
distance is 2.

The normalized Kendall tau distance is the ratio of the
number of pairs ranked in a different order to all possible
number of pairs.

In the example above, the normalized Kendall distance is
2/3 = 0.6666.

Your program should read the following from the standard
input:

- The first positive integer, n, is the number of items
  (n > 1).  
- The next n numbers is a permutation of integers between
  1 to n. This corresponds to the ranking of the items
  from 1 to n.

Your program should print the normalized Kendall tau
distance between the ranking read above and the base ranking
(1, 2, 3, .. n) to the standard output.

Your program must not assume any limit to the length of the 
input, except that their length can fit into the type `size_t`.

#### Grading Criteria
---------------------

|               | Marks |
|---------------|-------|
| Style         | 1     |
| Documentation | 2     |
| Correctness   | 5     |

Your solution must contain at least one documented non-
trivial function other than main() to receive the 
documentation mark.

### Sample Runs
---------------
```
ooiwt@pe118:~/as03-skeleton$ ./kendall
3
2 3 1
0.6667
ooiwt@pe118:~/as03-skeleton$ ./kendall
10
1 2 3 4 5 6 7 8 9 10
0.0000
ooiwt@pe118:~/as03-skeleton$ ./kendall
6
6 5 4 3 2 1
1.0000
```


# Question 2: Counting Sort (10 Marks)
--------------------------------------

Sorting is a fundamental computational problem: given a list
of items, we want to rearrange the items in some order.

In this question, you will write your first sorting
algorithm, called counting sort. This is an extremely fast
algorithm for sorting positive integers if the range of the
integers is limited.

The idea of counting sort is that, given the list of
integers (each guaranteed to be between 1 to k) to sort, we
first count how many times each number appear in the list.  
Then, we print out each number between 1 to k, according to 
how many times they appear in the list, skipping those 
numbers who do not appear.

For instance, suppose we have 6 integers between 1 to 9:

 5 5 3 2 8 2

We first count how many times each number appears. Then we
print the sorted list the following way: 2 appears twice, so
we print

2
2

The number 3 appears once, we print

3

The number 5 appears twice, we print

5
5

Finally, 8 appears once, we print

8

The sorted output is thus

2
2
3
5
5
8

which is the numbers sorted in increasing order.

Write a program countingsort.c that reads the following in
order from the standard input:

-  n, the number of integers to sort.
-  The next n numbers are the integers to be sorted, each
   guaranteed to be between 0 and 10000.

Sort the integers using the algorithms above and print, to
the standard output: 

- The numbers in the input, in increasing order.  One number
  per line.

Note that if you use any other algorithms to sort the
numbers, you will be penalized heavily.

Your program must not assume any limit to the length of
the input, except that their length can fit into the type
`size_t`.

#### Grading Criteria
---------------------

|               | Marks |
|---------------|-------|
| Style         | 1     |
| Documentation | 2     |
| Efficiency    | 3     |
| Correctness   | 4     |

To obtain full marks for efficiency, your code must not 
loop through your arrays more times than necessary.

Your solution must contain at least one documented, non-
trivial, function other than main() to receive the 
documentation mark.

### Sample Runs
---------------
```
ooiwt@pe118:~/as03-skeleton$ ./countingsort
6
5 5 3 2 8 2
2
2
3
5
5
8
ooiwt@pe118:~/as03-skeleton$ ./countingsort
3
256 872 112
112
256
872
```


# Question 3: Add (12 marks)
----------------------------

In this question, you are asked to write a program that adds
two non-negative numbers which can be arbitrarily large.
The types provided by C can only represent a number up to a
certain value.  We have seen that `long long int` is not
even big enough to represent 21!.

For this question, we will represent a number using an
arbitrarily long string consisting of characters (of type
`char`) `'0'` to `'9'` (note: not integer 0 to 9).  C
supports arithmetic operations on `char` values as well.  To
convert between the numerical value of a digit character, we
can do the following:

- To convert from a digit character to its numerical value,
  we subtract the `char` '0'.  For instance, '6' - '0'
  will give us the value 6.

- To convert from a numerical value of a digit to its
  character, we add the `char` '0'.  For instance, 6 + '0'
  will give us the character '6'.

Write a program `add` that reads from the standard input two
non-negative numbers represented as strings consisting of
digits '0' to '9', and prints to the standard output the sum
of the two numbers.

You will likely need to use the C standard library function
`strlen`, which returns you the number of characters in a
string (excluding the terminating '\0').  Look up on how to
use this function on your own.  You might need casting of
the return value to avoid warnings.

Your program must not assume any limit to the length of
the input, except that their length can fit into the type
`size_t`.

In particular, you must not convert the input string to 
an integer before adding, since if the input string is 
long enough it would not fit into a C integer type.

#### Grading Criteria
---------------------

|               | Marks |
|---------------|-------|
| Style         | 1     |
| Documentation | 2     |
| Correctness   | 9     |

Your solution must contain at least one documented, non-
trivial, function other than main() to receive the 
documentation mark.

### Sample Runs
---------------

```
ooiwt@pe119:~/as06-skeleton$ ./add
1
1
2
ooiwt@pe119:~/as06-skeleton$ ./add
7
8
15
ooiwt@pe119:~/as06-skeleton$ ./add
999999
1
1000000
ooiwt@pe119:~/as04-skeleton$ ./add
1400060514000605140006051400605
19330911933091193309119330911933091
19332311993605193914259336963333696
```

