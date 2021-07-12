# Jazzy And Cricket Balls

Jazzy is good with bowling but is not good with studies. His mom wants him to focus on studies too and for this she has found an interesting way. She has brought N packets of balls which may or may not have the same number of balls in them. The balls in a packet are arranged in a linear manner and Jazzy wants to play with the balls.

She will give the balls to Jazzy only if he can tell the maximum number of moves required in which he can get to play with all the balls. There are few conditions though:
 
     
  * In one move, Jazzy can divide the number of balls in the packet into an equal number of groups only.
     
     Example : Suppose there are 6 balls in the packet. 
     
     Jazzy can divide this packet in 3 ways.
       
        1. Two groups of 3 balls each. (3, 3)
        2. Three groups of 2 balls each (2, 2, 2)
        3. Six groups of 1 ball each.
        
     Note: Dividing a single group into multiple groups of equal number is considered one move only.
     
 * Jazzy can get to play with the balls when they are present as a single unit only and not in any group of size greater than 1. Also, getting to play with a ball is considered a move.
    
    Example: In a group there are 2 balls, then Jazzy cannot play with them until he further divides them into single-single units.
    
 * The length of all the packets/groups should always be an integer.

    Example: Number of Packets, N = 1
             Number of balls in packet = 6
            
Jazzy only cares about playing with the balls and needs your help in finding the maximum number of moves. Can you help him?

#### Input Format:
 
The first line of input consists of the number of packets, N.
The second line of input consists of N space-separated integers representing the number of balls in the packet (length of the packet), Ni

#### Constraints:

1<= N <=100
1<= Ni <=10^12 (1e12)

#### Output Format:

Print the required number of maximum moves to get to play with the balls.

##### Sample Test :

Input

```
2
6 1
```

Output

```
11
```

Explanation

```
For 6 numbers of balls in a packet, 10 moves are required as explained above.

For 1 ball, only 1 move is required.

Total number of moves = 10 + 1 = 11
```
