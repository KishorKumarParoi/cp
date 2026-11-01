# [Codeforces #2278A] Fraction and Six

**Time Limit:** 1 second
**Memory Limit:** 256 megabytes
**Difficulty:** Unrated

## Description

## Problem

You are given two strings pp and qq, consisting of lowercase English letters.

Interpret the string pp as the product of variables written in the numerator of a fraction, and the string qq as the product of variables written in the denominator. Each character represents a variable.

Since multiplication is commutative, the variables in both the numerator and the denominator may be reordered arbitrarily. In addition, any variable that appears in both the numerator and the denominator may be cancelled. Note that a single occurrence of a variable in the denominator can only cancel exactly one occurrence of that variable in the numerator and vice versa.

Determine whether it is possible to simplify the fraction so that the resulting expression is exactly equal to the string six\texttt{six}. In other words, after performing any number of cancellations and rearrangements, the remaining variables in the numerator must form the string six\texttt{six}, and no variables may remain in the denominator.

For example, if p=sinxp=\texttt{sinx} and q=nq=\texttt{n}, then the variable n\texttt{n} can be cancelled, leaving six\texttt{six} in the numerator.

 ![](https://espresso.codeforces.com/1ac4929438e4908210cb2bb8872c7d6702fcd18f.png)    

## Input

The first line of the input contains a single integer tt (1≤t≤1001 \le t \le 100) — the number of test cases. The description of each test case follows.

The first line of each test case contains two integers nn and mm (1≤n,m≤1001 \le n, m \le 100) — the lengths of the strings pp and qq, respectively.

The second line of each test case contains a string pp denoting the numerator of the fraction. It is guaranteed that the length of the string pp is equal to nn and that it contains only lowercase English letters.

The third line of each test case contains a string qq denoting the denominator of the fraction. It is guaranteed that the length of the string qq is equal to mm and that it contains only lowercase English letters.

## Output

For each test case, print "YES" if you can simplify the fraction so that the resulting expression is exactly equal to the string six\texttt{six} and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Examples

Example

Input

```
54 1sinxn6 7xixsmsmixsxim8 5fixturesfrute3 3abcdef5 10sixtycodeforces
```

Output

```
YESNOYESNONO
```

## Note

In the first test case, the variable n appears in both the numerator and the denominator, so it can be cancelled. The remaining variables in the numerator are s, i, and x, which can be reordered to obtain six.

In the second test case, after cancelling all possible common variables, the numerator contains only s while the denominator contains only mi. Therefore, the fraction cannot be simplified to six.

In the third test case, the variables f, r, u, t, and e can be cancelled from both sides. The remaining variables in the numerator are s, i, and x, which can be reordered to form six.


## Examples

### Example 1

**Input:**
```
54 1sinxn6 7xixsmsmixsxim8 5fixturesfrute3 3abcdef5 10sixtycodeforces
```

**Output:**
```
YESNOYESNONO
```
