#include "../../../include/stdafx.h"
#include "../../../include/ge/city/City.h"


City::City( const std::string& name ) :
    GE( name )
{
    assert( !mName.empty() );

    Console::instance() << "Build City " << mName << std::endl;
}




City::~City() {
    Console::instance() << "Destroy City " << mName << std::endl;
}
