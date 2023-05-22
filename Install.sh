#!/bin/sh

current_distro=`cat /etc/*-release | grep "^ID=" | grep -E -o "[a-z]\w+"`
close_distro=`cat /etc/*-release | grep "^ID_LIKE=" | grep -E -o "[a-z]\w+"`

echo "$current_distro"
echo "$close_distro"

if [ "$close_distro" = "debian" ]; then
	sudo cp ./inferno-stress-test-0.0.7/inferno-stress-test /usr/bin/

elif [ "$close_distro" != "debian" ]; then
	sudo cp ./inferno-stress-test-0.0.7/inferno-stress-test /usr/bin/
fi

echo "Install Complete!"
