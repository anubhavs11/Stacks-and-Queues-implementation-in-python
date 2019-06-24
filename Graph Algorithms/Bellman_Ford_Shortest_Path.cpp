#include<vector>
#include<iostream>
const int MAX = 10001;
std::vector<std::pair<int, int>> arr[MAX];
int dis[MAX];

void initialize() {
    for (int i = 0; i < MAX; i++) {
        dis[i] = MAX;
    }
}

int main() {
    int nodes, edges, x, y, weight;
    std::cin >> nodes >> edges;
    
    for (int i = 0; i < edges; i++) {
        std::cin >> x >> y >> weight;
        arr[x].push_back(std::make_pair(y, weight));
    }
    
    initialize();
    bool improvement = true;
    
    for (int i = 1; i < nodes; i++) {
        dis[1] = 0;
        if(improvement){
            improvement = false;
            for (int j = 1; j <= nodes; j++) {
                for (int k = 0; k < arr[j].size(); k++) {
                    if ((dis[j] + arr[j][k].second) < dis[arr[j][k].first]) {
                        dis[arr[j][k].first] = (dis[j] + arr[j][k].second);
                        improvement = true;
                    }
                }
            }
        }
        else{
            break;
        }
    }
    
    for (int i = 2; i <= nodes; i++) {
    std::cout << dis[i] <<" ";
    }
}
