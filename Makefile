version = 0.1.1

finalize:
	gcc ./src/inferno.c ./src/metrics.c ./src/ui.c ./src/cleanup.c ./src/test.c ./src/score.c -o ./inferno-stress-test-$(version)/inferno-stress-test 
	@echo "Design Finalized, Increment Version Number as Applicable"

debug:
	gcc ./src/inferno.c ./src/metrics.c ./src/ui.c ./src/cleanup.c ./src/test.c ./src/score.c -o debug.out 
	@echo "debug.out ready to be run"

build-rpm:
	tar --create --file inferno-stress-test-$(version).tar.gz inferno-stress-test-$(version)
	mv inferno-stress-test-$(version).tar.gz ~/rpmbuild/SOURCES/
	rpmbuild -bs inferno.spec

source:
	tar --create --file inferno-stress-test-$(version).tar.gz inferno-stress-test-$(version)

clean:
	rm debug.out 
	rm test_results.csv
	@echo "All Clean!"

install:
	sudo cp ./inferno-stress-test-$(version)/inferno-stress-test /usr/bin/
