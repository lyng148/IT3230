#include <string.h>
#include <stdio.h>

char * reverseWords(char * s){
    int l = 0, index = 0;
    int len = strlen(s); // Lấy chiều dài của chuỗi
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            l = i - 1;
            while (index < l)
            {
                char tmp = s[index];
                s[index] = s[l];
                s[l] = tmp;
                index++;
                l--;
            }
            index = i + 1; // Cập nhật giá trị của index cho từ tiếp theo
        }
    }
    return s;
}
int main()
{
    char str[] = "ok abc";
    printf("%s\n", reverseWords(str));
    return 0;
}
