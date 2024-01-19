#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "aabacbebebe";
    int k = 5;

    int count = 0;
    int max = -1;
    int alpha[26] = {0};
    int l = 0;

    for (int r = 0; r < strlen(s); r++)
    {
        if (alpha[s[r] - 'a'] == 0)
        {
            count++;
        }
        alpha[s[r] - 'a']++;
        while (count > k)
        {
            alpha[s[l] - 'a']--;
            if (alpha[s[l] - 'a'] == 0) count--;
            l++;
        }
        max = max > (r - l + 1) ? max : (r - l + 1);
    }
    printf("%d", max);
}