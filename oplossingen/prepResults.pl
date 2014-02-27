use strict;
use warnings;


#dit perl script runt in een map en hernoemt de opgave1.cpp naar naam_opgave1.cpp
my $dir="/home/drew/school/Beeldverwerking/oplossingen";
my $naam= "Andreas_DeLille_opgave";

#`cd oplossingen`;
for (my $i = 1 ; $i < 13 ; $i++){
	`mkdir $dir/$naam$i`;
	`cp $dir/opgave$i.cpp $dir/$naam$i/$naam$i.cpp`;

	my $file = "$dir/opgave$i/CMakeLists.txt";
	open FILE, ">$dir/$naam$i/CMakeLists.txt";
	print FILE "cmake_minimum_required(VERSION 2.4)
	PROJECT(LABO$i)
	INCLUDE_DIRECTORIES(src)
	INCLUDE_DIRECTORIES(/usr/local/include)
	LINK_DIRECTORIES(/usr/local/lib)
	LINK_DIRECTORIES(/usr/lib)
	SET(EXECUTABLE_OUTPUT_PATH \${CMAKE_SOURCE_DIR}/bin)
	SET(LIBRARY_OUTPUT_PATH \${CMAKE_SOURCE_DIR}/bin)
	SET(CMAKE_CXX_FLAGS \"-o3 -w\")
	SET(CMAKE_CXX_LINK_FLAGS \"-pg\")
	SET(OpenCV_LIBRARIES opencv_core opencv_highgui opencv_imgproc)
	ADD_EXECUTABLE(opg$i $naam$i.cpp)
	TARGET_LINK_LIBRARIES(opg$i \${OpenCV_LIBRARIES})
	SET(CMAKE_BUILD_TYPE Release)";
	
	close FILE;

	`tar zcvf $naam$i.tar.gz $naam$i/`;
	`rm -rf $dir/$naam$i/`;
}