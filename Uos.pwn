/********************************************************
*														*
*			  University of Stunting 2018			    *
*		Build: 1	Version 1.0		Server: 0.3.7		*
*												   		*
*	- Developer: XeonTM, Stephen						*
* 	- File: Main file of UoS.					   		*
*														*
*********************************************************/

#include <a_samp>
#include <fixes>

// Saving System.
#include <a_mysql>

// Loops handle.
#include <foreach>

// Commands handles.
#include <zcmd>
#include <sscanf2>

// Social Medias.
#include <irc>
#include <discord-connector>

// Map Andrease plugin for 2D "Y, Z" exact position using 3D detection.
#include <MapAndreas>

// Gamemode Config.
#include "config.inc"

// Global Gamemode.
#include "Server\Server.pwn"

#include "Administration\Administration.pwn"

#if !defined adminsmain
	#error Error: administration\Administration.pwn is not fully included.
#endif

#include "Players\Player.pwn"

#if !defined playersmain
	#error Error: players\Player.pwn is not fully included.
#endif

#include "Games\Games.pwn"

#if !defined gamesmain
	#error Error: games\games.pwn is not fully included.
#endif

#include "Maps\main.pwn"

#if !defined mapsmain
	#error Error: maps\mapsmain.pwn is not fully included.
#endif

#include "Social Media\Social.pwn"

#if !defined socialmain
	#error Error: social media\social.pwn is not fully included.
#endif