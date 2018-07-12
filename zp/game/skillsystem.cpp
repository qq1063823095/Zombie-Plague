/**
 * ============================================================================
 *
 *  Zombie Plague Mod #3 Generation
 *
 *  File:          skillsystem.cpp
 *  Type:          Game 
 *  Description:   Provides functions for zombie skills system.
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
 * Creates commands for skills module. Called when commands are created.
 **/
void SkillsOnCommandsCreate(/*void*/)
{
    // Hook commands
    AddCommandListener(SkillsHook, "drop");
}

/**
 * Client has been infected.
 * 
 * @param clientIndex       The client index.
 * @param nemesisMode       (Optional) Indicates that client will be a nemesis.
 **/
void SkillsOnClientInfected(int clientIndex, bool nemesisMode = false)
{
    // If health restoring disabled, then stop
    if(!gCvarList[CVAR_ZOMBIE_RESTORE].BoolValue || nemesisMode)
    {
        return;
    }

    // Sets timer for restoring health
    delete gClientData[clientIndex][Client_ZombieHealTimer];
    gClientData[clientIndex][Client_ZombieHealTimer] = CreateTimer(ZombieGetRegenInterval(gClientData[clientIndex][Client_ZombieClass]), SkillsOnHealthRegen, GetClientUserId(clientIndex), TIMER_REPEAT | TIMER_FLAG_NO_MAPCHANGE);
}

/**
 * Timer for restore a player health.
 *
 * @param hTimer            The timer handle.
 * @param userID            The user id.
 **/
public Action SkillsOnHealthRegen(Handle hTimer, int userID)
{
    // Gets the client index from the user ID
    int clientIndex = GetClientOfUserId(userID);

    // Validate client
    if(clientIndex)
    {
        // Gets zombie's class regen interval/amount
        int iRegen = ZombieGetRegenHealth(gClientData[clientIndex][Client_ZombieClass]);
        float flInterval = ZombieGetRegenInterval(gClientData[clientIndex][Client_ZombieClass]);

        // Validate them
        if(iRegen || flInterval)
        {
            // Initialize float
            static float vVelocity[3];
            
            // Gets the client's velocity
            ToolsGetClientVelocity(clientIndex, vVelocity);
            
            // If the zombie don't move, then check health
            if(!(SquareRoot(Pow(vVelocity[0], 2.0) + Pow(vVelocity[1], 2.0))))
            {
                // If restoring is available, then do it
                int iHealth = GetClientHealth(clientIndex); // Store for next usage
                if(iHealth < ZombieGetHealth(gClientData[clientIndex][Client_ZombieClass]))
                {
                    // Initialize a new health amount
                    int healthAmount = iHealth + ZombieGetRegenHealth(gClientData[clientIndex][Client_ZombieClass]);
                    
                    // If new health more, than set default class health
                    if(healthAmount > ZombieGetHealth(gClientData[clientIndex][Client_ZombieClass]))
                    {
                        healthAmount = ZombieGetHealth(gClientData[clientIndex][Client_ZombieClass]);
                    }
                    
                    // Update health
                    ToolsSetClientHealth(clientIndex, healthAmount);

                    // Forward event to modules
                    SoundsOnClientRegen(clientIndex);
                    VEffectsOnClientRegen(clientIndex);
                }
            }

            // Allow counter
            return Plugin_Continue;
        }
    }

    // Clear timer
    gClientData[clientIndex][Client_ZombieHealTimer] = INVALID_HANDLE;
    
    // Destroy timer
    return Plugin_Stop;
}

/**
 * Hook client command.
 *
 * @param clientIndex       The client index.
 * @param commandMsg        Command name, lower case. To get name as typed, use GetCmdArg() and specify argument 0.
 * @param iArguments        Argument count.
 **/
public Action SkillsHook(int clientIndex, const char[] commandMsg, int iArguments)
{
    // If the client isn't zombie/survivor, than allow drop
    return (gClientData[clientIndex][Client_Zombie] && !gClientData[clientIndex][Client_Nemesis]) ? SkillsOnStart(clientIndex) : (gClientData[clientIndex][Client_Survivor] ? Plugin_Handled : Plugin_Continue);
}

/**
 * Called when player press drop button.
 *
 * @param clientIndex       The client index.
 **/
Action SkillsOnStart(int clientIndex)
{
    // If zombie class don't have a skill, then stop
    if(!ZombieGetSkillDuration(gClientData[clientIndex][Client_ZombieClass]) && !ZombieGetSkillCountDown(gClientData[clientIndex][Client_ZombieClass]))
    {
        return Plugin_Handled;
    }
    
    // Verify that the skills are avalible
    if(!gClientData[clientIndex][Client_Skill] && !gClientData[clientIndex][Client_SkillCountDown])
    {
        // Call forward
        Action resultHandle = API_OnClientSkillUsed(clientIndex);
        
        // Block skill usage
        if(resultHandle == Plugin_Handled || resultHandle == Plugin_Stop)
        {
            return Plugin_Handled;
        }

        // Sets skill usage
        gClientData[clientIndex][Client_Skill] = true;
        
        // Sets timer for removing skill usage
        delete gClientData[clientIndex][Client_ZombieSkillTimer];
        gClientData[clientIndex][Client_ZombieSkillTimer] = CreateTimer(ZombieGetSkillDuration(gClientData[clientIndex][Client_ZombieClass]), SkillsOnEnd, GetClientUserId(clientIndex), TIMER_FLAG_NO_MAPCHANGE);
    }
    
    // Allow skill
    return Plugin_Handled;
}

/**
 * Timer for remove a skill usage.
 *
 * @param hTimer            The timer handle.
 * @param userID            The user id.
 **/
public Action SkillsOnEnd(Handle hTimer, int userID)
{
    // Gets the client index from the user ID
    int clientIndex = GetClientOfUserId(userID);

    // Clear timer
    gClientData[clientIndex][Client_ZombieSkillTimer] = INVALID_HANDLE;
    
    // Validate client
    if(clientIndex)
    {
        // Remove skill usage and set countdown time
        gClientData[clientIndex][Client_Skill] = false;
        gClientData[clientIndex][Client_SkillCountDown] = ZombieGetSkillCountDown(gClientData[clientIndex][Client_ZombieClass]);
        
        // Sets timer for countdown
        delete gClientData[clientIndex][Client_ZombieCountDownTimer];
        gClientData[clientIndex][Client_ZombieCountDownTimer] = CreateTimer(1.0, SkillsOnCountDown, GetClientUserId(clientIndex), TIMER_REPEAT | TIMER_FLAG_NO_MAPCHANGE);
        
        // Call forward
        API_OnClientSkillOver(clientIndex);
    }

    // Destroy timer
    return Plugin_Stop;
}

/**
 * Timer for the skill countdown.
 *
 * @param hTimer            The timer handle.
 * @param userID            The user id.
 **/
public Action SkillsOnCountDown(Handle hTimer, int userID)
{
    // Gets the client index from the user ID
    int clientIndex = GetClientOfUserId(userID);

    // Validate client
    if(clientIndex)
    {
        // Substitute counter
        gClientData[clientIndex][Client_SkillCountDown]--;
        
        // If counter is over, then stop
        if(!gClientData[clientIndex][Client_SkillCountDown])
        {
            // Show message
            TranslationPrintHintText(clientIndex, "Skill ready");

            // Clear timer
            gClientData[clientIndex][Client_ZombieCountDownTimer] = INVALID_HANDLE;
            
            // Destroy timer
            return Plugin_Stop;
        }

        // Show counter
        TranslationPrintHintText(clientIndex, "Countdown", RoundToCeil(gClientData[clientIndex][Client_SkillCountDown]));
        
        // Allow timer
        return Plugin_Continue;
    }
    
    // Clear timer
    gClientData[clientIndex][Client_ZombieCountDownTimer] = INVALID_HANDLE;
    
    // Destroy timer
    return Plugin_Stop;
}