/* Problem: Tach_Xau
Description
Xây dựng hàm sau
char* subStr(char* s1, intoffset, int number)
Hàm này tách xâu con từ xâu s1 bắt đầu từ ký tự tại chỉ số offset (tính từ 0) và có độ dài number ký tự.
Viết hàm main để kiểm tra hàm subStr. Hàm main đọc vào từ bàn phím dữ liệu theo cú pháp 2 dòng, trong đó dòng thứ nhất là xâu, dòng thứ hai là hai số nguyên cách nhau bởi dấu cách (số đầu là offset, số thứ hai là number).
Hàm main gọi hàm  subStr và hiển thị ra màn hình xâu con được tách ra. Ví dụ về đầu vào và đầu ra như sau
Input:
Xin chao the gioi
4 4
Output
chao
Chú ý kiểm tra tính hợp lệ của các đối số. Trong trường hợp giá trị number lớn hơn độ dài phần còn lại của xâu s1 tính từ vị trí offset, trả về xâu con là phần còn lại của s1 tính từ vị trí offset.
Nếu offset < 0 hoặc offset >= độ dài của xâu hoặc number <= 0 thì hiển thị ra màn hình "Error". */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *subStr(char *s1, int offset, int number)
{
    if (number < 0)
    {
         char *s = (char *)malloc((6) * sizeof(char));
        strcpy(s, "Error");
        return s;
    }
    
    char *s = (char *)malloc((number + 1) * sizeof(char));
    if (offset < 0 || offset >= strlen(s1))
    {
        strcpy(s, "Error");
        return s;
    }
    
    int j = 0;
    for (int i = offset; i < offset + number; i++)
    {
        s[j++] = s1[i];
        if (i == strlen(s)) break;
    }
    return s;
}

int main()
{
    char s[1000];
    fgets(s, 1000, stdin);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s", subStr(s, a, b));
}