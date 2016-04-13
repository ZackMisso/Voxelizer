#ifndef __TRIMESHLOADER_H__
#define __TRIMESHLOADER_H__
#include <iostream>
#include <fstream>
#include <cstring>
#include "trimesh.h"
//#include "program.h"

#define LINE_SIZE 1024
#define TOKEN_LENGTH 8

using namespace std;

enum TokenID { T_NONE=-1, T_VERT, T_FACE};

struct TokenPair{
		char strval[TOKEN_LENGTH];
		TokenID id;
		bool operator==(const TokenPair &other) const{
			return strcmp(strval,other.strval) == 0 && id==other.id;
		}
		bool operator!=(const TokenPair &other) const{
		return !(*this==other);
	}
};

class TriMeshLoader{
public:
  TriMeshLoader();
	//static TokenPair tokenMap[];
	//static TokenPair EMPTY_PAIR;
	//static char TOK_SEPS[];
	TokenPair *tokenMatch(char *srchtok);
	void loadOBJ(const char* objfile, TriMesh* pmesh);
	int readFloats(char *tok,float *buf,int bufsz);
	int readInts(char *tok,int *buf,int bufsz){;
	void processSkip(char*tok);
	void processVertex(char* tok, Mesh *pmesh);
	void processFace(char *tok,Mesh *pmesh){;

	TokenPair EMPTY_PAIR={"",T_NONE};

	TokenPair tokenMap[3] = {
		{"v", T_VERT},{"f", T_FACE},
		EMPTY_PAIR
	};

	const char* TOK_SEPS = " \t";

};
#endif
