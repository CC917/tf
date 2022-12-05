INCLUDEDIR = ./tf/include

SOURCEC = ./sandbox/client.cpp

SOURCES = ./sandbox/server.cpp

#need config.
LIBWEB = C:\dev\CC\x86_64-w64-mingw32\lib

sandbox_rule:
	g++ -o sandbox -I $(INCLUDEDIR) $(SOURCEC) $(LIBWEB)\libws2_32.a
	
server_rule:
	g++ -o server -I $(INCLUDEDIR) $(SOURCES) $(LIBWEB)\libws2_32.a