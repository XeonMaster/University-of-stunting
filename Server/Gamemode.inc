/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Gamemode Init & Exit main file. 			*
*														*
*********************************************************/

public OnGameModeInit()
{
	print("*------------------------------------------*");
	print("*	 	University of Stunting 2018       *");
	print("* Build: 1	Version 1.0		Server: 0.3.7 *");
	print("*   		Main Developer: XeonTM			  *");
	print("*------------------------------------------*");
	print("* Status: Loading main gamemode...		  *");
	print("*------------------------------------------*");
	print("* UPDATE SRV01: VPS CPU is now stable 100% *");
	print("* UPDATE SRV01: Loading mysql connection.. *");
	print("*------------------------------------------*");
	print("* UOS MYSQL CONNECTION MANAGER LOADING...  *");
	print("*------------------------------------------*");
	print("-");
	print("-");
	print("*------------------------------------------------*");
	print("* MYSQL CONNECTION ETABLISHING..                 *");
	print("*------------------------------------------------*");
	print("* MYSQLHANDLE0: CONNECTION GETTING CONFIGURATION.*");
	printf("* MYSQLHANDLE0: COFING ITEM 1 MYSQL SERVER: %s 	*", MYSQL_HOST);
	printf("* MYSQLHANDLE0: COFING ITEM 2 MYSQL USER: %s 	*", MYSQL_USER);
	printf("* MYSQLHANDLE0: COFING ITEM 3 MYSQL DB: %s 	*", MYSQL_DATABASE);
	print("* MYSQLHANDLE0: COFING ITEM 3 MYSQL PASS: (consored)*");
	print("* MYSQLHANDLE0: ITEMS LOADED, CONNECTING.... *");
	handle = mysql_connect(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);
	if(handle == MYSQL_INVALID_HANDLE || mysql_errno(handle) != 0)
	{
		print("* MYSQLHANDLE0: MYSQL CONNECTION FAILED....      *");
		print("* MYSQLHANDLE0: CLOSING MYSQL CLIENT ADAPTER.... *");
		print("* UPDATE SERV01: CLOSING THE SERVER DUE TO UNEXCEPTED ERROR. *");
		print("* ERROR: CHECK YOUR MYSQL SETTINGS PLEASE. *");
		SendRconCommand("exit");
	}
	print("* MYSQLHANDLE0: CONNECTED. MOVING ON *");
	print("*------------------------------------------------------------------*");
	print("* DEBUG SECTION FINISHED. LODING THE REST OF GAMEMODE WITHOUT LOGS.*");
	print("*------------------------------------------------------------------*");

	// Setting up timers.
	SetUpTimers();
	return 1;
}

public OnGameModeExit()
{
	return 1;
}