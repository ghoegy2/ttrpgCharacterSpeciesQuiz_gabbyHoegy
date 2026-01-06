[Gabriella Hoegy] - [ghoegy2]

-------------------------------------------------

Description:

This project is a virtual, 10 question quiz for TTRPG players that are creating a character and have not decided on a species yet.
I made it for fun, and it's still a work in progress. I plan to create more functions to help condense/clean up the code in main.
I also plan to move questions and their corresponding answer data into a vector of objects to make storage and accessibility more
efficient. The quiz is runnable using Visual Studio Code 1.107.1 (IDE), C++17 (programming language), and mingw-w64 GCC 15.2.0
(compiler).

-------------------------------------------------

How to Compile and Run (Windows):

1. Ensure that Visual Studio Code 1.107.1, C++17, and mingw-w64 GCC 15.2.0 are installed on your machine.
2. On the GitHub repository page, navigate to the "<> Code" button and click "Download ZIP". Extract the project files into a
   new folder.
3. Open the folder in Visual Studio Code and navigate to the "ttrpgCharSpeciesQuiz_main.cpp" file.
4. In Visual Studio Code, ensure that your "C/C++: Edit Configurations (UI)" settings are set to gnu++17 for "C++ standard",
   and that your "Compiler path" contains mingw64 and GCC.
5. Open a terminal in Visual Studio Code. Enter "g++ ttrpgCharSpeciesQuiz_main.cpp -o ttrpgCharSpeciesQuiz_main.exe" to compile
   the code. Then, enter "./ttrpgCharSpeciesQuiz_main.exe" to run the code. :)
