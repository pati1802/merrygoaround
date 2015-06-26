/****************************************************************************
 *	Code for object loading used from:
 *		http://www.opengl-tutorial.org/beginners-tutorials/
 *
 ***************************************************************************/

#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <cstring>

#ifndef DEBUG
#define DEBUG true
#endif

bool loadOBJ(
        std::string path, 
        std::vector<glm::vec3> & out_vertices, 
        std::vector<glm::vec2> & out_uvs, 
        std::vector<glm::vec3> & out_normals
);



bool loadAssImp(
        std::string path, 
        std::vector<unsigned short> & indices,
        std::vector<glm::vec3> & vertices,
        std::vector<glm::vec2> & uvs,
        std::vector<glm::vec3> & normals
);

#endif
