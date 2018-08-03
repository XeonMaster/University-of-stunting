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

	if(cache_num_rows() > 0)
	{
		cache_get_value_name(0, PlayerInfo[playerid][Password], 129);
		cache_delete(getcache);
		return true;
	}
	else
	{
		cache_delete(getcache);
		mysql_format(handle, string, sizeof(string), "SELECT * FROM players WHERE GPCI='%e' OR IP='%e' LIMIT 1", GetGPCI(playerid), GetIp(playerid));
		getcache = mysql_query(handle, string);
		if(cache_num_rows() > 0)
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
	
}

RegisterPlayer(playerid, password)
{

}