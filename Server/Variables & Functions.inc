/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Variables & Functions main file.			*
*														*
*********************************************************/

// @YSI.inc
#pragma disablerecursion

// @BanFunctions.inc
#define DISCONNECT_TYPE_TIMEOUT 	(0)
#define DISCONNECT_TYPE_KICK 		(1)
#define DISCONNECT_TYPE_BAN			(2)

#define DisconnectUser(%0,%1)		SetTimerEx("DisconnectPlayer", 1000, false, "ii", %0, %1)

// @Global mysql.inc
new MySQL:handle;


// @Global user settings
GetPlayerID(playername[])
{
	foreach(new i : Player)
	{
		new playername2[MAX_PLAYER_NAME];
		GetPlayerName(i, playername2, sizeof(playername2));
		if(strcmp(playername2, playername, true, strlen(playername)) == 0)
		{
			return i;
		}
  	}
  	return INVALID_PLAYER_ID;
}

GetName(playerid)
{
	new string[24];
	GetPlayerName(playerid, string, sizeof(string));
	return string;
}
#undef GetIP
GetIP(playerid)
{
	new string[16];
	GetPlayerIp(playerid, string, sizeof(string));
	return string;
}

native gpci(playerid, serial[], len);
GetGPCI(playerid)
{
	new string[56];
	gpci(playerid, string, sizeof(string));
	return string;
}

// @Accounts.inc
enum ENUM_PLAYER_INFO
{
	// Account Classified info.
	Password[129],
	Bans,
	Kicks,
	Email[32],

	// General Settings
	/* Staff levels */
	Admin,
	VIP,

	/* Other */
	Skin,
	Deaths, 
	Kills,

	// Social media
	discord_id,
	irc_id,

	// Races
	RaceJoining,
	RaceWons,

	// Parkours
	ParkourJoined,
	ParkourWons,

	// Derbies,
	DerbiesJoined,
	DerbiesWons,

	// Deathmatches,
	DMJoined,
	DMWons,

	// HuntGames,
	MoneyBagsFound,
	CookiesJarFound,
	GiftsFound,

	// Achievements
	Achievements[11],

	// Settings
	AutoLogin,
	RampActivated,
	RampType,
	Bounce,
	SpeedBoost
}

new PlayerInfo[MAX_PLAYERS][ENUM_PLAYER_INFO];

// @Connections.inc
ResetVariables(playerid)
{
	new tmp[ENUM_PLAYER_INFO];
	PlayerInfo[playerid] = tmp;
	return 1;
}
