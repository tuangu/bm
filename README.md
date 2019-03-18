# Simple Bank Account Management

You can build this project with CMake. If you don't have CMake installed, you can get it from https://cmake.org/.

## Building
Get the code:
```
git clone --recursive https://github.com/tuangu/bm.git
```

### Windows
Do the following. All the commands are run with Powershell.
* Create a folder called **build-msvc**
```
mkdir build-msvc
cd build-msvc
```
* Generate projects to target **x64**
```
cmake -G "Visual Studio 15 2017 Win64" .. 
```
or 
```
cmake -G "Visual Studio 14 2015 Win64" ..
```
* Navigate to the project folder to open the solution file ({project_name}.sln).

Otherwise, you can use cmake-gui to configure and generate the project.

### GCC
* Create a folder called **build** and run CMake inside
```
mkdir build
cd build
cmake ..
```
* Build the project, then run the application (*bank_management* in this case) or the tests (*tests* in this case)
```
make

# Run the application
./bank_management 

# Run the tests
./tests
```

## How to use
As a user, you can 
* Create new account, be it basic, customer, or enterprise.
* Deposit to or withdraw from your account with account ID.
* Query the account details by customer's name or company's name.

To learn how to use it, it is best to watch a demo.

[![asciicast](https://asciinema.org/a/234575.svg)](https://asciinema.org/a/234575)

