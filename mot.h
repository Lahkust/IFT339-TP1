#ifndef MOT_H
#define MOT_H

#include <string>
using namespace std;

class mot
{

private :
  string value;

public:
    mot();
    mot(uint32_t);
    mot(const char*);
    mot(const string&);

    uint32_t size();
    const char& at(size_t)const;

    char& operator[](size_t);
    bool operator==(mot);
    const string tostring();
};

#endif // MOT_H
