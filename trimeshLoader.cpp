#include "trimeshLoader.h"

TriMeshLoader::TriMeshLoader() { }

TokenPair* TriMeshLoader::tokenMatch(char *srchtok){
  if(!srchtok) return NULL;
    TokenPair *ptokp=&tokenMap[0];
    for(;*ptokp!=EMPTY_PAIR&&strcmp(ptokp->strval,srchtok)!=0;ptokp++) {}
    if(*ptokp==EMPTY_PAIR) ptokp=0;
    return ptokp;
  }

void TriMeshLoader::loadOBJ(const char* objfile, Mesh* pmesh){
  fstream ifs;
  char line[LINE_SIZE];
  //cout << "READIING" << endl;
  char *tok;
  ifs.open(objfile);
  //cout << "REED" << endl;
  while(!ifs.eof()){
    //cout << "HEY LISTEN" << endl;
    ifs.getline(line,LINE_SIZE);
    //cout << "LISTEN HEY" << endl;
    //cout << line << endl;
    tok=strtok(line,TOK_SEPS);
    //cout << "BOOP" << endl;
    TokenPair *ptok=tokenMatch(tok);
    //cout << "POOB" << endl;
    if(ptok){
      switch(ptok->id){
        case T_VERT: processVertex(tok,pmesh); break;
        case T_FACE: processFace(tok,pmesh); break;
        default: /*processSkip(tok);*/ break;
      }
    }
  }
  //cout << "FINISHED READING" << endl;
  ifs.close();
}

int TriMeshLoader::readFloats(char *tok,float *buf,int bufsz){
  int i=0;
  while((tok=strtok(0,TOK_SEPS))!=0 && i<bufsz)
    buf[i++]=atof(tok);
  return i;
}

int TriMeshLoader::readInts(char *tok,int *buf,int bufsz){
  int i=0;
  while((tok=strtok(0,TOK_SEPS))!=0 && i<bufsz)
    buf[i++]=atoi(tok);
  return i;
}

void TriMeshLoader::processSkip(char*tok){}

void TriMeshLoader::processVertex(char* tok, Mesh *pmesh){
  //cout << "PROCESSING VERTEX" << endl;
  float values[3];
  int cnt=readFloats(tok,values,3);
  if(cnt>=3) pmesh->addVertex(values);
}

void TriMeshLoader::processFace(char *tok,Mesh *pmesh){
  //cout << "PROCESSING FACE" << endl;
  int ids[256];
  int cnt=readInts(tok,ids,256);
  if(cnt>=3){
    int tri[3]={ids[0]-1,ids[1]-1,ids[2]-1};
    pmesh->addFace(tri);
    for(int i=3;i<cnt;i++){
      tri[1]=tri[2];
      tri[2]=ids[i]-1;
      pmesh->addFace(tri);
    }
  }
}
