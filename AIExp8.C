1. Prolog program using Mathematic AI operations
OUTPUT :
?- X is 5+2.
X = 7.
?- X is 5-8.
X = -3.
?- X is 28*13.
X = 364.
?- X is 28/13.
X = 2.1538461538461537.
?- X is 5 mod 10.
X = 5.
?- X is 532.
X = 532.
?- X is 5^8.
X = 390625.
?- X is 5^2.
X = 25.
?- 26 is 5^2.
false.
?- X is 5*3, Y is X*20.
X = 15,
Y = 300.



2. Prolog program using functions.

CODE:

person(jignesh,5.1,black,white).
person(Rohit, 5.0, black,white).
person(system, 4.9, white,brown).
person(Allen, 5.1, white,white).


OUTPUT:

?- person(X,Y,Z,W).
X = jignesh,
Y = 5.1,
Z = black,
W = white ;
X = Rohit,
Y = 5.0,
Z = black,
W = white ;
X = system,
Y = 4.9,
Z = white,
W = brown ;
X = Allen,
Y = 5.1,
Z = W, W = white



3.

CODE:

food(burger).
food(sandwich).
food(pizza).
lunch(sandwich).
dinner(pizza).
meal(X):- food(X).
OUTPUT:
?- food(What).
What = burger ;
What = sandwich ;
What = pizza.
?- food(burger).
true.
?- dinner(pizza).
true.
?- meal(X),lunch(X).
X = sandwich .
?- meal(X),dinner(X).
X = pizza.
?- lunch(pizza).
false.


4.

CODE:

com(X,Y):-
X>Y,write('X is Bigger Value');
X<Y,write('Y is Bigger Value').
OUTPUT:
?- com(8,9).
Y is Bigger Value
true.
?- com(80,9).
X is Bigger Value
true .
?- com(69,71).
Y is Bigger Value
true.
?- com(68,68).
false.
?- com(41,10).
X is Bigger Value
true




5. Prolog program using input/output function.



CODE:

position('jignesh','student').
position('silviya','teacher').
find_posiion:-write('Whose position you want to know?'),nl,
read(Input),nl,
position(Input,Output),nl,
write(Output).
OUTPUT:
?- position(X,Y).
X = jignesh,
Y = student .
?- position(jignesh,Y).
Y = student.
?- position(X,teacher).
X = silviya.
?- find_position.
Correct to: "find_posiion"? yes
Whose position you want to know?
|: jignesh.
student
true .




