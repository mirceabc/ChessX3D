# ChessX3D 
ChessX3D is a 3D game developed in OpenGL for macOS with aarch64, designed to learn graphic programming.
 
![ChessGL](resources/icon_128x128.png)

## Installation

To run ChessX3D, follow these steps:

1. **Install Homebrew**: If you don't have Homebrew installed, you can do so by following the instructions on [Homebrew's official website](https://brew.sh/).
    
    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
2. **Install CMake**: Use Homebrew to install CMake. Open a terminal window and run the following command.

   ```bash
   brew install cmake
   
3. **Clone the repository**: Clone the ChessX3D repository to your local machine using the following command.

    ```bash
    git clone https://github.com/mirceabc/ChessX3D.git
    ```
4. **Navigate to game directory**: Navigate to the cloned repository directory.
    
    ```bash
    cd ChessX3D
    ```
5. **Build the project**: Use CMake to build the ChessX3D files. Run the following commands.

    ```bash
    cmake -S . -B build
    cmake --build build
    ```
   
6. **Run the game**: Launch the ChessX3D game using the following command.

    ```bash
    open ./bin/Debug/ChessX3D.app
    ```

## Development in Progress

❌ Beautifully rendered chessboard and pieces using OpenGL graphics.

❌ Player vs. player and player vs. AI modes available.

❌ Adjustable difficulty levels to suit players of all skill levels.

❌ Interactive interface with intuitive controls for an immersive gaming experience.

## Screenshots

Coming soon!

## Feedback

If you have any feedback or suggestions for improvement, feel free to contact us or open an issue on the [GitHub repository](https://github.com/mirceabc/ChessX3D/issues). We appreciate your input!

## Support

For additional support or questions, you can reach out to us via [GitHub discussions](https://github.com/mirceabc/ChessX3D/discussions). We're here to help!

## Content credentials
ChessX3D logo and icons are generated with AI and modified by Designer ∙ April 19, 2024 at 6:44 PM by Microsoft Copilot Powered by DALL·E 3

## License

ChessX3D is licensed under the [MIT License](LICENSE). See the [LICENSE](LICENSE) file for more details.

