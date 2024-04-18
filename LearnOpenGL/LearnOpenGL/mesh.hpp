//
// Created by Hongbeubeu on 4/18/2024.
//

#ifndef MESH_HPP
#define MESH_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <shader.hpp>

#include <string>
#include <vector>

using namespace std;

#define MAX_BONES_INFLUENCE 4

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
    // bone ids which will influence this vertex
    int m_BoneIDs[MAX_BONES_INFLUENCE];
    // weights from each bone
    float m_Weights[MAX_BONES_INFLUENCE];
};

struct Texture {
    unsigned int id;
    string type;
    string path; // we store the path of the texture to compare with other textures
};

class Mesh {
public:
    // mesh Data
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;
    
    // constructor
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    // render the mesh
    void Draw(shader &shader);
private:
    // render data
    unsigned int VBO, EBO;
    // initializes all the buffer objects/arrays
    void setupMesh();
};


#endif //MESH_HPP
