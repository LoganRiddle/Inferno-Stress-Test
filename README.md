# Inferno-Stress-Test

![alt text](https://github.com/LoganRiddle/Inferno-Stress-Test/blob/main/images/Screenshot%20from%202023-06-06%2010-14-31.png "App Image")

## Description
A simple non-graphical stress test application for testing systems through file writes. The build is currently very early on and is in development with plans to add a gui version as well. The application is entirely written in c and all code can be found withing the `/src/` directory. The test has a scoring system that relates time taken to complete the test to the number of lines written to the test file during the test. The test also displays core CPU tempature to the user to be monitored as needed. 

## Installation
#### Fedora Installation:
1. To install you must first enable the repository using `dnf copr enable loganriddlewc/inferno-stress-test`. 

2. Using the dnf package manager, just install the application with `dnf install inferno-stress-test`.

#### CentOS Installation:
1. To install you must first enable the repository using `yum copr enable loganriddlewc/inferno-stress-test`.

2. Using the yum package manager, just install the application with `yum install inferno-stress-test`.

#### Misc Linux Systems Installation:
1. To install on Debian based systems, you must first clone the github repository using `git clone https://github.com/LoganRiddle/Inferno-Stress-Test`

2. Change directory to the repository directory using `cd Inferno-Stress-Test`

3. Run the `make install` command which copies the executable to the `/usr/bin` directory

## How to use the Makefile

#### Debug:

* The `make debug` command generates an executable in the current directory called `debug.out` 

* This is for testing purposes to make it as easy as possible to make changes on the fly

#### Finalize: 

* The `make finalize` command generates an executable in the `Inferno-Stress-Test-<Version Number>` directory 

* The purpose of this is for easy packaging when ready to rollout the next release

#### Clean:

* The `make clean` command removes a `debug.out` executable if applicable 

#### Install:

* The `make install` command copies the `inferno-stress-test` executable to the `/usr/bin` directory 

#### Build-rpm:

* The `make build-rpm` command generates a compressed source file and builds an SRPM which will be saved in the `rpmbuild/SRPMS/` directory

#### Source:

* The `make source` just generates the compressed source file for packaging
