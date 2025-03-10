#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/**
* Determine if the string s starts with the string prefix.
* @param s - the string to see if it starts with prefix
* @param prefix - the prefix to test
* @returns true if the strings begins with the prefix.
*/



int startsWith(const char s[], const char prefix[])
{
	char buf[20];
	// fixed code
	//int length = strlen(s);
	//char buf[length];

	int i;
	int sz = strlen(prefix);

		for (i = 0; i < sz; i++)
		{
			buf[i] = s[i];
		}
		buf[sz] = '\0';

		return 0 == strcmp(buf, prefix);

}
/**
* Determine if the string s ends with the string suffix.
* @param s - the string to see if it ends with suffix
* @param suffix - the suffix to test
* @returns true if the strings ends with the suffix.
*/
int endsWith(const char s[], const char suffix[])
{
	int sz = strlen(suffix);
	int slen = strlen(s);

	return 0 == strcmp(s + slen - sz, suffix);
}
int main(void)
{
	// Bug 01 - More than 20 char

	//test case 1 (報錯誤訊息) 
	//char s1[] = { "upended" };
	//char prefix[] = { "upendedABCDEFGHIJKLMNOPRSTUVWXYZABCDEFGHIJKLMNOPRSTUVWXYZprefix" };
	//char suffix[] = { "ed" };

	// 剛好20個的話 (可以執行)
	//char s1[] = { "upended" };
	//char prefix[] = { "upendedABCDEFGHIJKL" };
	//char suffix[] = { "ed" };

	// 若21個的話 (報錯)
	//char s1[] = { "upended" };
	//char prefix[] = { "upendedABCDEFGHIJKLK" };
	//char suffix[] = { "ed" };

	

	// Bug 02 - If there is nothing inside
	// 輸出顯示錯誤
	
	//char s1[] = { "upended" };
	//char prefix[] = { "" };
	//char suffix[] = { "ed" };

	//char s1[] = { "upended" };
	//char prefix[] = { "up" };
	//char suffix[] = { "" };

	//char s1[] = { "upended" };
	//char prefix[] = { "up" };
	//char suffix[] = {'\0'};

	//char s1[] = { "upended" };
	//char prefix[] = { "up" };
	//char suffix[] = NULL;



	// Bug 03 - it shouldn't be sensitivity of character
	// 輸出顯示錯誤

	//char s1[] = { "upended" };
	//char prefix[] = { "UP" };
	//char suffix[] = { "ed" };



	// Bug 04 - if there is a space
	// 輸出顯示錯誤
	//char s1[] = { "upended" };
	//char prefix[] = { "up" };
	//char suffix[] = { " " };


	// -------------------------------------------------------
	// Normal test (PASS)
	//test case 1
	//char s1[] = { "upended" };	
	//char prefix[] = { "up" };
	//char suffix[] = { "ed" };


	//test case 2 (PASS) (not start with)
	//char s1[] = { "upended" };
	//char prefix[] = { "123" };
	//char suffix[] = { "ed" };

	//test case 3 (PASS)
	char s1[] = { "upended" };
	char prefix[] = { "up" };
	char suffix[] = { "%/&" };


	// -------------------------------------------------------
	// 不太好的test
	
	//test case
	//char s1[] = { "upended" };
	//char prefix[] = { "up" };
	//char suffix[] = { "upended" };

	//test case 
	//char s1[] = { "A\0" };
	//char prefix[] = { "A" };
	//char suffix[] = { "\0" };


	//test case 
	//char s1[] = { "upended" };
	//char prefix[] = { 'u' };
	//char suffix[] = { "ed" };


	//test case
	//char s1[] = { "upended" };
	//char prefix[] = { 'u', 'p', '\0' };
	//char suffix[] = { "ed" };


	//test case
	//char s1[] = { "upended" };
	//char prefix[] = { 'u', 'p' };
	//char suffix[] = { "ed" };


	printf("%s does %s start with %s\n",
		s1, startsWith(s1, prefix) ? "" : " not", prefix);
	printf("%s does %s end with %s\n",
		s1, endsWith(s1, suffix) ? "" : " not", suffix);
	return 0;

}




