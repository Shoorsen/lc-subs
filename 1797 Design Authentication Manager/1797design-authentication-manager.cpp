class AuthenticationManager {
public:
    std::unordered_map<string,int> tokens;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if (tokens.contains(tokenId)) {
            return;
        }
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (!tokens.contains(tokenId)) {
            return;
        }
        if (tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (const auto& tok : tokens) {
            auto id = tok.first;
            auto time = tok.second;
            if (time > currentTime) {
                ans++;
            }
        }
        return ans;
        
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */