#include "voxelWriter.h"

VoxelWriter* VoxelWriter::instance = 0x0;

VoxelWriter::VoxelWriter() { }

VoxelWriter::~VoxelWriter() { }

void VoxelWriter::writeVoxel(Voxel* voxel,string file) {
	// to be implemented
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
