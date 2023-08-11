/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Hunter Hasenfus
Hours to complete assignment: 2 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/

 The assignment is aimed at constructing a class based around the LFSR,
  then providing opaque object design through a header file. 
  Afterwards using the boost framework to link your design to a series of tests that verifies the correct implementation of the code. 



/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/

I used a simple vector of ints for the register bits, it allowed for myself to easily configure 
the spots and access all elements with random access memory. I think 
a potentially easier solution could be derived from using a queue. A queue 
is a vector with algorithms which regulate the addition and subtraction of 
elements within the data structure.

 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/

I could not think of anything all that fruitful to test beyond what was already
provided, thus I settled on an edge case, and on the verification of correct 
output datatype. For the edge case I implemented a string of all 0s 
to prove that no matter the amount of steps done, the output would always be 0.
For the other tests I verified the size of the datatype was equal to the size of the required datatype.
I lastly set the qualifacation that step must output either 0 or 1. 




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

 N/A