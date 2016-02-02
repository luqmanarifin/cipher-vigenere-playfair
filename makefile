vigenere: vigenere_standard.cpp
	g++ vigenere_standard.cpp -o vigenere -std=c++11

ascii: vigenere_extended.cpp
	g++ vigenere_extended.cpp -o ascii -std=c++11

bonus: vigenere_bonus.cpp
	g++ vigenere_bonus.cpp -o bonus -std=c++11

playfair: playfair.cpp
	g++ playfair.cpp -o playfair -std=c++11