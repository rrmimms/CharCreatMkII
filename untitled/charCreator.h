// charCreator.h
#ifndef CHARCREATOR_H
#define CHARCREATOR_H

#include <iostream>
using namespace std;

typedef int score;
typedef int pcLvl;

constexpr int totAncs = 11;
constexpr int totClss = 3;
constexpr int totSkill = 18;
constexpr int totBgs = 7;

inline score defAS = 8;
inline score pointsLeft = 27;

struct weapon {
    string name;
    int dmgDie;
    int numDie;
    int dmgBonus;
    string dmgType;
    bool finesse = false;
    bool heavy = false;
    bool light = false;
    bool loading = false;
    bool ranged = false;
    bool reach = false;
    bool thrown = false;
    bool twoHand = false;
    bool versatile = false;
    bool simple = false;
    bool martial = false;
};

struct ability {
    string name;
    score score = 0;
};

struct ancestry {
    string name;
    ability abOne;
    ability abTwo;
    bool dVis = false;
    int movSpeed = 30;
    int flySpeed = 0;
    int swimSpeed = 0;
    string possLangs[1];
    bool humAB = false;
};

struct spellSlots {
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    int fifth = 0;
    int sixth = 0;
    int seventh = 0;
    int eighth = 0;
    int ninth = 0;
};

struct skill {
    string name;
    ability assAbil;
    int bonus = 0;
    bool prof = false;
    bool expert = false;
};


class clAtt {
public:
    string name;
    skill possSkills[20];
    bool martProf = false;
    bool simpProf = false;
    bool lightProf = false;
    bool medProf = false;
    bool heavProf = false;
    bool shieldProf = false;
    bool halfCast = false;
    bool fullCast = false;
    ability primaryAb;
    ability saveOne;
    ability saveTwo;
    clAtt()

};


struct background {
    string name;
    skill availSkills[10];
    skill skillOne;
    skill skillTwo;
};

struct sheet {
    string pcName;
    string pcPros;
    clAtt pcClass;
    ancestry pcAncestry;
    score scoreArr[6] = {defAS, defAS, defAS, defAS, defAS, defAS};
    score profBonus = 2;
    pcLvl level = 1;
    spellSlots pcSLots;
    skill pcSkills[18];
    ability saveProf;
    int pcEXP = 0;
    background pcBackground;
    string langsKnown[1];
};

inline ability abilities[6] = {
    {"Strength"}, {"Dexterity"}, {"Constitution"},
    {"Intelligence"}, {"Wisdom"}, {"Charisma"}
};

inline string langs[10] = {
    "Common", "Elvish", "Deep Speech", "Draconic",
    "Infernal", "Abyssal", "Halfling", "Orc", "Gnomish", "Dwarvish"
};

inline string possiblePros[3] = {"They/Them", "She/Her", "He/Him"};

inline ancestry ancArr[totAncs] = {
    {"Human"}, {"Elf"}, {"Dwarf"}, {"Tiefling"}, {"Half-Orc"},
    {"Half-Elf"}, {"Aarakocra"}, {"Dragonborn"}, {"Gnome"}, {"Tabaxi"}, {"Halfling"}
};

// inline string ancNames[totAncs] = {
//     "Human", "Elf", "Dwarf", "Tiefling", "Half-Orc", "Half-Elf", "Aarakocra",
//     "Dragonborn", "Gnome", "Tabaxi", "Halfling"
//};

inline clAtt classArr[totClss] = {
    {"Cleric"}, {"Fighter"}, {"Rogue"}
};

// inline string clNames[totClss] = {
//     "Cleric", "Fighter", "Rogue"
// };
inline skill Athletics, Acrobatics, SleightOfHand, Stealth, Arcana, History, Investigation,
        Nature, Religion, AnimalHandling, Insight, Medicine, Perception, Survival, Deception,
        Intimidation, Performance, Persuasion;


inline skill skArr[totSkill] = {
    {"Athletics"}, {"Acrobatics"}, {"Sleight Of Hand"}, {"Stealth"},
    {"Arcana"}, {"History"}, {"Investigation"}, {"Nature"}, {"Religion"},
    {"Animal Handling"}, {"Insight"}, {"Medicine"}, {"Perception"}, {"Survival"},
    {"Deception"}, {"Intimidation"}, {"Performance"}, {"Persuasion"}
};
//
// inline string skNames[totSkill] = {
//     "Athletics", "Acrobatics", "Sleight Of Hand", "Stealth", "Arcana", "History", "Investigation",
//     "Nature", "Religion", "Animal Handling", "Insight", "Medicine", "Perception", "Survival",
//     "Deception", "Intimidation", "Performance", "Persuasion"
// };

inline background bgArr[totBgs] = {
    {"Acolyte"}, {"Criminal"}, {"Gladiator"}, {"Noble"}, {"Outlander"}, {"Sage"}, {"Urchin"}
};

// inline string bgNames[totBgs] = {
//     "Acolyte", "Criminal", "Gladiator", "Noble", "Outlander", "Sage", "Urchin"
// };

inline sheet player;
inline bool moveOn = false;
inline int yesNo = 0;
inline bool finishedChange = false;

void initialize();

string getName();
string getPros();
string getClDescription(int usrIn);
ancestry *getAncestry();
clAtt *getClass();
bool checkVowel(const string &check);
void abilityChange();
background *getBackground();

void initFighter(clAtt *Fighter);
void initCleric(clAtt *Cleric);
void initRogue(clAtt *Rogue);

void initElf(ancestry *elf);
void initHuman(ancestry *human);
void initDwarf(ancestry *dwarf);

void assignSkillBonuses(sheet *player);
void chooseProficiency(sheet *player);
void checkProficiency(sheet *player, skill *skil);
void printSkills(sheet *player);

void getSubclass(sheet *player);

#endif //CHARCREATOR_H


// #ifndef CHARCREATOR_H
// #define CHARCREATOR_H
//
// #include <iostream>
// using namespace std;
//
//
// typedef int score;
// typedef int pcLvl;
//
//
// constexpr int totAncs = 11;
// constexpr int totClss = 3;
// constexpr int totSkill = 18;
// constexpr int totBgs = 7;
//
// inline score defAS = 8;
// inline score pointsLeft = 27;
//
// struct ability {
//     string name;
//     score score = 0;
// };
//
//
// struct ancestry {
//     string name;
//     ability abOne;
//     ability abTwo;
//     bool dVis = false;
//     int movSpeed = 30;
//     int flySpeed = 0;
//     int swimSpeed = 0;
//     string possLangs[1];
//     bool humAB = false;
// };
//
// struct spellSlots {
//     int first = 0;
//     int second = 0;
//     int third = 0;
//     int fourth = 0;
//     int fifth = 0;
//     int sixth = 0;
//     int seventh = 0;
//     int eighth = 0;
//     int ninth = 0;
// };
//
// struct skill {
//     string name;
//     ability assAbil;
//     int bonus = 0;
//     bool prof = false;
//     bool expert = false;
// };
//
// struct clAtt {
//     string name;
//     skill possSkills[20];
//     bool martProf = false;
//     bool simpProf = false;
//     bool lightProf = false;
//     bool medProf = false;
//     bool heavProf = false;
//     bool shieldProf = false;
//     bool halfCast = false;
//     bool fullCast = false;
//     ability primaryAb;
//     ability saveOne;
//     ability saveTwo;
// };
//
// struct background {
//     string name;
//     skill availSkills[10];
//     skill skillOne;
//     skill skillTwo;
// };
//
// struct sheet {
//     string pcName;
//     string pcPros;
//     clAtt pcClass;
//     ancestry pcAncestry;
//     score scoreArr[6] = {defAS, defAS, defAS, defAS, defAS, defAS};
//     score profBonus = 2;
//     pcLvl level = 1;
//     spellSlots pcSLots;
//     skill pcSkills[18];
//     ability saveProf;
//     int pcEXP = 0;
//     background pcBackground;
//     string langsKnown[1];
// };
//
// inline ability Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma;
// inline ability abilities[6] = {Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma};
// inline string abilityNames[6] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
//
// inline score scoreArr[6] = {defAS, defAS, defAS, defAS, defAS, defAS};
//
// inline string langs[10] = {
//     "Common", "Elvish", "Deep Speech", "Draconic",
//     "Infernal", "Abyssal", "Halfling", "Orc", "Gnomish", "Dwarvish"
// };
//
// inline string possiblePros[3] = {"They/Them", "She/Her", "He/Him"};
//
// inline ancestry human, elf, dwarf, tiefling, halfOrc, halfElf, aarakocra, dragonborn, gnome, tabaxi, halfling;
//
// inline ancestry ancArr[totAncs] = {
//     human, elf, dwarf, tiefling, halfOrc,
//     halfElf, aarakocra, dragonborn, gnome, tabaxi, halfling
// };
//
// inline string ancNames[totAncs] = {
//     "Human", "Elf", "Dwarf", "Tiefling", "Half-Orc", "Half-Elf", "Aarakoca",
//     "Dragonborn", "Gnome", "Tabaxi", "Halfling"
// };
//
// inline clAtt Fighter, Rogue, Cleric;
// // Barbarian, Bard, Paladin,
// // Wizard, Sorcerer, Artificer,
// // Druid, Monk, Ranger, Warlock;
//
// inline clAtt classArr[totClss] = {
//     //Artificer, Barbarian, Bard,
//     Cleric,
//     //Druid,
//     Fighter,
//     //Monk, Paladin, Ranger,
//     Rogue
//     //Sorcerer, Warlock, Wizard
// };
// inline string clNames[totClss] = {
//     //"Artificer", "Barbarian", "Bard",
//     "Cleric",
//     //"Druid",
//     "Fighter",
//     //"Monk", "Paladin", "Ranger",
//     "Rogue"
//     //"Sorcerer", "Warlock", "Wizard"
// };
//
//
// inline skill Athletics, Acrobatics, SleightOfHand, Stealth, Arcana, History, Investigation,
//         Nature, Religion, AnimalHandling, Insight, Medicine, Perception, Survival, Deception,
//         Intimidation, Performance, Persuasion;
//
// inline string skNames[totSkill] = {
//     "Athletics", "Acrobatics", "Sleight Of Hand", "Stealth", "Arcana", "History", "Investigation",
//     "Nature", "Religion", "Animal Handling", "Insight", "Medicine", "Perception", "Survival",
//     "Deception", "Intimidation", "Performance", "Persuasion"
// };
//
// inline skill *skArr[totSkill] = {
//     &Athletics, &Acrobatics, &SleightOfHand, &Stealth,
//     &Arcana, &History, &Investigation, &Nature, &Religion,
//     &AnimalHandling, &Insight, &Medicine, &Perception, &Survival,
//     &Deception, &Intimidation, &Performance, &Persuasion
// };
//
//
// inline background Acolyte, Anthropologist, Archaeologist, Charlatan, CityWatch, CloisteredScholar, Courtier, Criminal,
//         Entertainer, FactionAgent, FarTraveler, FolkHero, Gladiator, GuildArtisan, GuildMerchant, HauntedOne, Heretic,
//         Hermit, Inquisitor, Investigator, Knight, Noble, Outlander, Pirate, Sage, Sailor, Soldier, Spy,
//         UrbanBountyHunter,
//         Urchin;
//
//
// inline background bgArr[totBgs] = {
//     Acolyte, Criminal, Gladiator, Noble, Outlander, Sage, Urchin
// };
//
// inline string bgNames[totBgs] = {
//     "Acolyte", "Criminal", "Gladiator", "Noble", "Outlander", "Sage", "Urchin"
//
// };
//
// inline sheet player;
// inline bool moveOn = false;
// inline int yesNo = 0;
// inline bool finishedChange = false;
//
// void initialize();
//
// void initFighter(clAtt *Fighter);
//
// void initCleric(clAtt *Cleric);
//
// void initRogue(clAtt *Rogue);
//
// void initElf(ancestry *elf);
//
// void initDwarf(ancestry *dwarf);
//
// void initHuman(ancestry *human);
//
// string getName();
//
// string getPros();
//
// string getClDescription(int usrIn);
//
// ancestry *getAncestry();
//
// clAtt *getClass();
//
// bool checkVowel(const string &check);
//
// void abilityChange();
//
// background *getBackground();
// #endif //CHARCREATOR_H
