# lostlands-gtk4
An implementation of the LostLands game in C with GTK4.

## How to build the app

### Prerequisites
Make sure the following software is installed on your computer.
- GTK4 libraries
- GCC (or another C compiler).

### Compiling the app on Windows
Identify directories where gcc.exe & make.exe are located.  
Add environment variables for gcc & make programs.  

Check your installations in cmd:  
gcc --version  
make --version

Open cmd, go to the app directory, type make:  
cd *\lostlands-gtk4\  
make

The app will be compiled through the Makefile and an executable file "lostlands-gtk4.exe" will appear in the app directory.

### Compiling the app on Unix/ Linux
Identify directories where gcc & make binary files are located.  
Add gcc & make programs location to your path environment variable.  

Check your installations:  
gcc --version  
make --version

Go to the app directory and type the following commands:  
cd */lostlands-gtk4/  
./make

The app will be compiled through the Makefile and a binary file "lostlands-gtk4" will appear in the app directory.

## How to run the app
### Running the app On Windows
Use cmd.  
In the app directory, type the following command:  
lostlands-gtk4.exe

### Running the app on Linux
Use a terminal.  
In the app directory, type the following command:  
./lostlands-gtk4

## Screenshots
![lostlands-gtk4_01.JPG](lostlands-gtk4_01.JPG?raw=true)
