## Virus Outbreak

In the Martian land faraway, a new virus has evolved and is attacking the individuals at a fast pace. The scientists have figured out the virus composition, V. The big task is to identify the people who are infected. The sample of N people is taken to check if they are POSITIVE or NEGATIVE. A report is generated which provides the current blood composition B of the person. 

#### POSITIVE or NEGATIVE ?

If the blood composition of the person is a subsequence of the virus composition V, then the person is identified as POSITIVE otherwise NEGATIVE.

#### Example:

Virus Composition, V = coronavirus
Blood Composition of the person , B = ravus

The person in question is POSITIVE as B is the subsequence of the V. 

The scientists are busy with their research for medicine and request you to build a program which can quickly figure out if the person is POSITIVE or NEGATIVE. They will provide you with the virus composition V and all the people’s current blood composition. Can you help them?

<mark><b>Note</b>: The virus and blood compositions are lowercase alphabet strings.</mark>

#### Input Format:

The first line of the input consists of the virus composition, V

The second line of he input consists of the number of people, N

Next N lines each consist of the blood composition of the ith person, Bi

#### Constraints:

1<= N <=10

1<= |B|<= |V|<= 10^5

#### Output Format:

For each person, print POSITIVE or NEGATIVE in a separate line

Sample Test Case 1:

Input

```
coronavirus
3
abcde
crnas
onarous
```

Output

```
NEGATIVE
POSITIVE
NEGATIVE
```
