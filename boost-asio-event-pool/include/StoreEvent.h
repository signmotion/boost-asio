#pragma once


template< class E >
class StoreEvent {
public:
    StoreEvent();

    virtual ~StoreEvent();


    inline void push( const std::shared_ptr< E >  e ) {
        mStore.push_back( e );
    }


private:
    std::list< std::shared_ptr< E > >  mStore;
};
