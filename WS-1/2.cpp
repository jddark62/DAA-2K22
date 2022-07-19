#include <iostream>
#include <vector>

void removeZeros(std::vector<int>& sacks) {

        for(auto i = sacks.begin(); i != sacks.end(); ++i){
                if(*i == 0) sacks.erase(i);
        }

}

bool isOver(std::vector<int>& sacks){

        for(int i = 1; i <= sacks.size(); i++){
                if(sacks[i - 1] != i) return false;
        }

        return true;

}

void print(std::vector<int>& sacks){

        for(int i = 0; i < sacks.size(); i++){
                std::cout << sacks[i] << ", ";
        }
        std::cout << std::endl;

}

int main() {


        std::vector<int> sacks = {2, 2, 2};

        print(sacks);

        // Game loop
        while(!isOver(sacks)){

                int picks = 0;
                // Pick One from each non-empty sack
                for(int i = 0; i < sacks.size(); i++){
                        if(sacks[i] != 0){
                                sacks[i]--;
                                picks++;
                        }
                }

                sacks.push_back(picks);
                removeZeros(sacks);
                print(sacks);

        }

        return 0;
}