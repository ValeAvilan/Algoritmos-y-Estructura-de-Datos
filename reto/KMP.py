

def LPS(pattern):
    l = 0
    i = 1
    lps = [0] * len(pattern)

    lps[0] = 0;

    while i < len(pattern):
        if pattern[i] == pattern[l]:
            l += 1
            lps[i] = l
            i += 1

        elif pattern[i] != pattern[l] and l == 0:
            lps[i] = 0
            i += 1

        elif pattern[i] != pattern[l] and l > 0:
            l = lps[l - 1]

    return lps


def KMP(texto , pattern):
    lps = LPS(pattern)
    i = 0  #t
    j = 0 #p

    while i < len(texto):
        if texto[i] == pattern[j]:
            i += 1
            j += 1

        if j == len(pattern):
            return i - j

        if texto[i] != pattern[j]:
            if j == 0:
                i += 1
            else:
                j = lps[j - 1]

    return -1



