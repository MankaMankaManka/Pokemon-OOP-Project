//Pokemon Game

// 18 different types, with an interaction array
// lots of different moves, each move has 1 type, and performs some action during battle
//each pokemon has different set stats, 2 types, changing HP, and 4 moves
//each trainer has 6 pokemon
//each battle has 2 trainers, and 2 pokemon


//trainers will be given 6 pokemon, then fight until hp reaches 0.
//
//if trainer wins, restart fight, otherwise game over, keep track of amount of wins
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>

// Class definition for a Type
class Type
{
public:
Type();
std::string pokemonTypeList[19]={"Normal", "Fire", "Water", "Electric", "Grass", "Ice",
					"Fighting", "Poison", "Ground", "Flying", "Psychic",
					"Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy", "???"};
int damageArray[19][19]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1/2, 0, 1, 1, 1/2, 1, 1,
				1, 1/2, 1/2, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1/2, 1, 1/2, 1, 2, 1, 1,
				1, 2, 1/2, 1, 1/2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1/2, 1, 1, 1, 1,
				1, 1, 2, 1/2, 1/2, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1/2, 1, 1, 1,	1,					
				1, 1/2, 2, 1, 1/2, 1, 1, 1/2, 2, 1/2, 1, 1/2, 2, 1, 1/2, 1, 1/2, 1, 1,
				1, 1/2, 1/2, 1, 2, 1/2, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 1/2, 1, 1,
				2, 1, 1, 1, 1, 2, 1, 1/2, 1, 1/2, 1/2, 1/2, 2, 0, 1, 2, 2, 1/2,	1,				
				1, 1, 1, 1, 2, 1, 1, 1/2, 1/2, 1, 1, 1, 1/2, 1/2, 1, 1, 0, 2, 1,
				1, 2, 1, 2, 1/2, 1, 1, 2, 1, 0, 1, 1/2, 2, 1, 1, 1, 2, 1, 1,
				1, 1, 1, 1/2, 2, 1, 2, 1, 1, 1, 1, 2, 1/2, 1, 1, 1, 1/2, 1, 1,
				1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1/2, 1, 1, 1, 1, 0, 1/2, 1, 1,						
				1, 1/2, 1, 1, 2, 1, 1/2, 1/2, 1, 1/2, 2, 1, 1, 1/2, 1, 2, 1/2, 1/2, 1,
				1, 2, 1, 1, 1, 2, 1/2, 1, 1/2, 2, 1, 2, 1, 1, 1, 1, 1/2, 1, 1,
				0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1/2, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1/2, 0, 1,
				1, 1, 1, 1, 1, 1, 1/2, 1, 1, 1, 2, 1, 1, 2, 1, 1/2, 1, 1/2, 1,					
				1, 1/2, 1/2, 1/2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1/2, 2, 1,
				1, 1/2, 1, 1, 1, 1, 2, 1/2, 1, 1, 1, 1, 1, 1, 2, 2, 1/2, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
Type(std::string ptypeName);
std::string typeName;
int positionIndex;
int Type_Index(std::string ptypeName);
~Type();

}; //Type_H

Type::Type(){
	typeName= "???";
	positionIndex=19;
};

Type::Type(std::string ptypeName){
	typeName = ptypeName;
	positionIndex=Type_Index(ptypeName);
}

int Type::Type_Index(std::string ptypeName){
	for (int i=0; i<19; i++){
		if (ptypeName == pokemonTypeList[i]){
			return i;
		}
	}
	std::cout <<"type does not exist"<<std::endl;
	return 19;
};

Type::~Type(){
};

// Class definition for a Move
class Move
{
public:
Move();
std::string moveName;
Type moveType;
bool special;
int power;
int accuracy;
Move(std::string pmoveName, Type pmoveType, bool pspecial, int ppower, int paccuracy);
//Future move function can attack self or opponent, affect HP and or affect stats
~Move();
};

Move::Move()
{
moveName= "unknown";
Type Null = Type("???");
moveType= Null;
special= 1;
power =70;
accuracy = 100;
}

Move::Move(std::string pmoveName, Type pmoveType, bool pspecial, int ppower, int paccuracy){
	moveType = pmoveType;
	moveName=pmoveName;
	special=pspecial;
	power=ppower;
	accuracy=paccuracy;
	
}

Move::~Move(){
}

// Class definition for a Species
class Species
{
public:
Species();
	std::string speciesName;
	int HP;
	int attack;
	int defense;
	int specialAttack;
	int specialDefense;
	int speed;
	int baseStats[6]={0,0,0,0,0,0};
	Type type1;
	Type type2;
Species(std::string pspeciesName, int pHP, int pattack, int pdefense,
		int pspecialAttack, int pspecialDefense, int pspeed, Type ptype1, Type ptype2);

~Species();
};
// Species_H

//default species constructor
Species::Species()
{
speciesName = "?";
HP=0;
attack=0;
defense=0;
specialAttack=0;
specialDefense=0;
speed=0;
Type Null = Type("???");
type1 = Null;
type2 = Null;
}

//implementation of species constructor
Species::Species(std::string pspeciesName, int pHP, int pattack, int pdefense,int pspecialAttack,
int pspecialDefense, int pspeed, Type ptype1, Type ptype2)
{
speciesName = pspeciesName;
HP=pHP;
attack=pattack;
defense=pdefense;
specialAttack=pspecialAttack;
specialDefense=pspecialDefense;
speed=pspeed;
baseStats[0]=pHP;
baseStats[1]=pattack;
baseStats[2]=pdefense;
baseStats[3]=pspecialAttack;
baseStats[4]=pspecialDefense;
baseStats[5]=pspeed;
type1 = ptype1;
type2 = ptype2;
}

Species::~Species(){
};

class Pokemon
{
public:
Pokemon();
Pokemon(Species pspecies);
Species speciesType;
int maxHitPoints;
int currentHitPoints;
int evs[6]={0,0,0,0,0,0};
int ivs[6]={0,0,0,0,0,0};
int pokemonStats[6]={0,0,0,0,0,0};
int *randomIvs();
int level;
std::string nickname;
Move pokemonMove[4];
Move move1;
Move move2;
Move move3;
Move move4;
std::string pokemonTypeList[19]={"Normal", "Fire", "Water", "Electric", "Grass", "Ice",
					"Fighting", "Poison", "Ground", "Flying", "Psychic",
					"Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy", "???"};
Move MoveList[36];
Move possibleMove[2];
Move* Base_Moves(Move pmove1, Move pmove2, Move pmove3, Move pmove4);
//Species randomPokemon();


//std::string nature
//Pokemon(Species pspecies);

~Pokemon();
};


Move* Pokemon::Base_Moves(Move pmove1, Move pmove2, Move pmove3, Move pmove4){
	pokemonMove[0]=pmove1;
	pokemonMove[1]=pmove2;
	pokemonMove[2]=pmove3;
	pokemonMove[3]=pmove4;
	return &pokemonMove[0];
}



int* Pokemon::randomIvs(){
	for (int i=0;i<6;i++){

		ivs[i]=rand()%32;
	}
	return &ivs[0];
}



Pokemon::Pokemon(){
	nickname= "unnamed Pokemon";
	ivs[0]=*Pokemon::randomIvs();
	level=50;
	maxHitPoints=floor(0.01*(2*100+ivs[0]+floor(0.25*evs[0]))*level)+level+10;
	currentHitPoints=maxHitPoints;
	for (int i=1; i<6; i++){
	pokemonStats[i]= (floor(0.01*(2*50 + ivs[i] + floor(0.25*evs[i]))*level) + 5);
	}

}

Pokemon::Pokemon(Species pspecies){
	nickname=pspecies.speciesName;
	evs[0]=0;
	ivs[0]=*Pokemon::randomIvs();
	level=50;
	for (int i=1; i<6; i++){
	pokemonStats[i]= (floor(0.01*(2*pspecies.baseStats[i] + ivs[i] + floor(0.25*evs[i]))*level) + 5);
	}
	maxHitPoints=floor(0.01*(2*pspecies.HP+ivs[0]+floor(0.25*evs[0]))*level)+level+10;
	pokemonStats[0]=maxHitPoints;
	currentHitPoints=maxHitPoints;
	speciesType=pspecies;
	
Type Normal =Type("Normal");
Type Fire =Type("Fire");
Type Water =Type("Water");
Type Electric =Type("Electric");
Type Grass =Type("Grass");
Type Ice =Type("Ice");
Type Fighting =Type("Fighting");
Type Poison =Type("Poison");
Type Ground =Type("Ground");
Type Flying =Type("Flying");
Type Psychic =Type("Psychic");
Type Bug =Type("Bug");
Type Rock =Type("Rock");
Type Ghost =Type("Ghost");
Type Dragon =Type("Dragon");
Type Dark =Type("Dark");
Type Steel =Type("Steel");
Type Fairy =Type("Fairy");
Type Null =Type("???");
	
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
	
	
	

	pokemonMove[0].moveType.typeName=pspecies.type1.typeName;
	int a=0;
	for (int i=0;i<36;i++){
		if (pokemonMove[0].moveType.typeName==MoveList[i].moveType.typeName){
			possibleMove[a]=MoveList[i];
			a++;
		}
	}
	pokemonMove[0]=possibleMove[rand()%2];
	
	if (pspecies.type2.typeName== "???"){
	pokemonMove[1].moveType.typeName=pokemonTypeList[rand()%19];
	}else{
	pokemonMove[1].moveType.typeName=pspecies.type2.typeName;	
	}
	a=0;
	for (int i=0;i<36;i++){
		if (pokemonMove[1].moveType.typeName==MoveList[i].moveType.typeName){
			possibleMove[a]=MoveList[i];
			a++;
		}
	}
	pokemonMove[1]=possibleMove[rand()%2];
	while (pokemonMove[1].moveName==pokemonMove[2].moveName){
		pokemonMove[1]=possibleMove[rand()%2];
	}
	pokemonMove[2]=MoveList[rand()%36];
	while (pokemonMove[2].moveName==pokemonMove[1].moveName
		|| pokemonMove[2].moveName==pokemonMove[0].moveName){
		pokemonMove[2]=MoveList[rand()%36];
	}
	pokemonMove[3]=MoveList[rand()%36];
	while (pokemonMove[3].moveName==pokemonMove[0].moveName
		|| pokemonMove[3].moveName==pokemonMove[1].moveName
		|| pokemonMove[3].moveName==pokemonMove[2].moveName){
		pokemonMove[3]=MoveList[rand()%36];
	}	
	//function that uses type names to find moves
}


Pokemon::~Pokemon(){
}


class Trainer
{
public:
Trainer();
Trainer(std::string ptrainerName);
//has team array of 6 pokemon
	Pokemon pokemonTeam[6];
	int amountPokemon;
	Pokemon *addToTeam(Pokemon ppokemon);
//has name
	std::string trainerName;
	void showTeam();
	void changeNickname(std::string oldName, std::string newName);
//has trainer rank
//has team storage array of upto 30 pokemon
void pokemonInfo(std::string pnickname);
~Trainer();
};

Trainer::Trainer(){
	amountPokemon=0;
}

Trainer::Trainer(std::string ptrainerName){
	trainerName=ptrainerName;
	amountPokemon=0;
}


Pokemon* Trainer::addToTeam(Pokemon ppokemon){
	if (amountPokemon<6){
	pokemonTeam[amountPokemon]= ppokemon;
	amountPokemon++;
	}
	return &pokemonTeam[0];
}

void Trainer::showTeam(){
	for (int i=0;i<amountPokemon; i++){
		std::cout << pokemonTeam[i].nickname << " [" <<i+1<< "] "<<std::endl;
	}
	
}

void Trainer::changeNickname(std::string oldName, std::string newName){
	for (int i=0; i<amountPokemon; i++){
		if (oldName==pokemonTeam[i].nickname){
			pokemonTeam[i].nickname = newName;
			return;
		}
	}
}
void Trainer::pokemonInfo(std::string pnickname){
	for (int i=0;i<6;i++){
		if (pokemonTeam[i].nickname==pnickname){
	std::cout<<"Pokemon Species:  "<<pokemonTeam[i].speciesType.speciesName <<std::endl;
	std::cout<<"Pokemon Name: "<<pokemonTeam[i].nickname <<std::endl;
	std::cout<<"Current HP: "<<pokemonTeam[i].maxHitPoints << "/"<<
	pokemonTeam[i].currentHitPoints <<std::endl;
	std::cout<<"attack: "<<pokemonTeam[i].pokemonStats[1] <<std::endl;
	std::cout<<"defense: "<<pokemonTeam[i].pokemonStats[2] <<std::endl;
	std::cout<<"SpAttack: "<<pokemonTeam[i].pokemonStats[3] <<std::endl;
	std::cout<<"SpDefense: "<<pokemonTeam[i].pokemonStats[4] <<std::endl;
	std::cout<<"Speed: "<<pokemonTeam[i].pokemonStats[5]<<std::endl;
	std::cout<<"Pokemon type: "<<pokemonTeam[i].speciesType.type1.typeName;
	if (pokemonTeam[i].speciesType.type2.typeName== "???"){
	}else{
	std::cout<<"/"<<pokemonTeam[i].speciesType.type2.typeName;
	}
	std::cout<< std::endl;	
	for (int j=0; j<4;j++){
		std::cout<< pokemonTeam[i].pokemonMove[j].moveName<<"   ";
		std::cout<< pokemonTeam[i].pokemonMove[j].power<< std::endl;
	}
	return;
		}
	}
}
Trainer::~Trainer(){
}

int main() {
//set random number generator seed
srand(time(0));

//types

Type Normal =Type("Normal");
Type Fire =Type("Fire");
Type Water =Type("Water");
Type Electric =Type("Electric");
Type Grass =Type("Grass");
Type Ice =Type("Ice");
Type Fighting =Type("Fighting");
Type Poison =Type("Poison");
Type Ground =Type("Ground");
Type Flying =Type("Flying");
Type Psychic =Type("Psychic");
Type Bug =Type("Bug");
Type Rock =Type("Rock");
Type Ghost =Type("Ghost");
Type Dragon =Type("Dragon");
Type Dark =Type("Dark");
Type Steel =Type("Steel");
Type Fairy =Type("Fairy");
Type Null =Type("???");

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

//Pokedex[i]=species("name",HP,Attack,Defense,SpecialAttack,SpecialDefense,Speed,type1,type2);

Pokedex[0]=Species("Bulbasaur",45,49,49,65,65,45,Grass,Poison);
Pokedex[1]=Species("Ivysaur",60,62,63,80,80,60,Grass,Poison);
Pokedex[2]=Species("Venusaur",80,82,83,100,100,80,Grass,Poison);
Pokedex[3]=Species("Charmander",39,52,43,60,50,65,Fire,Null);
Pokedex[4]=Species("Charmeleon",58,64,58,80,65,80,Fire,Null);
Pokedex[5]=Species("Charizard",78,84,78,109,85,100,Fire,Flying);
Pokedex[6]=Species("Squirtle",44,48,65,60,54,43,Water,Null);
Pokedex[7]=Species("Wartortle",59,63,80,65,80,58,Water,Null);
Pokedex[8]=Species("Blastoise",79,83,100,85,105,78,Water,Null);
Pokedex[9]=Species("Caterpie",45,30,35,20,20,45,Bug,Null);
Pokedex[10]=Species("Metapod",50,20,55,25,25,30,Bug,Null);

Pokedex[11]=Species("Butterfree",60,45,50,80,80,70,Bug,Flying);
Pokedex[12]=Species("Weedle",40,35,30,20,20,50,Bug,Poison);
Pokedex[13]=Species("Kakuna",45,25,50,25,25,35,Bug,Poison);
Pokedex[14]=Species("Beedrill",65,80,40,40,80,75,Bug,Poison);
Pokedex[15]=Species("Pidgey",40,45,40,35,35,56,Normal,Flying);
Pokedex[16]=Species("Pidgeotto",63,60,55,50,50,71,Normal,Flying);
Pokedex[17]=Species("Pidgeot",83,80,75,70,70,91,Normal,Flying);
Pokedex[18]=Species("Rattata",30,56,35,25,35,72,Normal,Null);
Pokedex[19]=Species("Raticate",55,81,60,50,70,97,Normal,Null);
Pokedex[20]=Species("Spearow",40,60,30,31,31,70,Normal,Flying);
Pokedex[21]=Species("Fearow",65,90,65,61,61,100,Normal,Flying);
Pokedex[22]=Species("Ekans",30,60,44,40,54,55,Poison,Null);
Pokedex[23]=Species("Arbok",60,85,69,65,79,80,Poison,Null);
Pokedex[24]=Species("Pikachu",35,55,30,50,40,90,Electric,Null);
Pokedex[25]=Species("Raichu",60,90,55,90,80,100,Electric,Null);
Pokedex[26]=Species("Sandshrew",50,75,85,20,30,40,Ground,Null);
Pokedex[27]=Species("Sandslash",75,100,110,45,55,65,Ground,Null);
Pokedex[28]=Species("Nidoran M",55,47,52,40,40,41,Poison,Null);
Pokedex[29]=Species("Nidorina",70,62,67,55,55,56,Poison,Null);
Pokedex[30]=Species("Nidoqueen",90,82,87,75,85,76,Poison,Ground);
Pokedex[31]=Species("Nidoran F",46,57,40,40,40,50,Poison,Null);
Pokedex[32]=Species("Nidorino",61,72,57,55,55,65,Poison,Null);
Pokedex[33]=Species("Nidoking",81,92,77,85,75,85,Poison,Ground);
Pokedex[34]=Species("Clefairy",70,45,48,60,65,35,Normal,Null);
Pokedex[35]=Species("Clefable",95,70,73,85,90,60,Normal,Null);
Pokedex[36]=Species("Vulpix",38,41,40,50,65,65,Fire,Null);
Pokedex[37]=Species("Ninetales",73,76,75,81,100,100,Fire,Null);
Pokedex[38]=Species("Jigglypuff",115,45,20,45,25,20,Normal,Null);
Pokedex[39]=Species("Wigglytuff",140,70,45,75,50,45,Normal,Null);
Pokedex[40]=Species("Zubat",40,45,35,30,40,55,Poison,Flying);
Pokedex[41]=Species("Golbat",75,80,70,65,75,90,Poison,Flying);
Pokedex[42]=Species("Oddish",45,50,55,75,65,30,Grass,Poison);
Pokedex[43]=Species("Gloom",60,65,70,85,75,40,Grass,Poison);
Pokedex[44]=Species("Vileplume",75,80,85,100,90,50,Grass,Poison);
Pokedex[45]=Species("Paras",35,70,55,45,55,25,Bug,Grass);
Pokedex[46]=Species("Parasect",60,95,80,60,80,30,Bug,Grass);
Pokedex[47]=Species("Venonat",60,55,50,40,55,45,Bug,Poison);
Pokedex[48]=Species("Venomoth",70,65,60,90,75,90,Bug,Poison);
Pokedex[49]=Species("Diglett",10,55,25,35,45,95,Ground,Null);
Pokedex[50]=Species("Dugtrio",35,80,50,50,70,120,Ground,Null);
Pokedex[51]=Species("Meowth",40,45,35,40,40,90,Normal,Null);
Pokedex[52]=Species("Persian",65,70,60,65,65,115,Normal,Null);
Pokedex[53]=Species("Psyduck",50,52,48,65,50,55,Water,Null);
Pokedex[54]=Species("Golduck",80,82,78,95,80,85,Water,Null);
Pokedex[55]=Species("Mankey",40,80,35,35,45,70,Fighting,Null);
Pokedex[56]=Species("Primeape",65,105,60,60,70,95,Fighting,Null);
Pokedex[57]=Species("Growlithe",55,70,45,70,50,60,Fire,Null);
Pokedex[58]=Species("Arcanine",90,110,80,100,80,95,Fire,Null);
Pokedex[59]=Species("Poliwag",40,50,40,40,40,90,Water,Null);
Pokedex[60]=Species("Poliwhirl",65,65,65,50,50,90,Water,Null);
Pokedex[61]=Species("Poliwrath",90,85,95,70,90,70,Water,Fighting);
Pokedex[62]=Species("Abra",25,20,15,105,55,90,Psychic,Null);
Pokedex[63]=Species("Kadabra",40,35,30,120,70,105,Psychic,Null);
Pokedex[64]=Species("Alakazam",55,50,45,135,85,120,Psychic,Null);
Pokedex[65]=Species("Machop",70,80,50,35,35,35,Fighting,Null);
Pokedex[66]=Species("Machoke",80,100,70,50,60,45,Fighting,Null);
Pokedex[67]=Species("Machamp",90,130,80,65,85,55,Fighting,Null);
Pokedex[68]=Species("Bellsprout",50,75,35,70,30,40,Grass,Poison);
Pokedex[69]=Species("Weepinbell",65,90,50,85,45,55,Grass,Poison);
Pokedex[70]=Species("Victreebel",80,105,65,100,60,70,Grass,Poison);
Pokedex[71]=Species("Tentacool",40,40,35,50,100,70,Water,Poison);
Pokedex[72]=Species("Tentacruel",80,70,65,80,120,100,Water,Poison);
Pokedex[73]=Species("Geodude",40,80,100,30,30,20,Rock,Ground);
Pokedex[74]=Species("Graveler",55,95,115,45,45,35,Rock,Ground);
Pokedex[75]=Species("Golem",80,110,130,55,65,45,Rock,Ground);
Pokedex[76]=Species("Ponyta",50,85,55,65,65,90,Fire,Null);
Pokedex[77]=Species("Rapidash",65,100,70,80,80,105,Fire,Null);
Pokedex[78]=Species("Slowpoke",90,65,65,40,40,15,Water,Psychic);
Pokedex[79]=Species("Slowbro",95,75,110,100,80,30,Water,Psychic);
Pokedex[80]=Species("Magnemite",25,35,70,95,55,45,Electric,Steel);
Pokedex[81]=Species("Magneton",50,60,95,120,70,70,Electric,Steel);
Pokedex[82]=Species("Farfetch'd",52,65,55,58,62,60,Normal,Flying);
Pokedex[83]=Species("Doduo",35,85,45,35,35,75,Normal,Flying);
Pokedex[84]=Species("Dodrio",60,110,70,60,60,100,Normal,Flying);
Pokedex[85]=Species("Seel",65,45,55,45,70,45,Water,Null);
Pokedex[86]=Species("Dewgong",90,70,80,70,95,70,Water,Ice);
Pokedex[87]=Species("Grimer",80,80,50,40,50,25,Poison,Null);
Pokedex[88]=Species("Muk",105,105,75,65,100,50,Poison,Null);
Pokedex[89]=Species("Shellder",30,65,100,45,25,40,Water,Null);
Pokedex[90]=Species("Cloyster",50,90,180,85,45,70,Water,Ice);
Pokedex[91]=Species("Gastly",30,35,30,100,35,80,Ghost,Poison);
Pokedex[92]=Species("Haunter",45,50,45,115,55,95,Ghost,Poison);
Pokedex[93]=Species("Gengar",60,65,60,130,75,110,Ghost,Poison);
Pokedex[94]=Species("Onix",35,45,160,30,45,70,Rock,Ground);
Pokedex[95]=Species("Drowzee",60,48,45,43,90,42,Psychic,Null);
Pokedex[96]=Species("Hypno",85,73,70,73,115,67,Psychic,Null);
Pokedex[97]=Species("Krabby",30,105,90,25,25,50,Water,Null);
Pokedex[98]=Species("Kingler",55,130,115,50,50,75,Water,Null);
Pokedex[99]=Species("Voltorb",40,30,50,55,55,100,Electric,Null);
Pokedex[100]=Species("Electrode",60,50,70,80,80,140,Electric,Null);
Pokedex[101]=Species("Exeggcute",60,40,80,60,45,40,Grass,Psychic);
Pokedex[102]=Species("Exeggutor",95,95,85,125,65,55,Grass,Psychic);
Pokedex[103]=Species("Cubone",50,50,95,40,50,35,Ground,Null);
Pokedex[104]=Species("Marowak",60,80,110,50,80,45,Ground,Null);
Pokedex[105]=Species("Hitmonlee",50,120,53,35,110,87,Fighting,Null);
Pokedex[106]=Species("Hitmonchan",50,105,79,35,110,76,Fighting,Null);
Pokedex[107]=Species("Lickitung",90,55,75,60,75,30,Normal,Null);
Pokedex[108]=Species("Koffing",40,65,95,60,45,35,Poison,Null);
Pokedex[109]=Species("Weezing",65,90,120,85,70,60,Poison,Null);
Pokedex[110]=Species("Rhyhorn",80,85,95,30,30,25,Ground,Rock);
Pokedex[111]=Species("Rhydon",105,130,120,45,45,40,Ground,Rock);
Pokedex[112]=Species("Chansey",250,5,5,35,105,50,Normal,Null);
Pokedex[113]=Species("Tangela",65,55,115,100,40,60,Grass,Null);
Pokedex[114]=Species("Kangaskhan",105,95,80,40,80,90,Normal,Null);
Pokedex[115]=Species("Horsea",30,40,70,70,25,60,Water,Null);
Pokedex[116]=Species("Seadra",55,65,95,95,45,85,Water,Null);
Pokedex[117]=Species("Goldeen",45,67,60,35,50,63,Water,Null);
Pokedex[118]=Species("Seaking",80,92,65,65,80,68,Water,Null);
Pokedex[119]=Species("Staryu",30,45,55,70,55,85,Water,Null);
Pokedex[120]=Species("Starmie",60,75,85,100,85,115,Water,Psychic);
Pokedex[121]=Species("Mr. Mime",40,45,65,100,120,90,Psychic,Null);
Pokedex[122]=Species("Scyther",70,110,80,55,80,105,Bug,Flying);
Pokedex[123]=Species("Jynx",65,50,35,115,95,95,Ice,Psychic);
Pokedex[124]=Species("Electabuzz",65,83,57,95,85,105,Electric,Null);
Pokedex[125]=Species("Magmar",65,95,57,100,85,93,Fire,Null);
Pokedex[126]=Species("Pinsir",65,125,100,55,70,85,Bug,Null);
Pokedex[127]=Species("Tauros",75,100,95,40,70,110,Normal,Null);
Pokedex[128]=Species("Magikarp",20,10,55,15,20,80,Water,Null);
Pokedex[129]=Species("Gyarados",95,125,79,60,100,81,Water,Flying);
Pokedex[130]=Species("Lapras",130,85,80,85,95,60,Water,Ice);
Pokedex[131]=Species("Ditto",48,48,48,48,48,48,Normal,Null);
Pokedex[132]=Species("Eevee",55,55,50,45,65,55,Normal,Null);
Pokedex[133]=Species("Vaporeon",130,65,60,110,95,65,Water,Null);
Pokedex[134]=Species("Jolteon",65,65,60,110,95,130,Electric,Null);
Pokedex[135]=Species("Flareon",65,130,60,95,110,65,Fire,Null);
Pokedex[136]=Species("Porygon",65,60,70,85,75,40,Normal,Null);
Pokedex[137]=Species("Omanyte",35,40,100,90,55,35,Rock,Water);
Pokedex[138]=Species("Omastar",70,60,125,115,70,55,Rock,Water);
Pokedex[139]=Species("Kabuto",30,80,90,55,45,55,Rock,Water);
Pokedex[140]=Species("Kabutops",60,115,105,65,70,80,Rock,Water);
Pokedex[141]=Species("Aerodactyl",80,105,65,60,75,130,Rock,Flying);
Pokedex[142]=Species("Snorlax",160,110,65,65,110,30,Normal,Null);
Pokedex[143]=Species("Articuno",90,85,100,95,125,85,Ice,Flying);
Pokedex[144]=Species("Zapdos",90,90,85,125,90,100,Electric,Flying);
Pokedex[145]=Species("Moltres",90,100,90,125,85,90,Fire,Flying);
Pokedex[146]=Species("Dratini",41,64,45,50,50,50,Dragon,Null);
Pokedex[147]=Species("Dragonair",61,84,65,70,70,70,Dragon,Null);
Pokedex[148]=Species("Dragonite",91,134,95,100,100,80,Dragon,Flying);
Pokedex[149]=Species("Mewtwo",106,110,90,154,90,130,Psychic,Null);
Pokedex[150]=Species("Mew",100,100,100,100,100,100,Psychic,Null);
/*
Pokedex[151]=Species("Chikorita",45,49,65,49,65,45,Grass,Null);
Pokedex[152]=Species("Bayleef",60,62,80,63,80,69,Grass,Null);
Pokedex[153]=Species("Meganium",80,82,100,83,100,80,Grass,Null);
Pokedex[154]=Species("Cyndaquil",39,52,43,60,50,65,Fire,Null);
Pokedex[155]=Species("Quilava",58,64,58,80,65,80,Fire,Null);
Pokedex[156]=Species("Typhlosion",78,84,78,109,85,100,Fire,Null);
Pokedex[157]=Species("Totodile",50,65,64,44,48,43,Water,Null);
Pokedex[158]=Species("Croconaw",65,80,80,59,63,58,Water,Null);
Pokedex[159]=Species("Feraligatr",85,105,100,79,83,78,Water,Null);
Pokedex[160]=Species("Sentret",35,46,34,35,45,20,Normal,Null);
Pokedex[161]=Species("Furret",85,76,64,45,55,90,Normal,Null);
Pokedex[162]=Species("Hoothoot",60,30,30,36,56,50,Normal,Flying);
Pokedex[163]=Species("Noctowl",100,50,50,76,96,70,Normal,Flying);
Pokedex[164]=Species("Ledyba",40,20,30,40,80,55,Bug,Flying);
Pokedex[165]=Species("Ledian",55,35,50,55,110,85,Bug,Flying);
Pokedex[166]=Species("Spinarak",40,60,40,40,40,30,Bug,Poison);
Pokedex[167]=Species("Ariados",70,90,70,60,60,40,Bug,Poison);
Pokedex[168]=Species("Crobat",85,90,80,70,80,130,Poison,Flying);
Pokedex[169]=Species("Chinchou",75,38,38,56,56,67,Water,Electric);
Pokedex[170]=Species("Lanturn",125,58,58,76,76,67,Water,Electric);
Pokedex[171]=Species("Pichu",20,40,15,35,35,60,Electric,Null);
Pokedex[172]=Species("Cleffa",50,25,28,45,55,15,Normal,Null);
Pokedex[173]=Species("Igglybuff",90,30,15,40,20,15,Normal,Null);
Pokedex[174]=Species("Togepi",35,20,65,40,65,20,Normal,Null);
Pokedex[175]=Species("Togetic",55,40,85,80,105,40,Normal,Flying);
Pokedex[176]=Species("Natu",40,50,45,70,45,70,Psychic,Flying);
Pokedex[177]=Species("Xatu",65,75,70,95,70,95,Psychic,Flying);
Pokedex[178]=Species("Mareep",55,40,40,65,45,35,Electric,Null);
Pokedex[179]=Species("Flaaffy",70,55,55,80,60,45,Electric,Null);
Pokedex[180]=Species("Ampharos",90,75,75,115,90,55,Electric,Null);
Pokedex[181]=Species("Bellossom",75,80,85,90,100,50,Grass,Null);
Pokedex[182]=Species("Marill",70,20,50,20,50,40,Water,Null);
Pokedex[183]=Species("Azumarill",100,50,80,50,80,50,Water,Null);
Pokedex[184]=Species("Sudowoodo",70,100,115,30,65,30,Rock,Null);
Pokedex[185]=Species("Politoed",90,75,75,90,100,70,Water,Null);
Pokedex[186]=Species("Hoppip",35,35,40,35,55,50,Grass,Flying);
Pokedex[187]=Species("Skiploom",55,45,50,45,65,80,Grass,Flying);
Pokedex[188]=Species("Jumpluff",75,55,70,55,85,110,Grass,Flying);
Pokedex[189]=Species("Aipom",55,70,55,40,55,85,Normal,Null);
Pokedex[190]=Species("Sunkern",30,30,30,30,30,30,Grass,Null);
Pokedex[191]=Species("Sunflora",75,75,55,105,85,30,Grass,Null);
Pokedex[192]=Species("Yanma",65,65,45,75,45,95,Bug,Flying);
Pokedex[193]=Species("Wooper",55,45,45,25,25,15,Water,Ground);
Pokedex[194]=Species("Quagsire",95,85,85,65,65,35,Water,Ground);
Pokedex[195]=Species("Espeon",65,65,60,130,95,110,Psychic,Null);
Pokedex[196]=Species("Umbreon",95,65,110,60,130,65,Dark,Null);
Pokedex[197]=Species("Murkrow",60,85,42,85,42,91,Dark,Flying);
Pokedex[198]=Species("Slowking",95,75,80,100,110,30,Water,Psychic);
Pokedex[199]=Species("Misdreavus",60,60,60,85,85,85,Ghost,Null);
Pokedex[200]=Species("Unown",48,72,48,72,48,48,Psychic,Null);
Pokedex[201]=Species("Wobbuffet",190,33,58,33,58,33,Psychic,Null);
Pokedex[202]=Species("Girafarig",70,80,65,90,65,85,Normal,Psychic);
Pokedex[203]=Species("Pineco",50,65,90,35,35,15,Bug,Null);
Pokedex[204]=Species("Forretress",75,90,140,60,60,40,Bug,Steel);
Pokedex[205]=Species("Dunsparce",100,70,70,65,65,45,Normal,Null);
Pokedex[206]=Species("Gligar",65,75,105,35,65,85,Ground,Flying);
Pokedex[207]=Species("Steelix",75,85,200,55,65,30,Steel,Ground);
Pokedex[208]=Species("Snubbull",60,80,50,40,40,30,Normal,Null);
Pokedex[209]=Species("Granbull",90,120,75,60,60,45,Normal,Null);
Pokedex[210]=Species("Qwilfish",65,95,75,55,55,85,Water,Poison);
Pokedex[211]=Species("Scizor",70,130,100,55,80,65,Bug,Steel);
Pokedex[212]=Species("Shuckle",20,10,230,10,230,5,Bug,Rock);
Pokedex[213]=Species("Heracross",80,125,75,40,95,85,Bug,Fighting);
Pokedex[214]=Species("Sneasel",55,95,55,35,75,115,Dark,Ice);
Pokedex[215]=Species("Teddiursa",60,80,50,50,50,40,Normal,Null);
Pokedex[216]=Species("Ursaring",90,130,75,75,75,55,Normal,Null);
Pokedex[217]=Species("Slugma",40,40,40,70,40,20,Fire,Null);
Pokedex[218]=Species("Magcargo",50,50,120,80,80,30,Fire,Rock);
Pokedex[219]=Species("Swinub",50,50,40,30,30,50,Ice,Ground);
Pokedex[220]=Species("Piloswine",100,100,80,60,60,50,Ice,Ground);
Pokedex[221]=Species("Corsola",55,55,85,65,85,35,Water,Rock);
Pokedex[222]=Species("Remoraid",35,65,35,65,35,65,Water,Null);
Pokedex[223]=Species("Octillery",75,105,75,105,75,45,Water,Null);
Pokedex[224]=Species("Delibird",45,55,45,65,45,75,Ice,Flying);
Pokedex[225]=Species("Mantine",65,40,70,80,140,70,Water,Flying);
Pokedex[226]=Species("Skarmory",65,80,140,40,70,70,Steel,Flying);
Pokedex[227]=Species("Houndour",45,60,30,80,50,65,Dark,Fire);
Pokedex[228]=Species("Houndoom",75,90,50,110,80,95,Dark,Fire);
Pokedex[229]=Species("Kingdra",75,95,95,95,95,85,Water,Dragon);
Pokedex[230]=Species("Phanpy",90,60,60,40,40,40,Ground,Null);
Pokedex[231]=Species("Donphan",90,120,120,60,60,50,Ground,Null);
Pokedex[232]=Species("Porygon2",85,80,90,105,95,60,Normal,Null);
Pokedex[233]=Species("Stantler",73,95,62,85,65,85,Normal,Null);
Pokedex[234]=Species("Smeargle",55,20,35,20,45,75,Normal,Null);
Pokedex[235]=Species("Tyrogue",35,35,35,35,35,35,Fighting,Null);
Pokedex[236]=Species("Hitmontop",50,95,95,35,110,70,Fighting,Null);
Pokedex[237]=Species("Smoochum",45,30,15,85,65,65,Ice,Psychic);
Pokedex[238]=Species("Elekid",45,63,37,65,55,95,Electric,Null);
Pokedex[239]=Species("Magby",45,75,37,70,55,83,Fire,Null);
Pokedex[240]=Species("Miltank",95,80,105,40,70,100,Normal,Null);
Pokedex[241]=Species("Blissey",255,10,10,75,135,55,Normal,Null);
Pokedex[242]=Species("Raikou",90,85,75,115,100,115,Electric,Null);
Pokedex[243]=Species("Entei",115,115,85,90,75,100,Fire,Null);
Pokedex[244]=Species("Suicune",100,75,115,90,115,85,Water,Null);
Pokedex[245]=Species("Larvitar",50,64,50,45,50,41,Rock,Ground);
Pokedex[246]=Species("Pupitar",70,84,70,65,70,51,Rock,Ground);
Pokedex[247]=Species("Tyranitar",100,134,110,95,100,61,Rock,Dark);
Pokedex[248]=Species("Lugia",106,90,130,90,154,110,Psychic,Flying);
Pokedex[249]=Species("Ho-oh",106,130,90,110,154,90,Fire,Flying);
Pokedex[250]=Species("Celebi",100,100,100,100,100,100,Psychic,Grass);
Pokedex[251]=Species("Treecko",40,45,35,65,55,70,Grass,Null);
Pokedex[252]=Species("Grovyle",50,65,45,85,65,95,Grass,Null);
Pokedex[253]=Species("Sceptile",70,85,65,105,85,120,Grass,Null);
Pokedex[254]=Species("Torchic",45,60,40,70,50,45,Fire,Null);
Pokedex[255]=Species("Combusken",60,85,60,85,60,55,Fire,Fighting);
Pokedex[256]=Species("Blaziken",80,120,70,110,70,80,Fire,Fighting);
Pokedex[257]=Species("Mudkip",50,70,50,50,50,40,Water,Null);
Pokedex[258]=Species("Marshtomp",70,85,70,60,70,50,Water,Ground);
Pokedex[259]=Species("Swampert",100,110,90,85,90,60,Water,Ground);
Pokedex[260]=Species("Poochyena",35,55,35,30,30,35,Dark,Null);
Pokedex[261]=Species("Mightyena",70,90,70,60,60,70,Dark,Null);
Pokedex[262]=Species("Zigzagoon",38,30,41,30,41,60,Normal,Null);
Pokedex[263]=Species("Linoone",78,70,61,50,61,100,Normal,Null);
Pokedex[264]=Species("Wurmple",45,45,35,20,30,20,Bug,Null);
Pokedex[265]=Species("Silcoon",50,35,55,25,25,15,Bug,Null);
Pokedex[266]=Species("Beautifly",60,70,50,90,50,65,Bug,Flying);
Pokedex[267]=Species("Cascoon",50,35,55,25,25,15,Bug,Null);
Pokedex[268]=Species("Dustox",60,50,70,50,90,65,Bug,Poison);
Pokedex[269]=Species("Lotad",40,30,30,40,50,30,Water,Grass);
Pokedex[270]=Species("Lombre",60,50,50,60,70,50,Water,Grass);
Pokedex[271]=Species("Ludicolo",80,70,70,90,100,70,Water,Grass);
Pokedex[272]=Species("Seedot",40,40,50,30,30,30,Grass,Null);
Pokedex[273]=Species("Nuzleaf",70,70,40,60,40,60,Grass,Dark);
Pokedex[274]=Species("Shiftry",90,100,60,90,60,80,Grass,Dark);
Pokedex[275]=Species("Taillow",40,55,30,30,30,85,Normal,Flying);
Pokedex[276]=Species("Swellow",60,85,60,50,50,125,Normal,Flying);
Pokedex[277]=Species("Wingull",40,30,30,55,30,85,Water,Flying);
Pokedex[278]=Species("Pelipper",60,50,100,85,70,65,Water,Flying);
Pokedex[279]=Species("Ralts",28,25,25,45,35,40,Psychic,Null);
Pokedex[280]=Species("Kirlia",38,35,35,65,55,50,Psychic,Null);
Pokedex[281]=Species("Gardevoir",68,65,65,125,115,80,Psychic,Null);
Pokedex[282]=Species("Surskit",40,30,32,50,52,65,Bug,Water);
Pokedex[283]=Species("Masquerain",70,60,62,80,82,60,Bug,Flying);
Pokedex[284]=Species("Shroomish",60,40,60,40,60,35,Grass,Null);
Pokedex[285]=Species("Breloom",60,130,80,60,60,70,Grass,Fighting);
Pokedex[286]=Species("Slakoth",60,60,60,35,35,30,Normal,Null);
Pokedex[287]=Species("Vigoroth",80,80,80,55,55,90,Normal,Null);
Pokedex[288]=Species("Slaking",150,160,100,95,65,100,Normal,Null);
Pokedex[289]=Species("Nincada",31,45,90,30,30,40,Bug,Ground);
Pokedex[290]=Species("Ninjask",61,90,45,50,50,160,Bug,Flying);
Pokedex[291]=Species("Shedinja",1,90,45,30,30,40,Bug,Ghost);
Pokedex[292]=Species("Whismur",64,51,23,51,23,28,Normal,Null);
Pokedex[293]=Species("Loudred",84,71,43,71,43,48,Normal,Null);
Pokedex[294]=Species("Exploud",104,91,63,91,63,68,Normal,Null);
Pokedex[295]=Species("Makuhita",72,60,30,20,30,25,Fighting,Null);
Pokedex[296]=Species("Hariyama",144,120,60,40,60,50,Fighting,Null);
Pokedex[297]=Species("Azurill",50,20,40,20,40,20,Normal,Null);
Pokedex[298]=Species("Nosepass",30,45,135,45,90,30,Rock,Null);
Pokedex[299]=Species("Skitty",50,45,45,35,35,50,Normal,Null);
Pokedex[300]=Species("Delcatty",70,65,65,55,55,70,Normal,Null);
Pokedex[301]=Species("Sableye",50,75,75,65,65,50,Dark,Ghost);
Pokedex[302]=Species("Mawile",50,85,85,55,55,50,Steel,Null);
Pokedex[303]=Species("Aron",50,70,100,40,40,30,Steel,Rock);
Pokedex[304]=Species("Lairon",60,90,140,50,50,40,Steel,Rock);
Pokedex[305]=Species("Aggron",70,110,180,60,60,50,Steel,Rock);
Pokedex[306]=Species("Meditite",30,40,55,40,55,60,Fighting,Psychic);
Pokedex[307]=Species("Medicham",60,60,75,60,75,80,Fighting,Psychic);
Pokedex[308]=Species("Electrike",40,45,40,65,40,65,Electric,Null);
Pokedex[309]=Species("Manectric",70,75,60,105,60,105,Electric,Null);
Pokedex[310]=Species("Plusle",60,50,40,85,75,95,Electric,Null);
Pokedex[311]=Species("Minun",60,40,50,75,85,95,Electric,Null);
Pokedex[312]=Species("Volbeat",65,73,55,47,75,85,Bug,Null);
Pokedex[313]=Species("Illumise",65,47,55,73,75,85,Bug,Null);
Pokedex[314]=Species("Roselia",50,60,45,100,80,65,Grass,Poison);
Pokedex[315]=Species("Gulpin",70,43,53,43,53,40,Poison,Null);
Pokedex[316]=Species("Swalot",100,73,83,73,83,55,Poison,Null);
Pokedex[317]=Species("Carvanha",45,90,20,65,20,65,Water,Dark);
Pokedex[318]=Species("Sharpedo",70,120,40,95,40,95,Water,Dark);
Pokedex[319]=Species("Wailmer",130,70,35,70,35,60,Water,Null);
Pokedex[320]=Species("Wailord",170,90,45,90,45,60,Water,Null);
Pokedex[321]=Species("Numel",60,60,40,65,45,35,Fire,Ground);
Pokedex[322]=Species("Camerupt",70,100,70,105,75,40,Fire,Ground);
Pokedex[323]=Species("Torkoal",70,85,140,85,70,20,Fire,Null);
Pokedex[324]=Species("Spoink",60,25,35,70,80,60,Psychic,Null);
Pokedex[325]=Species("Grumpig",80,45,65,90,110,80,Psychic,Null);
Pokedex[326]=Species("Spinda",60,60,60,60,60,60,Normal,Null);
Pokedex[327]=Species("Trapinch",45,100,45,45,45,10,Ground,Null);
Pokedex[328]=Species("Vibrava",50,70,50,50,50,70,Ground,Dragon);
Pokedex[329]=Species("Flygon",80,100,80,80,80,100,Ground,Dragon);
Pokedex[330]=Species("Cacnea",50,85,40,85,40,35,Grass,Null);
Pokedex[331]=Species("Cacturne",70,115,60,115,60,55,Grass,Dark);
Pokedex[332]=Species("Swablu",45,40,60,40,75,50,Normal,Flying);
Pokedex[333]=Species("Altaria",75,70,90,70,105,80,Dragon,Flying);
Pokedex[334]=Species("Zangoose",73,115,60,60,60,90,Normal,Null);
Pokedex[335]=Species("Seviper",73,100,60,100,60,65,Poison,Null);
Pokedex[336]=Species("Lunatone",70,55,65,95,85,70,Rock,Psychic);
Pokedex[337]=Species("Solrock",70,95,85,55,65,70,Rock,Psychic);
Pokedex[338]=Species("Barboach",50,48,43,46,41,60,Water,Ground);
Pokedex[339]=Species("Whiscash",110,78,73,76,71,60,Water,Ground);
Pokedex[340]=Species("Corphish",43,80,65,50,35,35,Water,Null);
Pokedex[341]=Species("Crawdaunt",63,120,85,90,55,55,Water,Dark);
Pokedex[342]=Species("Baltoy",40,40,55,40,70,55,Ground,Psychic);
Pokedex[343]=Species("Claydol",60,70,105,70,120,75,Ground,Psychic);
Pokedex[344]=Species("Lileep",66,41,77,61,87,23,Rock,Grass);
Pokedex[345]=Species("Cradily",86,81,97,81,107,43,Rock,Grass);
Pokedex[346]=Species("Anorith",45,95,50,40,50,75,Rock,Bug);
Pokedex[347]=Species("Armaldo",75,125,100,70,80,45,Rock,Bug);
Pokedex[348]=Species("Feebas",20,15,20,10,55,80,Water,Null);
Pokedex[349]=Species("Milotic",95,60,79,100,125,81,Water,Null);
Pokedex[350]=Species("Castform",70,70,70,70,70,70,Normal,Null);
Pokedex[351]=Species("Kecleon",60,90,70,60,120,40,Normal,Null);
Pokedex[352]=Species("Shuppet",44,75,35,63,33,45,Ghost,Null);
Pokedex[353]=Species("Banette",64,115,65,83,63,65,Ghost,Null);
Pokedex[354]=Species("Duskull",20,40,90,30,90,25,Ghost,Null);
Pokedex[355]=Species("Dusclops",40,70,130,60,130,25,Ghost,Null);
Pokedex[356]=Species("Tropius",99,68,83,72,87,51,Grass,Flying);
Pokedex[357]=Species("Chimecho",65,50,70,95,80,65,Psychic,Null);
Pokedex[358]=Species("Absol",65,130,60,75,60,75,Dark,Null);
Pokedex[359]=Species("Wynaut",95,23,48,23,48,23,Psychic,Null);
Pokedex[360]=Species("Snorunt",50,50,50,50,50,50,Ice,Null);
Pokedex[361]=Species("Glalie",80,80,80,80,80,80,Ice,Null);
Pokedex[362]=Species("Spheal",70,40,50,55,50,25,Ice,Water);
Pokedex[363]=Species("Sealeo",90,60,70,75,70,45,Ice,Water);
Pokedex[364]=Species("Walrein",110,80,90,95,90,65,Ice,Water);
Pokedex[365]=Species("Clamperl",35,64,85,74,55,32,Water,Null);
Pokedex[366]=Species("Huntail",55,104,105,94,75,52,Water,Null);
Pokedex[367]=Species("Gorebyss",55,84,105,114,75,52,Water,Null);
Pokedex[368]=Species("Relicanth",100,90,130,45,65,55,Water,Rock);
Pokedex[369]=Species("Luvdisc",43,30,55,40,65,97,Water,Null);
Pokedex[370]=Species("Bagon",45,75,60,40,30,50,Dragon,Null);
Pokedex[371]=Species("Shelgon",65,95,100,60,50,50,Dragon,Null);
Pokedex[372]=Species("Salamence",95,135,80,110,80,100,Dragon,Flying);
Pokedex[373]=Species("Beldum",40,55,80,35,60,30,Steel,Psychic);
Pokedex[374]=Species("Metang",60,75,100,55,80,50,Steel,Psychic);
Pokedex[375]=Species("Metagross",80,135,130,95,90,70,Steel,Psychic);
Pokedex[376]=Species("Regirock",80,100,200,50,100,50,Rock,Null);
Pokedex[377]=Species("Regice",80,50,100,100,200,50,Ice,Null);
Pokedex[378]=Species("Registeel",80,75,150,75,150,50,Steel,Null);
Pokedex[379]=Species("Latias",80,80,90,110,130,110,Dragon,Psychic);
Pokedex[380]=Species("Latios",80,90,80,130,110,110,Dragon,Psychic);
Pokedex[381]=Species("Kyogre",100,100,90,150,140,90,Water,Null);
Pokedex[382]=Species("Groudon",100,150,140,100,90,90,Ground,Null);
Pokedex[383]=Species("Rayquaza",105,150,90,150,90,95,Dragon,Flying);
Pokedex[384]=Species("Jirachi",100,100,100,100,100,100,Steel,Psychic);
Pokedex[385]=Species("Deoxys (N)",50,150,50,150,50,150,Psychic,Null);
Pokedex[386]=Species("Deoxys (A)",50,180,20,180,20,150,Psychic,Null);
Pokedex[387]=Species("Deoxys (D)",50,70,160,70,160,90,Psychic,Null);
Pokedex[388]=Species("Deoxys (S)",50,95,90,95,90,180,Psychic,Null);
Pokedex[389]=Species("Turtwig",55,68,64,45,55,31,Grass,Null);
Pokedex[390]=Species("Grotle",75,89,85,55,65,36,Grass,Null);
Pokedex[391]=Species("Torterra",95,109,105,75,85,56,Grass,Ground);
Pokedex[392]=Species("Chimchar",44,58,44,58,44,61,Fire,Null);
Pokedex[393]=Species("Monferno",64,78,52,78,52,81,Fire,Fighting);
Pokedex[394]=Species("Infernape",76,104,71,104,71,108,Fire,Fighting);
Pokedex[395]=Species("Piplup",53,51,53,61,56,40,Water,Null);
Pokedex[396]=Species("Prinplup",64,66,68,81,76,50,Water,Null);
Pokedex[397]=Species("Empoleon",84,86,88,111,101,60,Water,Steel);
Pokedex[398]=Species("Starly",40,55,30,30,30,60,Normal,Flying);
Pokedex[399]=Species("Staravia",55,75,50,40,40,80,Normal,Flying);
Pokedex[400]=Species("Staraptor",85,120,70,50,50,100,Normal,Flying);
Pokedex[401]=Species("Bidoof",59,45,40,35,40,31,Normal,Null);
Pokedex[402]=Species("Bibarel",79,85,60,60,71,55,Normal,Water);
Pokedex[403]=Species("Kricketot",37,25,41,25,41,25,Bug,Null);
Pokedex[404]=Species("Kricketune",77,85,51,55,51,65,Bug,Null);
Pokedex[405]=Species("Shinx",45,65,34,40,34,45,Electric,Null);
Pokedex[406]=Species("Luxio",60,85,49,60,49,60,Electric,Null);
Pokedex[407]=Species("Luxray",80,120,79,95,79,70,Electric,Null);
Pokedex[408]=Species("Budew",40,30,35,50,70,55,Grass,Poison);
Pokedex[409]=Species("Roserade",60,70,55,125,105,90,Grass,Poison);
Pokedex[410]=Species("Cranidos",67,125,40,30,30,58,Rock,Null);
Pokedex[411]=Species("Rampardos",97,165,60,65,50,58,Rock,Null);
Pokedex[412]=Species("Shieldon",30,42,118,42,88,30,Rock,Steel);
Pokedex[413]=Species("Bastiodon",60,52,168,47,138,30,Rock,Steel);
Pokedex[414]=Species("Burmy",40,29,45,29,45,36,Bug,Null);
Pokedex[415]=Species("Wormadam (P)",60,59,85,79,105,36,Bug,Grass);
Pokedex[416]=Species("Wormadam (S)",60,79,105,59,85,36,Bug,Ground);
Pokedex[417]=Species("Wormadam (T)",60,69,95,69,95,36,Bug,Steel);
Pokedex[418]=Species("Mothim",70,94,50,94,50,66,Bug,Flying);
Pokedex[419]=Species("Combee",30,30,42,30,42,70,Bug,Flying);
Pokedex[420]=Species("Vespiquen",70,80,102,80,102,40,Bug,Flying);
Pokedex[421]=Species("Pachirisu",60,45,70,45,90,95,Electric,Null);
Pokedex[422]=Species("Buizel",55,65,35,60,30,85,Water,Null);
Pokedex[423]=Species("Floatzel",85,105,55,85,50,115,Water,Null);
Pokedex[424]=Species("Cherubi",45,35,45,62,53,35,Grass,Null);
Pokedex[425]=Species("Cherrim",70,60,70,87,78,85,Grass,Null);
Pokedex[426]=Species("Shellos",76,48,48,57,62,34,Water,Null);
Pokedex[427]=Species("Gastrodon",111,83,68,92,82,39,Water,Ground);
Pokedex[428]=Species("Ambipom",75,100,66,60,66,115,Normal,Null);
Pokedex[429]=Species("Drifloon",90,50,34,60,44,70,Ghost,Flying);
Pokedex[430]=Species("Drifblim",150,80,44,90,54,80,Ghost,Flying);
Pokedex[431]=Species("Buneary",55,66,44,44,56,85,Normal,Null);
Pokedex[432]=Species("Lopunny",65,76,84,54,96,105,Normal,Null);
Pokedex[433]=Species("Mismagius",60,60,60,105,105,105,Ghost,Null);
Pokedex[434]=Species("Honchkrow",100,125,52,105,52,71,Dark,Flying);
Pokedex[435]=Species("Glameow",49,55,42,42,37,85,Normal,Null);
Pokedex[436]=Species("Purugly",71,82,64,64,59,112,Normal,Null);
Pokedex[437]=Species("Chingling",45,30,50,65,50,45,Psychic,Null);
Pokedex[438]=Species("Stunky",63,63,47,41,41,74,Poison,Dark);
Pokedex[439]=Species("Skuntank",103,93,67,71,61,84,Poison,Dark);
Pokedex[440]=Species("Bronzor",57,24,86,24,86,23,Steel,Psychic);
Pokedex[441]=Species("Bronzong",67,89,116,79,116,33,Steel,Psychic);
Pokedex[442]=Species("Bonsly",50,80,95,10,45,10,Rock,Null);
Pokedex[443]=Species("Mime Jr.",20,25,45,70,90,60,Psychic,Null);
Pokedex[444]=Species("Happiny",100,5,5,15,65,30,Normal,Null);
Pokedex[445]=Species("Chatot",76,65,45,92,42,91,Normal,Flying);
Pokedex[446]=Species("Spiritomb",50,92,108,92,108,35,Ghost,Dark);
Pokedex[447]=Species("Gible",58,70,45,40,45,42,Dragon,Ground);
Pokedex[448]=Species("Gabite",68,90,65,50,55,82,Dragon,Ground);
Pokedex[449]=Species("Garchomp",108,130,95,80,85,102,Dragon,Ground);
Pokedex[450]=Species("Munchlax",135,85,40,40,85,5,Normal,Null);
Pokedex[451]=Species("Riolu",40,70,40,35,40,60,Fighting,Null);
Pokedex[452]=Species("Lucario",70,110,70,115,70,90,Fighting,Steel);
Pokedex[453]=Species("Hippopotas",68,72,78,38,42,32,Ground,Null);
Pokedex[454]=Species("Hippowdon",108,112,118,68,72,47,Ground,Null);
Pokedex[455]=Species("Skorupi",40,50,90,30,55,65,Poison,Bug);
Pokedex[456]=Species("Drapion",70,90,110,60,75,95,Poison,Dark);
Pokedex[457]=Species("Croagunk",48,61,40,61,40,50,Poison,Fighting);
Pokedex[458]=Species("Toxicroak",83,106,65,86,65,85,Poison,Fighting);
Pokedex[459]=Species("Carnivine",74,100,72,90,72,46,Grass,Null);
Pokedex[460]=Species("Finneon",49,49,56,49,61,66,Water,Null);
Pokedex[461]=Species("Lumineon",69,69,76,69,86,91,Water,Null);
Pokedex[462]=Species("Mantyke",45,20,50,60,120,50,Water,Flying);
Pokedex[463]=Species("Snover",60,62,50,62,60,40,Ice,Grass);
Pokedex[464]=Species("Abomasnow",90,92,75,92,85,60,Ice,Grass);
Pokedex[465]=Species("Weavile",70,120,65,45,85,125,Dark,Ice);
Pokedex[466]=Species("Magnezone",70,70,115,130,90,60,Electric,Steel);
Pokedex[467]=Species("Lickilicky",110,85,95,80,95,50,Normal,Null);
Pokedex[468]=Species("Rhyperior",115,140,130,55,55,40,Ground,Rock);
Pokedex[469]=Species("Tangrowth",100,100,125,110,50,50,Grass,Null);
Pokedex[470]=Species("Electivire",75,123,67,95,85,95,Electric,Null);
Pokedex[471]=Species("Magmortar",75,95,67,125,95,83,Fire,Null);
Pokedex[472]=Species("Togekiss",85,50,95,120,115,80,Normal,Flying);
Pokedex[473]=Species("Yanmega",86,76,86,116,56,95,Bug,Flying);
Pokedex[474]=Species("Leafeon",65,110,130,60,65,95,Grass,Null);
Pokedex[475]=Species("Glaceon",65,60,110,130,95,65,Ice,Null);
Pokedex[476]=Species("Gliscor",75,95,125,45,75,95,Ground,Flying);
Pokedex[477]=Species("Mamoswine",110,130,80,70,60,80,Ice,Ground);
Pokedex[478]=Species("Porygon-Z",85,80,70,135,75,90,Normal,Null);
Pokedex[479]=Species("Gallade",68,125,65,65,115,80,Psychic,Fighting);
Pokedex[480]=Species("Probopass",60,55,145,75,150,40,Rock,Steel);
Pokedex[481]=Species("Dusknoir",45,100,135,65,135,45,Ghost,Null);
Pokedex[482]=Species("Froslass",70,80,70,80,70,110,Ice,Ghost);
Pokedex[483]=Species("Rotom",50,50,77,95,77,91,Electric,Ghost);
Pokedex[484]=Species("Rotom (Heat)",50,65,107,105,107,86,Electric,Fire);
Pokedex[485]=Species("Rotom (Wash)",50,65,107,105,107,86,Electric,Water);
Pokedex[486]=Species("Rotom (Frost)",50,65,107,105,107,86,Electric,Ice);
Pokedex[487]=Species("Rotom (Spin)",50,65,107,105,107,86,Electric,Flying);
Pokedex[488]=Species("Rotom (Cut)",50,65,107,105,107,86,Electric,Grass);
Pokedex[489]=Species("Uxie",75,75,130,75,130,95,Psychic,Null);
Pokedex[490]=Species("Mesprit",80,105,105,105,105,80,Psychic,Null);
Pokedex[491]=Species("Azelf",75,125,70,125,70,115,Psychic,Null);
Pokedex[492]=Species("Dialga",100,120,120,150,100,90,Steel,Dragon);
Pokedex[493]=Species("Palkia",90,120,100,150,120,100,Water,Dragon);
Pokedex[494]=Species("Heatran",91,90,106,130,106,77,Fire,Steel);
Pokedex[495]=Species("Regigigas",110,160,110,80,110,100,Normal,Null);
Pokedex[496]=Species("Giratina",150,100,120,100,120,90,Ghost,Dragon);
Pokedex[497]=Species("Giratina (O)",150,120,100,120,100,90,Ghost,Dragon);
Pokedex[498]=Species("Cresselia",120,70,120,75,130,85,Psychic,Null);
Pokedex[499]=Species("Phione",80,80,80,80,80,80,Water,Null);
Pokedex[500]=Species("Manaphy",100,100,100,100,100,100,Water,Null);
Pokedex[501]=Species("Darkrai",70,90,90,135,90,125,Dark,Null);
Pokedex[502]=Species("Shaymin",100,100,100,100,100,100,Grass,Null);
Pokedex[503]=Species("Shaymin (S)",100,103,75,120,75,127,Grass,Flying);
Pokedex[504]=Species("Arceus",120,120,120,120,120,120,Normal,Null);
*/
Trainer Daniel = Trainer("Daniel");
Trainer Opponent = Trainer("Opponent");
Pokemon RandomPokemon[6];
int a;
for (int i=0;i<6;i++){
	a=rand()%151;
	RandomPokemon[i]= Pokedex[a];
	Daniel.addToTeam(RandomPokemon[i]);
	for (int j=0; j<6; j++){
	if (Daniel.pokemonTeam[i].nickname==Daniel.pokemonTeam[j].nickname){
		if (i==j){
		}else{
	Daniel.changeNickname(Daniel.pokemonTeam[j].nickname, Daniel.pokemonTeam[j].nickname+"2");
		}
	}
	}
}
Daniel.showTeam();
for (int i=0;i<6;i++){
	Daniel.pokemonInfo(Daniel.pokemonTeam[i].nickname);
	std::cout<< std::endl;
}
for (int i=0;i<6;i++){
	a=rand()%151;
	RandomPokemon[i]= Pokedex[a];
	Opponent.addToTeam(RandomPokemon[i]);
}
Opponent.showTeam();
for (int i=0;i<6;i++){
	//Opponent.pokemonInfo(Pokemon[i].nickname);
	//std::cout<< std::endl;
}
/////////////////////////////////////////start different

int input=7;
Daniel.showTeam();
std::cout<<"Pick your Pokemon!"<<std::endl;
std::cin>>input;

	while (input<1 || input >6){
			std::cout<<"enter one of the given options"<<std::endl;
			input=7;
			std::cout<<"Pick your Pokemon!"<<std::endl;
			std::cin>>input;
		}
	
Pokemon *PlayerPokemon= &Daniel.pokemonTeam[input-1];
Pokemon *OpponentPokemon=&Opponent.pokemonTeam[rand()%6];
Move *PlayerMove;
Move *OpponentMove;
Pokemon* attacking;
Trainer* defendingTrainer;
Move* attackingMove;
Pokemon* defending;
int STAB;
bool selectedMove=false;
int damageNumber;
Move Move;
int pokemonKilled=0;
int playerPokemonKilled=0;


int turnPhase=1;
bool battle=true;
while (battle==true){
//main screen
while (turnPhase==1){
input=6;
while(input<1 || input >4){//picking from Fight Pokemon Bag and Run
std::cout << "\n\n\n\n\n\n\n\n\n";
std::cout<<OpponentPokemon->currentHitPoints<<
"/"<<OpponentPokemon->maxHitPoints<< "    "<<OpponentPokemon->nickname<< std::endl;
std::cout<<std::endl<<"         vs"<<std::endl<<std::endl;
std::cout << PlayerPokemon->nickname<<"    "<<PlayerPokemon->currentHitPoints<<
"/"<<PlayerPokemon->maxHitPoints<< std::endl<<std::endl;

std::cout << "Fight [1]" << "	"<< "Pokemon [2]"<<std::endl;
std::cout << "Bag [3]" <<"		"<< "Run [4]" << std::endl;
std::cout<< "\n\n\n";
	std::cin>>input;
	
if (input==1){//Fight

	std::cout << "\n\n\n\n\n\n\n\n\n";
	std::cout<<OpponentPokemon->currentHitPoints<<
	"/"<<OpponentPokemon->maxHitPoints<< "    "<<OpponentPokemon->nickname<< std::endl;
	std::cout<<std::endl<<"         vs"<<std::endl<<std::endl;
	std::cout << PlayerPokemon->nickname<<"    "<<PlayerPokemon->currentHitPoints<<
	"/"<<PlayerPokemon->maxHitPoints<< std::endl<<std::endl;

	std::cout << PlayerPokemon->pokemonMove[0].moveName <<" [1]    "
	<<PlayerPokemon->pokemonMove[1].moveName<< " [2]"<<std::endl;
	std::cout << PlayerPokemon->pokemonMove[2].moveName <<" [3]    "
	<<PlayerPokemon->pokemonMove[3].moveName<< " [4]"<<std::endl;
	
std::cin>>input;
	if 		  (input==1){
		PlayerMove=&PlayerPokemon->pokemonMove[0];
		turnPhase=2;
		selectedMove=true;
	} else if (input==2){
		PlayerMove=&PlayerPokemon->pokemonMove[1];
		turnPhase=2;
		selectedMove=true;
	} else if (input==3){
		PlayerMove=&PlayerPokemon->pokemonMove[2];
		turnPhase=2;
		selectedMove=true;
	} else if (input==4){
		PlayerMove=&PlayerPokemon->pokemonMove[3];
		turnPhase=2;
		selectedMove=true;
	}
}else if(input==2){//pokemon
	std::cout << "\n\n\n\n\n\n\n\n\n";
	Daniel.showTeam();
	std::cin>>input;
	if (input>0 && input <7){
		if (!(Daniel.pokemonTeam[input-1].currentHitPoints==0)){
		PlayerPokemon= &Daniel.pokemonTeam[input-1];
		selectedMove=false;
		turnPhase=3;
		}
	}

}else if(input==3){
	std::cout<< "Your Bag is empty!"<< std::endl;
}else if(input==4){
	std::cout<<"You can't run from a trainer battle!"<<std::endl;
	std::cout<<"But you can for now!"<<std::endl;
	return 0;
}else{
	std::cout << "Please enter a valid option" <<std::endl;
	}
}
}
while (turnPhase==2){
	//battlePhase
		std::cout << "\n\n\n\n\n\n\n\n\n";
			if (PlayerPokemon->pokemonStats[5]>OpponentPokemon->pokemonStats[5]){
				
				attacking=PlayerPokemon;
				defending=OpponentPokemon;
				defendingTrainer=&Opponent;
				attackingMove=PlayerMove;
				
			}else{
				attacking=OpponentPokemon;
				defending=PlayerPokemon;
				defendingTrainer=&Daniel;
				attackingMove=&OpponentPokemon->pokemonMove[rand()%4];
			}
			
			
				if (attacking->speciesType.type1.typeName==attackingMove->moveType.typeName ||
			attacking->speciesType.type2.typeName==attackingMove->moveType.typeName){
			STAB=3;
		}else{
			STAB=2;
		}
	damageNumber=floor((((2*attacking->level/5+2)*attackingMove->power*
	attacking->pokemonStats[1+2*attackingMove->special]/
	defending->pokemonStats[2+2*attackingMove->special])/50+2)*STAB/2
	*attackingMove->moveType.damageArray
	[attackingMove->moveType.positionIndex][defending->speciesType.type1.positionIndex]*
	attackingMove->moveType.damageArray
	[attackingMove->moveType.positionIndex][defending->speciesType.type2.positionIndex]);
	
	
	std::cout<< attacking->nickname << " used " << attackingMove->moveName<< 
	" and dealt "<< damageNumber<<"\n";
	defending->currentHitPoints=defending->currentHitPoints-damageNumber;
	
	
	
	if (defending->currentHitPoints<0){
		defending->currentHitPoints=0;
		if (defendingTrainer==&Opponent){
		pokemonKilled++;
		OpponentPokemon=&Opponent.pokemonTeam[pokemonKilled];
		}else{
			//player picks a new pokemon
			playerPokemonKilled++;
Daniel.showTeam();
std::cout<<"Pick your Pokemon!"<<std::endl;
std::cin>>input;
if (Daniel.pokemonTeam[input-1].currentHitPoints==0){
	std::cout << "pokemon has 0 hitpoints" << "\n";
	input=7;
}
	while (input<1 || input >6){
			std::cout<<"enter one of the given options"<<std::endl;
			input=7;
			std::cout<<"Pick your Pokemon!"<<std::endl;
			std::cin>>input;
			if (Daniel.pokemonTeam[input-1].currentHitPoints==0){
	std::cout << "pokemon has 0 hitpoints" << "\n";
	input=7;
}
		}
	PlayerPokemon= &Daniel.pokemonTeam[input-1];
		}
	turnPhase=4;
	}else{
	turnPhase=3;
		}

}
	while (turnPhase==3){		
	if (selectedMove==true){	
	if (attacking==PlayerPokemon){
				attacking=OpponentPokemon;
				defending=PlayerPokemon;
				defendingTrainer=&Daniel;
				attackingMove=&OpponentPokemon->pokemonMove[rand()%4];
	}else{
				attacking=PlayerPokemon;
				defending=OpponentPokemon;
				defendingTrainer=&Opponent;
				attackingMove=PlayerMove;	
	}
	
	}else{
			std::cout << "\n\n\n\n\n\n\n\n\n";
				attacking=OpponentPokemon;
				defending=PlayerPokemon;
				defendingTrainer=&Daniel;
				attackingMove=&OpponentPokemon->pokemonMove[rand()%4];
		}
if (attacking->speciesType.type1.typeName==attackingMove->moveType.typeName ||
			attacking->speciesType.type2.typeName==attackingMove->moveType.typeName){
			STAB=3;
		}else{
			STAB=2;
		}
	damageNumber=floor((((2*attacking->level/5+2)*attackingMove->power*
	attacking->pokemonStats[1+2*attackingMove->special]/
	defending->pokemonStats[2+2*attackingMove->special])/50+2)*STAB/2
	*attackingMove->moveType.damageArray
	[attackingMove->moveType.positionIndex][defending->speciesType.type1.positionIndex]*
	attackingMove->moveType.damageArray
	[attackingMove->moveType.positionIndex][defending->speciesType.type2.positionIndex]);
	
	std::cout<< attacking->nickname << " used " << attackingMove->moveName<< 
	" and dealt "<< damageNumber<<"\n";
	
	defending->currentHitPoints=defending->currentHitPoints-damageNumber;
	
	if (defending->currentHitPoints<0){
		defending->currentHitPoints=0;
		if (defendingTrainer==&Opponent){
		pokemonKilled++;
		if (pokemonKilled<6){
		OpponentPokemon=&Opponent.pokemonTeam[pokemonKilled];
		}
		}else{
			//player picks a new pokemon
			playerPokemonKilled++;
Daniel.showTeam();
std::cout<<"Pick your Pokemon!"<<std::endl;
std::cin>>input;

	while (input<1 || input >6){
			std::cout<<"enter one of the given options"<<std::endl;
			input=7;
			std::cout<<"Pick your Pokemon!"<<std::endl;
			std::cin>>input;
		}
	PlayerPokemon= &Daniel.pokemonTeam[input-1];
		}
	turnPhase=4;
	}else{
	turnPhase=4;
		}
	
}while (turnPhase==4){
	if (playerPokemonKilled==6){
	 std::cout<<"you have run out of Pokemon to use" << "\n" << "Player Blacked out!\n";
	 battle=false;
	}
	if (pokemonKilled==6){
	 std::cout<<"opponent has run out of Pokemon to use" << "\n" << "Player wins 100g!\n";
	 battle=false;
	}
	
turnPhase=1;

}

}
return 0;
}