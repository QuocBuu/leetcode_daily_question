char* lexGreaterPermutation(char* s, char* target)
{
    int n = strlen(s);
    int count[26] = {0};

    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }

    char* retVal = malloc((n + 1) * sizeof(char));

    if (retVal == NULL)
    {
        return NULL;
    }

    int i = 0;

    while (i < n)
    {
        int c = target[i] - 'a';

        if (count[c] == 0)
        {
            break;
        }

        retVal[i] = target[i];
        count[c]--;
        i++;
    }

    int pos = i;

    while (pos >= 0)
    {
        if (pos < i)
        {
            count[target[pos] - 'a']++;
        }

        if (pos < n)
        {
            int candidate = -1;

            for (int c = target[pos] - 'a' + 1; c < 26; c++)
            {
                if (count[c] > 0)
                {
                    candidate = c;
                    break;
                }
            }

            if (candidate != -1)
            {
                retVal[pos] = 'a' + candidate;
                count[candidate]--;

                int write = pos + 1;

                for (int c = 0; c < 26; c++)
                {
                    while (count[c] > 0)
                    {
                        retVal[write++] = 'a' + c;
                        count[c]--;
                    }
                }

                retVal[n] = '\0';
                return retVal;
            }
        }

        pos--;
    }

    retVal[0] = '\0';

    return retVal;
}