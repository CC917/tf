INCLUDEDIR0 = -I ./tf/include

INCLUDEDIR1 = -I ./tf/include/infra/common/log/spdlog-1.x/include

SOURCEC = ./sandbox/client.cpp

SOURCEC += ./tf/src/domain/prefix/*.cpp

SOURCEC += ./tf/src/domain/site/*.cpp

SOURCEC += ./tf/src/domain/obj/*.cpp

SOURCES = ./sandbox/server.cpp

#need config.
LIBWEB = C:\dev\CC\x86_64-w64-mingw32\lib

sandbox_rule:
	g++ -std=c++11 -o sandbox $(INCLUDEDIR0) $(INCLUDEDIR1) $(SOURCEC) $(LIBWEB)\libws2_32.a