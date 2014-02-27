use strict;
use warnings;


#dit perl script runt in een map en hernoemt de opgave1.cpp naar naam_opgave1.cpp
my $dir="/home/drew/school/Beeldverwerking/oplossingen";
my $naam= "Andreas_DeLille_opgave";

for (my $i = 1 ; $i < 12 ; $i++){
	`mkdir $dir/$naam$i`;
	`cp -v $dir/opgave$i.cpp $dir/$naam$i/$naam$i.cpp`;
	my $file = "$dir/opgave$i/CMakeList.txt";
	open FILE, ">$dir/$naam$i/CMakeList.txt";
	print FILE "cmake_minimum_required(VERSION 2.4)\n";
	print FILE "PROJECT(LABO1)\n";
	print FILE "INCLUDE_DIRECTORIES(src)\n";
	print FILE "INCLUDE_DIRECTORIES(/usr/local/include)\n";
	print FILE "LINK_DIRECTORIES(/usr/local/lib)\n";
	print FILE "LINK_DIRECTORIES(/usr/lib)\n";
	print FILE "SET(EXECUTABLE_OUTPUT_PATH \${CMAKE_SOURCE_DIR}/bin)\n";
	print FILE "SET(LIBRARY_OUTPUT_PATH \${CMAKE_SOURCE_DIR}/bin)\n";
	print FILE "SET(CMAKE_CXX_FLAGS \"-o3 -w\")\n";
	print FILE "SET(CMAKE_CXX_LINK_FLAGS \"-pg\")\n";
	print FILE "SET(OpenCV_LIBRARIES opencv_core opencv_highgui opencv_imgproc)\n";
	print FILE "ADD_EXECUTABLE(opg$i $naam$i.cpp)\n";
	print FILE "TARGET_LINK_LIBRARIES(opg1 \${OpenCV_LIBRARIES})\n";
	print FILE "SET(CMAKE_BUILD_TYPE Release)\n";
	close FILE;

	`tar -zcvf oplossingen/$naam$i.tar.gz $naam$i/`;
	`rm -rf $dir/$naam$i/`;
}