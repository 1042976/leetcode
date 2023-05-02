class Leaderboard {
public:
    unordered_map<int, int> idToScore;
    map<int, int, greater <int> > scoreToCount;
    Leaderboard() {
        
    }
    
    // Time O(logN), Space O(1), N is the number of players recorded on the Leaderboard.
    void addScore(int playerId, int score) {
        if(idToScore.count(playerId)){
            int oldScore = idToScore[playerId];
            if(--scoreToCount[oldScore] == 0){
                scoreToCount.erase(oldScore);
            }
            score += idToScore[playerId];
            idToScore[playerId] = score;
        }
        ++scoreToCount[score];
        idToScore[playerId] = score;

    }
    
    // Time O(K), Space O(1)
    int top(int K) {
        int sum = 0;
        auto it = scoreToCount.begin();
        while(K){
            if(it->second < K){
                sum += it->first * it->second;
                K -= it->second;
                ++it;
            }else{
                sum += it->first * K;
                return sum;
            }
        }
        return sum;
    }
    
    // Time O(logN), Space O(1)
    void reset(int playerId) {
        if(--scoreToCount[idToScore[playerId]] == 0){
            scoreToCount.erase(idToScore[playerId]);
        }
        idToScore.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
