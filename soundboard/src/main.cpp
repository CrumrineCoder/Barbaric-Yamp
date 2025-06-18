#include <Windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

#pragma comment(lib, "Winmm.lib")

int main()
{
    std::filesystem::path current_dir = std::filesystem::current_path();

    std::cout << "Current directory: " << current_dir << std::endl;

    std::string subfolder_name = "WAV";

    std::filesystem::path new_dir = current_dir / subfolder_name;

    try {
        std::filesystem::current_path(new_dir);
        std::cout << "Changed to directory: " << std::filesystem::current_path() << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error changing directory: " << e.what() << std::endl;
    }

    std::vector<std::filesystem::path> audioFiles;

    for (const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {
        if (entry.is_regular_file()) {
            auto ext = entry.path().extension().string();
            if (ext == ".wav") {
                audioFiles.push_back(entry.path());
            }
        }
    }

    for (const auto& file : audioFiles) {
        std::cout << "Playing: " << file << std::endl;
        if (!std::filesystem::exists(file)) {
            std::cerr << "File does not exist: " << file << std::endl;
            continue;
        }
        if (!PlaySoundA(file.string().c_str(), NULL, SND_FILENAME | SND_SYNC)) {
            std::cerr << "Failed to play: " << file << std::endl;
        }
    }

    std::cout << "All music finished playing\n";
    return 0;
}