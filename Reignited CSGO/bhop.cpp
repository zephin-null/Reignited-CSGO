#include "Includes.h"
#include "Offsets.h"

//Definitions (Define things suck as local player, etc. You should use unitptr_t for it, but i use DWORD as an example for csgo
DWORD dwClient = (DWORD)GetModuleHandle(L"client.dll");  //Gets the game module
DWORD localPlayer = *(DWORD*)(dwClient + dwLocalPlayer);  //Gets the localPlayer, which is yourself
DWORD forceJump = *(DWORD*)(dwClient + dwForceJump);  //Function for force jump ( I added it so you can experiment and change the way that the jump is executed)
DWORD flags = *(DWORD*)(localPlayer + fFlags);  // This is the flags, which check if you hit the ground or not
DWORD health = *(DWORD*)(localPlayer + iHealth);  //Checks for local player health

void bhop()  //Creates your bhop function
{
    while (!GetAsyncKeyState(VK_INSERT))  //This key exits the bhop hack
    {
        if (GetAsyncKeyState(VK_SPACE))  //This key checks if you are holding space bar to activate it
        {

            if (localPlayer != NULL)
            {
                flags = *(DWORD*)(localPlayer + fFlags);     //This defines flags again
                health = *(DWORD*)(localPlayer + iHealth);   //This redefines health again

                if (flags == 257 && health > 0)   //This checks if your on the ground and if your alive (hp > 0)
                {
                    *(DWORD*)(dwClient + dwForceJump) = 6;  //This makes your player jump
                }
            }
        }
    }
}