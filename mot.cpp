#include "mot.h"


mot::mot()
{
  value = string();
}

mot::mot(uint32_t i=0)
{
    value = string(i,'-');
}

mot::mot(const char * str)
{
    value = string(str);
}

mot::mot(const string& str)
{
    value = string(str);
}

char& mot::operator[](size_t pos)
{
    return value.operator[](pos);
}

const char& mot::at(size_t pos)const
{
    return value.at(pos);
}


bool mot::operator==(mot m)
{
    bool retour = false;

    if( m.size() == value.size() )
        {
            retour = true;
            for(size_t i = 0; i<m.size() ; ++i)
                retour &= (m.at(i) == value.at(i));
        }
    return retour;
}

uint32_t mot::size()
{
  return value.size();
}


    const string mot::tostring()
    {
      return value;
    }
