# 課題3 レポート
35319057 吉田龍生


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

3. 補助関数  
なし

## ソースコードの説明

〈力ずく法〉

l.13 int型でそれぞれ定義する

l.19 for文で文字列の先頭から比較対象がなくなるまでループ

l.20 for文でキーの先頭から最後までループ

l.22 もし、文字が一致したら、iに1を加算

l.24 一致しなかったら、l.20のループを抜ける

l.28 もし、iがキーの文字数と一致したら、検索する文字列が出現した場所をreturnで返す

l.35 検索する文字が現れなかったら、NULLを返す

〈BM法〉

l.42 int型でそれぞれ定義

l.50 ずらし量テーブルを作成

l.59 indexとstart_indexを定義

l.62 while文でindexが最後尾の前にあるまでループ

l.64 for文でキーの最後の文字から1文字ずつ前に行き、先頭に行くまでループ

l.65 確認のためのコード

l.71 もし一致したらindexを1文字前にずらし、countに1を加算し、countとキーの長さが一致したらreturnで検索する文字列が出現した場所を返す

l.77 一致しなかったら、countを0に戻してl.62のfor文を抜ける

l.83 次の比較開始位置を計算し、もし、新しい比較開始位置が前回の比較位置より前か同じの場合は、start_index+1の値を新しい比較開始位置とする。

l.87 新しい比較開始位置を更新する

l.90 検索する文字列が現れなかったら、NULLを返す


## 出力結果

```
Force Search. Find keyword at:wind in my hair.
On a dark deseart highway, cool wind in my hair.
wind
count= 0
On a dark deseart highway, cool wind in my hair.
 wind
count= 0
On a dark deseart highway, cool wind in my hair.
     wind
count= 0
On a dark deseart highway, cool wind in my hair.
         wind
count= 0
On a dark deseart highway, cool wind in my hair.
             wind
count= 0
On a dark deseart highway, cool wind in my hair.
                 wind
count= 0
On a dark deseart highway, cool wind in my hair.
                     wind
count= 0
On a dark deseart highway, cool wind in my hair.
                         wind
count= 0
On a dark deseart highway, cool wind in my hair.
                             wind
count= 0
On a dark deseart highway, cool wind in my hair.
                                wind
count= 0
On a dark deseart highway, cool wind in my hair.
                               wind
count= 1
On a dark deseart highway, cool wind in my hair.
                              wind
count= 2
On a dark deseart highway, cool wind in my hair.
                             wind
count= 3
BM Search. Find keyword at: wind in my hair.
```

## 修正履歴

