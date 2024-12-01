# robosystem-test [![Build Status](https://github.com/0Haruto/robosystem-test/actions/workflows/test.yml/badge.svg)](https://github.com/0Haruto/robosystem-test/actions/workflows/test.yml)

## 概要
- このプログラムは、入力したテキストを受け取り、半角英字を指定された記号に置き換えて暗号化するものです。
- オプションとして、半角英字以外の文字や記号を空白に置き換える機能もございます。

## クイックスタート
### 前提条件
- Python 3.7以上がインストールされていること
### インストール
- リポジトリをクローンします。 
```
$ git clone https://github.com/0Haruto/robosystem-test.git
```
### 実行

- 1, 実行ファイルに実行権限を付与します。
```
$ cd robosystem-test
$ chmod +x crypto_generation.py
```

- 2, 以下のコマンドから実行します。
```
$ echo "Hello, World!" | ./crypto_generation.py
```
- 3, 次のような実行結果が得られます
```
85!2!2!5  ?3!5!8!24
```

## 使用方法

### 1, パイプを使用して簡易的なテキストを入力する場合

- 以下のコマンドから実行できます。

```
$ echo 任意の文字列 | ./crypto_generation.py
```

- "任意の文字列"の部分に入力した半角英字のみが暗号化され、その他文字や記号はすべて空白に置き換えられます。

* 注意事項
	- コマンドの性質上、"任意の文字列"の部分に''や""を入力する場合は必ずセットで使用してください。
	- また、Enterを押すとコマンドが実行されてしまうため改行はできません。

### 2, パイプを使用してテキストファイルから読み込む場合

- 以下のコマンドから実行できます。

```
$ cat input.txt | ./crypto_generation.py
```

- input.txtに保存されたテキストが暗号化され、標準出力に出力されます。改行も読み込む事が可能です。

* 注意事項
	- テキストファイルはinput.txtでは無く任意のテキストファイルで問題ありませんがその場合"cat"と"|"の間のファイル名を変更してください。また、上のコマンドでは同じディレクトリ内である必要があります。

## インストール
- 以下のコマンドからインストールをすることができます
```
$ git clone https://github.com/0Haruto/robosystem-test.git
```
- ファイルに実行権限が付いていない場合は以下のコマンドから実行権限を付与してください。
```
$ cd robosystem-test
$ chmod +x crypto_generation.py test_script.sh
```
## シェルスクリプトを使ったテスト

- シェルスクリプトも使用し、上で実行したコマンドと合わせて３つのコマンドを同時にテストすることができます

### テストを実行
- 以下のコマンドからシェルスクリプトを実行できます
```
$ ./test_script.sh
```
- テストをパスした場合次のような結果になります。
```
Test 1 passed!
Test 2 passed!
Test 3 passed!
```

## オプション
- このプログラムは暗号化する前のテキストから半角英字と改行のみを出力することも可能です。
```
def main():
    import sys
    buffer = []

    for line in sys.stdin:
        for ch in line:
            buffer.append(replace_text(ch))
            #buffer.append(english_text(ch))  # 英文のみを表示したい場合はこちらを使用

    print(''.join(buffer))
```
def main内にあるこのコマンドから
```
buffer.append(replace_text(ch))
```
をコメントアウトし
```
#buffer.append(english_text(ch)) 
```
の"#"を外すことで切り替えることができます。

## よくありそうなエラーと糸口

- 動いたが文字が何も出ない。
	- 半角英字以外の文字は空白に置き換わります。全角のアルファベットも空白になるので注意が必要です。

## 最後に
- このプログラムは暗号化はできますが、復元機能はございません。ご了承ください。
## ライセンス
- このプログラムはBSD-3-Clauseライセンスの下で配布されています。詳細なライセンス情報については、[LICENSE](./LICENSE) ファイルを参照してください。
