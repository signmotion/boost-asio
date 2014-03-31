#include "../../../include/stdafx.h"
#include "../../../include/ge/human/Human.h"


Human::Human( const std::string& name ) :
    GE( name )
{
    assert( !mName.empty() );

    Console::instance() << "Born Human " << mName << std::endl;
}




Human::~Human() {
    Console::instance() << "Die Human " << mName << std::endl;
}
