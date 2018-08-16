/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Connections file.					   		*
*														*
*********************************************************/

public OnPlayerConnect(playerid)
{
	ResetVariables(playerid);
	if(IsPlayerNPC(playerid))
	{
		if(!strcmp(GetName(playerid), "Steven"))
		{
			SetSpawnInfo(playerid, NO_TEAM, 217, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
			SetPlayerColor(playerid, 0xAA3333AA);
			SpawnPlayer(playerid);
			return 1;
		}
	}
	if(IsPlayerBanned(playerid))
	{
		PermantlyBan(GetPlayerID("Steven"), playerid, "Ban Evading");
		return 1;
	}
	
	SendClientMessage(playerid, -1, "{FFAF00}******************************************************************************");
	SendClientMessage(playerid, -1, "{FFAF00}	   	      ★·.·´¯`·.·★ ᴜɴɪᴠᴇʀsɪᴛʏ ᴏғ sᴛᴜɴᴛɪɴɢ ★·.·´¯`·.·★ 	   	           ");
	SendClientMessage(playerid, -1, "{FFAF00}******************************************************************************");
	SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Hello! Welcome to University of Stunting server.");
	SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}On this server you will another experience of samp concept.");
	SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Welcome to the first fortnite server in samp world!.");
	SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}We hope you have fun at University of Stunting server.");
	SendClientMessage(playerid, -1, "{FFAF00}******************************************************************************");
	SendClientMessage(playerid, -1, "{FFAF00}	   	     ▁ ▂ ▄ ▅ ▆ ▇ █ 𝔘𝔫𝔦𝔳𝔢𝔯𝔰𝔦𝔱𝔶 𝔬𝔣 𝔖𝔱𝔲𝔫𝔱𝔦𝔫𝔤 █ ▇ ▆ ▅ ▄ ▂ ▁ 	   	       ");
	SendClientMessage(playerid, -1, "{FFAF00}******************************************************************************");

	if(CheckRegistration(playerid))
	{
		SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}After checking the database we found out that you are registred.");
		SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Please insert your password in case you want to login.");
		ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "{F81414}"SERVER_TAG": {FFFFFF}Login", "Welcome Back, It's been long time!\nWe will have only one look at you to make sure you are you xD\nPlease insert your password below.", "Login", "Cancel");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}After checking the database we found out that you are not registred.");
		SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Please follow the registration process in case to join our membership.");
		StartRegistrationProcess(playerid);
		return 1;
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if(GetPVarInt(playerid, "Disconnect") == 1)
	{
		new string[25];
		DeletePVar(playerid, "Disconnect");
		format(string, sizeof(string), "unbanip %s", GetIP(playerid));
		SendRconCommand(string);
	}
	SaveStats(playerid);
	ResetVariables(playerid);
	return 1;
}