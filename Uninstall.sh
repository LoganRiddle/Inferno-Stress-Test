#!/bin/sh

current_distro=`cat /etc/*-release | grep "^ID=" | grep -E -o "[a-z]\w+"`
close_distro=`cat /etc/*-release | grep "^ID_LIKE=" | grep -E -o "[a-z]\w+"`

programs="htop fastfetch docker python3 vim starship pip git cmatrix neo neofetch gnome-tweaks virtualenv powertop"

echo "$current_distro"
echo "$close_distro"

if [ "$close_distro" = "debian" ]; then
	sudo rm /usr/bin/inferno-stress-test

elif [ "$close_distro" != "debian" ]; then
	sudo rm /usr/bin/inferno-stress-test
fi

echo "Install Complete!"
