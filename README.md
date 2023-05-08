# Inferno-Stress-Test

![alt text](https://github.com/LoganRiddle/Inferno-Stress-Test/blob/main/images/Screenshot%20from%202023-04-28%2016-37-47.png "App Image")

## Description
A simple non-graphical stress test application for testing processors through file writes. The build is currently very early on and is in development with plans to add a gui version as well. The application is entirely written in c and all code can be found withing the `/src/` directory. 

## Installation
#### Fedora Installation:
1. To install you must first enable the repository using `dnf copr enable loganriddlewc/inferno-stress-test`. 

2. Using the dnf package manager, just install the application with `dnf install inferno-stress-test`.

#### CentOS Installation:
1. To install you must first enable the repository using `yum copr enable loganriddlewc/inferno-stress-test`.

2. Using the yum package manager, just install the application with `yum install inferno-stress-test`.

#### Ubuntu/Debian Based Systems Installation:
1. To install on Debian based systems, you must first clone the github repository using `git clone https://github.com/LoganRiddle/Inferno-Stress-Test`

2. Change directory to the repository directory using `cd Inferno-Stress-Test`

3. Using the `Install.sh` script, the executable will be install in the `/usr/bin/` directory. 

4. An uninstall script is also provided which removes the executable from that location `Uninstall.sh` 

## How to use the Makefile

#### Debug:

* The `make debug` command generates an executable in the current directory called `debug.out` 

* This is for testing purposes to make it as easy as possible to make changes on the fly

#### Finalize: 

* The `make finalize` command generates an executable in the `Inferno-Stress-Test-<Version Number>` directory 

* The purpose of this is for easy packaging when ready to rollout the next release

#### Clean:

* The `make clean` command removes a `debug.out` executable if applicable 
