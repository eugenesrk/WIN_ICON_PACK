#undef UNICODE
#define UNICODE

#include <windows.h>
#include <stdio.h>


__declspec(dllexport) __attribute__((dllexport))
int __cdecl summarize(int a, int b) {
    return a + b;
}

__declspec( dllexport ) __attribute__((dllexport))
void sayHello(HWND inhw, HINSTANCE inin, wchar_t const *inwc, int inint) {
    wchar_t message[255];
    wsnprintf(message, sizeof(message), L"Hello: %s", inwc);
    MessageBox(
            inhw,
            message,
            L"Hello From Iconpack dll!",
            MB_ICONINFORMATION | MB_OK | MB_SETFOREGROUND
    );

}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        // Code to run when the DLL is loaded
        // printf ("Load working...\n");
        break;

        case DLL_PROCESS_DETACH:
        // Code to run when the DLL is freed
        // printf ("Unload working...\n");
        break;

        case DLL_THREAD_ATTACH:
        // Code to run when a thread is created during the DLL's lifetime
        // printf ("ThreadLoad working...\n");
        break;

        case DLL_THREAD_DETACH:
        // Code to run when a thread ends normally.
        // printf ("ThreadUnload working...\n");
        break;
    }

    return TRUE;
}
