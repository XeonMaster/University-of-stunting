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
	CallLocalFunction("AccountSettingUp", "iiiis", playerid, dialogid, response, listitem, inputtext);
	return 1;

}