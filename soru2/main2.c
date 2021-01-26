#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>  
bool isPalRec(char str[], int s, int e) 
{ 
    // 1 karakter varsa polindromdur.
    if (s == e) 
    return true; 
  
    // ilk karakter ve son karakter eşit değilse polindrom değildir.
    if (str[s] != str[e]) 
    return false; 
  
    // diğer karakterler için
    if (s < e + 1) 
    return isPalRec(str, s + 1, e - 1); 
  
    return true; 
} 
  
bool isPalindrome(char str[]) 
{ 
int n = strlen(str); 
  
// boş string polindromdur.
if (n == 0) 
    return true; 
  
return isPalRec(str, 0, n - 1); 
} 

int main() 
{ 
    char str[] = "özge"; 
  
    if (isPalindrome(str)) 
    printf("True"); 
    else
    printf("false"); 
  
    return 0; 
} 
