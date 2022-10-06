// Pokemon Game

// 18 different types, with an interaction array
// lots of different moves, each move has 1 type, and performs some action
// during battle
// each pokemon has different set stats, 2 types, changing HP, and 4 moves
// each trainer has 6 pokemon
// each battle has 2 trainers, and 2 pokemon

// trainers will be given 6 pokemon, then fight until hp reaches 0.
//
// if trainer wins, restart fight, otherwise game over, keep track of amount of
// wins
#include <time.h>

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

// Class definition for a Type
class Type {
 public:
  Type();
  std::string pokemonTypeList[19] = {
      "Normal", "Fire",   "Water",  "Electric", "Grass", "Ice",  "Fighting",
      "Poison", "Ground", "Flying", "Psychic",  "Bug",   "Rock", "Ghost",
      "Dragon", "Dark",   "Steel",  "Fairy",    "???"};
  int damageArray[19][19] = {
      1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      1,     1,     1 / 2, 0,     1,     1,     1 / 2, 1,     1,     1,
      1 / 2, 1 / 2, 1,     2,     2,     1,     1,     1,     1,     1,
      2,     1 / 2, 1,     1 / 2, 1,     2,     1,     1,     1,     2,
      1 / 2, 1,     1 / 2, 1,     1,     1,     2,     1,     1,     1,
      2,     1,     1 / 2, 1,     1,     1,     1,     1,     1,     2,
      1 / 2, 1 / 2, 1,     1,     1,     0,     2,     1,     1,     1,
      1,     1 / 2, 1,     1,     1,     1,     1,     1 / 2, 2,     1,
      1 / 2, 1,     1,     1 / 2, 2,     1 / 2, 1,     1 / 2, 2,     1,
      1 / 2, 1,     1 / 2, 1,     1,     1,     1 / 2, 1 / 2, 1,     2,
      1 / 2, 1,     1,     2,     2,     1,     1,     1,     1,     2,
      1,     1 / 2, 1,     1,     2,     1,     1,     1,     1,     2,
      1,     1 / 2, 1,     1 / 2, 1 / 2, 1 / 2, 2,     0,     1,     2,
      2,     1 / 2, 1,     1,     1,     1,     1,     2,     1,     1,
      1 / 2, 1 / 2, 1,     1,     1,     1 / 2, 1 / 2, 1,     1,     0,
      2,     1,     1,     2,     1,     2,     1 / 2, 1,     1,     2,
      1,     0,     1,     1 / 2, 2,     1,     1,     1,     2,     1,
      1,     1,     1,     1,     1 / 2, 2,     1,     2,     1,     1,
      1,     1,     2,     1 / 2, 1,     1,     1,     1 / 2, 1,     1,
      1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
      1 / 2, 1,     1,     1,     1,     0,     1 / 2, 1,     1,     1,
      1 / 2, 1,     1,     2,     1,     1 / 2, 1 / 2, 1,     1 / 2, 2,
      1,     1,     1 / 2, 1,     2,     1 / 2, 1 / 2, 1,     1,     2,
      1,     1,     1,     2,     1 / 2, 1,     1 / 2, 2,     1,     2,
      1,     1,     1,     1,     1 / 2, 1,     1,     0,     1,     1,
      1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
      2,     1,     1 / 2, 1,     1,     1,     1,     1,     1,     1,
      1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      2,     1,     1 / 2, 0,     1,     1,     1,     1,     1,     1,
      1,     1 / 2, 1,     1,     1,     2,     1,     1,     2,     1,
      1 / 2, 1,     1 / 2, 1,     1,     1 / 2, 1 / 2, 1 / 2, 1,     2,
      1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
      1 / 2, 2,     1,     1,     1 / 2, 1,     1,     1,     1,     2,
      1 / 2, 1,     1,     1,     1,     1,     1,     2,     2,     1 / 2,
      1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
      1};
  Type(std::string ptypeName);
  std::string typeName;
  int positionIndex;
  int Type_Index(std::string ptypeName);
  ~Type();

};  // Type_H

Type::Type() {
  typeName = "???";
  positionIndex = 19;
};

Type::Type(std::string ptypeName) {
  typeName = ptypeName;
  positionIndex = Type_Index(ptypeName);
}

int Type::Type_Index(std::string ptypeName) {
  for (int i = 0; i < 19; i++) {
    if (ptypeName == pokemonTypeList[i]) {
      return i;
    }
  }
  std::cout << "type does not exist" << std::endl;
  return 19;
};

Type::~Type(){};

// Class definition for a Move
class Move {
 public:
  Move();
  std::string moveName;
  Type moveType;
  bool special;
  int power;
  int accuracy;
  Move(std::string pmoveName, Type pmoveType, bool pspecial, int ppower,
       int paccuracy);
  // Future move function can attack self or opponent, affect HP and or affect
  // stats
  ~Move();
};

Move::Move() {
  moveName = "unknown";
  Type Null = Type("???");
  moveType = Null;
  special = 1;
  power = 70;
  accuracy = 100;
}

Move::Move(std::string pmoveName, Type pmoveType, bool pspecial, int ppower,
           int paccuracy) {
  moveType = pmoveType;
  moveName = pmoveName;
  special = pspecial;
  power = ppower;
  accuracy = paccuracy;
}

Move::~Move() {}

// Class definition for a Species
class Species {
 public:
  Species();
  std::string speciesName;
  int HP;
  int attack;
  int defense;
  int specialAttack;
  int specialDefense;
  int speed;
  int baseStats[6] = {0, 0, 0, 0, 0, 0};
  Type type1;
  Type type2;
  Species(std::string pspeciesName, int pHP, int pattack, int pdefense,
          int pspecialAttack, int pspecialDefense, int pspeed, Type ptype1,
          Type ptype2);

  ~Species();
};
// Species_H

// default species constructor
Species::Species() {
  speciesName = "?";
  HP = 0;
  attack = 0;
  defense = 0;
  specialAttack = 0;
  specialDefense = 0;
  speed = 0;
  Type Null = Type("???");
  type1 = Null;
  type2 = Null;
}

// implementation of species constructor
Species::Species(std::string pspeciesName, int pHP, int pattack, int pdefense,
                 int pspecialAttack, int pspecialDefense, int pspeed,
                 Type ptype1, Type ptype2) {
  speciesName = pspeciesName;
  HP = pHP;
  attack = pattack;
  defense = pdefense;
  specialAttack = pspecialAttack;
  specialDefense = pspecialDefense;
  speed = pspeed;
  baseStats[0] = pHP;
  baseStats[1] = pattack;
  baseStats[2] = pdefense;
  baseStats[3] = pspecialAttack;
  baseStats[4] = pspecialDefense;
  baseStats[5] = pspeed;
  type1 = ptype1;
  type2 = ptype2;
}

Species::~Species(){};

class Pokemon {
 public:
  Pokemon();
  Pokemon(Species pspecies);
  Species speciesType;
  int maxHitPoints;
  int currentHitPoints;
  int evs[6] = {0, 0, 0, 0, 0, 0};
  int ivs[6] = {0, 0, 0, 0, 0, 0};
  int pokemonStats[6] = {0, 0, 0, 0, 0, 0};
  int* randomIvs();
  int level;
  std::string nickname;
  Move pokemonMove[4];
  Move move1;
  Move move2;
  Move move3;
  Move move4;
  std::string pokemonTypeList[19] = {
      "Normal", "Fire",   "Water",  "Electric", "Grass", "Ice",  "Fighting",
      "Poison", "Ground", "Flying", "Psychic",  "Bug",   "Rock", "Ghost",
      "Dragon", "Dark",   "Steel",  "Fairy",    "???"};
  Move MoveList[36];
  Move possibleMove[2];
  Move* Base_Moves(Move pmove1, Move pmove2, Move pmove3, Move pmove4);
  // Species randomPokemon();

  // std::string nature
  // Pokemon(Species pspecies);

  ~Pokemon();
};

Move* Pokemon::Base_Moves(Move pmove1, Move pmove2, Move pmove3, Move pmove4) {
  pokemonMove[0] = pmove1;
  pokemonMove[1] = pmove2;
  pokemonMove[2] = pmove3;
  pokemonMove[3] = pmove4;
  return &pokemonMove[0];
}

int* Pokemon::randomIvs() {
  for (int i = 0; i < 6; i++) {
    ivs[i] = rand() % 32;
  }
  return &ivs[0];
}

Pokemon::Pokemon() {
  nickname = "unnamed Pokemon";
  ivs[0] = *Pokemon::randomIvs();
  level = 50;
  maxHitPoints =
      floor(0.01 * (2 * 100 + ivs[0] + floor(0.25 * evs[0])) * level) + level +
      10;
  currentHitPoints = maxHitPoints;
  for (int i = 1; i < 6; i++) {
    pokemonStats[i] =
        (floor(0.01 * (2 * 50 + ivs[i] + floor(0.25 * evs[i])) * level) + 5);
  }
}

Pokemon::Pokemon(Species pspecies) {
  nickname = pspecies.speciesName;
  evs[0] = 0;
  ivs[0] = *Pokemon::randomIvs();
  level = 50;
  for (int i = 1; i < 6; i++) {
    pokemonStats[i] =
        (floor(0.01 *
               (2 * pspecies.baseStats[i] + ivs[i] + floor(0.25 * evs[i])) *
               level) +
         5);
  }
  maxHitPoints =
      floor(0.01 * (2 * pspecies.HP + ivs[0] + floor(0.25 * evs[0])) * level) +
      level + 10;
  pokemonStats[0] = maxHitPoints;
  currentHitPoints = maxHitPoints;
  speciesType = pspecies;

  Type Normal = Type("Normal");
  Type Fire = Type("Fire");
  Type Water = Type("Water");
  Type Electric = Type("Electric");
  Type Grass = Type("Grass");
  Type Ice = Type("Ice");
  Type Fighting = Type("Fighting");
  Type Poison = Type("Poison");
  Type Ground = Type("Ground");
  Type Flying = Type("Flying");
  Type Psychic = Type("Psychic");
  Type Bug = Type("Bug");
  Type Rock = Type("Rock");
  Type Ghost = Type("Ghost");
  Type Dragon = Type("Dragon");
  Type Dark = Type("Dark");
  Type Steel = Type("Steel");
  Type Fairy = Type("Fairy");
  Type Null = Type("???");

  MoveList[0] = Move("Poison Jab", Poison, 0, 80, 100);
  MoveList[1] = Move("Sludge Bomb", Poison, 1, 90, 100);
  MoveList[2] = Move("Extrasensory", Psychic, 1, 80, 100);
  MoveList[3] = Move("Zen Headbutt", Psychic, 0, 80, 90);
  MoveList[4] = Move("Flash Cannon", Steel, 1, 80, 100);
  MoveList[5] = Move("Iron Head", Steel, 0, 80, 100);
  MoveList[6] = Move("Surf", Water, 1, 90, 100);
  MoveList[7] = Move("Liquidation", Water, 0, 85, 100);
  MoveList[8] = Move("Rock Slide", Rock, 0, 75, 90);
  MoveList[9] = Move("Stone Edge", Rock, 0, 100, 80);
  MoveList[10] = Move("Tri Attack", Normal, 1, 80, 100);
  MoveList[11] = Move("Strength", Normal, 0, 80, 100);
  MoveList[12] = Move("Hurricane", Flying, 1, 110, 70);
  MoveList[13] = Move("Shadow Ball", Ghost, 1, 80, 100);
  MoveList[14] = Move("Shadow Claw", Ghost, 0, 70, 100);
  MoveList[15] = Move("Leaf Blade", Grass, 0, 90, 100);
  MoveList[16] = Move("Energy Ball", Grass, 1, 90, 100);
  MoveList[17] = Move("Earthquake", Ground, 0, 100, 100);
  MoveList[18] = Move("Earth Power", Ground, 1, 90, 100);
  MoveList[19] = Move("Ice Punch", Ice, 0, 75, 100);
  MoveList[20] = Move("Ice Beam", Ice, 1, 90, 100);
  MoveList[21] = Move("Bug Buzz", Bug, 1, 90, 100);
  MoveList[22] = Move("Megahorn", Bug, 0, 120, 85);
  MoveList[23] = Move("Crunch", Dark, 0, 80, 100);
  MoveList[24] = Move("Thunder Punch", Electric, 0, 75, 100);
  MoveList[25] = Move("Thunder", Electric, 1, 110, 70);
  MoveList[26] = Move("Play Rough", Fairy, 0, 90, 90);
  MoveList[27] = Move("Moonblast", Fairy, 1, 95, 100);
  MoveList[28] = Move("Jump Kick", Fighting, 0, 100, 95);
  MoveList[29] = Move("Aura Sphere", Fighting, 1, 80, 100);
  MoveList[30] = Move("Flamethrower", Fire, 1, 90, 100);
  MoveList[31] = Move("Fire Punch", Fire, 0, 75, 100);
  MoveList[32] = Move("Drill Peck", Flying, 0, 80, 100);
  MoveList[33] = Move("Dragon Claw", Dragon, 0, 80, 100);
  MoveList[34] = Move("Dragon Pulse", Dragon, 1, 85, 100);
  MoveList[35] = Move("Dark Pulse", Dark, 1, 80, 100);

  pokemonMove[0].moveType.typeName = pspecies.type1.typeName;
  int a = 0;
  for (int i = 0; i < 36; i++) {
    if (pokemonMove[0].moveType.typeName == MoveList[i].moveType.typeName) {
      possibleMove[a] = MoveList[i];
      a++;
    }
  }
  pokemonMove[0] = possibleMove[rand() % 2];

  if (pspecies.type2.typeName == "???") {
    pokemonMove[1].moveType.typeName = pokemonTypeList[rand() % 19];
  } else {
    pokemonMove[1].moveType.typeName = pspecies.type2.typeName;
  }
  a = 0;
  for (int i = 0; i < 36; i++) {
    if (pokemonMove[1].moveType.typeName == MoveList[i].moveType.typeName) {
      possibleMove[a] = MoveList[i];
      a++;
    }
  }
  pokemonMove[1] = possibleMove[rand() % 2];
  while (pokemonMove[1].moveName == pokemonMove[2].moveName) {
    pokemonMove[1] = possibleMove[rand() % 2];
  }
  pokemonMove[2] = MoveList[rand() % 36];
  while (pokemonMove[2].moveName == pokemonMove[1].moveName ||
         pokemonMove[2].moveName == pokemonMove[0].moveName) {
    pokemonMove[2] = MoveList[rand() % 36];
  }
  pokemonMove[3] = MoveList[rand() % 36];
  while (pokemonMove[3].moveName == pokemonMove[0].moveName ||
         pokemonMove[3].moveName == pokemonMove[1].moveName ||
         pokemonMove[3].moveName == pokemonMove[2].moveName) {
    pokemonMove[3] = MoveList[rand() % 36];
  }
  // function that uses type names to find moves
}

Pokemon::~Pokemon() {}

class Trainer {
 public:
  Trainer();
  Trainer(std::string ptrainerName);
  // has team array of 6 pokemon
  Pokemon pokemonTeam[6];
  int amountPokemon;
  Pokemon* addToTeam(Pokemon ppokemon);
  // has name
  std::string trainerName;
  void showTeam();
  void changeNickname(std::string oldName, std::string newName);
  // has trainer rank
  // has team storage array of upto 30 pokemon
  void pokemonInfo(std::string pnickname);
  ~Trainer();
};

Trainer::Trainer() { amountPokemon = 0; }

Trainer::Trainer(std::string ptrainerName) {
  trainerName = ptrainerName;
  amountPokemon = 0;
}

Pokemon* Trainer::addToTeam(Pokemon ppokemon) {
  if (amountPokemon < 6) {
    pokemonTeam[amountPokemon] = ppokemon;
    amountPokemon++;
  }
  return &pokemonTeam[0];
}

void Trainer::showTeam() {
  for (int i = 0; i < amountPokemon; i++) {
    std::cout << pokemonTeam[i].nickname << " [" << i + 1 << "] " << std::endl;
  }
}

void Trainer::changeNickname(std::string oldName, std::string newName) {
  for (int i = 0; i < amountPokemon; i++) {
    if (oldName == pokemonTeam[i].nickname) {
      pokemonTeam[i].nickname = newName;
      return;
    }
  }
}
void Trainer::pokemonInfo(std::string pnickname) {
  for (int i = 0; i < 6; i++) {
    if (pokemonTeam[i].nickname == pnickname) {
      std::cout << "Pokemon Species:  "
                << pokemonTeam[i].speciesType.speciesName << std::endl;
      std::cout << "Pokemon Name: " << pokemonTeam[i].nickname << std::endl;
      std::cout << "Current HP: " << pokemonTeam[i].maxHitPoints << "/"
                << pokemonTeam[i].currentHitPoints << std::endl;
      std::cout << "attack: " << pokemonTeam[i].pokemonStats[1] << std::endl;
      std::cout << "defense: " << pokemonTeam[i].pokemonStats[2] << std::endl;
      std::cout << "SpAttack: " << pokemonTeam[i].pokemonStats[3] << std::endl;
      std::cout << "SpDefense: " << pokemonTeam[i].pokemonStats[4] << std::endl;
      std::cout << "Speed: " << pokemonTeam[i].pokemonStats[5] << std::endl;
      std::cout << "Pokemon type: "
                << pokemonTeam[i].speciesType.type1.typeName;
      if (pokemonTeam[i].speciesType.type2.typeName == "???") {
      } else {
        std::cout << "/" << pokemonTeam[i].speciesType.type2.typeName;
      }
      std::cout << std::endl;
      for (int j = 0; j < 4; j++) {
        std::cout << pokemonTeam[i].pokemonMove[j].moveName << "   ";
        std::cout << pokemonTeam[i].pokemonMove[j].power << std::endl;
      }
      return;
    }
  }
}
Trainer::~Trainer() {}

int main_game() {
  // set random number generator seed
  srand(time(0));

  // types

  Type Normal = Type("Normal");
  Type Fire = Type("Fire");
  Type Water = Type("Water");
  Type Electric = Type("Electric");
  Type Grass = Type("Grass");
  Type Ice = Type("Ice");
  Type Fighting = Type("Fighting");
  Type Poison = Type("Poison");
  Type Ground = Type("Ground");
  Type Flying = Type("Flying");
  Type Psychic = Type("Psychic");
  Type Bug = Type("Bug");
  Type Rock = Type("Rock");
  Type Ghost = Type("Ghost");
  Type Dragon = Type("Dragon");
  Type Dark = Type("Dark");
  Type Steel = Type("Steel");
  Type Fairy = Type("Fairy");
  Type Null = Type("???");

  /*
  Move MoveList[36];
MoveList[0]=Move("Poison Jab", Poison, 0, 80, 100);
MoveList[1]=Move("Sludge Bomb", Poison, 1, 90, 100);
MoveList[2]=Move("Extrasensory", Psychic, 1, 80, 100);
MoveList[3]=Move("Zen Headbutt", Psychic, 0, 80, 90);
MoveList[4]=Move("Flash Cannon", Steel, 1, 80, 100);
MoveList[5]=Move("Iron Head", Steel, 0, 80, 100);
MoveList[6]=Move("Surf", Water, 1, 90, 100);
MoveList[7]=Move("Liquidation", Water, 0, 85, 100);
MoveList[8]=Move("Rock Slide", Rock, 0, 75, 90);
MoveList[9]=Move("Stone Edge", Rock, 0, 100, 80);
MoveList[10]=Move("Tri Attack", Normal, 1, 80, 100);
MoveList[11]=Move("Strength", Normal, 0, 80, 100);
MoveList[12]=Move("Hurricane", Flying, 1, 110, 70);
MoveList[13]=Move("Shadow Ball", Ghost, 1, 80, 100);
MoveList[14]=Move("Shadow Claw", Ghost, 0, 70, 100);
MoveList[15]=Move("Leaf Blade", Grass, 0, 90, 100);
MoveList[16]=Move("Energy Ball", Grass, 1, 90, 100);
MoveList[17]=Move("Earthquake", Ground, 0, 100, 100);
MoveList[18]=Move("Earth Power", Ground, 1, 90, 100);
MoveList[19]=Move("Ice Punch", Ice, 0, 75, 100);
MoveList[20]=Move("Ice Beam", Ice, 1, 90, 100);
MoveList[21]=Move("Bug Buzz", Bug, 1, 90, 100);
MoveList[22]=Move("Megahorn", Bug, 0, 120, 85);
MoveList[23]=Move("Crunch", Dark, 0, 80, 100);
MoveList[24]=Move("Thunder Punch", Electric, 0, 75, 100);
MoveList[25]=Move("Thunder", Electric, 1, 110, 70);
MoveList[26]=Move("Play Rough", Fairy, 0, 90, 90);
MoveList[27]=Move("Moonblast", Fairy, 1, 95, 100);
MoveList[28]=Move("Jump Kick", Fighting, 0, 100, 95);
MoveList[29]=Move("Aura Sphere", Fighting, 1, 80, 100);
MoveList[30]=Move("Flamethrower", Fire, 1, 90, 100);
MoveList[31]=Move("Fire Punch", Fire, 0, 75, 100);
MoveList[32]=Move("Drill Peck", Flying, 0, 80, 100);
MoveList[33]=Move("Dragon Claw", Dragon, 0, 80, 100);
MoveList[34]=Move("Dragon Pulse", Dragon, 1, 85, 100);
MoveList[35]=Move("Dark Pulse", Dark, 1, 80, 100);
  */
  Species Pokedex[663];

  // Pokedex[i]=species("name",HP,Attack,Defense,SpecialAttack,SpecialDefense,Speed,type1,type2);

  Pokedex[0] = Species("Bulbasaur", 45, 49, 49, 65, 65, 45, Grass, Poison);
  Pokedex[1] = Species("Ivysaur", 60, 62, 63, 80, 80, 60, Grass, Poison);
  Pokedex[2] = Species("Venusaur", 80, 82, 83, 100, 100, 80, Grass, Poison);
  Pokedex[3] = Species("Charmander", 39, 52, 43, 60, 50, 65, Fire, Null);
  Pokedex[4] = Species("Charmeleon", 58, 64, 58, 80, 65, 80, Fire, Null);
  Pokedex[5] = Species("Charizard", 78, 84, 78, 109, 85, 100, Fire, Flying);
  Pokedex[6] = Species("Squirtle", 44, 48, 65, 60, 54, 43, Water, Null);
  Pokedex[7] = Species("Wartortle", 59, 63, 80, 65, 80, 58, Water, Null);
  Pokedex[8] = Species("Blastoise", 79, 83, 100, 85, 105, 78, Water, Null);
  Pokedex[9] = Species("Caterpie", 45, 30, 35, 20, 20, 45, Bug, Null);
  Pokedex[10] = Species("Metapod", 50, 20, 55, 25, 25, 30, Bug, Null);

  Pokedex[11] = Species("Butterfree", 60, 45, 50, 80, 80, 70, Bug, Flying);
  Pokedex[12] = Species("Weedle", 40, 35, 30, 20, 20, 50, Bug, Poison);
  Pokedex[13] = Species("Kakuna", 45, 25, 50, 25, 25, 35, Bug, Poison);
  Pokedex[14] = Species("Beedrill", 65, 80, 40, 40, 80, 75, Bug, Poison);
  Pokedex[15] = Species("Pidgey", 40, 45, 40, 35, 35, 56, Normal, Flying);
  Pokedex[16] = Species("Pidgeotto", 63, 60, 55, 50, 50, 71, Normal, Flying);
  Pokedex[17] = Species("Pidgeot", 83, 80, 75, 70, 70, 91, Normal, Flying);
  Pokedex[18] = Species("Rattata", 30, 56, 35, 25, 35, 72, Normal, Null);
  Pokedex[19] = Species("Raticate", 55, 81, 60, 50, 70, 97, Normal, Null);
  Pokedex[20] = Species("Spearow", 40, 60, 30, 31, 31, 70, Normal, Flying);
  Pokedex[21] = Species("Fearow", 65, 90, 65, 61, 61, 100, Normal, Flying);
  Pokedex[22] = Species("Ekans", 30, 60, 44, 40, 54, 55, Poison, Null);
  Pokedex[23] = Species("Arbok", 60, 85, 69, 65, 79, 80, Poison, Null);
  Pokedex[24] = Species("Pikachu", 35, 55, 30, 50, 40, 90, Electric, Null);
  Pokedex[25] = Species("Raichu", 60, 90, 55, 90, 80, 100, Electric, Null);
  Pokedex[26] = Species("Sandshrew", 50, 75, 85, 20, 30, 40, Ground, Null);
  Pokedex[27] = Species("Sandslash", 75, 100, 110, 45, 55, 65, Ground, Null);
  Pokedex[28] = Species("Nidoran M", 55, 47, 52, 40, 40, 41, Poison, Null);
  Pokedex[29] = Species("Nidorina", 70, 62, 67, 55, 55, 56, Poison, Null);
  Pokedex[30] = Species("Nidoqueen", 90, 82, 87, 75, 85, 76, Poison, Ground);
  Pokedex[31] = Species("Nidoran F", 46, 57, 40, 40, 40, 50, Poison, Null);
  Pokedex[32] = Species("Nidorino", 61, 72, 57, 55, 55, 65, Poison, Null);
  Pokedex[33] = Species("Nidoking", 81, 92, 77, 85, 75, 85, Poison, Ground);
  Pokedex[34] = Species("Clefairy", 70, 45, 48, 60, 65, 35, Normal, Null);
  Pokedex[35] = Species("Clefable", 95, 70, 73, 85, 90, 60, Normal, Null);
  Pokedex[36] = Species("Vulpix", 38, 41, 40, 50, 65, 65, Fire, Null);
  Pokedex[37] = Species("Ninetales", 73, 76, 75, 81, 100, 100, Fire, Null);
  Pokedex[38] = Species("Jigglypuff", 115, 45, 20, 45, 25, 20, Normal, Null);
  Pokedex[39] = Species("Wigglytuff", 140, 70, 45, 75, 50, 45, Normal, Null);
  Pokedex[40] = Species("Zubat", 40, 45, 35, 30, 40, 55, Poison, Flying);
  Pokedex[41] = Species("Golbat", 75, 80, 70, 65, 75, 90, Poison, Flying);
  Pokedex[42] = Species("Oddish", 45, 50, 55, 75, 65, 30, Grass, Poison);
  Pokedex[43] = Species("Gloom", 60, 65, 70, 85, 75, 40, Grass, Poison);
  Pokedex[44] = Species("Vileplume", 75, 80, 85, 100, 90, 50, Grass, Poison);
  Pokedex[45] = Species("Paras", 35, 70, 55, 45, 55, 25, Bug, Grass);
  Pokedex[46] = Species("Parasect", 60, 95, 80, 60, 80, 30, Bug, Grass);
  Pokedex[47] = Species("Venonat", 60, 55, 50, 40, 55, 45, Bug, Poison);
  Pokedex[48] = Species("Venomoth", 70, 65, 60, 90, 75, 90, Bug, Poison);
  Pokedex[49] = Species("Diglett", 10, 55, 25, 35, 45, 95, Ground, Null);
  Pokedex[50] = Species("Dugtrio", 35, 80, 50, 50, 70, 120, Ground, Null);
  Pokedex[51] = Species("Meowth", 40, 45, 35, 40, 40, 90, Normal, Null);
  Pokedex[52] = Species("Persian", 65, 70, 60, 65, 65, 115, Normal, Null);
  Pokedex[53] = Species("Psyduck", 50, 52, 48, 65, 50, 55, Water, Null);
  Pokedex[54] = Species("Golduck", 80, 82, 78, 95, 80, 85, Water, Null);
  Pokedex[55] = Species("Mankey", 40, 80, 35, 35, 45, 70, Fighting, Null);
  Pokedex[56] = Species("Primeape", 65, 105, 60, 60, 70, 95, Fighting, Null);
  Pokedex[57] = Species("Growlithe", 55, 70, 45, 70, 50, 60, Fire, Null);
  Pokedex[58] = Species("Arcanine", 90, 110, 80, 100, 80, 95, Fire, Null);
  Pokedex[59] = Species("Poliwag", 40, 50, 40, 40, 40, 90, Water, Null);
  Pokedex[60] = Species("Poliwhirl", 65, 65, 65, 50, 50, 90, Water, Null);
  Pokedex[61] = Species("Poliwrath", 90, 85, 95, 70, 90, 70, Water, Fighting);
  Pokedex[62] = Species("Abra", 25, 20, 15, 105, 55, 90, Psychic, Null);
  Pokedex[63] = Species("Kadabra", 40, 35, 30, 120, 70, 105, Psychic, Null);
  Pokedex[64] = Species("Alakazam", 55, 50, 45, 135, 85, 120, Psychic, Null);
  Pokedex[65] = Species("Machop", 70, 80, 50, 35, 35, 35, Fighting, Null);
  Pokedex[66] = Species("Machoke", 80, 100, 70, 50, 60, 45, Fighting, Null);
  Pokedex[67] = Species("Machamp", 90, 130, 80, 65, 85, 55, Fighting, Null);
  Pokedex[68] = Species("Bellsprout", 50, 75, 35, 70, 30, 40, Grass, Poison);
  Pokedex[69] = Species("Weepinbell", 65, 90, 50, 85, 45, 55, Grass, Poison);
  Pokedex[70] = Species("Victreebel", 80, 105, 65, 100, 60, 70, Grass, Poison);
  Pokedex[71] = Species("Tentacool", 40, 40, 35, 50, 100, 70, Water, Poison);
  Pokedex[72] = Species("Tentacruel", 80, 70, 65, 80, 120, 100, Water, Poison);
  Pokedex[73] = Species("Geodude", 40, 80, 100, 30, 30, 20, Rock, Ground);
  Pokedex[74] = Species("Graveler", 55, 95, 115, 45, 45, 35, Rock, Ground);
  Pokedex[75] = Species("Golem", 80, 110, 130, 55, 65, 45, Rock, Ground);
  Pokedex[76] = Species("Ponyta", 50, 85, 55, 65, 65, 90, Fire, Null);
  Pokedex[77] = Species("Rapidash", 65, 100, 70, 80, 80, 105, Fire, Null);
  Pokedex[78] = Species("Slowpoke", 90, 65, 65, 40, 40, 15, Water, Psychic);
  Pokedex[79] = Species("Slowbro", 95, 75, 110, 100, 80, 30, Water, Psychic);
  Pokedex[80] = Species("Magnemite", 25, 35, 70, 95, 55, 45, Electric, Steel);
  Pokedex[81] = Species("Magneton", 50, 60, 95, 120, 70, 70, Electric, Steel);
  Pokedex[82] = Species("Farfetch'd", 52, 65, 55, 58, 62, 60, Normal, Flying);
  Pokedex[83] = Species("Doduo", 35, 85, 45, 35, 35, 75, Normal, Flying);
  Pokedex[84] = Species("Dodrio", 60, 110, 70, 60, 60, 100, Normal, Flying);
  Pokedex[85] = Species("Seel", 65, 45, 55, 45, 70, 45, Water, Null);
  Pokedex[86] = Species("Dewgong", 90, 70, 80, 70, 95, 70, Water, Ice);
  Pokedex[87] = Species("Grimer", 80, 80, 50, 40, 50, 25, Poison, Null);
  Pokedex[88] = Species("Muk", 105, 105, 75, 65, 100, 50, Poison, Null);
  Pokedex[89] = Species("Shellder", 30, 65, 100, 45, 25, 40, Water, Null);
  Pokedex[90] = Species("Cloyster", 50, 90, 180, 85, 45, 70, Water, Ice);
  Pokedex[91] = Species("Gastly", 30, 35, 30, 100, 35, 80, Ghost, Poison);
  Pokedex[92] = Species("Haunter", 45, 50, 45, 115, 55, 95, Ghost, Poison);
  Pokedex[93] = Species("Gengar", 60, 65, 60, 130, 75, 110, Ghost, Poison);
  Pokedex[94] = Species("Onix", 35, 45, 160, 30, 45, 70, Rock, Ground);
  Pokedex[95] = Species("Drowzee", 60, 48, 45, 43, 90, 42, Psychic, Null);
  Pokedex[96] = Species("Hypno", 85, 73, 70, 73, 115, 67, Psychic, Null);
  Pokedex[97] = Species("Krabby", 30, 105, 90, 25, 25, 50, Water, Null);
  Pokedex[98] = Species("Kingler", 55, 130, 115, 50, 50, 75, Water, Null);
  Pokedex[99] = Species("Voltorb", 40, 30, 50, 55, 55, 100, Electric, Null);
  Pokedex[100] = Species("Electrode", 60, 50, 70, 80, 80, 140, Electric, Null);
  Pokedex[101] = Species("Exeggcute", 60, 40, 80, 60, 45, 40, Grass, Psychic);
  Pokedex[102] = Species("Exeggutor", 95, 95, 85, 125, 65, 55, Grass, Psychic);
  Pokedex[103] = Species("Cubone", 50, 50, 95, 40, 50, 35, Ground, Null);
  Pokedex[104] = Species("Marowak", 60, 80, 110, 50, 80, 45, Ground, Null);
  Pokedex[105] = Species("Hitmonlee", 50, 120, 53, 35, 110, 87, Fighting, Null);
  Pokedex[106] =
      Species("Hitmonchan", 50, 105, 79, 35, 110, 76, Fighting, Null);
  Pokedex[107] = Species("Lickitung", 90, 55, 75, 60, 75, 30, Normal, Null);
  Pokedex[108] = Species("Koffing", 40, 65, 95, 60, 45, 35, Poison, Null);
  Pokedex[109] = Species("Weezing", 65, 90, 120, 85, 70, 60, Poison, Null);
  Pokedex[110] = Species("Rhyhorn", 80, 85, 95, 30, 30, 25, Ground, Rock);
  Pokedex[111] = Species("Rhydon", 105, 130, 120, 45, 45, 40, Ground, Rock);
  Pokedex[112] = Species("Chansey", 250, 5, 5, 35, 105, 50, Normal, Null);
  Pokedex[113] = Species("Tangela", 65, 55, 115, 100, 40, 60, Grass, Null);
  Pokedex[114] = Species("Kangaskhan", 105, 95, 80, 40, 80, 90, Normal, Null);
  Pokedex[115] = Species("Horsea", 30, 40, 70, 70, 25, 60, Water, Null);
  Pokedex[116] = Species("Seadra", 55, 65, 95, 95, 45, 85, Water, Null);
  Pokedex[117] = Species("Goldeen", 45, 67, 60, 35, 50, 63, Water, Null);
  Pokedex[118] = Species("Seaking", 80, 92, 65, 65, 80, 68, Water, Null);
  Pokedex[119] = Species("Staryu", 30, 45, 55, 70, 55, 85, Water, Null);
  Pokedex[120] = Species("Starmie", 60, 75, 85, 100, 85, 115, Water, Psychic);
  Pokedex[121] = Species("Mr. Mime", 40, 45, 65, 100, 120, 90, Psychic, Null);
  Pokedex[122] = Species("Scyther", 70, 110, 80, 55, 80, 105, Bug, Flying);
  Pokedex[123] = Species("Jynx", 65, 50, 35, 115, 95, 95, Ice, Psychic);
  Pokedex[124] = Species("Electabuzz", 65, 83, 57, 95, 85, 105, Electric, Null);
  Pokedex[125] = Species("Magmar", 65, 95, 57, 100, 85, 93, Fire, Null);
  Pokedex[126] = Species("Pinsir", 65, 125, 100, 55, 70, 85, Bug, Null);
  Pokedex[127] = Species("Tauros", 75, 100, 95, 40, 70, 110, Normal, Null);
  Pokedex[128] = Species("Magikarp", 20, 10, 55, 15, 20, 80, Water, Null);
  Pokedex[129] = Species("Gyarados", 95, 125, 79, 60, 100, 81, Water, Flying);
  Pokedex[130] = Species("Lapras", 130, 85, 80, 85, 95, 60, Water, Ice);
  Pokedex[131] = Species("Ditto", 48, 48, 48, 48, 48, 48, Normal, Null);
  Pokedex[132] = Species("Eevee", 55, 55, 50, 45, 65, 55, Normal, Null);
  Pokedex[133] = Species("Vaporeon", 130, 65, 60, 110, 95, 65, Water, Null);
  Pokedex[134] = Species("Jolteon", 65, 65, 60, 110, 95, 130, Electric, Null);
  Pokedex[135] = Species("Flareon", 65, 130, 60, 95, 110, 65, Fire, Null);
  Pokedex[136] = Species("Porygon", 65, 60, 70, 85, 75, 40, Normal, Null);
  Pokedex[137] = Species("Omanyte", 35, 40, 100, 90, 55, 35, Rock, Water);
  Pokedex[138] = Species("Omastar", 70, 60, 125, 115, 70, 55, Rock, Water);
  Pokedex[139] = Species("Kabuto", 30, 80, 90, 55, 45, 55, Rock, Water);
  Pokedex[140] = Species("Kabutops", 60, 115, 105, 65, 70, 80, Rock, Water);
  Pokedex[141] = Species("Aerodactyl", 80, 105, 65, 60, 75, 130, Rock, Flying);
  Pokedex[142] = Species("Snorlax", 160, 110, 65, 65, 110, 30, Normal, Null);
  Pokedex[143] = Species("Articuno", 90, 85, 100, 95, 125, 85, Ice, Flying);
  Pokedex[144] = Species("Zapdos", 90, 90, 85, 125, 90, 100, Electric, Flying);
  Pokedex[145] = Species("Moltres", 90, 100, 90, 125, 85, 90, Fire, Flying);
  Pokedex[146] = Species("Dratini", 41, 64, 45, 50, 50, 50, Dragon, Null);
  Pokedex[147] = Species("Dragonair", 61, 84, 65, 70, 70, 70, Dragon, Null);
  Pokedex[148] =
      Species("Dragonite", 91, 134, 95, 100, 100, 80, Dragon, Flying);
  Pokedex[149] = Species("Mewtwo", 106, 110, 90, 154, 90, 130, Psychic, Null);
  Pokedex[150] = Species("Mew", 100, 100, 100, 100, 100, 100, Psychic, Null);

  Trainer Daniel = Trainer("Daniel");
  Trainer Opponent = Trainer("Opponent");
  Pokemon RandomPokemon[6];
  int a;
  for (int i = 0; i < 6; i++) {
    a = rand() % 151;
    RandomPokemon[i] = Pokedex[a];
    Daniel.addToTeam(RandomPokemon[i]);
    for (int j = 0; j < 6; j++) {
      if (Daniel.pokemonTeam[i].nickname == Daniel.pokemonTeam[j].nickname) {
        if (i == j) {
        } else {
          Daniel.changeNickname(Daniel.pokemonTeam[j].nickname,
                                Daniel.pokemonTeam[j].nickname + "2");
        }
      }
    }
  }
  //Daniel.showTeam();
  for (int i = 0; i < 6; i++) {
    Daniel.pokemonInfo(Daniel.pokemonTeam[i].nickname);
    std::cout << std::endl;
  }
  for (int i = 0; i < 6; i++) {
    a = rand() % 151;
    RandomPokemon[i] = Pokedex[a];
    Opponent.addToTeam(RandomPokemon[i]);
  }
  /*Opponent.showTeam();
  for (int i=0;i<6;i++){
          //Opponent.pokemonInfo(Pokemon[i].nickname);
          //std::cout<< std::endl;
  }
  /////////////////////////////////////////start different*/

  int input = 7;
  Daniel.showTeam();
  std::cout << "Pick your Pokemon!" << std::endl;
  std::cin >> input;

  while (input < 1 || input > 6) {
    std::cout << "enter one of the given options" << std::endl;
    input = 7;
    std::cout << "Pick your Pokemon!" << std::endl;
    std::cin >> input;
  }

  Pokemon* PlayerPokemon = &Daniel.pokemonTeam[input - 1];
  Pokemon* OpponentPokemon = &Opponent.pokemonTeam[rand() % 6];
  Move* PlayerMove;
  Move* OpponentMove;
  Pokemon* attacking;
  Trainer* defendingTrainer;
  Move* attackingMove;
  Pokemon* defending;
  int STAB;
  bool selectedMove = false;
  int damageNumber;
  Move Move;
  int pokemonKilled = 0;
  int playerPokemonKilled = 0;

  int turnPhase = 1;
  bool battle = true;
  while (battle == true) {
    // main screen
    while (turnPhase == 1) {
      input = 6;
      while (input < 1 || input > 4) {  // picking from Fight Pokemon Bag and
                                        // Run
        std::cout << "\n\n\n\n\n\n\n\n\n";
        std::cout << OpponentPokemon->currentHitPoints << "/"
                  << OpponentPokemon->maxHitPoints << "    "
                  << OpponentPokemon->nickname << std::endl;
        std::cout << std::endl << "         vs" << std::endl << std::endl;
        std::cout << PlayerPokemon->nickname << "    "
                  << PlayerPokemon->currentHitPoints << "/"
                  << PlayerPokemon->maxHitPoints << std::endl
                  << std::endl;

        std::cout << "Fight [1]"
                  << "	"
                  << "Pokemon [2]" << std::endl;
        std::cout << "Bag [3]"
                  << "		"
                  << "Run [4]" << std::endl;
        std::cout << "\n\n\n";
        std::cin >> input;

        if (input == 1) {  // Fight

          std::cout << "\n\n\n\n\n\n\n\n\n";
          std::cout << OpponentPokemon->currentHitPoints << "/"
                    << OpponentPokemon->maxHitPoints << "    "
                    << OpponentPokemon->nickname << std::endl;
          std::cout << std::endl << "         vs" << std::endl << std::endl;
          std::cout << PlayerPokemon->nickname << "    "
                    << PlayerPokemon->currentHitPoints << "/"
                    << PlayerPokemon->maxHitPoints << std::endl
                    << std::endl;

          std::cout << PlayerPokemon->pokemonMove[0].moveName << " [1]    "
                    << PlayerPokemon->pokemonMove[1].moveName << " [2]"
                    << std::endl;
          std::cout << PlayerPokemon->pokemonMove[2].moveName << " [3]    "
                    << PlayerPokemon->pokemonMove[3].moveName << " [4]"
                    << std::endl;

          std::cin >> input;
          if (input == 1) {
            PlayerMove = &PlayerPokemon->pokemonMove[0];
            turnPhase = 2;
            selectedMove = true;
          } else if (input == 2) {
            PlayerMove = &PlayerPokemon->pokemonMove[1];
            turnPhase = 2;
            selectedMove = true;
          } else if (input == 3) {
            PlayerMove = &PlayerPokemon->pokemonMove[2];
            turnPhase = 2;
            selectedMove = true;
          } else if (input == 4) {
            PlayerMove = &PlayerPokemon->pokemonMove[3];
            turnPhase = 2;
            selectedMove = true;
          }
        } else if (input == 2) {  // pokemon
          std::cout << "\n\n\n\n\n\n\n\n\n";
          Daniel.showTeam();
          std::cin >> input;
          if (input > 0 && input < 7) {
            if (!(Daniel.pokemonTeam[input - 1].currentHitPoints == 0)) {
              PlayerPokemon = &Daniel.pokemonTeam[input - 1];
              selectedMove = false;
              turnPhase = 3;
            }
          }

        } else if (input == 3) {
          std::cout << "Your Bag is empty!" << std::endl;
        } else if (input == 4) {
          std::cout << "You can't run from a trainer battle!" << std::endl;
          std::cout << "But you can for now!" << std::endl;
          return 0;
        } else {
          std::cout << "Please enter a valid option" << std::endl;
        }
      }
    }
    while (turnPhase == 2) {
      // battlePhase
      std::cout << "\n\n\n\n\n\n\n\n\n";
      if (PlayerPokemon->pokemonStats[5] > OpponentPokemon->pokemonStats[5]) {
        attacking = PlayerPokemon;
        defending = OpponentPokemon;
        defendingTrainer = &Opponent;
        attackingMove = PlayerMove;

      } else {
        attacking = OpponentPokemon;
        defending = PlayerPokemon;
        defendingTrainer = &Daniel;
        attackingMove = &OpponentPokemon->pokemonMove[rand() % 4];
      }

      if (attacking->speciesType.type1.typeName ==
              attackingMove->moveType.typeName ||
          attacking->speciesType.type2.typeName ==
              attackingMove->moveType.typeName) {
        STAB = 3;
      } else {
        STAB = 2;
      }
      damageNumber =
          floor((((2 * attacking->level / 5 + 2) * attackingMove->power *
                  attacking->pokemonStats[1 + 2 * attackingMove->special] /
                  defending->pokemonStats[2 + 2 * attackingMove->special]) /
                     50 +
                 2) *
                STAB / 2 *
                attackingMove->moveType
                    .damageArray[attackingMove->moveType.positionIndex]
                                [defending->speciesType.type1.positionIndex] *
                attackingMove->moveType
                    .damageArray[attackingMove->moveType.positionIndex]
                                [defending->speciesType.type2.positionIndex]);

      std::cout << attacking->nickname << " used " << attackingMove->moveName
                << " and dealt " << damageNumber << "\n";
      defending->currentHitPoints = defending->currentHitPoints - damageNumber;

      if (defending->currentHitPoints < 0) {
        defending->currentHitPoints = 0;
        if (defendingTrainer == &Opponent) {
          pokemonKilled++;
          OpponentPokemon = &Opponent.pokemonTeam[pokemonKilled];
        } else {
          // player picks a new pokemon
          playerPokemonKilled++;
          Daniel.showTeam();
          std::cout << "Pick your Pokemon!" << std::endl;
          std::cin >> input;
          if (Daniel.pokemonTeam[input - 1].currentHitPoints == 0) {
            std::cout << "pokemon has 0 hitpoints"
                      << "\n";
            input = 7;
          }
          while (input < 1 || input > 6) {
            std::cout << "enter one of the given options" << std::endl;
            input = 7;
            std::cout << "Pick your Pokemon!" << std::endl;
            std::cin >> input;
            if (Daniel.pokemonTeam[input - 1].currentHitPoints == 0) {
              std::cout << "pokemon has 0 hitpoints"
                        << "\n";
              input = 7;
            }
          }
          PlayerPokemon = &Daniel.pokemonTeam[input - 1];
        }
        turnPhase = 4;
      } else {
        turnPhase = 3;
      }
    }
    while (turnPhase == 3) {
      if (selectedMove == true) {
        if (attacking == PlayerPokemon) {
          attacking = OpponentPokemon;
          defending = PlayerPokemon;
          defendingTrainer = &Daniel;
          attackingMove = &OpponentPokemon->pokemonMove[rand() % 4];
        } else {
          attacking = PlayerPokemon;
          defending = OpponentPokemon;
          defendingTrainer = &Opponent;
          attackingMove = PlayerMove;
        }

      } else {
        std::cout << "\n\n\n\n\n\n\n\n\n";
        attacking = OpponentPokemon;
        defending = PlayerPokemon;
        defendingTrainer = &Daniel;
        attackingMove = &OpponentPokemon->pokemonMove[rand() % 4];
      }
      if (attacking->speciesType.type1.typeName ==
              attackingMove->moveType.typeName ||
          attacking->speciesType.type2.typeName ==
              attackingMove->moveType.typeName) {
        STAB = 3;
      } else {
        STAB = 2;
      }
      damageNumber =
          floor((((2 * attacking->level / 5 + 2) * attackingMove->power *
                  attacking->pokemonStats[1 + 2 * attackingMove->special] /
                  defending->pokemonStats[2 + 2 * attackingMove->special]) /
                     50 +
                 2) *
                STAB / 2 *
                attackingMove->moveType
                    .damageArray[attackingMove->moveType.positionIndex]
                                [defending->speciesType.type1.positionIndex] *
                attackingMove->moveType
                    .damageArray[attackingMove->moveType.positionIndex]
                                [defending->speciesType.type2.positionIndex]);

      std::cout << attacking->nickname << " used " << attackingMove->moveName
                << " and dealt " << damageNumber << "\n";

      defending->currentHitPoints = defending->currentHitPoints - damageNumber;

      if (defending->currentHitPoints < 0) {
        defending->currentHitPoints = 0;
        if (defendingTrainer == &Opponent) {
          pokemonKilled++;
          if (pokemonKilled < 6) {
            OpponentPokemon = &Opponent.pokemonTeam[pokemonKilled];
          }
        } else {
          // player picks a new pokemon
          playerPokemonKilled++;
          Daniel.showTeam();
          std::cout << "Pick your Pokemon!" << std::endl;
          std::cin >> input;

          while (input < 1 || input > 6) {
            std::cout << "enter one of the given options" << std::endl;
            input = 7;
            std::cout << "Pick your Pokemon!" << std::endl;
            std::cin >> input;
          }
          PlayerPokemon = &Daniel.pokemonTeam[input - 1];
        }
        turnPhase = 4;
      } else {
        turnPhase = 4;
      }
    }
    while (turnPhase == 4) {
      if (playerPokemonKilled == 6) {
        std::cout << "you have run out of Pokemon to use"
                  << "\n"
                  << "Player Blacked out!\n";
        battle = false;
      }
      if (pokemonKilled == 6) {
        std::cout << "opponent has run out of Pokemon to use"
                  << "\n"
                  << "Player wins 100g!\n";
        battle = false;
      }

      turnPhase = 1;
    }
  }
  return 0;
}