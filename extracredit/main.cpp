#include <iostream>
#include <algorithm>

int main() {
    int numHouses; //number of houses
    std::cout << "Enter number of houses: ";
    std::cin >> numHouses;
    std::cout << "Enter road length: ";
    int roadLength;
    std::cin >> roadLength;
    int numBases = 0; //number of bases
    //populate array with values representing each house's distance from westmost point
    int* houses = new int[numHouses];
    std::cout << "Enter house locations: " << std::endl;
    for(int i = 0; i < numHouses; ++i){
        std::cout << "Location " << i + 1 << ": ";
        int houseLocation;
        std::cin >> houseLocation;
        houses[i] = houseLocation;
    }
    std::sort(houses, houses + numHouses);

    //number of bases can't be more than number of houses. Initialize locations as -1
    int* bases = new int[numHouses];
    for(int i = 0; i < numHouses; ++i){
        bases[i] = -1;
    }
    bool hasBase;
    //iterate through each house and add bases as necessary
    for(int i = 0; i < numHouses; ++i){
        hasBase = false;
        //iterate through each base and check if any in range of house
        for(int j = 0; j < numBases; ++j){
            //check if a base is in range
            if(bases[j] != -1 && abs(houses[i] - bases[j]) <= 4){
                hasBase = true;
                break;
            }
        }
        //if no base is in range of the house, add one 4 miles east of house
        //or as far as the road goes
        if(!hasBase){
            if(houses[i] + 4 > roadLength){
                bases[numBases++] = roadLength;
            }else{
                bases[numBases++] = houses[i] + 4;
            }
        }
    }
    std::cout << "Number of bases: " << numBases << std::endl;
    std::cout <<"Base List: ";
    for(int i = 0; i < numBases; ++i){
        std::cout << bases[i] << " ";
    }

    return 0;
}
