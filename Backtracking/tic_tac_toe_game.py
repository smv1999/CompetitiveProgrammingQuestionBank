'''
TIC-TAC-TOE GAME USING MINIMAX ALGORITHM

Minimax is a kind of backtracking algorithm. It searches, recursively, the 
best move that leads the Max player to win or not lose (draw). It considers 
the current state of the game and the available moves at that state, then 
for each valid move, it plays (alternating min and max) until it finds a 
terminal state (win, draw or lose).

'''

#Import the necessary libraries
import numpy as np
from math import inf as infinity

#Set the Empty Board
game_state = [[' ',' ',' '],
              [' ',' ',' '],
              [' ',' ',' ']]
#Create the Two Players as 'X'/'O'
players = ['X','O']

#Method for checking the correct move on Tic-Tac-Toe
def play_move(state, player, block_num):
    if state[int((block_num-1)/3)][(block_num-1)%3] is ' ':
        
        state[int((block_num-1)/3)][(block_num-1)%3] = player
    else:
        block_num = int(input("Block is not empty, ya blockhead! Choose again: "))
        play_move(state, player, block_num)
        
#Method to copy the current game state to new_state of Tic-Tac-Toe
def copy_game_state(state):
    new_state = [[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']]
    for i in range(3):
        for j in range(3):
            new_state[i][j] = state[i][j]
    return new_state

#Method to check the current state of the Tic-Tac-Toe
def check_current_state(game_state):
    
    # Check horizontals in first row
    if (game_state[0][0] == game_state[0][1] and game_state[0][1] == game_state[0][2] and game_state[0][0] is not ' '):
        return game_state[0][0], "Done"
    # Check horizontals in second row
    if (game_state[1][0] == game_state[1][1] and game_state[1][1] == game_state[1][2] and game_state[1][0] is not ' '):
        return game_state[1][0], "Done"
    # Check horizontals in third row
    if (game_state[2][0] == game_state[2][1] and game_state[2][1] == game_state[2][2] and game_state[2][0] is not ' '):
        return game_state[2][0], "Done"
    
    # Check verticals in first column
    if (game_state[0][0] == game_state[1][0] and game_state[1][0] == game_state[2][0] and game_state[0][0] is not ' '):
        return game_state[0][0], "Done"
    # Check verticals in second column
    if (game_state[0][1] == game_state[1][1] and game_state[1][1] == game_state[2][1] and game_state[0][1] is not ' '):
        return game_state[0][1], "Done"
    # Check verticals in third column
    if (game_state[0][2] == game_state[1][2] and game_state[1][2] == game_state[2][2] and game_state[0][2] is not ' '):
        return game_state[0][2], "Done"
    
    # Check left diagonal
    if (game_state[0][0] == game_state[1][1] and game_state[1][1] == game_state[2][2] and game_state[1][1] is not ' '):
        return game_state[1][1], "Done"
    # Check right diagonal
    if (game_state[0][2] == game_state[1][1] and game_state[1][1] == game_state[2][0] and game_state[0][2] is not ' '):
        return game_state[1][1], "Done"
    
    draw_flag = 0
    for i in range(3):
        for j in range(3):
            if game_state[i][j] is ' ':
                draw_flag = 1    
    if draw_flag is 0:
        return None, "Draw"
        
    return None, "Not Done"

#Method to print the Tic-Tac-Toe Board
def print_board(game_state):
    print('----------------')
    print('| ' + str(game_state[0][0]) + ' || ' + str(game_state[0][1]) + ' || ' + str(game_state[0][2]) + ' |')
    print('----------------')
    print('| ' + str(game_state[1][0]) + ' || ' + str(game_state[1][1]) + ' || ' + str(game_state[1][2]) + ' |')
    print('----------------')
    print('| ' + str(game_state[2][0]) + ' || ' + str(game_state[2][1]) + ' || ' + str(game_state[2][2]) + ' |')
    print('----------------')
    
#Method for implement the Minimax Algorithm
def getBestMove(state, player):
    winner_loser , done = check_current_state(state)
    
    # Checking condition for winner, if winner_loser is 'O' then Computer won 
    # else if winner_loser is 'X' then You won else game is draw 
    if done == "Done" and winner_loser=='O':
        return 1  # for computer
    elif done == "Done" and winner_loser=='X': 
        return -1  # for player
    elif done == "Draw":    
        return 0
      
    moves = []    
    empty_cells = []
    
    #Append the block_num to the empty_cells list
    for i in range(3):
        for j in range(3):
            if state[i][j] is ' ':
                empty_cells.append(i*3 + (j+1))
    
    for empty_cell in empty_cells:
        move = {}
        
        move['index'] = empty_cell
        
        #Call the copy_game_state method
        new_state = copy_game_state(state)
        \
        play_move(new_state, player, empty_cell)
        
        #if player is computer
        if player == 'O':    
            result = getBestMove(new_state,'X')   
            move['score'] = result
        else:
            result = getBestMove(new_state,'O')
            move['score'] = result
        
        moves.append(move)

    # Find best move
    best_move = None
    #Check if player is computer('O')
    if player=='O':  
        best = -infinity
        for move in moves:
            if move['score']>best:
                best = move['score']
                best_move = move['index']
    else:
        best = infinity
        for move in moves:
            if move['score']<best:
                best = move['score']
                best_move = move['index']
                
    return best_move

# Now PLaying the Tic-Tac-Toe Game
play_again = 'Y'
while play_again == 'Y' or play_again == 'y':
    #Set the empty board for Tic-Tac-Toe
    game_state = [[' ',' ',' '],
              [' ',' ',' '],
              [' ',' ',' ']]
    #Set current_state as "Not Done"
    current_state = "Not Done"
    print("\nNew Game!")
    
    #print the game_state 
    print_board(game_state)
    
    #Select the player_choice to start the game
    player_choice = input("Choose which player goes first - X(You) or O(Computer): ")
    
    #Set winner as None
    winner = None
    
    #if player_choice is ('X' or 'x') for humans else for computer
    if player_choice == 'X' or player_choice == 'x':
        current_player_idx = 0
    else:
        current_player_idx = 1
        
    while current_state == "Not Done":
        #For Human Turn
        if current_player_idx == 0: 
            block_choice = int(input("Your turn please! Choose where to place (1 to 9): "))
            play_move(game_state, players[current_player_idx], block_choice)
        else:   # Computer turn
            block_choice = getBestMove(game_state, players[current_player_idx])
            play_move(game_state, players[current_player_idx], block_choice)
            print("AI plays move: " + str(block_choice))
        print_board(game_state)
        winner, current_state = check_current_state(game_state)
        if winner is not None:
            print(str(winner) + " won!")
        else:
            current_player_idx = (current_player_idx + 1)%2
        
        if current_state is "Draw":
            print("Draw!")
            
    play_again = input('Wanna try again?(Y/N) : ')
    if play_again == 'N':
        print('Thank you for playing Tic-Tac-Toe Game!!!!!!!')

'''
Sample woking:
    
New Game!
----------------
|   ||   ||   |
----------------
|   ||   ||   |
----------------
|   ||   ||   |
----------------

Choose which player goes first - X(You) or O(Computer): X

Your turn please! Choose where to place (1 to 9): 3
----------------
|   ||   || X |
----------------
|   ||   ||   |
----------------
|   ||   ||   |
----------------
AI plays move: 2
----------------
|   || O || X |
----------------
|   ||   ||   |
----------------
|   ||   ||   |
----------------

Your turn please! Choose where to place (1 to 9): 7
----------------
|   || O || X |
----------------
|   ||   ||   |
----------------
| X ||   ||   |
----------------
AI plays move: 1
----------------
| O || O || X |
----------------
|   ||   ||   |
----------------
| X ||   ||   |
----------------

Your turn please! Choose where to place (1 to 9): 5
----------------
| O || O || X |
----------------
|   || X ||   |
----------------
| X ||   ||   |
----------------
X won!

Wanna try again?(Y/N) : n

'''