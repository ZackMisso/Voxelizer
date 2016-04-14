#include "voxelWriter.h"
#include <iostream>
#include <fstream>

using namespace std;

VoxelWriter* VoxelWriter::instance = 0x0;

VoxelWriter::VoxelWriter() { }

VoxelWriter::~VoxelWriter() { }

void VoxelWriter::writeVoxel(Voxel* voxel,string file) {
	ofstream stream;
	stream.open(file);
	// to be implemented
	// stream << blah;
	stream.clost();
}

VoxelWriter* VoxelWriter::getInstance() {
	return instance;
}

void VoxelWriter::initialize() {
	if(!instance)
		instance = new VoxelWriter();
}

void VoxelWriter::destroy() {
	if(instance)
		delete instance;
}
