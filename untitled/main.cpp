#include <iostream>
#include "charCreator.h"

using namespace std;

int main() {
    initialize();
    player.pcPros = getPros();
    player.pcName = getName();
    player.pcAncestry = *getAncestry();
    player.pcBackground = *getBackground();
    player.pcClass = *getClass();
    if (player.pcClass.name == "Cleric" && player.level == 1) {
        getSubclass(&player);
    }

    if (player.pcAncestry.humAB == true) {
        for (int & i : player.scoreArr) {
            i += 1;
        }
    }
    if (checkVowel(player.pcAncestry.name))
        cout << "Okay, you're playing an ";
    else
        cout << "Okay, you're playing a ";

    cout << player.pcAncestry.name << " " << player.pcClass.name << "\nwith the " << player.pcBackground.name <<
            " background named " << player.pcName << "\nand your character's pronouns are " << player.pcPros << ".\n";
    system("Pause");
    cout << "Let's to choose your ability scores!\n" << "Your stats are\nStrength:\t" << player.scoreArr[0] <<
            "\nDexterity:\t" << player.scoreArr[1] << "\nConstitution:\t" << player.scoreArr[2] <<
            "\nIntelligence:\t" << player.scoreArr[3] << "\nWisdom:\t\t" << player.scoreArr[4] << "\nCharisma:\t" << player.scoreArr[5] <<
            "\n";
    cout << "You may distribute 27 points throughout your stats up to a maximum of 16," << ""
            "\nhowever, raising a stat above 13 requires 2 points each.\n";
    system("Pause");
    while (!finishedChange) {
        abilityChange();
        cout << "Would you like to keep changing your scores?\n1: Yes\n2: No\n";
        cin >> yesNo;
        if (yesNo == 2) {
            finishedChange = true;
            yesNo = 0;
        }
    }
    assignSkillBonuses(&player);
    chooseProficiency(&player);
    chooseProficiency(&player);
    printSkills(&player);
}


//create loop that allows testing small pieces one part at a time with predefined character sheet