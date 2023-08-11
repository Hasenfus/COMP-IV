/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Hunter M Hasenfus

Hours to complete assignment:2 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment delves into the topic of markov models and markov chains. A markov probability is one where the cumulative sum is 1.0, this is done by using frequency probabilities. 
In the assignment the frequencies of kgrams are found and then the frequencies of the subsequent letters are found. This enables the ability to create probability distributions for each kgram and
then randomly generate streams of characters based off the training data sets acquired probabilities. 




  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
In this implementation I constructed such markov model using three seperate data types. The first was a simple mapping from strings to ints, this was used for the frequencies of the kgrams. 
I then made a seperate data structure of a mapping into a vector, this allowed me to create a vector for each kgram and denote probabiltites for the following characters based on the frequency in which they were 
found in the training data. I chose to implement this with a vector because the last data structure I implemented was a mapping from strings into discrete distributions. By nature, the discrete distribution requires an input that is returns unlabeled integers. 
By using the sparse 127 element vector I was able to very seemlessly return the integer equivalent of the asci letters and conver to characters then and there. 




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
The mapping to discrete distributions is pretty interesting in that, it seemlessly takes the vector of character probabilites and converts it into a probaility distribution 
based on the discrete distribution. This allows the ability to pass a random generator into the probablity distribution and pass out a value. Provides a great deal of simplification for the latter half of the program. 
line 63-67 RandWriter.cpp
"
for (auto it: kgramCharProb) {
        std::discrete_distribution<int> dist(it.second.begin(), it.second.end());
        kgramCharDist[it.first] = dist;
    }
"




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I did complete the whole assignment successfully. The kgram works, the extraction of the alphabet works, the generation works. 



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
It does pass the unit tests because all the tests I put up passed. 



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
I used exceptions on all the points listed in the pdf. Mainly invalid argument exceptions that made sure the length of the kgrams were accurate. 
line 78-81 RandWriter.cpp
"
if (kgram.length() != order) {
        throw std::invalid_argument("kgram is not the same length as order"
         + kgram);
    }
"
This was an exception to catch invalid kgrams by length == order. 
line 126-130 RandWriter.cpp
"
if (n == 0) {
        throw std::invalid_argument("kgram does not exist: " + kgram
         + ", " + static_cast<char>(c));
    }
"
This was an exception to catch kgrams that were not apart of the original text. 





 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
Yes, when I made a list of the alphabet found in the given text, I used quick sort to sort the alphabet based on ascii int, this necesitated a lambda expression. 
line 29-30 of RandWriter.cpp
"
    qsort(&alphabet[0], alphabet.size(), sizeof(char), [](const void *a,
     const void *b) { return (*(char *)a - *(char *)b); });
"



/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/
No


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
None