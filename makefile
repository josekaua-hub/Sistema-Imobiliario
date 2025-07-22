imobiliaria: main.o cliente.o corretor.o imovel.o
	g++ -o imobiliaria main.o cliente.o corretor.o imovel.o

main.o: main.cpp
	g++ -c main.cpp


cliente.o: cliente.cpp
	g++ -c cliente.cpp

corretor.o: corretor.cpp
	g++ -c corretor.cpp

imovel.o: imovel.cpp
	g++ -c imovel.cpp


clean: 
	del /Q *.o imobiliaria.exe