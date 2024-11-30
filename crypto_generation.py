#!/usr/bin/python3
# SPDX-FileCopyrightText: 2024 Haruto Yamamoto
# SPDX-License-Identifier: BSD-3-Clause

def replace_text(ch):
    replacements = {
        'k': '!1', 'l': '!2', 'm': '!3', 'n': '!4', 'o': '!5',
        'p': '!6', 'q': '!7', 'r': '!8', 's': '!9', 'u': '?1',
        'v': '?2', 'w': '?3', 'x': '?4', 'y': '?5', 'z': '?6'
    }
    if ch.lower() in replacements:
        return replacements[ch.lower()]
    elif ch.isalpha():
        return str(ord(ch.lower()) - ord('a') + 1)
    elif ch == '\n':
        return '\n'
    else:
        return ' '

def english_text(ch):
    if not ch.isalpha() and ch != '\n':
        return ' '
    else:
        return ch

def main():
    import sys
    buffer = []

    for line in sys.stdin:
        for ch in line:
            buffer.append(replace_text(ch))
            #buffer.append(english_text(ch))  # 英文のみを表示したい場合はこちらを使用

    print(''.join(buffer), end='')

if __name__ == "__main__":
    main()

