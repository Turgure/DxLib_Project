#include "Mover.h"

void Mover::update(){
	for(auto i = movers.begin(); i != movers.end();){
		
		if(!(**i).isExist()){
			/*
			(**i).onRemove(*this);
			if(movers.empty()){ // onRemoveì‡Ç≈clearMoverÇ≥ÇÍÇΩèÍçáÇÃëŒèà
				return;
			}
			*/
			delete &i;	//TODO:
			i = movers.erase(i);
			continue;
		}
		
		(**i).update();
		++i;
	}
}

void Mover::add(std::shared_ptr<Object> obj){
	movers.push_back(obj);
}

void Mover::remove(std::shared_ptr<Object> obj){//TODO:
	for(auto i = movers.begin(); i != movers.end();){
		delete &i;
		i = movers.erase(i);
		continue;
	}
}

void Mover::clear(){
	for(auto i = movers.begin(); i != movers.end(); ++i) delete &i;
	movers.clear();
}
