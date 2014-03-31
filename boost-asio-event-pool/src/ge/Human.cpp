#include "../../include/stdafx.h"
#include "../../include/ge/Human.h"
#include "../../include/ge/event/human-event.h"


Human::Human( const std::string& name ) :
    mName( name )
{
    assert( !mName.empty() );

    std::cout << "Born Human " << mName << std::endl;
}




Human::~Human() {
    std::cout << "Die Human " << mName << std::endl;
}




template<>
void Human::desire< Talk< Human > >( const std::string& phrase ) {
    std::cout << "New desire Talk< Human >( " << phrase << " )\n";

    auto e = std::make_shared< Talk< Human > >( phrase );
    push( e );
}
