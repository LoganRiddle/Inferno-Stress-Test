# Inferno-Stress-Test

![alt text](https://github.com/LoganRiddle/Inferno-Stress-Test/blob/main/src/images/Inferno.png "App Image")

## Description
A simple non-graphical stress test application for testing processors through file writes. 

## Installation
#### Fedora Installtion:
1. To install you must first enable the repository using `dnf copr enable loganriddlewc/inferno-stress-test`. 

2. Using the dnf package manager, just install the application with `dnf install inferno-stress-test`.

#### CentOS Installtion:
1. To install you must first enable the repository using `yum copr enable loganriddlewc/inferno-stress-test`.

2. Using the yum package manager, just install the application with `yum install inferno-stress-test`.

## Building RPM Packages:

###Installing Necessary Tools: 
The following packages need to be installed to build the RPM package:
```
$ sudo dnf install -y rpmdevtools rpmlint
```
After installing rpmdevtools, create the file tree you need to build RPM packages:
```
$ rpmdev-setuptree
```
You build RPM packages as a normal (not root) user, so your build environment is placed into your home directory. It contains this directory structure:
```
rpmbuild/
├── BUILD
├── RPMS
├── SOURCES
├── SPECS
└── SRPMS
```

The BUILD directory is used during the build process of the RPM package. This is where the temporary files are stored, moved around, etc.
The RPMS directory holds RPM packages built for different architectures and noarch if specified in .spec file or during the build.
The SOURCES directory, as the name implies, holds sources. This can be a simple script, a complex C project that needs to be compiled, a pre-compiled program, etc. Usually, the sources are compressed as .tar.gz or .tgz files.
The SPEC directory contains the .spec files. The .spec file defines how a package is built. More on that later.
The SRPMS directory holds the .src.rpm packages. A Source RPM package doesn't belong to an architecture or distribution. The actual .rpm package build is based on the .src.rpm package.
A .src.rpm package is very flexible, because it can be built and re-built on every other RPM-based distribution and architecture.

You're now familiar with what each directory holds, so now create a simple script to distribute:
```
$ cat << EOF >> hello.sh
#!/bin/sh
echo "Hello world"
EOF
```
This creates a shell script called hello.sh, which prints "Hello world" to the terminal. It's simple, but it's enough to demonstrate packaging.

Place the script in the designated directory
To build a package for your script, you must put your script in the directory that the RPM build system expects it to be in. Create a directory for it, using semantic versioning as most projects do, and then move hello.sh into it:
```
$ mkdir hello-0.0.1
$ mv hello.sh hello-0.0.1
```
Most source code is distributed as an archive, so use the tar command to create an archive file:
```
$ tar --create --file hello-0.0.1.tar.gz hello-0.0.1
```
Then move the tarball you've just created into the SOURCES directory:
```
$ mv hello-0.0.1.tar.gz SOURCES
```
Create a .spec file
An RPM package is defined by a .spec file. The syntax of a .spec file is strict, but rpmdev can generate a boilerplate file for you:

```
$ rpmdev-newspec hello
```

This generates a file called hello.spec, which you must move to the SPECS directory. Run tree ~/rpmbuild to see what the directory structure looks like:
```
/home/tux/rpmbuild/
├── BUILD
├── BUILDROOT
├── RPMS
├── SOURCES
│   └── hello-0.0.1.tar.gz
├── SPECS
│   └── hello.spec
└── SRPMS
```

The generated hello.spec file provides a good starting point, but it doesn't have any specific information about what you're building. The generated .spec file assumes that I am going to compile and build software.

You're packaging a Bash script, so there's some simplification you can do. For instance, there's no Build process because there's no code to compile. I've added BuildArch: noarch because this package is valid for 32-bit, 64-bit, Arm, and any other CPU architecture that runs Bash.

I've also added Requires: bash so that the package ensures that Bash is installed. This simple "hello world" script runs on any shell, of course, but that's not true for all scripts, so this is a good way to demonstrate dependencies.
```
Name:           hello
Version:        0.0.1
Release:        1%{?dist}
Summary:        A simple hello world script
BuildArch:      noarch

License:        GPL
Source0:        %{name}-%{version}.tar.gz

Requires:       bash

%description
A demo RPM build

%prep
%setup -q

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_bindir}
cp %{name}.sh $RPM_BUILD_ROOT/%{_bindir}

%clean
rm -rf $RPM_BUILD_ROOT

%files
%{_bindir}/%{name}.sh

%changelog
* Sun Nov  18 2020 Valentin Bajrami <valentin.bajrami@slimmer.ai> - 0.0.1
- First version being packaged
```

As you can tell, there are a lot of shortcuts in .spec files. They're called macros, and there's an excellent list of what's available in the Fedora packaging documentation. It's important to use macros in your .spec files. They help ensure consistency across all RPM systems, they help you avoid mistakes in filenames and version numbering, and they make it easier to update the .spec file when you release a new version of your script.

For example, it's required that you specify exactly which files are installed under the %files section. Here I’ve explicitly put the following line:

```
%files
%{_bindir}/%{name}.sh
```

This works because I want the script to go to %{_bindir} (which is a macro that translates to /usr/bin by default, but is configurable when users want to install to a different location, such as /usr/local/bin). You can verify macro values by running:

```
$ rpm --eval '%{_bindir}'
/usr/bin
```

Other useful macros:

%{name} name of the package (as defined in the Name: field)
%{version} version of the package (as defined in the Version: field)
%{_datadir} shared data (/usr/sbin by default)
%{_sysconfdir} configuration directory (/etc by default)
Checking the .spec file on error (rpmlint)
The rpmlint command can find errors in .spec files:

$ rpmlint ~/rpmbuild/SPECS/hello.spec
SPECS/hello.spec: W: no-%build-section
SPECS/hello.spec: W: invalid-url Source0: hello-0.0.1.tar.gz
0 packages and 1 specfiles checked; 0 errors, 2 warnings.
There are 2 errors reported, but they're both acceptable. There's no code to build, so there's no need for a %build section, and the source archive is a local file and has no network URL.

Everything looks good.

Building the package (rpmbuild)
To build the RPM package, use the rpmbuild command. Earlier in this tutorial, I mentioned the difference between the .src.rpm (Source RPM package) and the .rpm package.

To create the .src rpm package:
```
$ rpmbuild -bs ~/rpmbuild/SPECS/hello.spec
```
The flags -bs have the following meanings:

-b: build
-s: source
To create the binary .rpm package:
```
$ rpmbuild -bb ~/rpmbuild/SPECS/rm-ssh-offendingkey.spec
```

The flags -bb have the following meanings:

-b: build
-b: binary
Use -ba to build both.

After the build process is finished, you have the following directory structure:

```
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     1,1           Top


