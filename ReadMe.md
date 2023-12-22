# Audio Player

## Overview

This C++ program serves as a basic audio player that supports WAV, OGG/Vorbis, and FLAC file formats. It utilizes the SFML library for audio handling and provides a minimalistic command-line interface with a progress bar for audio playback.

## Requirements

- C++ compiler supporting C++11 standards
- SFML library
- libsndfile library

## Usage

### Compilation

Compile the program using the following command:

```bash
g++ -std=c++11 -Wall -Wextra src/main.cpp -o bin/audio_player -lsndfile -lsfml-audio -lsfml-system
```

### Execution

Run the program with the desired input audio file:

```bash
./audio_player <input_audio_file>
```

Replace `<input_audio_file>` with the path to the audio file you want to play.

## Features

- Supports multiple audio file formats (WAV, OGG/Vorbis, FLAC).
- Prints a progress bar indicating the playback status.
- Allows pausing and resuming of audio playback (press Space key).

## Example

```bash
./audio_player audio_file.ogg
```

## License

This project is licensed under the [MIT License](LICENSE).

## Author

Matthew Deik

## Acknowledgments

- SFML Library: https://www.sfml-dev.org/
- libsndfile Library: http://www.mega-nerd.com/libsndfile/