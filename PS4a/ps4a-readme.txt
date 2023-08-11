/**********************************************************************
 *  Checkers ps4a-readme.txt template
 **********************************************************************/

Name: Hunter Hasenfus
Hours to complete assignment:1 

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignemnt is tasked with creating a game using the SFML library that mimics the game of checkers. The game of checkers
is inheretly designed in the form of an array, which makes the functionality of it very easy to design and implement. By using indices as locations 
the area of clicking as well the entire drawing process can be circumvented into a simple fashion. 

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The key data structures that I implemented was a map of pairs. This allowed me to have all the pieces designated to a given user in a single data structure, and made it very easy to decipher what locations were valid 
when a given user was up. It also allowed me to figure out where a piece was then easily decipher its type. 




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
I did not use smart pointers. I created an array of the game board, and then 2 map containers for the pieces relative to each user. For selecting the piece based on the button pressed and mouse location, I made a variable that was a member of that class.
This allowed a dynamic nature to the 'selected variable'. 



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
N/A

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
The player indicator image is found here, it is free. 
https://www.vecteezy.com/free-vector/arrow-up