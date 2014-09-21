#ifndef MOT_H
#define MOT_H

#include <string>
using namespace std;

class mot : public string
{

private :

public:
    mot();
    mot(uint32_t);
    mot(const char*);
    mot(const string&);
    ~mot();

    uint32_t size();
    const char& att(size_t)const;

    char& operator[](size_t);
    bool operator==(mot);
};

#endif // MOT_H
