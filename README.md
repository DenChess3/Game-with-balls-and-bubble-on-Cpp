# Game-with-balls-and-bubble-on-Cpp

Calls with g++ mainb.cpp function.cpp classes.cpp -lfltk

Write a program that simulates the movement of objects of the "soap bubble" and "
balloon" classes over a square field of the size of 𝑁 × 𝑁 cells. In the program, these classes must be inherited
from the common base class "round object". The "round object" class, in turn, should be inherited from the "cell contents" class. Optionally, the "empty cell" class can be inherited from
the "cell contents" class. Also, the program should describe the "scene" class, which stores everything that is
on the field, in the form of pointers to objects of the "cell contents" class. The program must have a
graphical user interface, including:
1. 𝑁 × 𝑁 buttons, each of which represents a field cell. Each of the buttons should be
painted in one of three colors corresponding to the following cell states: free, occupied
by a soap bubble, occupied by a ball.
2. The "Next step" button, when clicked, the buttons are repainted, displaying the movement of objects (see the rules of movement below).
3. Radio buttons "Add a balloon", "Add a bubble", "Pick up a balloon", "Burst a bubble". 
One and only one of these buttons should be active at each moment of the program operation. When pressing
one of the 𝑁2 buttons of the field, the corresponding action must be performed: an empty cell should
become occupied by a ball or bubble, or vice versa, a cell occupied by a ball or bubble should become
free. There is no transition to the next step. If the user tries to do
the wrong action (for example, pick up a ball from a free cell), a new window should appear with
an error message.
When you click the "Next step" button, the movement takes place according to the following rules:
1. First, each round object randomly chooses the direction of its movement. Movement can
occur one cell vertically, horizontally or diagonally.
2. All objects are moved simultaneously. At the same time, if an object attempts
to move out of the field, it remains in place. If two or more objects claim one cell of the field
, the following happens:
(a) All soap bubbles falling into this cell burst.
(b) Balloons falling into this cell change the direction of their movement to the opposite of the selected one and remain in their places.
3. If there are balls that have changed the direction of movement in paragraph 2b, then another attempt is made for them
to simultaneously move according to the same rules in a new direction. A maximum
of three attempts are made, after which the balls that have not moved remain in their places.
The unspecified details of the movement can be chosen arbitrarily. In particular, if desired, it is allowed to pop balls for which there is no room left.
Requirements:
1. The program must read three arguments from the command line: integer, — generating element
(seed) for the pseudorandom number generator is the size of the field 𝑁 and a real multiplier for
the interface size. With the same generating element and the same user actions on the field, the same thing should happen. All sizes used in the program should be multiplied by the multiplier passed in the third argument
: window size, button size, font size, etc.
2. Methods of the "scene" class are prohibited from learning any of their parameters from cells: what is stored in them, which button handler is used, etc. The methods of the "scene" class should remain the same
when adding a new type of cell content to the program.
3. The FLTK library should be used to implement the graphical interface. A brief guide to using the main tools of this library can be found in (A.V. Stolyarov.
Programming: An Introduction to the profession. Vol. 3: Paradigms. Moscow : DMK Press, 2021. Section 10.11). More
more information about the library can be found on the official website: https://www.fltk.org/doc-1.3/index.html .
4. Only static methods of the class can be set as handlers for clicking the button–cell of the field

5. Four radio buttons should be implemented by a separate class, one of the methods of which returns
the type of action to be performed. Radio button click handlers must be static
methods of this class.
6. It is forbidden to use STL.
7. The program should be divided into several modules (.hpp + .cpp).
