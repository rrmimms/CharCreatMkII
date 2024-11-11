// #include <iostream>
// #include <cstdio>
// #include "charCreator.h"
//
// using namespace std;
//
// void initialize() {
//     for (int g = 0; g < 6; g++) {
//         abilities[g].name = abilityNames[g];
//     }
//     for (int h = 0; h < totSkill; h++) {
//         skArr[h]->name = skNames[h];
//         skArr[h]->bonus = 0;
//         if (h == 0) {
//             skArr[h]->assAbil = abilities[0];
//         }
//         if (0 < h && h < 4) {
//             skArr[h]->assAbil = abilities[1];
//         }
//         if (4 <= h && h < 7) {
//             skArr[h]->assAbil = abilities[3];
//         }
//         if (7 <= h && h < 15) {
//             skArr[h]->assAbil = abilities[4];
//         }
//         if (h > 14) {
//             skArr[h]->assAbil = abilities[5];
//         }
//         //cout << skArr[h].name << " associated ability: " << skArr[h].assAbil.name << endl;
//     }
//     for (int i = 0; i < totAncs; i++) {
//         ancArr[i].name = ancNames[i];
//     }
//
//     //
//     // for (int j = 0; j < totClss; j++) {
//     //     classArr[j].name = clNames[j];
//     // }
//
//     for (int k = 0; k < totBgs; k++) {
//         bgArr[k].name = bgNames[k];
//     }
//
//     initFighter(&Fighter);
//     initCleric(&Cleric);
//     initRogue(&Rogue);
//     initElf(&elf);
//     initDwarf(&dwarf);
//     initHuman(&human);
//
// }
//
// void initFighter(clAtt *Fighter) {
//     Fighter->name = "Fighter";
//     Fighter->primaryAb = Strength;
//     Fighter->possSkills[0] = Acrobatics;
//     Fighter->possSkills[1] = AnimalHandling;
//     Fighter->possSkills[2] = Athletics;
//     Fighter->possSkills[3] = History;
//     Fighter->possSkills[4] = Insight;
//     Fighter->possSkills[5] = Intimidation;
//     Fighter->possSkills[6] = Perception;
//     Fighter->possSkills[7] = Survival;
//     Fighter->martProf = true;
//     Fighter->simpProf = true;
//     Fighter->lightProf = true;
//     Fighter->medProf = true;
//     Fighter->heavProf = true;
//     Fighter->shieldProf = true;
//     Fighter->saveOne = Strength;
//     Fighter->saveTwo = Constitution;
// }
//
//
// void initCleric(clAtt *Cleric) {
//     Cleric->name = "Cleric";
//     Cleric->primaryAb = Wisdom;
//     Cleric->possSkills[0] = History;
//     Cleric->possSkills[1] = Insight;
//     Cleric->possSkills[2] = Medicine;
//     Cleric->possSkills[3] = Persuasion;
//     Cleric->possSkills[4] = Religion;
//     Cleric->simpProf = true;
//     Cleric->lightProf = true;
//     Cleric->medProf = true;
//     Cleric->shieldProf = true;
//     Cleric->fullCast = true;
//     Cleric->saveOne = Wisdom;
//     Cleric->saveTwo = Charisma;
// }
//
//
// void initRogue(clAtt *Rogue) {
//     Rogue->name = "Rogue";
//     Rogue->primaryAb = Dexterity;
//     Rogue->possSkills[0] = Acrobatics;
//     Rogue->possSkills[1] = Athletics;
//     Rogue->possSkills[2] = Deception;
//     Rogue->possSkills[3] = Insight;
//     Rogue->possSkills[4] = Intimidation;
//     Rogue->possSkills[5] = Investigation;
//     Rogue->possSkills[6] = Perception;
//     Rogue->possSkills[7] = Performance;
//     Rogue->possSkills[8] = Persuasion;
//     Rogue->possSkills[9] = SleightOfHand;
//     Rogue->possSkills[10] = Stealth;
//     Rogue->martProf = true;
//     Rogue->simpProf = true;
//     Rogue->lightProf = true;
//     Rogue->medProf = true;
//     Rogue->heavProf = true;
//     Rogue->saveOne = Strength;
//     Rogue->saveTwo = Constitution;
// }
//
// void initElf(ancestry *elf) {
//     elf->name = "Elf";
//     elf->abOne = Dexterity;
//     elf->abTwo = Intelligence;
//     elf->movSpeed = 35;
//     elf->dVis = true;
// }
//
// void initDwarf(ancestry *dwarf) {
//     dwarf->name = "Dwarf";
//     dwarf->abOne = Strength;
//     dwarf->abTwo = Constitution;
//     elf.movSpeed = 25;
//     dwarf->dVis = true;
// }
//
// void initHuman(ancestry *human) {
//     human->name = "Human";
//     human->humAB = true;
// }
//
// string getName() {
//     string pName;
//     cout << "What would you like your character's name to be?\n";
//     cin >> pName;
//     return pName;
// }
//
// string getPros() {
//     bool valid = false;
//     int usrIn;
//     cout << "What are your character's pronouns?\n1: They/Them\n2: She/Her\n3: He/Him\n"
//             "Please enter the number next to your choice.\n";
//     cin >> usrIn;
//
//     while (!valid) {
//         if (1 > usrIn || usrIn > 3) {
//             cout << "Invalid response, please enter the number next to your choice.\n";
//             cin >> usrIn;
//             valid = false;
//         } else
//             valid = true;
//     }
//     return possiblePros[usrIn - 1];
// }
//
// string getClDescription(int usrIn) {
//     return "This is a class description.\n";
// }
//
//
// ancestry *getAncestry() {
//     int usrIn;
//     bool valid = false;
//     for (int i = 0; i < totAncs; i++) {
//         cout << i + 1 << ": " << ancNames[i] << "\n";
//     }
//     cout << "What ancestry does your character have? Please enter the number beside your answer.\n";
//     cin >> usrIn;
//
//     while (!valid) {
//         if (1 > usrIn or usrIn > totAncs) {
//             valid = false;
//             cout << "Invalid answer, please input the number beside your answer.\n";
//             cin >> usrIn;
//         } else
//             valid = true;
//     }
//
//
//     return &ancArr[usrIn - 1];
// }
//
// bool checkVowel(const string &check) {
//     char x = check[0];
//     if (x == 'a' || x == 'i' || x == 'o' || x == 'e' || x == 'u' ||
//         x == 'A' || x == 'I' || x == 'O' || x == 'E' || x == 'U') {
//         return true;
//     } else {
//         return false;
//     }
// }
//
// clAtt *getClass() {
//     int usrIn;
//     bool valid = false;
//     yesNo = 0;
//     while (yesNo != 1) {
//         for (int i = 0; i < totClss; i++) {
//             cout << i + 1 << ": " << clNames[i] << "\n";
//         }
//
//         cout << "What class would you like to learn more about? Please enter the number beside your answer.\n";
//         cin >> usrIn;
//         while (!valid) {
//             if (1 > usrIn or usrIn > totClss) {
//                 cout << "Invalid answer, please input the number beside your answer.\n";
//                 cin >> usrIn;
//                 valid = false;
//             } else
//                 valid = true;
//         }
//         cout << getClDescription(usrIn);
//         usrIn -= 1;
//         if (checkVowel(clNames[usrIn]))
//             cout << "Would you like to you play as an " << clNames[usrIn] << "?\n";
//         else
//             cout << "Would you like to you play as a " << clNames[usrIn] << "?\n";
//
//         cout << "Enter 1 for Yes and 2 to return to class select.\n";
//         cin >> yesNo;
//     }
//
//     return &classArr[usrIn];
// }
//
// background *getBackground() {
//     int usrIn;
//     bool valid = false;
//     for (int i = 0; i < totBgs; i++) {
//         cout << i + 1 << ": " << bgNames[i] << "\n";
//     }
//     cout << "What background does your character have? Please enter the number beside your answer.\n";
//     cin >> usrIn;
//
//     while (!valid) {
//         if (1 > usrIn or usrIn > totBgs) {
//             valid = false;
//             cout << "Invalid answer, please input the number beside your answer.\n";
//             cin >> usrIn;
//         } else
//             valid = true;
//     }
//
//
//     return &bgArr[usrIn - 1];
// }
//
// void abilityChange() {
//     int scoreToChange = 0;
//     int amtToAdd = 0;
//     bool add;
//     cout << "Which ability score would you like to change?\n" <<
//             "1: Strength\n2: Dexterity\n3: Constitution\n4: Intelligence\n5: Wisdom\n6: Charisma.\n"
//             << "Please enter the number next to the score you wish to change.\n";
//     cin >> scoreToChange;
//     while (1 > scoreToChange or scoreToChange > 6) {
//         cout << "\nInvalid response, please enter the number next to the score you wish to change\n";
//         cin >> scoreToChange;
//     }
//     scoreToChange -= 1;
//
//
//     cout << "Would you like to add or subtract points?\n1: Add\n2: Subtract\n";
//     cin >> yesNo;
//     bool valid = false;
//     while (!valid) {
//         switch (yesNo) {
//             case 1:
//                 add = true;
//                 valid = true;
//                 break;
//             case 2:
//                 add = false;
//                 valid = true;
//                 break;
//             default: {
//                 cout << "Invalid response, please enter 1 for Add or 2 for Subtract.\n";
//                 cin >> yesNo;
//                 valid = false;
//                 break;
//             }
//         }
//     }
//     if (add) {
//         cout << "How many points would you like to add to " << abilities[scoreToChange].name << "? \n";
//         cout << "You have " << pointsLeft << " points remaining.\n";
//         cin >> amtToAdd;
//
//         if (scoreArr[scoreToChange] + amtToAdd > 13) {
//             while (((scoreArr[scoreToChange] + amtToAdd) - 13) % 2 != 0) {
//                 cout << "Raising a score above 13 requires 2 points each.\n";
//                 cout << "If you'd like to raise your " << abilities[scoreToChange].name << " to " << scoreArr[
//                             scoreToChange]
//                         + amtToAdd
//                         << ",\nyou'll need to add one more point.\n";
//                 cout << "Your " << abilities[scoreToChange].name << " score is " << scoreArr[scoreToChange] <<
//                         ". You have "
//                         <<
//                         pointsLeft <<
//                         " points remaining.\n";
//                 cout << "How much would you like to add?\n";
//                 cin >> amtToAdd;
//             }
//             int twoPnts = (scoreArr[scoreToChange] + amtToAdd) - 13;
//             amtToAdd -= twoPnts;
//             amtToAdd += twoPnts / 2;
//             //cout << twoPnts << "\n";
//         }
//         while (scoreArr[scoreToChange] + amtToAdd > 16) {
//             cout << "Ability scores are capped at 16 during character creation.\n";
//             system("Pause");
//             cout << "Your " << abilities[scoreToChange].name << " score is " << scoreArr[scoreToChange] << ". You have "
//                     <<
//                     pointsLeft <<
//                     " points remaining.\n";
//             cout << "How many points would you like to add?";
//             amtToAdd = 0;
//             cin >> amtToAdd;
//         }
//         scoreArr[scoreToChange] += amtToAdd;
//         pointsLeft -= amtToAdd;
//         cout << "Your new " << abilities[scoreToChange].name << " score is " << scoreArr[scoreToChange] << ". You have "
//                 <<
//                 pointsLeft <<
//                 " points remaining.\n";
//     } else {
//         cout << "How many points would you like to subtract from " << abilities[scoreToChange].name << "? \n";
//         cout << "You have " << pointsLeft << " points remaining.\n";
//         cin >> amtToAdd;
//         int twoPnts = 0;
//         if (scoreArr[scoreToChange] > 13) {
//             for (int i = scoreArr[scoreToChange]; i > 13; i--) {
//                 twoPnts++;
//             }
//         }
//         scoreArr[scoreToChange] -= amtToAdd;
//         scoreArr[scoreToChange] -= twoPnts;
//         pointsLeft += amtToAdd;
//         cout << "Your new " << abilities[scoreToChange].name << " score is " << scoreArr[scoreToChange] << ". You have "
//                 <<
//                 pointsLeft <<
//                 " points remaining.\n";
//     }
// }
//
//
// // Created by rrmim on 5/21/2024.
// //


#include <iostream>
#include "charCreator.h"

using namespace std;


void initialize() {
    // for (int g = 0; g < 6; g++) {
    //     abilities[g] = abilities[g];
    // }
    for (int h = 0; h < totSkill; h++) {
        //skArr[h].name = skNames[h];
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
    // for (int i = 0; i < totAncs; i++) {
    //     ancArr[i].name = ancNames[i];
    // }
    // for (int k = 0; k < totBgs; k++) {
    //     bgArr[k].name = bgNames[k];
    // }

    initFighter(&classArr[1]);
    initCleric(&classArr[0]);
    initRogue(&classArr[2]);
    initElf(&ancArr[1]);
    initDwarf(&ancArr[2]);
    initHuman(&ancArr[0]);
}

void initFighter(clAtt *Fighter) {
    Fighter->name = "Fighter";
    Fighter->primaryAb = abilities[0];
    Fighter->possSkills[0] = Acrobatics;
    Fighter->possSkills[1] = AnimalHandling;
    Fighter->possSkills[2] = Athletics;
    Fighter->possSkills[3] = History;
    Fighter->possSkills[4] = Insight;
    Fighter->possSkills[5] = Intimidation;
    Fighter->possSkills[6] = Perception;
    Fighter->possSkills[7] = Survival;
    Fighter->martProf = true;
    Fighter->simpProf = true;
    Fighter->lightProf = true;
    Fighter->medProf = true;
    Fighter->heavProf = true;
    Fighter->shieldProf = true;
    Fighter->saveOne = abilities[0];
    Fighter->saveTwo = abilities[2];
}

void initCleric(clAtt *Cleric) {
    Cleric->name = "Cleric";
    Cleric->primaryAb = abilities[4];
    Cleric->possSkills[0] = History;
    Cleric->possSkills[1] = Insight;
    Cleric->possSkills[2] = Medicine;
    Cleric->possSkills[3] = Persuasion;
    Cleric->possSkills[4] = Religion;
    Cleric->simpProf = true;
    Cleric->lightProf = true;
    Cleric->medProf = true;
    Cleric->shieldProf = true;
    Cleric->fullCast = true;
    Cleric->saveOne = abilities[4];
    Cleric->saveTwo = abilities[5];
}

void initRogue(clAtt *Rogue) {
    Rogue->name = "Rogue";
    Rogue->primaryAb = abilities[1];
    Rogue->possSkills[0] = Acrobatics;
    Rogue->possSkills[1] = Athletics;
    Rogue->possSkills[2] = Deception;
    Rogue->possSkills[3] = Insight;
    Rogue->possSkills[4] = Intimidation;
    Rogue->possSkills[5] = Investigation;
    Rogue->possSkills[6] = Perception;
    Rogue->possSkills[7] = Performance;
    Rogue->possSkills[8] = Persuasion;
    Rogue->possSkills[9] = SleightOfHand;
    Rogue->possSkills[10] = Stealth;
    Rogue->martProf = true;
    Rogue->simpProf = true;
    Rogue->lightProf = true;
    Rogue->medProf = true;
    Rogue->heavProf = true;
    Rogue->saveOne = abilities[1];
    Rogue->saveTwo = abilities[3];
}

void initElf(ancestry *elf) {
    elf->name = "Elf";
    elf->abOne = abilities[1];
    elf->abTwo = abilities[3];
    elf->movSpeed = 35;
    elf->dVis = true;
}

void initDwarf(ancestry *dwarf) {
    dwarf->name = "Dwarf";
    dwarf->abOne = abilities[0];
    dwarf->abTwo = abilities[2];
    dwarf->movSpeed = 25;
    dwarf->dVis = true;
}

void initHuman(ancestry *human) {
    human->name = "Human";
    human->humAB = true;
    human->movSpeed = 30;
    human->dVis = false;
}

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

ancestry *getAncestry() {
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

clAtt *getClass() {
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

background *getBackground() {
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
    int amtToAdd = 0;
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
        cout << i + 1 << ": " << choices[i].name << "\n";
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
    }

    // Assign the chosen skill as proficient
    player->pcSkills[usrIn - 1].prof = true;

    free(choices);
}

void checkProficiency(sheet *player) {
    for (auto & pcSkill : player->pcSkills) {
        if (pcSkill.prof) {
            pcSkill.bonus += player->profBonus;
        }
        if (pcSkill.expert) {
            pcSkill.bonus += player->profBonus;
        }
    }
}

void printSkills(sheet *player) {
    for (auto &i: skArr) {
        cout << i.name << ": " << i.bonus << "\n";
    }
}

void getSubClass(sheet *player) {
}
