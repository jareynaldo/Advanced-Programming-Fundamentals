
#include <iostream>
template<typename T>
class ParticleFactory{

private:
    static T instance;
    std::vector<T*> inventory;
    ParticleFactory(){

        // check if there is a default invetory size
        if(DEFAULT_INVENTORY_SIZE){
            for(int i = 0; i <= DEFAULT_INVENTORY_SIZE; i++){
                inventory.push_back(new T);
            }
        }else {
            for (int i = 0; i < 99; i++) {
                // if doesn't excist just allocate and push back
                inventory.push_back( new T);
            }
        }

    };
public:

    static ParticleFactory<T> &getInstance(){
        // creates an instance and returns it
            static ParticleFactory instance;
            return instance;

    }


    T* getParticle(){
        if(inventory.size() > 0){
            // get the last value, then pop and return
            T* returnValue = inventory.back();
            inventory.pop_back();
            return returnValue;

        }else{
            T* returnValue = new T;
            return returnValue;

        }
    }

    void returnParticle(T* element){
        // just add last element to invetory
        inventory.push_back(element);
    }



};