% Basic Facts
% Define parent relationships
parent(john, mary).
parent(john, david).
parent(susan, mary).
parent(susan, david).

parent(mary, linda).
parent(mary, paul).
parent(mike, linda).
parent(mike, paul).

parent(david, kevin).
parent(david, emily).
parent(sara, kevin).
parent(sara, emily).

% Define gender
male(john).
male(david).
male(mike).
male(paul).
male(kevin).

female(susan).
female(mary).
female(sara).
female(linda).
female(emily).

% Derived Relationships

% Grandparent Rule
grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

% Sibling Rule
sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

% Cousin Rule
cousin(X, Y) :-
    parent(A, X),
    parent(B, Y),
    sibling(A, B),
    X \= Y.

% Find Children Rule
child(X, Y) :-
    parent(Y, X).

% Find All Descendants (Recursive)
descendant(X, Y) :-
    parent(Y, X).
descendant(X, Y) :-
    parent(Y, Z),
    descendant(X, Z).