/*!
 * PBP/ClassSelection/header.inc
 *
 > Priority: 0
 */

const WORLD_CLASS_SELECTION = this.OFFSET;

const MAX_WEAPON_SETS = 40;
const MAX_SPAWN_LOCATIONS = 100;
const MAX_CLASSES = 500;
const this.MAX_WEAPON_SLOT = MAX_WEAPON_SLOT + 1;

const INVALID_TEAM = -1;
const INVALID_WEAPON_SET = -1;
const INVALID_SPAWN_LOCATION = -1;
const INVALID_CLASS = -1;

#assert INVALID_TEAM != NO_TEAM

#if !defined WEAPON_ARMOUR
	#define WEAPON_ARMOUR  (100)
#endif


enum this.E_WEAPON_SET {
	Weapon,
	Ammo
};

enum this.E_SPAWN_LOCATION {
	      Interior,
	      World,
	Float:X, Float:Y, Float:Z,
	Float:Rot,
	Group:Group,
	      Team,
	      WeaponSet
};

enum this.E_CLASS {
	      Skin,
	      SpawnLocation,
	      WeaponSet,
	      World,
	      Team,
	Group:Group
};


new
	         this.WeaponSets[MAX_WEAPON_SETS][this.MAX_WEAPON_SLOT][this.E_WEAPON_SET],
	         this.SpawnLocations[MAX_SPAWN_LOCATIONS][this.E_SPAWN_LOCATION],
	         this.Classes[MAX_CLASSES][this.E_CLASS],
	
	         this.NumWeaponSets = 0,
	         this.NumSpawnLocations = 0,
	         this.NumClasses = 0,
	
	BitArray:this.PlayerHasRequestedClass<MAX_PLAYERS>,
	BitArray:this.ClassAvailableForAll<MAX_CLASSES>,
	BitArray:this.ClassAvailableForPlayer[MAX_PLAYERS]<MAX_CLASSES>,
	         this.PreviousClassid[MAX_PLAYERS char],
	         this.RequestedClass[MAX_PLAYERS],
	         this.PlayerClass[MAX_PLAYERS],
	   Group:this.GroupSetOnSpawn[MAX_PLAYERS],
	    Text:this.WeaponsInfo[MAX_PLAYERS] = {INVALID_TEXT_DRAW, ...},
	         this.Interior = 12,
	   Float:this.PlayerPos[] = {2324.0000, -1143.0000, 1050.4922},
	   Float:this.PlayerRot = 148.7130,
	   Float:this.CameraPos[] = {2322.5078, -1146.3310, 1050.7100},
	   Float:this.CameraLookAt[] = {2324.0000, -1143.0000, 1050.5000},
	         this.LastClass[MAX_PLAYERS],
	         this.LastClassSkin[MAX_PLAYERS],
	    bool:this.ShowsSpawn = true,
	   Float:this.CameraDistance = 3.5,
	   Float:this.CameraDistanceZ = 0.5,
	    bool:this.ShowWeapons = true
;


RegisterConfigVariable: this.Interior;
RegisterConfigArray:    this.PlayerPos;
RegisterConfigVariable: this.PlayerRot;
RegisterConfigArray:    this.CameraPos;
RegisterConfigArray:    this.CameraLookAt;
RegisterConfigVariable: this.ShowsSpawn;
RegisterConfigVariable: this.CameraDistance;
RegisterConfigVariable: this.CameraDistanceZ;
RegisterConfigVariable: this.ShowWeapons;


RegisterUserVariable: "last-class" => this.LastClass;
RegisterUserVariable: "last-class-skin" => this.LastClassSkin;


forward      CreateWeaponSet(...);
forward      CreateSpawnLocation(interior = 0, world = 0, Float:x, Float:y, Float:z, Float:rot, Group:group = GROUP_GLOBAL, team = INVALID_TEAM, weapon_set = INVALID_WEAPON_SET);
forward      CreateClass(skin, spawn_location, weapon_set = INVALID_WEAPON_SET, world = 0, Group:group = GROUP_GLOBAL, team = INVALID_TEAM);
forward bool:IsValidWeaponSet(ws);
forward bool:IsValidSpawnLocation(spawn);
forward bool:IsValidClass(class);
forward bool:PlayerCanSelectClass(playerid, class);
forward bool:SetFirstAvailableClass(playerid);
forward      GetPlayerClass(playerid);
forward      SetClassAvailableForAll(class, bool:set);
forward      SetClassAvailableForPlayer(class, playerid, bool:set);