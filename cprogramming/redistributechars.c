//LeetCode No. 1897
bool makeEqual(char** words, int wordsSize) {
    int stor[26] = {0};
    for (int a = 0; a < wordsSize; a++) {
        int inw = strlen(words[a]);
        for (int g = 0; g < inw; g++) {
                stor[words[a][g] - 'a']++;
        }
    }

    for (int f = 0; f < 26; f++) {
        if (stor[f] % wordsSize != 0) {
            return false;
        }
    }
    return true;  
}