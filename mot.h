#ifndef MOT_H
#define MOT_H

#include <string>
using namespace std;

class mot
{

private :

public:

 string value;
    bool operator==(mot);
    mot(void);
    mot(string);
    mot(uint32_t);
    ~mot(void);
};

#endif // MOT_H
