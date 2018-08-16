/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Admins Functions file.					   	*
*														*
*********************************************************/

AdminLevel(playerid, level)
{
	if(level >= PlayerInfo[playerid][Admin]) return true;
	else return false;
}

GetAdminLevelName(level)
{
	new str[24];
	switch(level)
	{
		case 1: str = "Trial moderator";
		case 2: str = "Moderator";
		case 3: str = "Experienced moderator";
		case 4: str = "Professional moderator";
		case 5: str = "Senior moderator";
		case 6: str = "Administrator";
		case 7: str = "Experienced Administrator";
		case 8: str = "Professional Administrator";
		case 9: str = "Senior Administrator";
		case 10: str = "Master Administrator";
		case 11: str = "Lead Administrator";
		case 12: str = "Head Administrator";
		case 13: str = "Server Manager";
		case 14: str = "Head manager";
		case 15: str = "Server Owner";
	}
	if(isnull(str))
	{
		str = "Invalid-Level";
	}
	else return str;
}

ConnectedAdmins()
{
	new str[512];
	foreach(new i : Player)
	{
		if(PlayerInfo[i][Admin] > 0)
		{
			format(str, sizeof(str), "%s\n* %s (Id: %d) - %s\n", str, GetName(i), i, PlayerInfo[i][Admin]);
		}
	}
	return str;
}