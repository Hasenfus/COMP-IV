/**********************************************************************
 *  readme.txt template                                                   
 *  PS7 Kronos 
 **********************************************************************/

Name: Hunter M Hasenfus

Hours to complete assignment: 1


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
 Yes, all parts of the assignment work. The device boot rpts show activity and have the same format as the example.


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
  std::regex timePattern(R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))");
    -This is the regular expression for the date, it begins with a section for the date and then a section for the time. \d{n} is used for a string of n numbers. 

  std::regex startPattern(R"(\((log\.c\.166)\) server started)");
    -This expression is an exact matching of the required string and nothing fancy. 

  std::regex finishPattern(R"(oejs\.AbstractConnector:Started SelectChannelConnector@\d+\.\d+\.\d+\.\d+:\d+)");
    -This regular expression uses \d which matches nonword boundarys and then + which adds one or more of the preceding characters. 

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
In this project, the approach I took was first understanding a necessary regular expression that would extract away time, and then I created two regular expressions for the start and finish. 
The time was straight forward and then was easily passed into the boost time date library to allow for the elapsed time to be computed if the boot was successful. 



/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
NA


/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
My friend told me about the regex_search and the smatch, this made it alot easier to extract the date/time from the line. 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
NA


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
NA