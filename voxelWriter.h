#ifndef __VOXELWRITER_H__
#define __VOXELWRITER_H__

#include "voxel.h"
#include <string>

using namespace std;

class VoxelWriter {
private:
	VoxelWriter();
	static VoxelWriter* instance;
public:
	~VoxelWriter();
	void writeVoxel(Voxel* voxel,string file);
	static VoxelWriter* getInstance();
	static void initialize();
	static void destroy();
};

#endif

