//
// Created by rrmim on 11/13/2024.
//

#ifndef CCHEAD_H
#define CCHEAD_H

#include <iostream>
#include <utility>
using namespace std;

typedef int score;
typedef int pcLvl;

constexpr int totAncs = 3;
constexpr int totClss = 3;
constexpr int totSkill = 18;
constexpr int totBgs = 7;

inline score defAS = 8;
inline score pointsLeft = 27;

class weapon {
    string name;
    int dmgDie{};
    int numDice{};
    int dmgBonus{};
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

    weapon() = default;

    weapon(string n, int dd, int nd, int db, string dt, bool f, bool h,
           bool l, bool lo, bool r, bool th, bool thh,
           bool vh, bool s, bool m) : name(move(n)), dmgDie(dd), numDice(nd), dmgBonus(db),
                                      dmgType(move(dt)), finesse(f), heavy(h), light(l), loading(lo),
                                      ranged(r), reach(th), thrown(thh), twoHand(vh), simple(s), martial(m) {
    }
};

struct ability {
    string name;
    score score = 0;
};

class ancestry {
public:
    string name;
    ability abOne;
    ability abTwo;
    bool dVis = false;
    int movSpeed = 30;
    int flySpeed = 0;
    int swimSpeed = 0;
    string possLangs[1];
    bool humAB = false;

    ancestry() = default;

    ancestry(string n, ability a1, ability a2, bool dv, int ms, int fs, int ss, string pl[1],
             bool ha) : name(std::move(n)), abOne(move(a1)), abTwo(move(a2)), dVis(dv), movSpeed(ms), flySpeed(fs),
                        swimSpeed(ss), humAB(ha) {
    };
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
    string name = "";
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

    clAtt() = default;

    clAtt(string n, skill ps[20], const bool mp, const bool sp, const bool lp, const bool mpf, const bool hp,
          const bool spf, const bool hc, const bool fc, ability pa, ability so, ability st) : name(std::move(n)),
        primaryAb(move(pa)), saveOne(move(so)), saveTwo(move(st)) {
    };
};

class background {
public:
    string name;
    skill addedProfs[2];
    string desc;
    string feature;

    background() = default;
    background(string n, skill ap1, skill ap2, string d, string f) : name(move(n)), desc(move(d)), feature(move(f)) {
    };
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

// inline background bgArr[totBgs] = {
//     {"Acolyte"}, {"Criminal"}, {"Gladiator"}, {"Noble"}, {"Outlander"}, {"Sage"}, {"Urchin"}
// };

// inline string bgNames[totBgs] = {
//     "Acolyte", "Criminal", "Gladiator", "Noble", "Outlander", "Sage", "Urchin"
// };

inline sheet player;
inline bool moveOn = false;
inline int yesNo = 0;
inline bool finishedChange = false;

clAtt *initClasses();

ancestry *initAncs();

background *initBG();

string getName();

string getPros();

string getClDescription(int usrIn);

ancestry *getAncestry(ancestry *ancArr);

clAtt *getClass(clAtt *classArr);

bool checkVowel(const string &check);

void abilityChange();

background *getBackground(background *bgArr);

// void initFighter(clAtt *Fighter);
//
// void initCleric(clAtt *Cleric);
//
// void initRogue(clAtt *Rogue);
//
// void initElf(ancestry *elf);
//
// void initHuman(ancestry *human);
//
// void initDwarf(ancestry *dwarf);

void assignSkillBonuses(sheet *player);

void chooseProficiency(sheet *player);

void checkProficiency(sheet *player, skill *skill);

void printSkills(sheet *player);

void getSubclass(sheet *player);

#endif //CCHEAD_H
