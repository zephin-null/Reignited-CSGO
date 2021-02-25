#include "Includes.h"
#include "pch.h"

int main()
{
    std::thread bunnyhop(bhop); //This like starts a thread for the bhop function
    bunnyhop.detach(); //Detaches the bhop function
}

// Hello


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);  //This line calls the main function to be executed
    }
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;


}
