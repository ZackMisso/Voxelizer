#include "voxelReader.h"

VoxelReader* VoxelReader::instance = 0x0;

VoxelReader::VoxelReader() { }

VoxelReader::~VoxelReader() { }

Voxel* VoxelReader::readVoxel(string param) {
	// to be implemented
	return 0x0;
}

VoxelReader* VoxelReader::getInstance() {
	return instance;
}

void VoxelReader::initialize() {
	if(!instance)
		instance = new VoxelReader();
}

void VoxelReader::destroy() {
	if(instance)
		delete instance;
}

