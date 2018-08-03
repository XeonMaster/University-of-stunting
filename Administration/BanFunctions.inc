/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Ban Functions.  					   		*
*														*
*********************************************************/


IsPlayerBanned(playerid)
{
	new Cache:getCache, string[169];
	mysql_format(handle, string, sizeof(string), "SELECT * FROM Bans WHERE `Name`='%e' OR `IP`='%s' OR `GPCI`=`%s` AND Actif = 1 ORDER BY `Days` DESC LIMIT 1", GetName(playerid), GetIP(playerid), GetGPCI(playerid));
	getCache = mysql_query(handle, string);
	if(cache_num_rows() != 0)
	{
		cache_delete(getCache);
		return true;
	}
	else
	{
		cache_delete(getCache);
		return false;
	}
}

PermantlyBan(playerid, targetid, reason[])
{
	new string[289];
	mysql_format(handle, string, sizeof(string), "INSERT INTO Bans (Name, IP, GPCI, Reason, Admin, BanDate) VALUES ('%e', '%s', '%s', '%s', '%s', UNIX_DATE())", GetName(targetid), GetIP(targetid), GetGPCI(targetid), GetName(playerid), reason);
	mysql_query(handle, string);

	format(string, sizeof(string), "[Admin Chat] Steven(%d): Player %s has been permantly banned by %s for %s.", GetPlayerID("Steven"), GetName(targetid), GetName(playerid), reason);
	SendClientMessageToAll(-1, string);

	DisconnectUser(playerid, DISCONNECT_TYPE_BAN);
	return true;
}

TemporaryBan(playerid, targetid, reason[], days)
{
	new string[289];
	mysql_format(handle, string, sizeof(string), "INSERT INTO Bans (Name, IP, GPCI, Reason, Admin, Date, BanDays) VALUES ('%e', '%s', '%s', '%s', '%s', UNIX_DATE())", GetName(targetid), GetIP(targetid), GetGPCI(targetid), GetName(playerid), reason, days);
	mysql_query(handle, string);

	format(string, sizeof(string), "[Admin Chat] Steven(%d): Player %s has been temporary banned by %s for %d with a given reason %s.", GetPlayerID("Steven"), GetName(targetid), GetName(playerid), days, reason);
	SendClientMessageToAll(-1, string);

	DisconnectUser(playerid, DISCONNECT_TYPE_BAN);
	return true;
}

KickPlayer(playerid, targetid, reason[])
{
	new string[289];
	mysql_format(handle, string, sizeof(string), "INSERT INTO Kicks (Name, IP, GPCI, Reason, Admin, KickDate) VALUES ('%e', '%s', '%s', '%s', '%s', UNIX_DATE())", GetName(targetid), GetIP(targetid), GetGPCI(targetid), GetName(playerid), reason);
	mysql_query(handle, string);

	format(string, sizeof(string), "[Admin Chat] Steven(%d): Player %s has been kicked by %s for %s.", GetPlayerID("Steven"), GetName(targetid), GetName(playerid), reason);
	SendClientMessageToAll(-1, string);

	DisconnectUser(playerid, DISCONNECT_TYPE_KICK);
	return true;
}

ReconnectPlayer(playerid, targetid, reason[])
{
	new string[162];
	format(string, sizeof(string), "[Admin Chat] Steven(%d): Player %s has been reconnected by %s for %s.", GetPlayerID("Steven"), GetName(targetid), GetName(playerid), reason);
	SendClientMessageToAll(-1, string);

	DisconnectUser(playerid, DISCONNECT_TYPE_TIMEOUT);
	return 1;
}

forward DisconnectPlayer(playerid, type);
public DisconnectPlayer(playerid, type)
{
	switch(type)
	{
		case DISCONNECT_TYPE_TIMEOUT:
		{
			new string[23];
			format(string, sizeof(string), "banip %s", GetIP(playerid));
			SendRconCommand(string);
			SetPVarInt(playerid, "Disconnect", 1);
		}
		case DISCONNECT_TYPE_BAN:
		{
			Ban(playerid);
		}
		case DISCONNECT_TYPE_KICK:
		{
			Kick(playerid);
		}
	}
	return 1;
}

UnbanPlayer(admin[], player[])
{
	mysql_format(handle, string, sizeof(string), "UPDATE Bans SET Actif=0 WHERE Name='%e'", player);
	mysql_query(handle, string);

	new string[162];
	format(string, sizeof(string), "[Admin Chat] Steven(%d): Player %s has been unbanned by %s for %s.", GetPlayerID("Steven"), player, admin, reason);
	SendClientMessageToAll(-1, string);
	return 1;
}