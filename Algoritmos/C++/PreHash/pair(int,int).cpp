struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2*31;
    }
};

//Stronger hash function:
struct PairHash {
    template<typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        size_t h1 = hash<T1>{}(p.first);
        size_t h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 * 2654435761ULL + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
