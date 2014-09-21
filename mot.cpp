#include "mot.h"


mot::mot():string()
{

}

mot::mot(uint32_t i=0):string(i,'-')
{

}

mot::mot(const char * str):string(str)
{

}

mot::mot(const string& str):string(str)
{

}

/*uint32_t mot::size()
{

}*/
/*
char& mot::operator[](size_t pos)
{
  return this->at(pos);

}*/

const char& mot::att(size_t pos)const
{
   return this->at(pos);
}

mot::~mot()
{

}

bool mot::operator==(mot m)
{


}



