#ifndef __VOXELREADER_H__
#define __VOXELREADER_H__

#include "voxel.h"
#include <iostream>

using namespace std;

class VoxelReader {
private:	
	VoxelReader();
	static VoxelReader* instance;
public:
	~VoxelReader();
	Voxel* readVoxel(string file);
	static VoxelReader* getInstance();
	static void initialize();
	static void destroy();
};

#endif

