Name:           inferno-stress-test
Version:        0.0.8
Release:        1%{?dist}
Summary:        A simple stress test program for system stressing and testing

License:        GPL
Source0:        %{name}-%{version}.tar.gz

Requires:       bash

%description
Inferno Stress Test

%prep
%setup -q


%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/%{_bindir}
cp %{name} $RPM_BUILD_ROOT/%{_bindir}

%files
%{_bindir}/%{name}


%changelog
* Tue May 23 2023 Logan Riddle <motobecane28@vinces-mobile-station> - 0.0.8
- Bug Fixes, opens test file in the tmp directory
