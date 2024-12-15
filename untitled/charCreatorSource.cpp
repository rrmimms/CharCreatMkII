#include <iostream>
#include "CCHead.h"

using namespace std;


clAtt *initClasses() {
    for (int h = 0; h < totSkill; h++) {
        skArr[h].bonus = 0;
        if (h == 0) {
            skArr[h].assAbil = abilities[0];
        } else if (h < 4) {
            skArr[h].assAbil = abilities[1];
        } else if (h < 7) {
            skArr[h].assAbil = abilities[3];
        } else if (h < 15) {
            skArr[h].assAbil = abilities[4];
        } else {
            skArr[h].assAbil = abilities[5];
        }
    }

    skill fighterSkills[8] = {skArr[1], skArr[10], skArr[0], skArr[5], skArr[11], skArr[16], skArr[12], skArr[13]};
    skill clericSkills[5] = {skArr[5], skArr[10], skArr[11], skArr[15], skArr[16]};
    skill rogueSkills[11] = {
        skArr[1], skArr[0], skArr[14], skArr[11], skArr[16], skArr[6], skArr[12], skArr[17], skArr[15], skArr[9],
        skArr[3]
    };
    clAtt Fighter(
        "Fighter",
        fighterSkills,
        true, // martProf
        true, // simpProf
        true, // lightProf
        true, // medProf
        true, // heavProf
        true, // shieldProf
        false, // halfCast
        false, // fullCast
        abilities[0], // primaryAb
        abilities[0], // saveOne
        abilities[2] // saveTwo
    );
    clAtt Cleric(
        "Cleric",
        clericSkills,
        false,
        true,
        true,
        true,
        false,
        true,
        false,
        true,
        abilities[4],
        abilities[4],
        abilities[5]
    );
    clAtt Rogue(
        "Rogue",
        rogueSkills,
        true,
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        abilities[1],
        abilities[1],
        abilities[3]
    );
    auto *classArr = new clAtt[totClss]{Fighter, Cleric, Rogue};
    return classArr;
}

ancestry *initAncs() {
    ancestry Human = {"Human", abilities[0], abilities[1], false, 30, 0, 0, &langs[0], true};
    ancestry Elf = {"Elf", abilities[1], abilities[3], true, 35, 0, 0, &langs[1], false};
    ancestry Dwarf = {"Dwarf", abilities[0], abilities[2], true, 25, 0, 0, &langs[8], false};
    auto *ancArr = new ancestry[totAncs]{Human, Elf, Dwarf};
    return ancArr;
}

background *initBG() {
    background Acolyte = {"Acolyte", skArr[8], skArr[10], "You're an acolyte.", "Shrine of the gods"};
    background Criminal = {"Criminal", skArr[14], skArr[3], "You're a criminal.", "Criminal contact"};
    background Gladiator = {"Gladiator", skArr[1], skArr[16], "You're a gladiator.", "Arena fighter"};
    background Noble = {"Noble", skArr[5], skArr[17], "You're a noble.", "Position of privilege"};
    background Outlander = {"Outlander", skArr[0], skArr[13], "You're an outlander.", "Wanderer"};
    background Sage = {"Sage", skArr[4], skArr[5], "You're a sage.", "Researcher"};
    background Urchin = {"Urchin", skArr[3], skArr[2], "You're an urchin.", "City secrets"};
    auto *bgArr = new background[totBgs]{Acolyte, Criminal, Gladiator, Noble, Outlander, Sage, Urchin};
    return bgArr;
}
// void initElf(ancestry *elf) {
//     elf->name = "Elf";
//     elf->abOne = abilities[1];
//     elf->abTwo = abilities[3];
//     elf->movSpeed = 35;
//     elf->dVis = true;
// }
//
// void initDwarf(ancestry *dwarf) {
//     dwarf->name = "Dwarf";
//     dwarf->abOne = abilities[0];
//     dwarf->abTwo = abilities[2];
//     dwarf->movSpeed = 25;
//     dwarf->dVis = true;
// }
//
// void initHuman(ancestry *human) {
//     human->name = "Human";
//     human->humAB = true;
//     human->movSpeed = 30;
//     human->dVis = false;
// }

string getName() {
    string pName;
    cout << "What would you like your character's name to be?\n";
    cin >> pName;
    return pName;
}

string getPros() {
    bool valid = false;
    int usrIn;
    cout << "What are your character's pronouns?\n1: They/Them\n2: She/Her\n3: He/Him\n"
            "Please enter the number next to your choice.\n";
    cin >> usrIn;

    while (!valid) {
        if (1 > usrIn || usrIn > 3) {
            cout << "Invalid response, please enter the number next to your choice.\n";
            cin >> usrIn;
        } else {
            valid = true;
        }
    }
    return possiblePros[usrIn - 1];
}

string getClDescription(int usrIn) {
    return "This is a class description.\n";
}

ancestry *getAncestry(ancestry *ancArr) {
    int usrIn;
    bool valid = false;
    for (int i = 0; i < totAncs; i++) {
        cout << i + 1 << ": " << ancArr[i].name << "\n";
    }
    cout << "What ancestry does your character have? Please enter the number beside your answer.\n";
    cin >> usrIn;

    while (!valid) {
        if (1 > usrIn || usrIn > totAncs) {
            cout << "Invalid answer, please input the number beside your answer.\n";
            cin >> usrIn;
        } else {
            valid = true;
        }
    }
    return &ancArr[usrIn - 1];
}

bool checkVowel(const string &check) {
    char x = check[0];
    return (x == 'a' || x == 'i' || x == 'o' || x == 'e' || x == 'u' ||
            x == 'A' || x == 'I' || x == 'O' || x == 'E' || x == 'U');
}

clAtt *getClass(clAtt *classArr) {
    int usrIn;
    bool valid = false;
    yesNo = 0;
    while (yesNo != 1) {
        for (int i = 0; i < totClss; i++) {
            cout << i + 1 << ": " << classArr[i].name << "\n";
        }

        cout << "What class would you like to learn more about? Please enter the number beside your answer.\n";
        cin >> usrIn;
        while (!valid) {
            if (1 > usrIn || usrIn > totClss) {
                usrIn = 0;
                cout << "Invalid answer, please input the number beside your answer.\n";
                cin >> usrIn;
                valid = false;
            } else {
                valid = true;
            }
        }
        cout << getClDescription(usrIn);
        usrIn -= 1;
        if (checkVowel(classArr[usrIn].name))
            cout << "Would you like to you play as an " << classArr[usrIn].name << "?\n";
        else
            cout << "Would you like to you play as a " << classArr[usrIn].name << "?\n";

        cout << "Enter 1 for Yes and 2 to return to class select.\n";
        cin >> yesNo;
    }

    return &classArr[usrIn];
}

background *getBackground(background *bgArr) {
    int usrIn;
    bool valid = false;
    for (int i = 0; i < totBgs; i++) {
        cout << i + 1 << ": " << bgArr[i].name << "\n";
    }
    cout << "What background does your character have? Please enter the number beside your answer.\n";
    cin >> usrIn;

    while (!valid) {
        if (1 > usrIn || usrIn > totBgs) {
            cout << "Invalid answer, please input the number beside your answer.\n";
            cin >> usrIn;
        } else {
            valid = true;
        }
    }
    return &bgArr[usrIn - 1];
}

void abilityChange() {
    int scoreToChange = 0;
    int usrIn = 0;
    cout << "Which ability score would you like to change?\n"
            << "1: Strength\n2: Dexterity\n3: Constitution\n4: Intelligence\n5: Wisdom\n6: Charisma.\n"
            << "Please enter the number next to the score you wish to change.\n";
    cin >> scoreToChange;
    while (1 > scoreToChange || scoreToChange > 6) {
        cout << "\nInvalid response, please enter the number next to the score you wish to change\n";
        cin >> scoreToChange;
    }
    scoreToChange -= 1;

   cout << "Would you like to add or subtract points?\n1: Add\n2: Subtract\n";
cin >> yesNo;
bool valid = false;
bool add = false;
while (!valid) {
    switch (yesNo) {
        case 1:
            add = true;
            valid = true;
            break;
        case 2:
            add = false;
            valid = true;
            break;
        default:
            cout << "Invalid response, please enter 1 for Add or 2 for Subtract.\n";
            cin >> yesNo;
            break;
    }
}
if (add) {
    cout << "How many points would you like to add to " << abilities[scoreToChange].name << "? \n";
    cout << "You have " << pointsLeft << " points remaining.\n";
    cin >> amtToAdd;

    if (player.scoreArr[scoreToChange] + amtToAdd > 13) {
        while (((player.scoreArr[scoreToChange] + amtToAdd) - 13) % 2 != 0) {
            cout << "Raising a score above 13 requires 2 points each.\n";
            cout << "If you'd like to raise your " << abilities[scoreToChange].name << " to " << player.scoreArr[
                        scoreToChange] + ((amtToAdd / 2) + 1)
                    << ",\nyou'll need to add one more point.\n";
            cout << "Your " << abilities[scoreToChange].name << " score is " << player.scoreArr[scoreToChange] <<
                    ". You have "
                    << pointsLeft << " points remaining.\n";
            cout << "How much would you like to add?\n";
            cin >> amtToAdd;
        }
        int twoPnts = (player.scoreArr[scoreToChange] + amtToAdd) - 13;
        amtToAdd -= twoPnts;
        amtToAdd += twoPnts / 2;
    }
    while (player.scoreArr[scoreToChange] + amtToAdd > 16) {
        cout << "Ability scores are capped at 16 during character creation.\n";
        cout << "Your " << abilities[scoreToChange].name << " score is " << player.scoreArr[scoreToChange] <<
                ". You have "
                << pointsLeft << " points remaining.\n";
        cout << "How many points would you like to add?";
        amtToAdd = 0;
        cin >> amtToAdd;
    }
    player.scoreArr[scoreToChange] += amtToAdd;
    pointsLeft -= amtToAdd;
    cout << "Your new " << abilities[scoreToChange].name << " score is " << player.scoreArr[scoreToChange] <<
            ". You have "
            << pointsLeft << " points remaining.\n";
} else {
    cout << "How many points would you like to subtract from " << abilities[scoreToChange].name << "? \n";
    cout << "You have " << pointsLeft << " points remaining.\n";
    cin >> amtToAdd;
    int twoPnts = 0;
    if (player.scoreArr[scoreToChange] > 13) {
        for (int i = player.scoreArr[scoreToChange]; i > 13; i--) {
            twoPnts++;
        }
    }
    player.scoreArr[scoreToChange] -= amtToAdd;
    player.scoreArr[scoreToChange] -= twoPnts;
    pointsLeft += amtToAdd;
    cout << "Your new " << abilities[scoreToChange].name << " score is " << player.scoreArr[scoreToChange] <<
            ". You have "
            << pointsLeft << " points remaining.\n";
}
}


void assignSkillBonuses(sheet *player) {
    for (auto &pcSkill: player->pcSkills) {
        int abilityScore = pcSkill.assAbil.score;
        pcSkill.bonus = (abilityScore - 10) / 2;
        checkProficiency(player, &pcSkill);
    }
}

void chooseProficiency(sheet *player) {
    auto *choices = static_cast<skill *>(malloc(sizeof(player->pcClass.possSkills)));
    for (int i = 0; i < (sizeof(player->pcClass.possSkills)) / (sizeof(skill)); i++) {
       if (!player->pcSkills[i].prof) cout << i + 1 << ": " << choices[i].name << "\n";
       else cout << i + 1 << ": " << choices[i].name << " (Already Proficient From Background)\n";
       }
    int usrIn;
    bool valid = false;
    while (!valid) {
        cout << "Please choose a skill from the list above, enter the number next to the skill you'd"
                "like to be proficient in:\n";
        cin >> usrIn;
        if (cin.fail() || usrIn < 1 || usrIn > (sizeof(player->pcClass.possSkills)) / (sizeof(skill))) {
            cin.clear(); // clear the error flag
            //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. ";
        } else {
            valid = true;
        }

        if (player->pcSkills[usrIn - 1].prof) {
            cout << "You are already proficient in that skill.\n";
            valid = false;
        }
        else valid = true;
    }


    // Assign the chosen skill as proficient
    player->pcSkills[usrIn - 1].prof = true;

    free(choices);
}

void checkProficiency(sheet *player, skill *skill) {
    for (auto &pcSkill: player->pcSkills) {
        if (pcSkill.prof) {
            pcSkill.bonus += player->profBonus;
        }
        if (pcSkill.expert) {
            pcSkill.bonus += player->profBonus;
        }
    }
}

void printSkills(sheet *player) {
    bool prof = false;
    for (auto & pcSkill : player->pcSkills) {
        if (pcSkill.prof) {
            prof = true;
        }
        cout << pcSkill.name << ": " << pcSkill.bonus << "prof: " << prof << "\n";
    }
}

void getSubClass(sheet *player) {
}
