#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <ctime>
#include <utility>

using namespace std;

// initiates the welcome sequence. Consists of introductory print statements. Also, requests user input to start the quiz
void welcomeSequence() {
    string startStr;
    char startChar;

    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "                                Welcome to the TTRPG Character Species Quiz!\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n\n";
    std::cout << "Your answers to the following 10 questions will be used to determine your character's species.\n\n";
    std::cout << "Potential species include: Aasimar, Dragonborn, Dwarf, Elf, Gnome, Goliath, Halfling, Human, Orc, and Tiefling\n\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";

    // repeatedly requests valid user input to start the quiz until the user enters 's' or 'S'
    while (tolower(startChar) != 's') {
        std::cout << "Enter 's' to START the quiz: ";
        std::cin >> startStr;
        startChar = startStr[0];
    }
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";
};

// lists the valid answer choices the user can pick from, and requests user input. Returns userInputChar
char answerChoiceList(string userInputStr) {
    char userInputChar; 

    // repeatedly requests the user's answer to a question until the user enters 'a', 'b', 'c', or 'A', 'B', 'C'
    while (tolower(userInputChar) != 'a' && tolower(userInputChar) != 'b' && tolower(userInputChar) != 'c') {
        std::cout << "Enter 'a', 'b', or 'c': ";
        std::cin >> userInputStr;
        userInputChar = userInputStr[0];
    }

    return userInputChar;
};

// struct that holds a name variable and a number variable
struct d20RollTotals {
    // name coresponds with a species name
    string name;
    // num coresponds with the number of question answers attached to a species's name
    int num;
};

int main(void) {
    string userAnswerStr, userRollStr;
    char userAnswerChar, userRollChar;
    int aasimarNum = 0, dragonbornNum = 0, dwarfNum = 0, elfNum = 0, gnomeNum = 0, goliathNum = 0, 
        halflingNum = 0, humanNum = 0, orcNum = 0, tieflingNum = 0;
    int maxAnswerTotal, y = 0, highestNumIndex = 0;
    vector<int> answerTotals, maxAnswerIndexNums;
    vector<string> speciesNames;
    vector<d20RollTotals> d20RollTotalsData;
    srand(time(NULL));

    // handles the welcome sequence
    welcomeSequence();

    // QUESTION 1
    std::cout << "QUESTION 1: Where would you rather live?\n\na. In the mountains... I prefere solitude\nb. Deep in a forest where I can be one with nature\nc. In a vast cave system\n\n";
    // calls answerChoiceList() to print out the user's answer choices, and prompts the user for answer input. Assigns the user input to userAnswerChar
    userAnswerChar = answerChoiceList(userAnswerStr);
    // when the user picks an answer, the answer's corresponding species num count gets increased by 1
    switch (tolower(userAnswerChar)) {
        case 'a':
            goliathNum += 1;
            break;
        case 'b':
            halflingNum += 1;
            break;
        case 'c':
            orcNum += 1;
            break;
    }
    // resets the user's answer string in preparation for the next question (this helps provide input to answerChoiceList() again)
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 2
    std::cout << "QUESTION 2: What superpower would you want to have in real life?\n\na. Super speed, duh!\nb. Firebending so I can cook food whenever I want\nc. Invisibility... now you see me, now you don't\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            halflingNum += 1;
            break;
        case 'b':
            dragonbornNum += 1;
            break;
        case 'c':
            gnomeNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 3
    std::cout << "QUESTION 3: Which of these personality traits are you drawn to the most?\n\na. Curiosity, who doesn't love investigating a bit of a mystery?\nb. Ambition! Whatever it takes!\nc. Resilience. Failure means coming back stronger\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            gnomeNum += 1;
            break;
        case 'b':
            humanNum += 1;
            break;
        case 'c':
            tieflingNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 4
    std::cout << "QUESTION 4: What do you think about magic?\n\na. It's a necessary part of life\nb. Magic saves lives\nc. Magic always leads to chaos - be careful!\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            elfNum += 1;
            break;
        case 'b':
            aasimarNum += 1;
            break;
        case 'c':
            dwarfNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 5
    std::cout << "QUESTION 5: What's more important to you?\n\na. Art... creativity is everything\nb. Beauty, of course!\nc. Strength! RAHHHHHHH\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            dwarfNum += 1;
            break;
        case 'b':
            elfNum += 1;
            break;
        case 'c':
            dragonbornNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 6
    std::cout << "QUESTION 6: Would you rather be...?\n\na. Tall\nb. Short\nc. In between\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            goliathNum += 1;
            break;
        case 'b':
            dwarfNum += 1;
            break;
        case 'c':
            humanNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 7
    std::cout << "QUESTION 7: Quick! Bandits are attacking!!\n\na. To war!\nb. Not to worry, I'll use my undeniable charm to talk them out of it!\nc. I'll put on a show for them! Let's pull a tiny prank :)\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            orcNum += 1;
            break;
        case 'b':
            tieflingNum += 1;
            break;
        case 'c':
            gnomeNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 8
    std::cout << "QUESTION 8: Which describes you best?\n\na. Introvert. I need time to recharge my social battery\nb. Extrovert!!! Let's party!!\nc. Idk haha\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            tieflingNum += 1;
            break;
        case 'b':
            halflingNum += 1;
            break;
        case 'c':
            humanNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 9
    std::cout << "QUESTION 9: You just experienced deja vu! How do you react?\n\na. Omg!!! I saw this happen in my dreams!\nb. Hmm... well that was strange\nc. Someone is clearly messing with me!! Time to fight!!\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            aasimarNum += 1;
            break;
        case 'b':
            dragonbornNum += 1;
            break;
        case 'c':
            orcNum += 1;
            break;
    }
    userAnswerStr = "x";
    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    // QUESTION 10
    std::cout << "QUESTION 10: Choose a clique!\n\na. Scholars all the way! Knowledge is power\nb. Jocks for the win!!\nc. Musicians! Let's make some sick beats!!\n\n";
    userAnswerChar = answerChoiceList(userAnswerStr);
    switch (tolower(userAnswerChar)) {
        case 'a':
            aasimarNum += 1;
            break;
        case 'b':
            goliathNum += 1;
            break;
        case 'c':
            elfNum += 1;
            break;
    }
    userAnswerStr = "x";

    // puts each species's totaled answer number count in the answerTotals vector
    answerTotals.push_back(aasimarNum);
    answerTotals.push_back(dragonbornNum);
    answerTotals.push_back(dwarfNum);
    answerTotals.push_back(elfNum);
    answerTotals.push_back(gnomeNum);
    answerTotals.push_back(goliathNum);
    answerTotals.push_back(halflingNum);
    answerTotals.push_back(humanNum);
    answerTotals.push_back(orcNum);
    answerTotals.push_back(tieflingNum);

    // finds the largest value in the answerTotals vector
    maxAnswerTotal = *max_element(answerTotals.begin(), answerTotals.end());

    // loops through answerTotals to see if multiple species have the largest value
    for (int i = 0; i <= answerTotals.size() - 1; i++) {
        // when a species's index contains the largest value, its index gets put into the maxAnswerIndexNums vector
        if (answerTotals[i] == maxAnswerTotal) {
            maxAnswerIndexNums.push_back(i);
        }
    }

    // sets the speciesNames vector to the same size as maxAnswerIndexNums
    speciesNames.resize(maxAnswerIndexNums.size());

    // loops through maxAnswerIndexNums to determine which species name is associated with value contained at an index
    for (int i = 0; i <= maxAnswerIndexNums.size() - 1; i++) {
        // when the value contained at an index in maxAnswerIndexNums matches a number, that number's corresponding species name gets added to the speciesNames vector 
        if (maxAnswerIndexNums[i] == 0) {
            speciesNames[y].append("Aasimar");
        }
        else if (maxAnswerIndexNums[i] == 1) {
            speciesNames[y].append("Dragonborn");
        }
        else if (maxAnswerIndexNums[i] == 2) {
            speciesNames[y].append("Dwarf");
        }
        else if (maxAnswerIndexNums[i] == 3) {
            speciesNames[y].append("Elf");
        }
        else if (maxAnswerIndexNums[i] == 4) {
            speciesNames[y].append("Gnome");
        }
        else if (maxAnswerIndexNums[i] == 5) {
            speciesNames[y].append("Goliath");
        }
        else if (maxAnswerIndexNums[i] == 6) {
            speciesNames[y].append("Halfling");
        }
        else if (maxAnswerIndexNums[i] == 7) {
            speciesNames[y].append("Human");
        }
        else if (maxAnswerIndexNums[i] == 8) {
            speciesNames[y].append("Orc");
        }
        else if (maxAnswerIndexNums[i] == 9) {
            speciesNames[y].append("Tiefling");
        }
        y++;
    }

    std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "                                               Your Quiz Results!\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";

    // when there's only one species name in the speciesNames vector, the resulting species name gets printed
    if (speciesNames.size() - 1 == 0) {
        std::cout << "\nCongrats!\n\nYou got: *** " << speciesNames[0] << " ***" << std::endl << std::endl;
    }
    // when there's more than one species name in speciesNames, each species name gets printed. Virtual dice are rolled to break the tie
    else {
        std::cout << "Woah!! You got more than one species: \n\n";

        // prints out each species name in speciesNames
        for (int i = 0; i <= speciesNames.size() - 1; i++) {
            std::cout << "* "<< speciesNames[i] << std::endl;
        }

        std::cout << "\n--------------------------------------------------------------------------------------------------------------\n";
        std::cout << "Hmm... that means there's only one way to break this tie... it's time for the dice to decide your fate!\n";
        std::cout << "Roll a virtual d20 for each species! Highest number wins!\n\n";
        std::cout << "Note: If there's another tie, the first species that rolled the tied number wins\n\n";
        std::cout << "--------------------------------------------------------------------------------------------------------------\n";

        // rolls a virtual d20 for each species name in speciesNames
        for (int i = 0; i <= speciesNames.size() - 1; i++) {
            userRollChar = 'd';
            // prompts the user for valid input until they enter 'x' or 'X' to roll the d20
            while (tolower(userRollChar) != 'x' && tolower(userRollChar) != 'X') {
                std::cout << "Enter 'x' to roll for " << speciesNames[i] << ": ";
                cin >> userRollStr;
                userRollChar = userRollStr[0];
            }

            // represents the d20 - picks a random number between 1 and 20
            auto diceNum = rand() % 20 + 1;
            // adds the species's name and its d20 value to the d20RollTotalsData vector
            d20RollTotalsData.push_back({speciesNames[i], diceNum});

            // prints out what number was rolled for the species name
            std::cout << std::endl << speciesNames[i] << ": " << diceNum << std::endl << std::endl;
        }

        std::cout << "--------------------------------------------------------------------------------------------------------------\n";
        std::cout << "                                               Your Quiz Results!\n";
        std::cout << "--------------------------------------------------------------------------------------------------------------\n";

        // loops through d20RollTotalsData to find which index contains the highest d20 number
        for (int i = 0; i <= d20RollTotalsData.size() - 1; i++) {
            if (d20RollTotalsData[i].num > d20RollTotalsData[highestNumIndex].num) {
                highestNumIndex = i;
            }
        }
        
        // prints out the name of the species that rolled the highest number
        std::cout << "\nCongrats!\n\nYou got: *** " << d20RollTotalsData[highestNumIndex].name << " ***" << std::endl << std::endl;
    }

    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "                                          Safe travels, Adventurer! :)\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
};
