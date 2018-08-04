/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Accounts file.					   			*
*														*
*********************************************************/

CheckRegistration(playerid)
{
	new string[60], Cache:getcache;
	mysql_format(handle, string, sizeof(string), "SELECT * FROM players WHERE Name='%e' LIMIT 1", GetName(playerid));
	getcache = mysql_query(handle, string);

	if(cache_xeon_rows() > 0)
	{
		cache_get_value_name(0, PlayerInfo[playerid][Password], 129);
		cache_delete(getcache);
		return true;
	}
	else
	{
		cache_delete(getcache);
		mysql_format(handle, string, sizeof(string), "SELECT * FROM players WHERE GPCI='%e' LIMIT 1", GetGPCI(playerid));
		getcache = mysql_query(handle, string);
		if(cache_xeon_rows() > 0)
		{
			TemporaryBan(GetPlayerID("Steven"), playerid, "Multi-Accounts");
			cache_delete(getcache);
			return -1;
		}
		else
		{
			return false;
		}
	}
}

StartRegistrationProcess(playerid)
{
	ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "{F81414}"SERVER_TAG": {FFFFFF}Login", "Register" "Welcome Dear player!\nWelcome again to our server, we hope that you will have the best experience here!\nPlease put a password that you are going to use it for your next login!", "Register", "Cancel");
	return 1;
}

RegisterAccount(playerid, password[])
{
	mysql_format(handle, string, sizeof(string), "INSERT INTO players (\
		Name,\
		Password,\
		GPCI,\
		JoinDate,\
		) VALUES (\
		'%e',\
		'%e',\
		'%e',\
		unix_timestamp(), '%d')", GetName(playerid), password, GetGPCI(playerid));

	mysql_query(handle, string);
	SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Woah welcome! You finnaly joined us xD i like you mate we hope we meet each others soon.");

	new Cache:getcache;
	getcache = mysql_query(handle, "SELECT * FROM players WHERE 1");

	new rows;
	cache_get_row_count(rows);
	cache_delete(getcache);

	ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, "{F81414}"SERVER_TAG": {FFFFFF}Email", "Please input a valid below or use Ignore to disable email verification feature {F81414}(Not Recommended)", "Confirm", "Ignore");

	format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}Yay, %s has joined our club! we are making a new personal record everyday! %d players.", GetName(playerid), rows);
	SendClientMessageToAll(-1, string);

	format(PlayerInfo[playerid][Password], 129, password);
	format(PlayerInfo[playerid][Email], 32, "*");

	PlayerInfo[playerid][Bans] = 0;
	PlayerInfo[playerid][Kicks] = 0;
	PlayerInfo[playerid][Admin] = 0;
	PlayerInfo[playerid][VIP] = 0;

	PlayerInfo[playerid][Skin] = 0;
	PlayerInfo[playerid][Deaths] = 0; 
	PlayerInfo[playerid][Kills] = 0;
	PlayerInfo[playerid][JoinDate] = 0;

	// Social media
	PlayerInfo[playerid][discord_id] = 0;
	PlayerInfo[playerid][irc_id] = 0;

	// Races
	PlayerInfo[playerid][RaceJoining] = 0;
	PlayerInfo[playerid][RaceWons] = 0;

	// Parkours
	PlayerInfo[playerid][ParkourJoined] = 0;
	PlayerInfo[playerid][ParkourWons] = 0;

	// Derbies
	PlayerInfo[playerid][DerbiesJoined] = 0;
	PlayerInfo[playerid][DerbiesWons] = 0;

	// Deathmatches
	PlayerInfo[playerid][DMJoined] = 0;
	PlayerInfo[playerid][DMWons] = 0;

	// HuntGames
	PlayerInfo[playerid][MoneyBagsFound] = 0;
	PlayerInfo[playerid][CookiesJarFound] = 0;
	PlayerInfo[playerid][GiftsFound] = 0;

	// Achievements
	for(new i = 0; i < 11; i++) PlayerInfo[playerid][Achievements[i]] = 0;

	// Settings
	PlayerInfo[playerid][AutoLogin] = 0;
	PlayerInfo[playerid][RampActivated] = 0;
	PlayerInfo[playerid][RampType] = 0;
	PlayerInfo[playerid][Bounce] = 0;
	PlayerInfo[playerid][SpeedBoost] = 0;
	return 1;
}

LoadPlayerAccount(playerid)
{
	new Cache:getcache, string[60];
	mysql_format(handle, string, sizeof(string), "SELECT * FROM players WHERE Name='%e'", GetName(playerid));
	getcache = mysql_query(handle, string);

	cache_get_value_name_int(0, "Bans", PlayerInfo[playerid][Bans]);
	cache_get_value_name_int(0, "Kicks", PlayerInfo[playerid][Kicks]);
	cache_get_value_name_int(0, "Admin", PlayerInfo[playerid][Admin]);
	cache_get_value_name_int(0, "VIP", PlayerInfo[playerid][VIP]);

	cache_get_value_name_int(0, "Skin", PlayerInfo[playerid][Skin]);
	cache_get_value_name_int(0, "Deaths", PlayerInfo[playerid][Deaths]); 
	cache_get_value_name_int(0, "Kills", PlayerInfo[playerid][Kills]);
	cache_get_value_name_int(0, "JoinDate", PlayerInfo[playerid][JoinDate]);

	// Social media
	cache_get_value_name_int(0, "discord_id", PlayerInfo[playerid][discord_id]);
	cache_get_value_name_int(0, "irc_id", PlayerInfo[playerid][irc_id]);

	// Races
	cache_get_value_name_int(0, "RaceJoining", PlayerInfo[playerid][RaceJoining]);
	cache_get_value_name_int(0, "RaceWons", PlayerInfo[playerid][RaceWons]);

	// Parkours
	cache_get_value_name_int(0, "ParkourJoined", PlayerInfo[playerid][ParkourJoined]);
	cache_get_value_name_int(0, "ParkourWons", PlayerInfo[playerid][ParkourWons]);

	// Derbies
	cache_get_value_name_int(0, "DerbiesJoined", PlayerInfo[playerid][DerbiesJoined]);
	cache_get_value_name_int(0, "DerbiesWons", PlayerInfo[playerid][DerbiesWons]);

	// Deathmatches
	cache_get_value_name_int(0, "DMJoined", PlayerInfo[playerid][DMJoined]);
	cache_get_value_name_int(0, "DMWons", PlayerInfo[playerid][DMWons]);

	// HuntGames
	cache_get_value_name_int(0, "MoneyBagsFound", PlayerInfo[playerid][MoneyBagsFound]);
	cache_get_value_name_int(0, "CookiesJarFound", PlayerInfo[playerid][CookiesJarFound]);
	cache_get_value_name_int(0, "GiftsFound", PlayerInfo[playerid][GiftsFound]);

	// Settings
	cache_get_value_name_int(0, "AutoLogin", PlayerInfo[playerid][AutoLogin]);
	cache_get_value_name_int(0, "RampActivated", PlayerInfo[playerid][RampActivated]);
	cache_get_value_name_int(0, "RampType", PlayerInfo[playerid][RampType]);
	cache_get_value_name_int(0, "Bounce", PlayerInfo[playerid][Bounce]);
	cache_get_value_name_int(0, "SpeedBoost", PlayerInfo[playerid][SpeedBoost]);

	// Achievements
	new string[24]
	cache_get_value_name_int(0, "Achievements", string); 
	
	sscanf(string 
		"i(0)i(0)i(0)i(0)i(0)i(0)i(0)i(0)i(0)i(0)", 
		PlayerInfo[playerid][Achievements[0]], 
		PlayerInfo[playerid][Achievements[1]],
		PlayerInfo[playerid][Achievements[2]],
		PlayerInfo[playerid][Achievements[3]],
		PlayerInfo[playerid][Achievements[4]],
		PlayerInfo[playerid][Achievements[5]],
		PlayerInfo[playerid][Achievements[6]],
		PlayerInfo[playerid][Achievements[7]],
		PlayerInfo[playerid][Achievements[8]],
		PlayerInfo[playerid][Achievements[9]],
		PlayerInfo[playerid][Achievements[10]],
		);

	cache_delete(getcache);
	return 1;
}


forward public AccountSettingUp(playerid, dialogid, response, listitem, inputtext[]);
public AccountSettingUp(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_LOGIN:
		{
			if(!response)
			{
				SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Failed to login, Please try again later.");
				KickPlayer(GetPlayerID("Steven"), playerid, "Failed to login.");
				return 1;
			}
			if(!strcmp(sha1(inputtext), PlayerInfo[playerid][Password]))
			{
				LoadPlayerAccount(playerid);
				return 1;
			}
			else
			{
				if(GetPVarInt(playerid, "Failed") != 1) 
				{
					SetPVarInt(playerid, "Failed", 1);
					SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Failed to login, Please try again.");
					ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "{F81414}"SERVER_TAG": {FFFFFF}Login", "Welcome Back, It's been long time!\nWe will have only one look at you to make sure you are you xD\nPlease insert your password below.", "Login", "Cancel");
				}
				else
				{
					SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Failed to login, Please try again later.");
					KickPlayer(GetPlayerID("Steven"), playerid, "Failed to login.");
				}	
			}
		}
		case DIALOG_REGISTER:
		{
			if(!response)
			{
				SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Failed to register, Please try again later.");
				KickPlayer(GetPlayerID("Steven"), playerid, "Failed to register.");
				return 1;
			}
			if(strlen(inputtext) < 4)
			{
				SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Ops you can't use a password that has less than 4 characters.");
				StartRegistrationProcess(playerid);
				return 1;
			}
			if(IsNumeric(inputtext))
			{
				SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Well no, you can't use a password that has no chars at all..");
				StartRegistrationProcess(playerid);
				return 1;
			}
			RegisterAccount(playerid, sha1(inputtext));
		}
		case DIALOG_EMAIL:
		{
			if(!response) 
			{

			}
			if(strlen(inputtext) < 5) // 
			{
				SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Well what the hell you just put, i can't believe that less than 5 chars?.");
				ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, "{F81414}"SERVER_TAG": {FFFFFF}Email", "Please input a valid below or use Ignore to disable email verification feature {F81414}(Not Recommended)", "Confirm", "Ignore");
				return 1;
			}
			if(strfind(inputtext, "@") == -1 || strfind(inputtext, ".") == -1) // 
			{
				SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Hmm, I don't think that's a valid email, Please try again with a valid one.");
				ShowPlayerDialog(playerid, DIALOG_EMAIL, DIALOG_STYLE_INPUT, "{F81414}"SERVER_TAG": {FFFFFF}Email", "Please input a valid below or use Ignore to disable email verification feature {F81414}(Not Recommended)", "Confirm", "Ignore");
				return 1;
			}
			new string[74];
			mysql_format(handle, string, sizeof(string), "UPDATE players SET Email='%e' WHERE Name='%e'", inputtext, GetName(playerid));
			mysql_query(handle, string); 
			format(PlayerInfo[playerid][Email], 32, inputtext);
			SendClientMessage(playerid, -1, "{F81414}Steven(0): {FFFFFF}Amazing! You will have to confirm your email later or you account is going to be deleted after one week..");
			SetSpawnInfo(playerid, NO_TEAM, 0, 0.0, 0.0, 0.0, 0.0, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
		}
	}
}
