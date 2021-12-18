# CS210-Project-3

# Summarize the project and what problem it was solving

  This project was created to read through an input file containing names of all items purchased at a grocery store. The output is a display of the count of all the different items and how many were purchased for that day. User may also search for a particular item in the input file or output the count to 'Frequency.dat'. The problem that was solved is how to count and display a large quantity of input text from a file in a convenient format.
  
# What did you do particularly well?

  I felt this project came together into a nice readable format, where all code is broken down into small functions and a project class. It is well encapsulated as only the main menu is made public from the project. Virtually every line is documented with a comment. It should be easy for another user to read and write new functions for. This program also handles bad input gracefully and there should be no possible input that crashes the executable.
  
# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
 
  The output is displayed directly at the command console window. Both the data output and a log of program file access is displayed there. I did this as part of the project so that it would be clear what the program was doing. I would like to format the display better, perhaps adding color to either the log or data to distinguish it, or log the file access into a seperate text document instead. Doing so would increase efficiency for the user.  There can also be more checks of the data input, perhaps for example checking for a file that is too long (>billions of lines or so forth) to keep this program from executing endlessly.
  
# What pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

  The most challenging piece of this project was the compilation. Combining two programming languages into a single project is simple enough to write, especially as Python already has a well-defined library for integrating with C\C++ (the starter code was also provided beforehand for integration which made this simpler). However, compiling it is not nearly as simple as a single language and care must be taken to set the programming environment correctly and use the compiler properly otherwise you will get errors. I found both StackOverflow and Youtube to be great resources to help with issues like this and others. There are many experienced programmers on the internet willing to help new users to succeed with great write-ups and video tutorials, and I plan to use these as a support as I continue learning about programming.
  
# What skills from this project will be particularly transferable to other projects or course work?

  The skills I have identified here are, as above, working with two languages which I expect will be more common on more advanced projects in the future, and experience with file I/O in both Python and C++ will be easily transferable as often projects will deal with data from files as well as direct input.
  
# How did you make this program maintainable, readable, and adaptable?

  This program is maintanable and readable by being well encapsulated and documented with comments. The individual class methods are all short and well defined, each function does not go beyond its scope of a single problem solution. This should make it easy to work with (no long, windy functions with no comments to sift through). It is adaptable as it is built as a class with a defined header. Project 3 can be easily imported into any project this way, and due to OOP principles it will not be possible to use it incorrectly (accessing private functions or data). Also, since most of the legwork is built in Python, the basic functionality is easily adaptable without having to recompile the C++.
