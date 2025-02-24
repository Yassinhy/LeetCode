rom typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        for word in strs:
            sortedword = tuple(sorted(word))
            if (sortedword not in hashmap):
                hashmap[sortedword] = []
            hashmap[sortedword].append(word)
        return list(hashmap.values())
