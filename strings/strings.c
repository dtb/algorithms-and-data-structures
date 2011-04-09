#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* revWords(char* sentence, int length)
{
	char* buff = (char *)malloc(length * sizeof(char));
	
	int buffIndex = 0;
	int lastWordIndex = length - 1;
	int q;
	for(q = length - 1; q > 0; q--)
	{
		if(sentence[q] != 0x20 && q > 0)
			continue;
			
		int tmp = q + 1;
		while(tmp <= lastWordIndex)
		{
			buff[buffIndex++] = sentence[tmp++];
		}
		
		buff[buffIndex++] = 0x20;
		
		lastWordIndex = q - 1;
	}
	
	int tmp = q;
	while(tmp <= lastWordIndex)
	{
		buff[buffIndex++] = sentence[tmp++];
	}
	
	buff[buffIndex] = 0;
	
	return buff;
}

char* revStr(char* words, int len)
{
	int t = 0;
	char tmpa;
	while(t < len / 2)
	{
		tmpa = words[len - t - 1];
		words[len - t - 1] = words[t];
		words[t++] = tmpa;
	}
	
	return words;
}

int main(int argc, char *argv[])
{
	char* words = "they had a large barge with an antenna on it that the2y would charge up and discharge";
	
	printf("'%s'\n", words);
	printf("'%s'\n", revWords(words, strlen(words)));
	
	char * myWords = (char*)malloc(strlen(words) * sizeof(char));
	int i = 0;
	while(i < strlen(words))
	{
		myWords[i] = words[i];
		i++;
	}
	
	printf("'%s'\n", myWords);
	
	printf("'%s'\n", revStr(myWords, strlen(myWords)));
	
	return 0;
}