/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Spawn file.						   			*
*														*
*********************************************************/

public OnPlayerSpawn(playerid)
{
	if(IsPlayerNPC(playerid))
	{
		new veh = CreateVehicle(412, 0.0, 0.0, 0.0, 0.0, -1, -1, -1, 0);
		PutPlayerInVehicle(playerid, veh, 0);
		return 1;
	}
	return true;
}