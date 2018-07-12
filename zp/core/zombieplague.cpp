/**
 * ============================================================================
 *
 *  Zombie Plague Mod #3 Generation
 *
 *  File:          zombieplague.cpp
 *  Type:          Main 
 *  Description:   General plugin functions and defines.
 *
 *  Copyright (C) 2015-2018 Nikita Ushakov (Ireland, Dublin)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ============================================================================
 **/
 
/**
 * @section All engines versions.
 **/
#define ENGINE_UNKNOWN              "could not determine the engine version"    
#define ENGINE_ORIGINAL             "Original Source Engine"         
#define ENGINE_SOURCESDK2006        "Episode 1 Source Engine"         
#define ENGINE_SOURCESDK2007        "Orange Box Source Engine"        
#define ENGINE_LEFT4DEAD            "Left 4 Dead"   
#define ENGINE_DARKMESSIAH          "Dark Messiah Multiplayer"
#define ENGINE_LEFT4DEAD2           "Left 4 Dead 2"
#define ENGINE_ALIENSWARM           "Alien Swarm"
#define ENGINE_BLOODYGOODTIME       "Bloody Good Time"
#define ENGINE_EYE                  "E.Y.E Divine Cybermancy"
#define ENGINE_PORTAL2              "Portal 2"
#define ENGINE_CSGO                 "Counter-Strike: Global Offensive"
#define ENGINE_CSS                  "Counter-Strike: Source"
#define ENGINE_DOTA                 "Dota 2"
#define ENGINE_HL2DM                "Half-Life 2 Deathmatch"
#define ENGINE_DODS                 "Day of Defeat: Source"
#define ENGINE_TF2                  "Team Fortress 2"
#define ENGINE_NUCLEARDAWN          "Nuclear Dawn"
#define ENGINE_SDK2013              "Source SDK 2013"
#define ENGINE_BLADE                "Blade Symphony"
#define ENGINE_INSURGENCY           "Insurgency"
#define ENGINE_CONTAGION            "Contagion"
/**
 * @endsection
 **/
 
/*
 * Engine functions
 */
 
/**
 * Called once when server is started. Will log a warning if a unsupported game is detected.
 **/
void GameEngineInit(/*void*/)
{
    // Gets engine of the game
    switch(GetEngineVersion(/*void*/))
    {
        case Engine_Unknown :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague %s", ENGINE_UNKNOWN);
        }
        case Engine_Original :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_ORIGINAL);
        }
        case Engine_SourceSDK2006 :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_SOURCESDK2006);
        }
        case Engine_SourceSDK2007 :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_SOURCESDK2007);
        }
        case Engine_Left4Dead :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_LEFT4DEAD);
        }
        case Engine_DarkMessiah :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_DARKMESSIAH);
        }
        case Engine_Left4Dead2 :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_LEFT4DEAD2);
        }
        case Engine_AlienSwarm :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_ALIENSWARM);
        }
        case Engine_BloodyGoodTime :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_BLOODYGOODTIME);
        }
        case Engine_EYE :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_EYE);
        }
        case Engine_Portal2 :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_PORTAL2);
        }
        case Engine_CSGO :    
        {
            LogEvent(true, LogType_Normal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Engine catched: \"%s\"", ENGINE_CSGO);
        }
        case Engine_CSS :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_CSS);
        }
        case Engine_DOTA :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_DOTA);
        }
        case Engine_HL2DM :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_HL2DM);
        }
        case Engine_DODS :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_DODS);
        }
        case Engine_TF2 :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_TF2);
        }
        case Engine_NuclearDawn :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_NUCLEARDAWN);
        }
        case Engine_SDK2013 :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_SDK2013);
        }
        case Engine_Blade :    
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_BLADE);
        }
        case Engine_Insurgency :
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_INSURGENCY);
        }
        case Engine_Contagion :
        {
            LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Zombie Plague doesn't support: \"%s\"", ENGINE_CONTAGION);
        }
    }

    // Unload the gamedata config
    delete gServerData[Server_GameConfig];
}

/*
 * Player functions
 */

/**
 * Returns true if the player is connected and alive, false if not.
 *
 * @param clientIndex       The client index.
 * @param clientAlive       (Optional) Set to true to validate that the client is alive, false to ignore.
 *
 * @return                  True or false.
 **/
stock bool IsPlayerExist(int clientIndex, bool clientAlive = true)
{
    // If client isn't valid
    if(clientIndex <= 0 || clientIndex > MaxClients)
    {
        return false;
    }

    // If client isn't connected
    if(!IsClientConnected(clientIndex))
    {
        return false;
    }

    // If client isn't in game
    if(!IsClientInGame(clientIndex) || IsClientInKickQueue(clientIndex)) //! Improved, thanks to fl0wer!
    {
        return false;
    }

    // If client is TV
    if(IsClientSourceTV(clientIndex))
    {
        return false;
    } 

    // If client isn't alive
    if(clientAlive && !IsPlayerAlive(clientIndex))
    {
        return false;
    }

    // If client exist
    return true;
}

/**
 * Returns whether a player has exact of the specified admin flag or not.
 *
 * @param clientIndex       The client index.
 *
 * @return                  True or false.
 **/
stock bool IsPlayerHasFlag(int clientIndex, AdminFlag iFlag = Admin_Generic)
{
    // Validate client
    if(!IsPlayerExist(clientIndex, false))
    {
        return false;
    }

    /*********************************
     *                               *
     *  FLAG SIMPLE AUTHENTICATION   *
     *                               *
     *********************************/

    // Retrieves a client's AdminId
    AdminId iD = GetUserAdmin(clientIndex);

    // Validate id
    if(iD == INVALID_ADMIN_ID)
    {
        return false;
    }
    
    // Return true on the success
    return GetAdminFlag(iD, iFlag);
}

/**
 * Returns whether a player has all of the specified admin flags or not.
 *
 * @param clientIndex       The client index.
 * @param sFlags            The string with flags to validate.
 *
 * @return                  True or false.
 **/
stock bool IsPlayerHasFlags(int clientIndex, const char[] sFlags)
{
    // Validate normal user
    if(!strlen(sFlags))
    {
        return true;
    }
    
    // Validate client
    if(!IsPlayerExist(clientIndex, false))
    {
        return false;
    }

    /*********************************
     *                               *
     *   FLAG BASED AUTHENTICATION   *
     *                               *
     *********************************/
    
    #define ADMFLAG_BYTE    (1 << view_as<int>(i))
    
    // Retrieves a client's AdminId
    AdminId iD = GetUserAdmin(clientIndex);

    // Validate id
    if(iD == INVALID_ADMIN_ID)
    {
        return false;
    }
    
    // Gets number of flags
    int iCount, iFound, iFlag = ReadFlagString(sFlags);

    // Loop through access levels (flags) for admins
    for(AdminFlag i = Admin_Reservation; i <= Admin_Custom6; i++)
    {
        // Validate bitwise values definitions for admin flags
        if(iFlag & ADMFLAG_BYTE)
        {
            iCount++;

            // Validate flag
            if(GetAdminFlag(iD, i))
            {
                iFound++;
            }
        }
    }

    // Return true on the success
    return (iCount == iFound);
}  

/**
 * Returns whether a player is in a spesific group or not.
 *
 * @param clientIndex       The client index.
 * @param sGroup            The SourceMod group name to check.
 *
 * @return                  True or false.
 **/
stock bool IsPlayerInGroup(int clientIndex, const char[] sGroup)
{
    // Validate client
    if(!IsPlayerExist(clientIndex, false))
    {
        return false;
    }

    /*********************************
     *                               *
     *   FLAG GROUP AUTHENTICATION   *
     *                               *
     *********************************/
    
    // Retrieves a client's AdminId
    AdminId iD = GetUserAdmin(clientIndex);
    
    // Validate id
    if(iD == INVALID_ADMIN_ID)
    {
        return false;
    }
    
    // Gets number of groups
    int nGroup = GetAdminGroupCount(iD);
    static char sGroupName[NORMAL_LINE_LENGTH];
    
    // Validate number of groups
    if(nGroup)
    {
        // Loop through each group
        for(int i = 0; i < nGroup; i++)
        {
            // Gets group name
            GetAdminGroup(iD, i, sGroupName, sizeof(sGroupName));
            
            // Compare names
            if(!strcmp(sGroup, sGroupName, false))
            {
                return true;
            }
        }
    }
    
    // No groups or no match
    return false;
}

/*
 * Server functions
 */
 
/**
 * Gets amount of total humans.
 * 
 * @return      The amount of total humans.
 **/
stock int fnGetHumans(/*void*/)
{
    // Initialize variables
    int nHumans;
    
    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate human
        if(IsPlayerExist(i) && !gClientData[i][Client_Zombie])
        {
            // Increment amount
            nHumans++;
        }
    }
    
    // Return amount
    return nHumans;
}

/**
 * Gets amount of total zombies.
 *
 * @return      The amount of total zombies.
 **/
stock int fnGetZombies(/*void*/)
{
    // Initialize variables
    int nZombies;
    
    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate zombie
        if(IsPlayerExist(i) && gClientData[i][Client_Zombie])
        {
            // Increment amount    
            nZombies++;
        }
    }
    
    // Return amount
    return nZombies;
}

/**
 * Gets amount of total alive players.
 *
 * @return      The amount of total alive players.
 **/
stock int fnGetAlive(/*void*/)
{
    // Initialize variables
    int nAlive;

    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate client
        if(IsPlayerExist(i))
        {
            // Increment amount
            nAlive++;
        }
    }
    
    // Return amount
    return nAlive;
}

/**
 * Gets index of the random human.
 *
 * @return      The index of random human.
 **/
stock int fnGetRandomHuman(/*void*/)
{
    // Initialize variables
    int nRandom; static int clientIndex[MAXPLAYERS+1];

    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate human
        if(IsPlayerExist(i) && !gClientData[i][Client_Zombie] && !gClientData[i][Client_Survivor])
        {
            // Increment amount
            clientIndex[nRandom++] = i;
        }
    }

    // Return amount
    return (nRandom) ? clientIndex[GetRandomInt(0, nRandom-1)] : -1;
}

/**
 * Gets index of the random zombie.
 *
 * @return      The index of random zombie.
 **/
stock int fnGetRandomZombie(/*void*/)
{
    // Initialize variables
    int nRandom; static int clientIndex[MAXPLAYERS+1];

    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate zombie
        if(IsPlayerExist(i) && gClientData[i][Client_Zombie] && !gClientData[i][Client_Nemesis])
        {
            // Increment amount
            clientIndex[nRandom++] = i;
        }
    }

    // Return amount
    return (nRandom) ? clientIndex[GetRandomInt(0, nRandom-1)] : -1;
}

/**
 * Gets index of the random survivor.
 *
 * @return      The index of random survivor.
 **/
stock int fnGetRandomSurvivor(/*void*/)
{
    // Initialize variables
    int nRandom; static int clientIndex[MAXPLAYERS+1];

    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate survivor
        if(IsPlayerExist(i) && gClientData[i][Client_Survivor])
        {
            // Increment amount
            clientIndex[nRandom++] = i;
        }
    }

    // Return amount
    return (nRandom) ? clientIndex[GetRandomInt(0, nRandom-1)] : -1;
}

/**
 * Gets index of the random nemesis.
 *
 * @return      The index of random nemesis.
 **/
stock int fnGetRandomNemesis(/*void*/)
{
    // Initialize variables
    int nRandom; static int clientIndex[MAXPLAYERS+1];

    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate nemesis
        if(IsPlayerExist(i) && gClientData[i][Client_Nemesis])
        {
            // Increment amount
            clientIndex[nRandom++] = i;
        }
    }

    // Return amount
    return (nRandom) ? clientIndex[GetRandomInt(0, nRandom-1)] : -1;
}

/**
 * Gets amount of total playing players.
 *
 * @return      The amount of total playing players.
 **/
stock int fnGetPlaying(/*void*/)
{
    // Initialize variables
    int nPlaying;

    // i = client index
    for(int i = 1; i <= MaxClients; i++)
    {
        // Validate client
        if(IsPlayerExist(i, false))
        {
            // Increment amount
            nPlaying++;
        }
    }
    
    // Return amount
    return nPlaying;
}


/**
 * Precache file and add it to the download table.
 *
 * @param sPath             The path to file.
 * @return                  True or false.
 **/
stock bool fnMultiFilePrecache(const char[] sPath)
{
    // Finds the first occurrence of a character in a string
    int iDelimiter = FindCharInString(sPath, '@', true); //! Fix for particles
    
    // If file doesn't exist, then log, and stop
    if(!FileExists(sPath) && iDelimiter == -1) 
    {
        LogEvent(false, LogType_Error, LOG_CORE_EVENTS, LogModule_Engine, "Config Validation", "Missing file: %s", sPath);
        return false;
    }
    
    // Finds the first occurrence of a character in a string
    int iFormat = FindCharInString(sPath, '.', true);
    
    // If model's path is don't have format, then log, and stop
    if(iFormat == -1)
    {
        LogEvent(false, LogType_Error, LOG_CORE_EVENTS, LogModule_Engine, "Config Validation", "Missing file format: %s", sPath);
        return false;
    }
    
    // Add to precache if path contains '.mdl'
    if(!strcmp(sPath[iFormat], ".mdl", false))
    {
        // If model doesn't precache yet, then continue
        if(!IsModelPrecached(sPath))
        {
            // Add file to download table
            AddFileToDownloadsTable(sPath);
            
            // Precache file
            PrecacheModel(sPath, true);
        }
    }
    // Add to precache if path contains '.mp3' or '.wav'
    else if(!strcmp(sPath[iFormat], ".mp3", false) || !strcmp(sPath[iFormat], ".wav", false))
    {
        // Copy one string onto another
        static char sSound[PLATFORM_MAX_PATH];
        strcopy(sSound, sizeof(sSound), sPath);

        /// Look here: https://wiki.alliedmods.net/Csgo_quirks#Fake_precaching_and_EmitSound
        if(ReplaceStringEx(sSound, sizeof(sSound), "sound", "*", 5, 1, true) != -1)
        {
            // If sound doesn't precache yet, then continue
            if(fnGetTableItemIndex("soundprecache", sSound) == INVALID_STRING_INDEX)
            {
                // Add file to download table
                AddFileToDownloadsTable(sPath);

                // Precache sound
                ///bool bSave = LockStringTables(false);
                AddToStringTable(fnGetTableIndex("soundprecache"), sSound);
                ///LockStringTables(bSave);
            }
        }
        else
        {
            LogEvent(false, LogType_Error, LOG_CORE_EVENTS, LogModule_Engine, "Config Validation", "Wrong sound path: %s", sPath);
            return false;
        }
    }
    // Add to precache if path contains '.pcf'
    else if(!strncmp(sPath[iFormat], ".pcf", 4, false))
    {
        // Cut out name at the end of a line
        static char sParticle[NORMAL_LINE_LENGTH];
        if(SplitString(sPath, "@", sParticle, sizeof(sParticle)) != -1)
        {
            // Add file to download table
            AddFileToDownloadsTable(sParticle);
            
            // Precache generic
            PrecacheGeneric(sParticle, true); //! Precache only here

            // If particle doesn't precache yet, then continue
            ///if(fnGetTableItemIndex("ParticleEffectNames", sPath[iDelimiter+1]) == INVALID_STRING_INDEX) => NOT WORK!!! WTF???

            // Precache particle
            bool bSave = LockStringTables(false);
            AddToStringTable(fnGetTableIndex("ParticleEffectNames"), sPath[iDelimiter+1]);
            LockStringTables(bSave);
        }
        else
        {
            LogEvent(false, LogType_Error, LOG_CORE_EVENTS, LogModule_Engine, "Config Validation", "Wrong particle path: %s", sPath);
            return false;
        }
    }
    // Add to precache if path contains '.vtf'
    else if(!strcmp(sPath[iFormat], ".vtf", false))
    {
        // If decal doesn't precache yet, then continue
        if(!IsDecalPrecached(sPath))
        {
            // Add file to download table
            AddFileToDownloadsTable(sPath);
            
            // Precache file
            PrecacheDecal(sPath, true);
        }
    }
    else
    {
        // Add file to download table
        AddFileToDownloadsTable(sPath);
    }
    
    // Return on success
    return true;
}

/**
 * Searches for a string table.
 *
 * @param sTable            The table name.
 * @return                  The table index.
 **/
stock int fnGetTableIndex(const char[] sTable)
{
    // Searches for a string table
    int tableIndex = FindStringTable(sTable);

    // Validate table
    if(tableIndex == INVALID_STRING_TABLE)
    {
        ///LogEvent(false, LogType_Error, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Table not found: %s", sTable);
        return INVALID_STRING_TABLE;
    }

    // Return index on the success
    return tableIndex;
}

/**
 * Searches for the index of a given string in a string table.
 *
 * @param sTable            The table.
 * @param sIndex            The index.
 * @return                  The item index.
 **/
stock int fnGetTableItemIndex(const char[] sTable, const char[] sIndex)
{
    // Searches for the index of a given string in a string table
    int itemIndex = FindStringIndex(fnGetTableIndex(sTable), sIndex);

    // Validate item
    if(itemIndex == INVALID_STRING_INDEX)
    {
        ///LogEvent(false, LogType_Error, LOG_CORE_EVENTS, LogModule_Engine, "Engine Validation", "Item not found: %s", sIndex);
        return INVALID_STRING_INDEX;
    }

    // Return index on the success
    return itemIndex;
}

/**
 * Returns an offset value from a given config.
 *
 * @param gameConf          The game config handle.
 * @param iOffset           An offset, or -1 on failure. (Destanation)
 * @param sKey              Key to retrieve from the offset section.
 **/
stock void fnInitGameConfOffset(Handle gameConf, int &iOffset, const char[] sKey)
{
    // Validate offset
    if((iOffset = GameConfGetOffset(gameConf, sKey)) == -1)
    {
        LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "GameData Validation", "Failed to get offset: \"%s\"", sKey);
    }
}

/**
 * Given a server classname, finds a networkable send property offset.
 *
 * @param iOffset           An offset, or -1 on failure. (Destanation) 
 * @param sServerClass      The classname.
 * @param sProp             The property name.
 **/
stock void fnInitSendPropOffset(int &iOffset, const char[] sServerClass, const char[] sProp)
{
    // Validate prop
    if((iOffset = FindSendPropInfo(sServerClass, sProp)) < 1)
    {
        LogEvent(false, LogType_Fatal, LOG_CORE_EVENTS, LogModule_Engine, "GameData Validation", "Failed to find prop: \"%s\"", sProp);
    }
}