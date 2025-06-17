#include <Windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <iostream>

#pragma comment(lib, "Winmm.lib")

int main()
{
    MCIERROR err = mciSendString("open \"*.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);

    if (err != 0) {
        char errorText[256];
        mciGetErrorString(err, errorText, sizeof(errorText));
        std::cerr << "Failed to open fitness.mp3: " << errorText << std::endl;
        MessageBoxA(NULL, errorText, "MCI Open Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    mciSendString("play mp3", NULL, 0, NULL);
}