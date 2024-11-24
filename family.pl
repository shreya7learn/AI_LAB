% Defining males and females
male(dinkar).
male(dnyandev).
male(dnyaneshwar).
male(narayan).
male(hari).
male(anant).
male(bapurao).
male(sanjay).
male(kamlakar).
male(pravin).
male(dhiraj).
male(amol).
male(sumit).
male(sitaram).
male(sitaraman).
male(abasaheb).
male(dhananjay).
male(rohan).
male(aditya).
male(bhargav).
male(prajot).
male(aryan).
male(ashitosh).
male(sushant).
male(yash).

female(kantabai).
female(krushna).
female(lalita).
female(kalpana).
female(ranjana).
female(renu).
female(ayodhya).
female(komal).
female(kanchan).
female(swati).
female(manisha).
female(renuka).
female(sulochana).
female(shubhangi).
female(shruti).
female(vishakha).
female(vaishnav).
female(shreya).
female(mahi).
female(rutuja).

% Defining parent-child relationships
parent(dinkar, dnyaneshwar).
parent(dinkar, ayodhya).
parent(dinkar, hari).
parent(dinkar, anant).
parent(dinkar, narayan).
parent(kantabai, dnyaneshwar).
parent(kantabai, ayodhya).
parent(kantabai, hari).
parent(kantabai, anant).
parent(kantabai, narayan).

parent(dnyandev, kalpana).
parent(dnyandev, komal).
parent(dnyandev, kanchan).
parent(dnyandev, swati).
parent(dnyandev, dhiraj).
parent(krushna, kalpana).
parent(krushna, komal).
parent(krushna, kanchan).
parent(krushna, swati).
parent(krushna, dhiraj).

parent(dnyaneshwar, amol).
parent(dnyaneshwar, sumit).
parent(lalita, amol).
parent(lalita, sumit).

parent(ayodhya, renuka).
parent(ayodhya, sulochana).
parent(ayodhya, abasaheb).
parent(ayodhya, dhananjay).
parent(bapurao, renuka).
parent(bapurao, sulochana).
parent(bapurao, abasaheb).
parent(bapurao, dhananjay).

parent(hari, shruti).
parent(hari, vishakha).
parent(ranjana, shruti).
parent(ranjana, vishakha).

parent(anant, shri).
parent(anant, janhvi).
parent(renu, shri).
parent(renu, janhvi).

parent(narayan, vaishnav).
parent(narayan, shreya).
parent(kalpana, vaishnav).
parent(kalpana, shreya).

parent(komal, rohan).
parent(komal, mahi).
parent(sanjay, rohan).
parent(sanjay, mahi).

parent(kanchan, aditya).
parent(kanchan, bhargav).
parent(kamlakar, aditya).
parent(kamlakar, bhargav).

parent(swati, prajot).
parent(swati, aryan).
parent(pravin, prajot).
parent(pravin, aryan).

parent(renuka, ashitosh).
parent(sitaram, ashitosh).

parent(sulochana, sushant).
parent(sitaraman, sushant).

parent(abasaheb, yash).
parent(shubhangi, yash).

% Basic family relationships
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
child(X, Y) :- parent(Y, X).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
grandfather(X, Y) :- male(X), grandparent(X, Y).
grandmother(X, Y) :- female(X), grandparent(X, Y).
wife(X, Y) :- female(X), male(Y), parent(X, Z), parent(Y, Z).
husband(X, Y) :- male(X), female(Y), parent(X, Z), parent(Y, Z).
niece(X, Y) :- female(X), sibling(Y, Z), parent(Z, X).
nephew(X, Y) :- male(X), sibling(Y, Z), parent(Z, X).
father_in_law(X, Y) :- male(X), wife(W, Y), parent(X, W).
father_in_law(X, Y) :- male(X), husband(W, Y), parent(X, W).
mother_in_law(X, Y) :- female(X), wife(W, Y), parent(X, W).
mother_in_law(X, Y) :- female(X), husband(W, Y), parent(X, W).
cousin(X, Y) :-  parent(A, X), parent(B, Y), sibling(A, B).
maternal_uncle(X, Y) :-  male(X), parent(Z, Y), sister(Z, X).
maternal_aunt(X, Y) :- female(X), parent(Z, Y), sister(X, Z).
paternal_uncle(X, Y) :- male(X), parent(Z, Y), brother(X, Z).
paternal_aunt(X, Y) :- female(X), parent(Z, Y), brother(Z, X).
son_in_law(X, Y) :- male(X), wife(W, X), parent(Y, W).
daughter_in_law(X, Y) :- female(X), husband(W, X), parent(Y, W).
great_grandfather(X, Y) :- male(X), parent(X, Z), grandparent(Z, Y).
great_great_grandfather(X, Y) :- male(X), parent(X, Z), grandparent(Z, W), parent(W, Y).
son(X, Y) :- male(X), child(X, Y).
daughter(X, Y) :- female(X), child(X, Y).

% Find all parents of a person
find_parents(Person, Parents) :- 
    setof(P, parent(P, Person), Parents).

% Find all grandparents of a person
find_grandparents(Person, Grandparents) :- 
    setof(G, grandparent(G, Person), Grandparents).

% Find all cousins of a person
find_cousins(Person, Cousins) :- 
    setof(C, cousin(Person, C), Cousins).

% Find relation between two peopleK
find_relation(Person1, Person2, Relation) :- 
    ( parent(Person1, Person2) -> Relation = 'parent'  
    ; parent(Person2, Person1) -> Relation = 'child'
    ; grandparent(Person1, Person2) -> Relation = 'grandparent'
    ; grandparent(Person2, Person1) -> Relation = 'grandchild'
    ; great_grandfather(Person1, Person2) -> Relation = 'great-grandfather'
    ; great_great_grandfather(Person1, Person2) -> Relation = 'great-great-grandfather'
    ; great_grandfather(Person2, Person1) -> Relation = 'great-grandchild'
    ; great_great_grandfather(Person2, Person1) -> Relation = 'great-great-grandchild'
    ; cousin(Person1, Person2) -> Relation = 'cousin'
    ; sibling(Person1, Person2) -> Relation = 'sibling'
    ; brother(Person1, Person2) -> Relation = 'brother'
    ; sister(Person1, Person2) -> Relation = 'sister'
    ; niece(Person1, Person2) -> Relation = 'niece'
    ; nephew(Person1, Person2) -> Relation = 'nephew'
    ; maternal_uncle(Person1, Person2) -> Relation = 'maternal uncle'
    ; paternal_uncle(Person1, Person2) -> Relation = 'paternal uncle'
    ; maternal_aunt(Person1, Person2) -> Relation = 'maternal aunt'
    ; paternal_aunt(Person1, Person2) -> Relation = 'paternal aunt'
    ; son_in_law(Person1, Person2) -> Relation = 'son-in-law'
    ; daughter_in_law(Person1, Person2) -> Relation = 'daughter-in-law'
    ; father_in_law(Person1, Person2) -> Relation = 'father-in-law'
    ; mother_in_law(Person1, Person2) -> Relation = 'mother-in-law'
    ; Relation = 'no direct relation'  % Default case if no relation is found
    ).