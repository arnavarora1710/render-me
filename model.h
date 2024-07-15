#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "geometry.h"

// model needs to have a list of vertices and triangles
// vertices can be a vector of coordinates
// triangles can be a vector of indices of vertices included in the triangle

class Model {
private:
    std::vector<vec3f> vertices;
    std::vector<std::vector<int>> triangles;
public:
    Model(const char* filename);
    ~Model();
    int vertexCnt() const;
    int triangleCnt() const;
    vec3f getVertex(int i) const;
    std::vector<int> getTriangle(int i) const;
};

#endif // _MODEL_H