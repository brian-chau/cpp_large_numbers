# C++ on WSL2 with VS Code

This is an example of how to use:
* Visual Studio Code with a C++ application written for GCC compiler
* ncurses to display a menu and select an option

## Setting up WSL2
1. Install WSL
    1. Start "Command Prompt"
    2. Run "wsl --set-default-version 2"
    3. Run "wsl --list --online" to see available distributions
    4. Run "wsl --install -d <distro_name>" based on what you see in the list.
        * This will take several minutes

2. Start WSL
    1. Press Ctrl+R
    2. Type "wsl"
    3. Press Enter

3. Fix the command line path name.
    a. Edit the ~/.bashrc file.
        * At the top of the file, paste the following code snippet, where <current_directory> is the name of the 
          mount point shown in the console window (e.g. "/mnt/c/Users/<username>")

            if [[ $PWD == /mnt/c/Users/<username> ]]; then
              cd /home/user/user
            else
              case $PWD/ in
                /mnt/c/Users/<username>/*)
                  without_prefix=${PWD#/mnt/c/Users/<username>/}
                  cd /home/user/user/$without_prefix
                  ;;
              esac
            fi

    b. Look for the line that says "if [ "$color_prompt" = yes ]; then"
        * In the following line, remove the part that specifies the username "\u" and the host name "\h"
        * Do the same for the "else" block.

4. Update the system
    a. sudo apt update
    b. sudo apt upgrade
    c. sudo apt autoremove

5. Add custom aliases to ~/.bash_aliases
    a. alias cls="printf '\ec'; history -c"
    b. alias nanos="nano -ET4"

6. Add GitHub settings
    a. Restart WSL
    b. Run "mkdir repos"
    c. Connect to GitHub
        c1. Sign in to GitHub
        c2. Click profile picture in upper right corner, then click Settings
        c3. Delete any old SSH keys if any.
        c4. Start creating SSH keys
            c4a: Run the following commands:
                ssh-keygen -t ed25519 -C "your_email@example.com"
                eval "$(ssh-agent -s)"
                ssh-add ~/.ssh/id_ed25519
                cat ~/.ssh/id_ed25519.pub
            c4b: Copy the result and go to this page: https://github.com/settings/ssh/new
            c4c: For "Title," put "Linux".
            c4d: For "Key," paste the result of (c4b)
            c4e: Click "Add SSH Key"
            c4f: Run "ssh -T git@github.com", then type "yes"

## Setting up the dependencies for this project
1. Download the project source code:
    a. Open WSL.
        a1. Ctrl+R
        a2. Type "wsl"
        a3. Press Enter

    b. Run these commands:
        b1. cd repos
        b2. git clone git@github.com:brian-chau/cpp_large_numbers.git

2. Setup the project
    a. Navigate to the project with "cd cpp_large_numbers"
    b. Run this command to install the necessary libraries: sudo apt install make build-essential lzip m4 libncurses5-dev
    c. Install "gmp":
        c3a. Download GMP from here: https://gmplib.org/
        c3b. Unpack it with the command: sudo tar --lzip -xvf gmp-x.y.z.tar.lz
        c3c. Navigate into that folder: cd gmp-x.y.z
        c3d. Run the following commands:
                sudo ./configure --enable-cxx
                sudo make
                sudo make check
                sudo make install
    d. Run: make
    e. Run: sudo ldconfig

## Setting up VSCode
1. In WSL, type "code ."
2. Press Ctrl+Shift+X to open the "Extensions" window.
3. Install the following extensions
    a. C/C++ Themes
    b. C/C++ Extension Pack
    c. Makefile Tools
    d. Remote - WSL
    e. Better C++ Syntax
4. Close VSCode
5. Type "code ." in the terminal to restart it.
6. Press Ctrl+Shift+X again to open the "Extensions" window.
7. If any of the above extensions say "Install in WSL: Ubuntu-20.04", then click that button.
8. Configure editor settings
    a. Click the gear icon in the lower left corner.
    b. Click Settings.
    c. In the search bar, type "minimap" and uncheck "Editor > Minimap: Enabled" where the checkbox says "Controls whether the minimap is shown"
    d. In the search bar, type "Trim Trailing Whitespace" and check the box for "Files: Trim Trailing Whitespace"
    e. In the search bar, type "Detect Indentation" and uncheck the box for "Editor: Detect Indentation"
    f. In the search bar, type "Format On Save" and check the box for "Editor: Format On Save"
9. Set the key bindings to build and clean the solution.
    a. Press Ctrl+K Ctrl+S
    b. In the keybindings search box, type "makefile: build clean the target ALL"
        b1. Double-click the keybinding and replace it with Ctrl+Shift+B.
            * There is already a keybinding for that in VSCode, but you can remove the other keybinding to replace it with this.
        b2. Press Enter to save the keybinding.
    c. In the keybindings search box, type "Makefile: Build clean the current target"
        c1. Double-click the keybinding and replace it with Ctrl+Shift+Z.