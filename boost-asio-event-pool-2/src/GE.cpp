#include "../include/stdafx.h"
#include "../include/GE.h"


std::unique_ptr< ManagerEvent >  GE::mManagerEvent( new ManagerEvent() );




GE::GE( const std::string& nm ) :
    mName( nm )
{
    assert( !nm.empty()
        && "Имя элемента должно быть указано." );
}




GE::~GE() {
}
