/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM									*
* 	- File: Hunting games file.					   		*
*														*
*********************************************************/

forward public MoneyBag();
public MoneyBag()
{
	new string[175];
    if(!MoneyBagFound)
    {
    	new i = random(3);
    	switch(i)
    	{
    		case 0: format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}Woah, No one found the hidden moneybag you guys are lazy as fuck, it was just at %s :facepalm:", MoneyBagLocation);
    		case 1: format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}Yay, i just found a moneybag at %s, call me pro baby", MoneyBagLocation);
    		case 2: format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}YOU NOOBS! it was at %s in a ez place, you lost it.", MoneyBagLocation);
    	}
        SendClientMessageToAll(-1, string);
        MoneyBagFound = true;
        MoneyBag();
    }
    else if(MoneyBagFound)
    {
        MoneyBagFound = false;

        new brk = 0;
		while(!brk) {
			MoneyBagPos[0] = random(MAX_COORD_MB - MIN_COORD_MB) + MIN_COORD_MB;
			MoneyBagPos[1] = random(MAX_COORD_MB - MIN_COORD_MB) + MIN_COORD_MB;
			MapAndreas_FindZ_For2DCoord(MoneyBagPos[0], MoneyBagPos[1], MoneyBagPos[2]);
			if(MoneyBagPos[2] >= 5.0) {
				brk = 1;
				break;
			}
		}

		format(MoneyBagLocation, sizeof(MoneyBagLocation), "%s", GetPositionLocation(MoneyBagPos[0], MoneyBagPos[1]));

        new i = random(3);
    	switch(i)
    	{
    		case 0: format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}OKAY MY DOG STOLE MY BAG AGAIN, the first one who will found it i will give me a prize, it was somehow at %s", MoneyBagLocation);
    		case 1: format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}WELL FUCK, i just lost my bag again last time i saw it it was at %s, come on search for it", MoneyBagLocation);
    		case 2: format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}WHERE THE HELL MY BAG!! IT WAS AT %s PLEASE SEARCH FOR IT!!!!", MoneyBagLocation);
    	}
        format(string, sizeof(string), "{F81414}Steven(0): {FFFFFF}OKAY MY DOG STOLE MY BAG AGAIN, the first one who will found it i will give me a prize, it was somehow at %s", MoneyBagLocation);
    	SendClientMessageToAll(-1, string);
    	DestroyPickup(MoneyBagPickup);
        MoneyBagPickup = CreatePickup(1550, 2, MoneyBagPos[0], MoneyBagPos[1], MoneyBagPos[2], -1);
    }
}

forward public GiftsHunt();
public GiftsHunt()
{

}

forward public CookiesHunt();
public CookiesHunt()
{

}

forward public HuntGamesTimer();
public HuntGamesTimer()
{
	MoneyBag();
	GiftsHunt();
	CookiesHunt();
	return 1;
}