#!/bin/sh

current_distro=`cat /etc/*-release | grep "^ID=" | grep -E -o "[a-z]\w+"`
close_distro=`cat /etc/*-release | grep "^ID_LIKE=" | grep -E -o "[a-z]\w+"`

programs="htop fastfetch docker python3 vim starship pip git cmatrix neo neofetch gnome-tweaks virtualenv powertop"

echo "$current_distro"
echo "$close_distro"

if [ "$close_distro" = "debian" ]; then
	cp ./inferno-stress-test-0.0.4/inferno-stress-test /usr/env/bin/

elif [ "$close_distro" != "debian" ]; then
	cp ./inferno-stress-test-0.0.4/inferno-stress-test /usr/env/bin/
fi

echo "Install Complete!"
