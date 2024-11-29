// SPDX-FileCopyrightText: 2024 Haruto Yamamoto
// SPDX-License-Identifier: BSD-3-Clause
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//暗号化
void Replacetext(char ch, char *buffer) {
	switch (tolower((unsigned char)ch)) {
		case 'k': strcat(buffer, "!1"); break;
		case 'l': strcat(buffer, "!2"); break;
		case 'm': strcat(buffer, "!3"); break;
		case 'n': strcat(buffer, "!4"); break;
		case 'o': strcat(buffer, "!5"); break;
		case 'p': strcat(buffer, "!6"); break;
                case 'q': strcat(buffer, "!7"); break;
                case 'r': strcat(buffer, "!8"); break;
                case 's': strcat(buffer, "!9"); break;
                case 'u': strcat(buffer, "?1"); break;
		case 'v': strcat(buffer, "?2"); break;
                case 'w': strcat(buffer, "?3"); break;
                case 'x': strcat(buffer, "?4"); break;
                case 'y': strcat(buffer, "?5"); break;
                case 'z': strcat(buffer, "?6"); break;
		default:
	  		if (isalpha((unsigned char)ch)) {
	      			int value = tolower((unsigned char)ch) - 'a' + 1;
				char numStr[4];
				sprintf(numStr, "%d", value);
				strcat(buffer, numStr);
			} else if (ch == '\n') {
				strcat(buffer, "\n");
			} else {
				strcat(buffer, " ");
			}
			break;
	}
}

//アルファベットのみの文
void Englishtext(char ch, char *buffer) {
	char temp[2];
	if (isalpha((unsigned char)ch) == 0 && ch != '\n') {
		temp[0] = ' ';
	} else {
                temp[0] = ch;
        }
	strcat(buffer, temp);
}

		

int main() {
	char line[160000];
	char buffer[320000] = "";

	while (fgets(line, sizeof(line), stdin) != NULL) {
		for (int i = 0; line[i] != '\0'; i++) {
			Replacetext(line[i], buffer);
			//Englishtext(line[i], buffer);	//英文のみを表示したい場合は上の文をコメントアウトしこちらを適用
		}
	}
	printf("%s", buffer);
	return 0;
}
