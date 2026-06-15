# Sorting Visualizer

A C++ sorting algorithm visualizer built with SFML. The app renders an array as vertical bars and animates how different sorting algorithms rearrange the data.

## Features

- Real-time bar chart visualization
- Keyboard controls for switching algorithms
- Implemented algorithms:
  - Selection Sort
  - Bubble Sort
  - Insertion Sort
  - Merge Sort

## Demo Controls

Run the app, then press one of the number keys:

| Key | Algorithm |
| --- | --- |
| `1` | Selection Sort |
| `2` | Bubble Sort |
| `3` | Insertion Sort |
| `4` | Merge Sort |

Close the SFML window to exit.

## Requirements

- C++17 compiler
- CMake 3.16 or newer
- SFML 3 with the Graphics component installed

On macOS with Homebrew, SFML can be installed with:

```bash
brew install sfml
```

## Build And Run

From the repository root:

```bash
cmake -S . -B build
cmake --build build
./build/sorting_algo
```

## Project Structure

```text
.
├── assets/              # Fonts and other runtime assets
├── include/             # Header files
│   ├── sorting/         # Sorting algorithm headers
│   └── visuals/         # Visualizer headers
├── src/                 # Application source files
│   ├── sorting/         # Sorting algorithm implementations
│   ├── visuals/         # SFML rendering code
│   └── main.cpp         # App entry point and keyboard controls
└── CMakeLists.txt       # CMake build configuration
```

## Roadmap

- Add more algorithms, such as Quick Sort and Heap Sort
- Highlight active comparisons and sorted ranges
- Add randomized array generation
- Add on-screen instructions
- Improve runtime asset loading

## License

No license has been added yet. Add a license before publishing if you want others to know how they can use, modify, or distribute the project.
