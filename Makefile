finalize:
	gcc ./src/inferno.c ./src/cpu.c ./src/cleanup.c ./src/test.c ./src/score.c -o ./Inferno-Stress-Test-0.0.4/inferno-stress-test
	@echo "Design Finalized, Increment Version Number as Applicable"

debug:
	gcc ./src/inferno.c ./src/cpu.c ./src/cleanup.c ./src/test.c ./src/score.c -o debug.out
	@echo "debug.out ready to be run"

clean:
	rm debug.out
	@echo "All Clean!"
