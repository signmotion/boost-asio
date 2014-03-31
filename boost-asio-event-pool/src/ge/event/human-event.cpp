#include "../../../include/stdafx.h"
#include "../../../include/ge/event/human-event.h"


template<>
class Talk< Human > :
    public Event< Human > {
public:
    Talk( const std::string& phrase ) :
        Event< Human >( nullptr ),
        mPhrase( phrase )
    {
        assert( !phrase.empty() );
        std::cout << "  START Human talk '" << mPhrase << "'\n";
    }


    ~Talk() {
        std::cout << "  START Human talk '" << mPhrase << "'\n";
    }


private:
    const std::string  mPhrase;
};
