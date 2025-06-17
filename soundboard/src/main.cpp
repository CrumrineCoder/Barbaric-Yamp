#include <Windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <iostream>

#pragma comment(lib, "Winmm.lib")

int main()
{
	std::cout << "Playing music \n";
	PlaySound(TEXT("dayo.wav"), NULL, SND_FILENAME | SND_SYNC);
	std::cout << "Music finished playing \n";
}