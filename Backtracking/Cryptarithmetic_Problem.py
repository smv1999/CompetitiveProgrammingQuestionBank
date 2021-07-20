'''
Cryptarithmetic problems are mathematical puzzles where digits are replaced by symbols. 
And the aim is to find unique digits(0-9) that the letters should represent, such that 
they satisfy the given constraints.

The cryptarithmetic problem that is needed to be solved here is:
    
   SEND
 + MORE
---------
= MONEY
---------

Distinct variables are: S, E, N, D, M, O, R, Y
Domain: {0,...,9}

'''

# importing the necessary libraries
from typing import Generic, TypeVar, Dict, List, Optional
from abc import ABC, abstractmethod

# declaring a type variable V as variable type and D as domain type
V = TypeVar('V') # variable type
D = TypeVar('D') # domain type

# this is a Base class for all constraints
class Constraint(Generic[V, D], ABC):
    # the variables that the constraint is between
    def __init__(self, variables: List[V]) -> None:
        self.variables = variables

    # this is an abstract method which must be overridden by subclasses
    @abstractmethod
    def satisfied(self, assignment: Dict[V, D]) -> bool:
        ...
        
# A constraint satisfaction problem consists of variables of type V
# that have ranges of values known as domains of type D and constraints
# that determine whether a particular variable's domain selection is valid
class CSP(Generic[V, D]):
    def __init__(self, variables: List[V], domains: Dict[V, List[D]]) -> None:
        # variables to be constrained
        # assigning variables parameter to self.variables
        self.variables: List[V] = variables 
        # domain of each variable
        # assigning domains parameter to self.domains
        self.domains: Dict[V, List[D]] = domains
        # assigning an empty dictionary to self.constraints
        self.constraints: Dict[V, List[Constraint[V, D]]] = {}
        # iterating over self.variables
        for variable in self.variables:
            self.constraints[variable] = []
            # if the variable is not in domains, then raise a LookupError("Every variable should have a domain assigned to it.")
            if variable not in self.domains:
                raise LookupError("Every variable should have a domain assigned to it.")
    # this method adds constraint to variables as per their domains 
    def add_constraint(self, constraint: Constraint[V, D]) -> None:
        for variable in constraint.variables:
            if variable not in self.variables:
                raise LookupError("Variable in constraint not in CSP")
            else:
                self.constraints[variable].append(constraint)

    # checking if the value assignment is consistent by checking all constraints
    # for the given variable against it
    def consistent(self, variable: V, assignment: Dict[V, D]) -> bool:
        # iterating over self.constraints[variable]
        for constraint in self.constraints[variable]:
            # if constraint not satisfied then returning False
            if not constraint.satisfied(assignment):
                return False
        # otherwise returning True
        return True
    
    # this method is performing the backtracking search to find the result
    def backtracking_search(self, assignment: Dict[V, D] = {}) -> Optional[Dict[V, D]]:
        # assignment is complete if every variable is assigned (our base case)
        if len(assignment) == len(self.variables):
            return assignment

        # get all variables in the CSP but not in the assignment
        unassigned: List[V] = [v for v in self.variables if v not in assignment]

        # get the every possible domain value of the first unassigned variable
        first: V = unassigned[0]
        # iterating over self.domains[first]
        for value in self.domains[first]:
            local_assignment = assignment.copy()
            # assign the value
            local_assignment[first] = value
            # if we're still consistent, we recurse (continue)
            if self.consistent(first, local_assignment):
                # recursively calling the self.backtracking_search method based on the local_assignment
                result: Optional[Dict[V, D]] = self.backtracking_search(local_assignment)
                # if we didn't find the result, we will end up backtracking
                if result is not None:
                    return result
        return None
    
# SendMoreMoneyConstraint is a subclass of Constraint class
class SendMoreMoneyConstraint(Constraint[str, int]):
    
    def __init__(self, letters: List[str]) -> None:
        super().__init__(letters)
        self.letters: List[str] = letters

    def satisfied(self, assignment: Dict[str, int]) -> bool:
        # if there are duplicate values then it's not a solution
        if len(set(assignment.values())) < len(assignment):
            return False

        # if all variables have been assigned, check if it adds correctly
        if len(assignment) == len(self.letters):
            s: int = assignment["S"]
            e: int = assignment["E"]
            n: int = assignment["N"]
            d: int = assignment["D"]
            m: int = assignment["M"]
            o: int = assignment["O"]
            r: int = assignment["R"]
            y: int = assignment["Y"]
            send: int = s * 1000 + e * 100 + n * 10 + d
            more: int = m * 1000 + o * 100 + r * 10 + e
            money: int = m * 10000 + o * 1000 + n * 100 + e * 10 + y
            return send + more == money
        return True # no conflict

if __name__ == "__main__":
    letters: List[str] = ["S", "E", "N", "D", "M", "O", "R", "Y"]
    possible_digits: Dict[str, List[int]] = {}
    print("******************************************************************")
    print("\nHere are the results:\n")
    for letter in letters:
        possible_digits[letter] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    possible_digits["M"] = [1]  # so we don't get answers starting with a 0
    csp: CSP[str, int] = CSP(letters, possible_digits)
    csp.add_constraint(SendMoreMoneyConstraint(letters))
    solution: Optional[Dict[str, int]] = csp.backtracking_search()
    if solution is None:
        print("No solution found!")
    else:
        print(solution)
    print("\n******************************************************************")  
    
'''
Sample working:

******************************************************************

Here are the results:

{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O': 0, 'R': 8, 'Y': 2}

******************************************************************

'''
