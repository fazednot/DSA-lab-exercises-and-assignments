#include <vector>
#include <queue>

using namespace std;

int numBusesToDestination(vector<vector<int>>& busRoutes, int sourceStop, int targetStop) {
    if (sourceStop == targetStop) return 0;

    vector<vector<int>> stopToBusRoutes(1000001);
    for (int busIndex = 0; busIndex < busRoutes.size(); ++busIndex) {
        for (int stop : busRoutes[busIndex]) {
            stopToBusRoutes[stop].push_back(busIndex);
        }
    }

    queue<pair<int, int>> busesToExplore;
    vector<bool> visitedBuses(busRoutes.size(), false);
    vector<bool> visitedStops(1000001, false);

    for (int busIndex : stopToBusRoutes[sourceStop]) {
        busesToExplore.push({busIndex, 1});
        visitedBuses[busIndex] = true;
    }
    visitedStops[sourceStop] = true;

    while (!busesToExplore.empty()) {
        int currentBus = busesToExplore.front().first;
        int busesTaken = busesToExplore.front().second;
        busesToExplore.pop();

        for (int stop : busRoutes[currentBus]) {
            if (stop == targetStop) return busesTaken;

            if (!visitedStops[stop]) {
                visitedStops[stop] = true;
                for (int nextBus : stopToBusRoutes[stop]) {
                    if (!visitedBuses[nextBus]) {
                        visitedBuses[nextBus] = true;
                        busesToExplore.push({nextBus, busesTaken + 1});
                    }
                }
            }
        }
    }

    return -1;
}