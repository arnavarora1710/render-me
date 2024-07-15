#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "model.h"
using namespace std;

Model::Model(const char* filename) {
    ifstream inp(filename);
    if (inp.fail()) return;
    while (!inp.eof()) {
        char c;
        inp >> c;
        if (c == 'v') {
            vec3f v;
            inp >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        } else if (c == 'f') {
            std::vector<int> f;
            int tmp;
            while (inp >> tmp) {
                f.push_back(tmp - 1);
                inp.ignore(256, ' ');
            }
            triangles.push_back(f);
        }
    }
    inp.close();
    cerr << "vertex count: " << vertices.size() << " triangle count: " << triangles.size() << endl;
}

Model::~Model() {
    vertices.clear();
    triangles.clear();
}

int Model::vertexCnt() const {
    return vertices.size();
}

int Model::triangleCnt() const {
    return triangles.size();
}

vec3f Model::getVertex(int i) const {
    return vertices[i];
}

std::vector<int> Model::getTriangle(int i) const {
    return triangles[i];
}