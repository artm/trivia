test-run: game
	./game > test.out.txt
	diff -u golden.master.txt test.out.txt

game: Game.cpp GameRunner.cpp Game.h
	g++ -std=c++11 Game.cpp GameRunner.cpp -o game

