bool one_edit_apart(char *s1, char *s2) {
    if (!s1 || !s2) {
        return false;
    }
    
    int sizeDiff = strlen(s1) - strlen(s2);
    if (sizeDiff > 0) {
        char* tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    sizeDiff = abs(sizeDiff);
    
    if (sizeDiff > 1)
        return false;

        bool hasDiff = false;
        while (*s1 && *s2) {
            if (*s1 != *s2) {
                if (!hasDiff) {
                    hasDiff = true;
                    
                    if (sizeDiff == 0) { 
                        s2++;
                    }
                }
                else {
                    return false;
                }
            }
            
            s1++;
            s2++;
        }
        
    if (sizeDiff == 0) {
        bool hasDiff = false;
        while (*s1 && *s2) {
            if (*s1 != *s2) {
                if (!hasDiff)
                    hasDiff = true;
                else
                    return false;
            }
            
            s1++;
            s2++;
        }
        
        return hasDiff;
    }

    bool hasDiff = false;
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            if (!hasDiff) {
                hasDiff = true;
                s2++;
            } else {
                return false;
            }
        } else {
            s1++;
            s2++;
        }
    }
    return true;
}

OneEditApart("cat", "dog") = false
OneEditApart("cat", "cats") = true
OneEditApart("cat", "cut") = true
OneEditApart("cat", "cast") = true
OneEditApart("cat", "at") = true
OneEditApart("cat", "act") = false
