#ifndef VERTEX_H
#define VERTEX_H

#include <string>
using namespace std;

class Vertex
{
    public:
        string title;

        Vertex(string name)
        {
            title = name;
        };

        string getTitle() const;
};

#endif // VERTEX_H
