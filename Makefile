#finalize:
#	gcc ./src/inferno.c ./src/cpu.c ./src/cleanup.c ./src/test.c ./src/score.c -o ./Inferno-Stress-Test-0.0.5/inferno-stress-test
#	@echo "Design Finalized, Increment Version Number as Applicable"

debug:
	gcc ./src/inferno.c ./src/cpu.c ./src/cleanup.c ./src/test.c ./src/score.c ./src/gui.c -o debug.out `pkg-config --cflags --libs gtk+-3.0`
	@echo "debug.out ready to be run"

#Feature is still being tested, DO NOT USE!!!!!!
build-rpm:
	rpmbuild -ba ~/rpmbuild/SPECS/inferno.spec

clean:
	rm debug.out
	@echo "All Clean!"

install:
	sudo cp ./inferno-stress-test-0.0.6/inferno-stress-test /usr/bin/
