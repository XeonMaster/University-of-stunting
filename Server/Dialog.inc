/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Dialogs file.					   			*
*														*
*********************************************************/

#define DIALOG_LOGIN 	0
#define DIALOG_REGISTER 1
#define DIALOG_EMAIL	2

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case DIALOG_LOGIN:
		{
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
					DisconnectPlayer(playerid, DISCONNECT_TYPE_KICK);
				}	
			}
		}
		case DIALOG_REGISTER:
		{
			
		}
		case DIALOG_EMAIL:
		{
			
		}
	}
}