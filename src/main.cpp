#include <iostream>
#include <cstring>
#include <SFML/Audio.hpp>
#include <sndfile.h>

int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments is provided.
    // If not, print usage information and exit the program.
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_audio_file>" << std::endl;
        return 1;
    }

    const char *inputFileName = argv[1];

    // Open the audio file
    // Supports WAV, OGG/Vorbis and FLAC
    SF_INFO fileInfo;
    SNDFILE *inputFile = sf_open(inputFileName, SFM_READ, &fileInfo);

    // Check if the input audio file is successfully opened.
    // If not, print an error message to standard error and exit the program.
    if (!inputFile)
    {
        std::cerr << "Error opening input audio file." << std::endl;
        return 1;
    }

    // Read audio data into a buffer
    const int bufferSize = fileInfo.frames * fileInfo.channels;
    float *buffer = new float[bufferSize];
    sf_readf_float(inputFile, buffer, fileInfo.frames);

    // Convert the float buffer to sf::Int16
    sf::Int16 *intBuffer = new sf::Int16[bufferSize];
    for (int i = 0; i < bufferSize; ++i)
    {
        intBuffer[i] = static_cast<sf::Int16>(buffer[i] * 32767); // Scale to the range of Int16
    }

    // Initialize SFML audio
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    // Set the audio data for the SoundBuffer
    soundBuffer.loadFromSamples(intBuffer, bufferSize, fileInfo.channels, fileInfo.samplerate);

    // Set the buffer for the Sound
    sound.setBuffer(soundBuffer);

    // Play the sound
    sound.play();

    const int barWidth = 50; // Progress bar width in characters

    // Wait for the sound to finish
    while (sound.getStatus() == sf::Sound::Playing)
    {
        // Calculate progress
        float progress = sound.getPlayingOffset().asSeconds() / soundBuffer.getDuration().asSeconds();

        // Print a simple progress bar
        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                std::cout << "=";
            else if (i == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << "%\r";
        std::cout.flush();

        sf::sleep(sf::milliseconds(10));
    }

    // Print a full progress bar
    std::cout << "[";
    for (int i = 0; i < barWidth; ++i)
    {
        std::cout << "=";
    }
    std::cout << "] " << int(100.0) << "%\r";

    // Clear the console after the progress bar
    std::cout << std::endl;

    // Clean up
    delete[] buffer;
    delete[] intBuffer;
    sf_close(inputFile);

    return 0;
}